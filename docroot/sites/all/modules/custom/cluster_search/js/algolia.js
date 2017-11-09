(function ($) {
  Drupal.behaviors.clusterSearchAlgolia = {
    attach: function (context, settings) {
      $('#cluster-search-mega-menu').once('clusterSearchAlgolia', function() {
        var algolia_app_id = settings.cluster_search.algolia_app_id;
        var algolia_search_key = settings.cluster_search.algolia_search_key;
        var algolia_prefix = settings.cluster_search.algolia_prefix;
        if (!algolia_app_id || !algolia_search_key || !algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(algolia_app_id, algolia_search_key);

        var dateHelper = function(timestamp) {
          var date = new Date(parseInt(timestamp) * 1000);
          var months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
          return date.getDate() + ' ' + (months[date.getMonth()]) + ' ' + date.getFullYear();
        };

        var processDocument = function(result) {
          var group = typeof result.og_group_ref !== 'undefined' && result.og_group_ref.length > 0
            ? result.og_group_ref[0]
            : null;

          return {
            url: result.url,
            title: result.title,
            group: group,
            date: typeof result['field_report_meeting_date'] !== 'undefined'
              ? dateHelper(result['field_report_meeting_date'])
              : null,
            featured: result['field_featured'],
            key: result['field_key_document']
          };
        };
        var processEvent = function(result) {
          var group = typeof result.og_group_ref !== 'undefined' && result.og_group_ref.length > 0
            ? result.og_group_ref[0]
            : null;

          var location = '';
          if (result['field_postal_address:postal_code'])
            location += ' ' + result['field_postal_address:postal_code'];
          if (result['field_postal_address:locality'])
            location += ' ' + result['field_postal_address:locality'];
          if (result['field_postal_address:country'])
            location += ' ' + result['field_postal_address:country'];
          location = $.trim(location);

          return {
            url: result.url,
            title: result.title,
            group: group,
            date: dateHelper(result['field_recurring_event_date2:value']),
            location: location
          };
        };
        var processPage = function(result) {
          var types = {
            'arbitrary_library': 'Library',
            'library': 'Library',
            'article': 'Article',
            'basic_page': null,
            'discussion': 'Discussion',
            'homepage': null
          };

          var group = typeof result.og_group_ref !== 'undefined' && result.og_group_ref.length > 0
            ? result.og_group_ref[0]
            : null;

          return {
            url: result.url,
            title: result.title,
            group: group,
            type: typeof types[result.type] !== 'undefined' ? types[result.type] : null
          };
        };
        var processGroup = function(result) {
          var types = {
            'community_of_practice': 'Community of practice',
            'geographic_region': 'Geographic region',
            'hub': 'Hub',
            'response': 'Response',
            'discussion': 'Discussion',
            'strategic_advisory': 'Strategic Advisory Group',
            'working_group': 'Working Group'
          };

          return {
            url: result.url,
            title: result.title,
            type: typeof types[result.type] !== 'undefined' ? types[result.type] : null
          };
        };
        var processContact = function(result) {
          var group = typeof result.og_group_ref !== 'undefined' && result.og_group_ref.length > 0
            ? result.og_group_ref[0]
            : null;
          var org = typeof result.field_organisation_name !== 'undefined' && result.field_organisation_name.length > 0
            ? result.field_organisation_name[0]
            : null;
          var role = typeof result.field_role_or_title !== 'undefined' && result.field_role_or_title.length > 0
            ? result.field_role_or_title[0]
            : null;

          return {
            url: result.url,
            title: result.title,
            group: group,
            org: org,
            role: role
          };
        };

        new Vue({
          el: '#cluster-search-mega-menu',
          data: {
            query: '',
            timeout: null,
            results: null,
            searching: false
          },
          computed: {
            hasResults: function() {
              return this.results && (
                this.results.documents.length > 0 ||
                this.results.documents2.length > 0 ||
                this.results.events.length > 0 ||
                this.results.pages.length > 0 ||
                this.results.groups.length > 0 ||
                this.results.contacts.length > 0
              );
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
            }
          },
          methods: {
            focusHandler: function() {
              $('#cluster-search-mega-menu').addClass('force-visible');
            },
            blurHandler: function() {
              $('#cluster-search-mega-menu').removeClass('force-visible');
            },
            focus: function() {
              $('#cluster-search-mega-menu input').focus();
            },
            search: function() {
              var vue = this;
              vue.timeout = null;

              if ($.trim(this.query) === '') {
                vue.results = null;
                return;
              }

              var query = [];

              // if (category)
              //   hint_params['filters'] = 'tags:' + category;

              query.push({
                indexName: algolia_prefix + 'Documents',
                query: vue.query,
                params: {
                  hitsPerPage: 20
                }
              });

              query.push({
                indexName: algolia_prefix + 'Events',
                query: vue.query,
                params: {
                  hitsPerPage: 10
                }
              });

              query.push({
                indexName: algolia_prefix + 'Pages',
                query: vue.query,
                params: {
                  hitsPerPage: 10
                }
              });

              query.push({
                indexName: algolia_prefix + 'Groups',
                query: vue.query,
                params: {
                  hitsPerPage: 10
                }
              });

              query.push({
                indexName: algolia_prefix + 'Contacts',
                query: vue.query,
                params: {
                  hitsPerPage: 10
                }
              });

              algolia_client.search(query, function searchDone(err, content) {
                if (err) {
                  vue.results = null;
                  return;
                }

                var ret = {
                  documents: [],
                  documents2: [],
                  events: [],
                  pages: [],
                  groups: [],
                  contacts: []
                };

                if (content.results[0].hits.length > 0)
                  ret.documents = content.results[0].hits.slice(0, 10).map(processDocument);
                if (content.results[0].hits.length > 10)
                  ret.documents2 = content.results[0].hits.slice(10).map(processDocument);
                if (content.results[1].hits.length > 0)
                  ret.events = content.results[1].hits.map(processEvent);
                if (content.results[2].hits.length > 0)
                  ret.pages = content.results[2].hits.map(processPage);
                if (content.results[3].hits.length > 0)
                  ret.groups = content.results[3].hits.map(processGroup);
                if (content.results[4].hits.length > 0)
                  ret.contacts = content.results[4].hits.map(processContact);

                // Limit "pages + groups" to a maximum of 10 results
                ret.pages = ret.pages.slice(0, 10 - Math.min(ret.groups.length, 5));
                ret.groups = ret.groups.slice(0, 10 - Math.min(ret.pages.length, 5));

                vue.results = ret;
                vue.searching = false;
              });
            }
          }
        });
      });
    }
  }
})(jQuery);
