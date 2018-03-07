(function ($) {
  Drupal.behaviors.clusterSearchDocuments = {
    processDocument: function(result, facets) {
      var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
        ? result._highlightResult.og_group_ref[0].value
        : null;

      var canEdit = false, canDelete = false;
      if (typeof Drupal.settings.cluster_search.doc_permissions_by_group !== 'undefined') {
        for (var i in result.group_nids) {
          if (typeof Drupal.settings.cluster_search.doc_permissions_by_group[result.group_nids[i]] !== 'undefined') {
            if (Drupal.settings.cluster_search.doc_permissions_by_group[result.group_nids[i]].edit)
              canEdit = true;
            if (Drupal.settings.cluster_search.doc_permissions_by_group[result.group_nids[i]].delete)
              canDelete = true;
            if (canEdit && canDelete)
              break;
          }
        }
      }
      result.can_edit = canEdit;
      result.can_delete = canDelete;

      result.thumb = result['field_preview:file:url'];
      if (result.thumb && Drupal.settings.cluster_search.algolia_prefix === 'local')
        result.thumb = result.thumb.replace('local.sheltercluster.org', 'dev.sheltercluster.org').replace('/styles/document_preview/public', '');

      result.nid = result.objectID;
      result.title = result._highlightResult.title.value;
      result.group = group;
      result.date = typeof result['document_date'] !== 'undefined'
        ? Drupal.behaviors.clusterSearchAlgolia.dateHelper(result['document_date'])
        : null;
      result.featured = result['field_featured'];
      result.key = result['field_key_document'];

      result.tags = [];
      for (var facet in Drupal.settings.cluster_search.taxonomies) {
        if (facet === 'field_language')
          continue;
        if (typeof result[facet] === 'undefined' || !result[facet].length)
          continue;
        for (var tagIndex in result[facet])
          result.tags[result.tags.length] = {
            field_key: facet,
            field: Drupal.settings.cluster_search.taxonomies[facet],
            value: result[facet][tagIndex]
          };
      }

      if (typeof result['field_file:file:url'] !== 'undefined')
        result.direct_url = result['field_file:file:url'];
      else if (typeof result['field_link:url'] !== 'undefined')
        result.direct_url = result['field_link:url'];

      if (typeof result.direct_url !== 'undefined') {
        var file_extension = result.direct_url.substr(result.direct_url.lastIndexOf('.') + 1);
        if (file_extension.length <= 6)
          result.file_extension = file_extension.toUpperCase();
      }

      if (typeof result.field_document_status !== 'undefined' && result.field_document_status)
        result.class = 'document-preview--' + result.field_document_status.toLowerCase().replace(/[^a-z]+/g, '-');

      return result;
    },
    attach: function (context, settings) {
      Vue.filter('strip_tags', function (html) {
        return $('<div />').html(html).text();
      });
      Vue.filter('file_size', function (bytes) {
        return (parseInt(bytes)/1024/1024).toFixed(2) + 'M';
      });

      $('.cluster-search-docs-list').closest('#content').once('clusterSearchDocuments', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);
        var facets = settings.cluster_search.taxonomies;

        var hitsPerPage = 30;

        var historyApiAvailable = typeof history.pushState !== 'undefined';

        var data = {
          mode: 'normal', //normal (all docs in this group) | descendants (all docs in this and its subgroups) | key (only key docs from this group)
          display: 'preview', //preview (document blocks) | list (table)
          facets: {},
          facetFilters: {},
          initialFilters: typeof settings.cluster_search !== 'undefined' ? settings.cluster_search.initial_filters : null,
          nidFilter: typeof settings.cluster_search !== 'undefined' ? settings.cluster_search.nid_filter : null,
          search: '',
          page: 0,
          pages: 0,
          hits: 0,
          timeout: null,
          results: null,
          searching: false,
          initializing: true,
          groupNid: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.group_nid : null,
          descendantNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
          showGroup: false
        };

        function processQuery(data, query, key, validOptions) {
          if (typeof query[key] === 'undefined')
            return;

          if (typeof validOptions === 'object') {
            if ($.inArray(query[key], validOptions) !== -1)
              data[key] = query[key];
          } else if (validOptions === 'string') {
            if (typeof query[key] === 'string')
              data[key] = query[key];
          } else if (validOptions === 'facet') {
            var facetValue = {};
            if (typeof query[key] === 'object') {
              for (var i = 0; i < query[key].length; i++)
                facetValue[query[key][i]] = true;
            } else {
              facetValue[query[key]] = true;
            }
            data.facetFilters['field_' + key] = facetValue;
          }
        }

        var query = (new URI()).search(true);
        processQuery(data, query, 'mode', ['normal', 'descendants', 'key']);
        processQuery(data, query, 'display', ['preview', 'list']);
        processQuery(data, query, 'search', 'string');
        for (var facetField in facets) {
          processQuery(data, query, facetField.substr('field_'.length), 'facet');
        }
        var page = typeof query.page !== 'undefined' ? parseInt(query.page) - 1 : 0;

        var vue = new Vue({
          el: '#content',
          data: data,
          computed: {
            showModes: function() {
              return true;//this.descendantNids.length > 1; //TODO: adjust this logic when working on the "key" mode
            },
            hasSubgroups: function() {
              return this.descendantNids.length > 1;
            },
            hasResults: function() {
              return this.results && this.results.length > 0;
            },
            showNoResultsMessage: function() {
              return !this.searching && !this.hasResults;
            },
            hasFacetFiltersSelected: function() {
              for (var facet in this.facetFilters) {
                if (this.facetFilters[facet].length === 0)
                  continue;

                for (var value in this.facetFilters[facet])
                  if (this.facetFilters[facet][value])
                    return true;
              }
              return false;
            },
            facetsDisplay: function() {
              // The "taxonomy_groups" setting is an array of ints where each number represents how many facets belong
              // to each "group" (lang&doctype, basic tags, advanced tags).
              // The idea is to decide whether to show "the next group of facets", based on how many we're showing already.
              // If there's less than 3 facets shown, we add the next group to the display (see facetsDisplay() below).
              var vue = this, ret = {}, facetsShown = 0, stopLooking = false;
              var facetKeys = Object.keys(facets), currentFacetKey = 0;
              for (var i = 0; i < settings.cluster_search.taxonomy_groups.length; i++) {
                for (var j = 0; j < settings.cluster_search.taxonomy_groups[i]; j++) {
                  var facet_key = facetKeys[currentFacetKey];
                  currentFacetKey++;
                  if (!vue.facets[facet_key])
                    continue;
                  if (typeof vue.initialFilters[facet_key] !== 'undefined')
                    continue;

                  var show = false, first = true;
                  for (var value in vue.facets[facet_key].values) {
                    if (vue.isFacetActive(facet_key, value)) {
                      // Value is selected by the user
                      show = true;
                      break;
                    }
                    if (first)
                      first = false;
                    else if (!stopLooking) {
                      // Facet has 2 or more values
                      show = true;
                      break;
                    }
                  }

                  if (show) {
                    ret[facet_key] = vue.facets[facet_key];
                    facetsShown++;
                  }
                }

                if (facetsShown >= 3) {
                  // We're showing 3 or more facets, stop looking actively (only show facets that have selected values).
                  stopLooking = true;
                }
              }

              return ret;
            },
            paginationPages: function() {
              var ret = [];
              var lastShown = -1;
              var i;

              // First few pages
              for (i = 0; i < Math.min(this.pages, 3); i++) {
                ret[ret.length] = i;
                lastShown = i;
              }

              if (lastShown >= this.pages)
                return ret;

              // Pages around the current one
              var from = Math.max(lastShown + 1, this.page - 2);
              var to = Math.min(this.pages - 1, this.page + 2);
              if (to >= from) {
                if (from === lastShown + 2)
                  from--;
                if (from > lastShown + 1)
                  ret[ret.length] = '-';
                for (i = from; i <= to; i++) {
                  ret[ret.length] = i;
                  lastShown = i;
                }
              }

              // Last few pages
              var from = Math.max(lastShown + 1, this.pages - 3);
              var to = this.pages - 1;
              if (to >= from) {
                if (from === lastShown + 2)
                  from--;
                if (from > lastShown + 1)
                  ret[ret.length] = '-';
                for (i = from; i <= to; i++) {
                  ret[ret.length] = i;
                  lastShown = i;
                }
              }

              return ret;
            },
            resultsFrom: function() {
              return this.page * hitsPerPage + 1;
            },
            resultsTo: function() {
              return this.resultsFrom + this.results.length - 1;
            }
          },
          watch: {
            search: function() {
              if (this.initializing)
                return;
              if (this.timeout)
                clearTimeout(this.timeout);
              this.searching = true;
              this.timeout = setTimeout(this.doSearch, 150);
            },
            mode: function() {
              if (this.initializing)
                return;
              this.doSearch();
            },
            display: function() {
              if (this.initializing)
                return;
              this.pushHistory();
            }
          },
          methods: {
            prepareFacetFilters: function() {
              var ret = [];

              var process = function(filters) {
                for (var facet in filters) {
                  var currentFacetFilter = [];
                  if (filters[facet].length === 0)
                    continue;

                  for (var value in filters[facet])
                    if (filters[facet][value])
                      currentFacetFilter[currentFacetFilter.length] = facet + ':' + value;

                  if (currentFacetFilter.length === 1)
                    ret[ret.length] = currentFacetFilter[0];
                  else if (currentFacetFilter.length > 1)
                    ret[ret.length] = currentFacetFilter;
                }
              };

              process(this.initialFilters);
              process(this.facetFilters);

              if (this.mode === 'key') {
                ret[ret.length] = 'field_key_document:true';
              }

              return ret.length > 0 ? ret : null;
            },
            changeFacetFilter: function(e, facet, value) {
              var checkbox = $(e.target);
              if (checkbox.is(':checked'))
                this.selectFacet(facet, value);
              else
                this.deselectFacet(facet, value);
            },
            selectFacet: function(facet, value) {
              if (typeof this.facetFilters[facet] === 'undefined')
                this.facetFilters[facet] = {};

              this.facetFilters[facet][value] = true;
              this.doSearch();
            },
            deselectFacet: function(facet, value) {
              if (typeof this.facetFilters[facet] === 'undefined')
                return;

              this.facetFilters[facet][value] = false;
              this.doSearch();
            },
            isFacetActive: function(facet, value) {
              if (typeof this.facetFilters[facet] === 'undefined')
                return false;
              if (typeof this.facetFilters[facet][value] === 'undefined')
                return false;
              return this.facetFilters[facet][value];
            },
            clearSelectedFacets: function() {
              var changed = false;
              for (var facet in this.facetFilters) {
                if (typeof this.facets[facet] === 'undefined') {
                  this.facetFilters[facet] = {};
                  changed = true;
                  continue;
                }
                for (var value in this.facetFilters[facet]) {
                  if (this.facetFilters[facet][value] && typeof this.facets[facet].values[value] === 'undefined') {
                    this.facetFilters[facet][value] = false;
                    changed = true;
                  }
                }
              }
              if (changed)
                this.doSearch(true);
            },
            focus: function() {
              $('#content .facet input[type=search]').first().focus();
            },
            doSearch: function(skipClearFacets, pageChange) {
              var vue = this;
              vue.timeout = null;
              vue.searching = true;

              var attributesToRetrieve = [
                'url',
                'document_date',
                'group_nids',
                'field_document_source',
                'field_document_status',

                'field_featured',
                'field_key_document',

                'field_preview:file:url',

                'field_file:file:url',
                'field_file:file:size',
                'field_link:url'
              ];
              var facetsToRetrieve = [];
              for (var facet in facets) {
                attributesToRetrieve[attributesToRetrieve.length] = facet;
                facetsToRetrieve[facetsToRetrieve.length] = facet;
              }

              var indexName = settings.cluster_search.algolia_prefix + 'Documents';
              if (!vue.search)
                indexName += '_sortByDate';

              var query = [{
                indexName: indexName,
                query: vue.search,
                params: {
                  facets: facetsToRetrieve,
                  attributesToRetrieve: attributesToRetrieve,
                  hitsPerPage: hitsPerPage,
                  page: isNaN(pageChange) ? 0 : parseInt(pageChange) // If not given, always resets to the first page
                }
              }];

              if (vue.mode === 'descendants')
                query[0].params.filters = vue.descendantNids
                  .map(function(i) {return 'group_nids:' + i})
                  .join(' OR ');
              else if (vue.groupNid)
                query[0].params.filters = 'group_nids:' + vue.groupNid;

              if (vue.nidFilter) { // E.g. arbitrary libraries
                if (query[0].params.filters !== '')
                  query[0].params.filters += ' AND ';
                query[0].params.filters += '(' + vue.nidFilter
                    .map(function (i) {
                      return 'objectID:' + i
                    })
                    .join(' OR ')
                  + ')';
              }

              var facetFilters = vue.prepareFacetFilters();
              if (facetFilters)
                query[0].params.facetFilters = facetFilters;

              algolia_client.search(query, function searchDone(err, content) {
                if (err) {
                  vue.facets = {};
                  vue.results = null;
                  return;
                }

                if (content.results[0].hits.length > 0)
                  vue.results = content.results[0].hits.map(Drupal.behaviors.clusterSearchDocuments.processDocument);
                else
                  vue.results = null;

                vue.facets = {};
                for (var facet in facets) {
                  if (typeof content.results[0].facets[facet] === 'undefined')
                    continue;
                  var facet_values = {};
                  for (var facet_key in content.results[0].facets[facet])
                    facet_values[facet_key] = content.results[0].facets[facet][facet_key];
                  vue.facets[facet] = {
                    title: facets[facet],
                    values: facet_values
                  };
                }

                vue.pages = content.results[0].nbPages;
                vue.hits = content.results[0].nbHits;
                vue.page = content.results[0].page;
                vue.showGroup = vue.mode === 'descendants';

                if (!skipClearFacets)
                  vue.clearSelectedFacets();
                vue.searching = false;

                if (vue.initializing)
                  vue.initializing = false;
                else
                  vue.pushHistory();
              });
            },
            pushHistory: function() {
              if (!historyApiAvailable)
                return;

              // Determine if the query string has changed, and push to the browser's history if it did
              var vue = this;
              var data = {};

              var process = function(data, value, key, possibleValues) {
                if (possibleValues === 'string') {
                  if (value !== '')
                    data[key] = value;
                } else if (possibleValues === 'facet') {
                  data[key] = [];
                  for (var facetValue in value)
                    if (value[facetValue])
                      data[key][data[key].length] = facetValue;
                } else if ($.inArray(value, possibleValues) !== -1)
                  data[key] = value;
              };

              process(data, vue.mode, 'mode', ['descendants', 'key']);
              process(data, vue.display, 'display', ['list']);
              process(data, vue.search, 'search', 'string');

              for (var facetField in facets) {
                if (typeof vue.facetFilters[facetField] !== 'undefined')
                  process(data, vue.facetFilters[facetField], facetField.substr('field_'.length), 'facet');
              }

              if (vue.page > 0)
                data.page = vue.page + 1;

              var newURI = (new URI()).search(data);
              if (newURI.equals(new URI()))
                return;

              var url = newURI.search();
              if (url === '')
                url = '?';
              history.pushState(data, null, url);
            },
            popHistory: function(data) {
              this.initializing = true;

              this.mode = 'normal';
              this.display = 'preview';
              this.search = '';
              this.facetFilters = {};

              processQuery(this, data, 'mode', ['normal', 'descendants', 'key']);
              processQuery(this, data, 'display', ['preview', 'list']);
              processQuery(this, data, 'search', 'string');
              for (var facetField in facets) {
                processQuery(this, data, facetField.substr('field_'.length), 'facet');
              }
              var page = typeof data.page !== 'undefined' ? parseInt(data.page) - 1 : 0;

              this.initializing = false;
              this.doSearch(false, page);
            }
          }
        });

        window.addEventListener('popstate', function(e) {
          vue.popHistory(e.state);
        });

        vue.doSearch(false, page);
      });

      $('#shelter-documents').once('clusterSearchDocuments', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);
        var facets = settings.cluster_search.taxonomies;

        var data = {
          results: null,
          groupNid: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.group_nid : null,
          descendantNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
          showGroup: true
        };

        var vue = new Vue({
          el: '#shelter-documents',
          data: data,
          computed: {
            title: function() {
              return this.keyDocs ? 'Recent Key Documents' : 'Recent Documents';
            },
            keyDocs: function() {
              return this.groupNid ? false : true;
            },
            hasSubgroups: function() {
              return this.descendantNids.length > 1;
            }
          },
          methods: {
            prepareFacetFilters: function() {
              var ret = [];

              if (this.keyDocs) {
                ret[ret.length] = 'field_key_document:true';
              }

              return ret.length > 0 ? ret : null;
            },
            doSearch: function() {
              var vue = this;

              var attributesToRetrieve = [
                'url',
                'document_date',
                'group_nids',
                'field_document_source',
                'field_document_status',

                'field_featured',
                'field_key_document',

                'field_preview:file:url',

                'field_file:file:url',
                'field_file:file:size',
                'field_link:url'
              ];
              for (var facet in facets) {
                attributesToRetrieve[attributesToRetrieve.length] = facet;
              }

              var indexName = settings.cluster_search.algolia_prefix + 'Documents_sortByDate';

              var query = [{
                indexName: indexName,
                query: '',
                params: {
                  attributesToRetrieve: attributesToRetrieve,
                  hitsPerPage: 3
                }
              }, {
                indexName: indexName,
                query: '',
                params: {
                  attributesToRetrieve: attributesToRetrieve,
                  hitsPerPage: 3
                }
              }];

              if (vue.keyDocs) {

              }

              // First query is "this group only"
              if (vue.groupNid) {
                query[0].params.filters = 'group_nids:' + vue.groupNid;

                // Second query is "including descendants"
                query[1].params.filters = vue.descendantNids
                  .map(function (i) {
                    return 'group_nids:' + i
                  })
                  .join(' OR ');
              }

              var facetFilters = vue.prepareFacetFilters();
              if (facetFilters)
                query[0].params.facetFilters = facetFilters;

              algolia_client.search(query, function searchDone(err, content) {
                if (err) return;

                if (content.results[0].hits.length > 0)
                  vue.results = content.results[0].hits.map(Drupal.behaviors.clusterSearchDocuments.processDocument);
                else if (content.results[1].hits.length > 0)
                  vue.results = content.results[1].hits.map(Drupal.behaviors.clusterSearchDocuments.processDocument);
              });
            }
          }
        });

        vue.doSearch();
      });
    }
  }
})(jQuery);
