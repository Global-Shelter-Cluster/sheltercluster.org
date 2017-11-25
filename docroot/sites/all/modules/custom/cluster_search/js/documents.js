(function ($) {
  Drupal.behaviors.clusterSearchDocuments = {
    attach: function (context, settings) {
      $('#content').once('clusterSearchDocuments', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);
        var facets = {
          'field_language': "Language",

          'field_document_type': "Document Type",

          'field_coordination_management': "Coordination Management",
          'field_information_management': "Information Management",
          'field_technical_support_design': "Technical Support and Design"

          //TODO: advanced tags
        };

        Vue.filter('strip_tags', function (html) {
          return $('<div />').html(html).text();
        });
        Vue.filter('file_extension', function (filename) {
          var ret = filename.substr(filename.lastIndexOf('.') + 1);
          if (ret.length > 6)
            return null;
          return ret;
        });

        var processDocument = function(result) {
          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
            : null;

          result.thumb = result['field_preview:file:url'];
          if (result.thumb)
            result.thumb = result.thumb.replace('local.sheltercluster.org', 'dev.sheltercluster.org'); //TODO: temporary code

          result.nid = result.objectID;
          result.title = result._highlightResult.title.value;
          result.group = group;
          result.date = typeof result['field_report_meeting_date'] !== 'undefined'
            ? Drupal.behaviors.clusterSearchAlgolia.dateHelper(result['field_report_meeting_date'])
            : null;
          result.featured = result['field_featured'];
          result.key = result['field_key_document'];

          return result;
        };

        var vue = new Vue({
          el: '#content',
          data: {
            facets: {},
            facetFilters: {},
            query: '',
            timeout: null,
            results: null,
            searching: false,
            indexFilter: null,
            groupNid: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.group_nid : null,
            descendantNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
            includeDescendants: "0"
          },
          computed: {
            hasResults: function() {
              return this.results && this.results.length > 0;
            },
            showNoResultsMessage: function() {
              return !this.searching && $.trim(this.query) !== '' && !this.hasResults;
            }
          },
          watch: {
            query: function() {
              if (this.timeout)
                clearTimeout(this.timeout);
              this.searching = true;
              this.timeout = setTimeout(this.search, 150);
            },
            includeDescendants: function() {
              this.search();
              this.focus();
            }
          },
          methods: {
            changeFacetFilter: function(e, facet, value) {
              var checkbox = $(e.target);
              if (typeof this.facetFilters[facet] === 'undefined')
                this.facetFilters[facet] = {};
              this.facetFilters[facet][value] = checkbox.is(':checked');
              this.search();
            },
            isFacetActive: function(facet, value) {
              if (typeof this.facetFilters[facet] === 'undefined')
                return false;
              if (typeof this.facetFilters[facet][value] === 'undefined')
                return false;
              return this.facetFilters[facet][value];
            },
            cleanSelectedFacets: function() {
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
            getPage: function(items, page, items_per_page) {
              return items.slice(items_per_page * page, items_per_page * page + items_per_page);
            },
            focus: function() {
              $('#content .facet input[type=search]').first().focus();
            },
            search: function(skipCleanFacets) {
              var vue = this;
              vue.timeout = null;

              var attributesToRetrieve = [
                'url',
                'field_report_meeting_date',

                'field_featured',
                'field_key_document',

                'field_preview:file:url',

                'field_file:file:url',
                'field_file:file:size'
              ];
              var facetsToRetrieve = [];
              for (var facet in facets) {
                attributesToRetrieve[attributesToRetrieve.length] = facet;
                facetsToRetrieve[facetsToRetrieve.length] = facet;
              }

              var query = [{
                indexName: settings.cluster_search.algolia_prefix + 'Documents',
                query: vue.query,
                params: {
                  facets: facetsToRetrieve,
                  attributesToRetrieve: attributesToRetrieve,
                  hitsPerPage: 24
                }
              }];

              if (parseInt(vue.includeDescendants))
                query[0].params.filters = vue.descendantNids
                  .map(function(i) {return 'group_nids:' + i})
                  .join(' OR ');
              else
                query[0].params.filters = 'group_nids:' + vue.groupNid;

              if (vue.facetFilters) {
                var facetFilters = [];
                for (var facet in vue.facetFilters) {
                  var currentFacetFilter = [];
                  if (vue.facetFilters[facet].length === 0)
                    continue;

                  for (var value in vue.facetFilters[facet])
                    if (vue.facetFilters[facet][value])
                      currentFacetFilter[currentFacetFilter.length] = facet + ':' + value;

                  if (currentFacetFilter.length === 1)
                    facetFilters[facetFilters.length] = currentFacetFilter[0];
                  else if (currentFacetFilter.length > 1)
                    facetFilters[facetFilters.length] = currentFacetFilter;
                }
                if (facetFilters.length > 0)
                  query[0].params.facetFilters = facetFilters;
              }

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

                if (!skipCleanFacets)
                  vue.cleanSelectedFacets();
                vue.searching = false;
                if (vue.results) console.log(vue.results[0]);
              });
            }
          }
        });
        vue.search();
      });
    }
  }
})(jQuery);
