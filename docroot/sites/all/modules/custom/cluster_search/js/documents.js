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

        new Vue({
          el: '#content',
          data: {
            facets: [],
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
            getPage: function(items, page, items_per_page) {
              return items.slice(items_per_page * page, items_per_page * page + items_per_page);
            },
            focus: function() {
              $('#content .facet input[type=search]').first().focus();
            },
            search: function() {
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
                  hitsPerPage: 50
                }
              }];

              if (parseInt(vue.includeDescendants))
                query[0].params.filters = vue.descendantNids
                  .map(function(i) {return 'group_nids:' + i})
                  .join(' OR ');
              else
                query[0].params.filters = 'group_nids:' + vue.groupNid;

              algolia_client.search(query, function searchDone(err, content) {
                if (err) {
                  vue.facets = null;
                  vue.results = null;
                  return;
                }

                if (content.results[0].hits.length > 0)
                  vue.results = content.results[0].hits.map(processDocument);
                else
                  vue.results = null;

                for (var facet in facets) {
                  if (typeof content.results[0].facets[facet] === 'undefined')
                    continue;
                  var facet_values = [];
                  for (var facet_key in content.results[0].facets[facet])
                    facet_values[facet_values.length] = {
                      label: facet_key,
                      count: content.results[0].facets[facet][facet_key]
                    }
                  vue.facets.push({
                    title: facets[facet],
                    values: facet_values
                  });
                }

                vue.searching = false;
                if (vue.results) console.log(vue.results[0]);
              });
            }
          }
        }).search();
      });
    }
  }
})(jQuery);
