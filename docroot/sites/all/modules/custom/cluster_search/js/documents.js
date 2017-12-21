(function ($) {
  Drupal.behaviors.clusterSearchDocuments = {
    attach: function (context, settings) {
      $('#content').once('clusterSearchDocuments', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);
        var facets = settings.cluster_search.taxonomies;

        Vue.filter('strip_tags', function (html) {
          return $('<div />').html(html).text();
        });
        Vue.filter('file_size', function (bytes) {
          return (parseInt(bytes)/1024/1024).toFixed(2) + 'M';
        });

        var processDocument = function(result) {
          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
            : null;

          result.thumb = result['field_preview:file:url'];
          if (result.thumb && settings.cluster_search.algolia_prefix === 'local')
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
          for (var facet in facets) {
            if (facet === 'field_language')
              continue;
            if (typeof result[facet] === 'undefined' || !result[facet].length)
              continue;
            for (var tagIndex in result[facet])
              result.tags[result.tags.length] = {
                field_key: facet,
                field: facets[facet],
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

          return result;
        };

        var hitsPerPage = 30;

        var vue = new Vue({
          el: '#content',
          data: {
            mode: 'normal', //normal (all docs in this group) | descendants (all docs in this and its subgroups) | key (only key docs from this group)
            display: 'preview', //preview (document blocks) | list (table)
            facets: {},
            facetFilters: {},
            query: '',
            page: 0,
            pages: 0,
            hits: 0,
            timeout: null,
            results: null,
            searching: false,
            groupNid: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.group_nid : null,
            descendantNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
            showGroup: false
          },
          computed: {
            showModes: function() {
              return this.descendantNids.length > 1; //TODO: adjust this logic when working on the "key" mode
            },
            hasResults: function() {
              return this.results && this.results.length > 0;
            },
            showNoResultsMessage: function() {
              return !this.searching && !this.hasResults;
            },
            hasFacetFiltersSelected: function() {
              return this.prepareFacetFilters() ? true : false;
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
            query: function() {
              if (this.timeout)
                clearTimeout(this.timeout);
              this.searching = true;
              this.timeout = setTimeout(this.search, 150);
            },
            mode: function() {
              this.search();
            }
          },
          methods: {
            prepareFacetFilters: function() {
              var facetFilters = [];
              for (var facet in this.facetFilters) {
                var currentFacetFilter = [];
                if (this.facetFilters[facet].length === 0)
                  continue;

                for (var value in this.facetFilters[facet])
                  if (this.facetFilters[facet][value])
                    currentFacetFilter[currentFacetFilter.length] = facet + ':' + value;

                if (currentFacetFilter.length === 1)
                  facetFilters[facetFilters.length] = currentFacetFilter[0];
                else if (currentFacetFilter.length > 1)
                  facetFilters[facetFilters.length] = currentFacetFilter;
              }

              return facetFilters.length > 0 ? facetFilters : null;
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
              this.search();
            },
            deselectFacet: function(facet, value) {
              if (typeof this.facetFilters[facet] === 'undefined')
                return;

              this.facetFilters[facet][value] = false;
              this.search();
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
                this.search(true);
            },
            focus: function() {
              $('#content .facet input[type=search]').first().focus();
            },
            search: function(skipClearFacets, pageChange) {
              var vue = this;
              vue.timeout = null;
              vue.searching = true;

              var attributesToRetrieve = [
                'url',
                'document_date',
                'group_nids',
                'field_document_source',

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
              if (!vue.query)
                indexName += '_sortByDate';

              var query = [{
                indexName: indexName,
                query: vue.query,
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
              else
                query[0].params.filters = 'group_nids:' + vue.groupNid;

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
                  vue.results = content.results[0].hits.map(processDocument);
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
              });
            }
          }
        });
        vue.search();
      });
    }
  }
})(jQuery);
