(function ($) {
  Drupal.behaviors.clusterSearchAlgolia = {
    dateHelper: function(timestamp) {
      var date = new Date(parseInt(timestamp) * 1000);
      var months = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
      return date.getDate() + ' ' + (months[date.getMonth()]) + ' ' + date.getFullYear();
    },
    attach: function (context, settings) {
      $('#cluster-search-mega-menu').once('clusterSearchAlgolia', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);

        Vue.filter('strip_tags', function (html) {
          return $('<div />').html(html).text();
        });

        var processDocument = function(result) {
          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
            : null;

          return {
            url: result.url,
            title: result._highlightResult.title.value,
            group: group,
            date: typeof result['field_report_meeting_date'] !== 'undefined'
              ? Drupal.behaviors.clusterSearchAlgolia.dateHelper(result['field_report_meeting_date'])
              : null,
            featured: result['field_featured'],
            key: result['field_key_document']
          };
        };
        var processEvent = function(result) {
          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
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
            title: result._highlightResult.title.value,
            group: group,
            date: Drupal.behaviors.clusterSearchAlgolia.dateHelper(result['field_recurring_event_date2:value']),
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

          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
            : null;

          return {
            url: result.url,
            title: result._highlightResult.title.value,
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
            title: result._highlightResult.title.value,
            type: typeof types[result.type] !== 'undefined' ? types[result.type] : null
          };
        };
        var processContact = function(result) {
          var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
            ? result._highlightResult.og_group_ref[0].value
            : null;
          var org = typeof result._highlightResult.field_organisation_name !== 'undefined' && result._highlightResult.field_organisation_name.length > 0
            ? result._highlightResult.field_organisation_name[0].value
            : null;
          var role = typeof result._highlightResult.field_role_or_title !== 'undefined' && result._highlightResult.field_role_or_title.length > 0
            ? result._highlightResult.field_role_or_title[0].value
            : null;
          var phone = typeof result._highlightResult.field_phone_number !== 'undefined' && result._highlightResult.field_phone_number.length > 0
            ? result._highlightResult.field_phone_number[0].value
            : null;
          var email = typeof result._highlightResult.field_email !== 'undefined' && result._highlightResult.field_email.length > 0
            ? result._highlightResult.field_email[0].value
            : null;
          var rawEmail = typeof result.field_email !== 'undefined' && result.field_email.length > 0
            ? result.field_email[0]
            : null;

          return {
            url: rawEmail ? 'mailto:' + rawEmail : null,
            title: result._highlightResult.title.value,
            group: group,
            org: org,
            role: role,
            phone: phone,
            email: email
          };
        };

        new Vue({
          el: '#cluster-search-mega-menu',
          data: {
            query: '',
            timeout: null,
            results: null,
            searching: false,
            shouldScrollOnResults: true,
            indexFilter: null,
            groupNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
            onlyWithinGroup: true
          },
          computed: {
            hasResults: function() {
              var ret = this.results && (
                this.results.documents.length > 0 ||
                this.results.events.length > 0 ||
                this.results.pages.length > 0 ||
                this.results.groups.length > 0 ||
                this.results.contacts.length > 0
              );

              if (!ret)
                this.shouldScrollOnResults = true;

              return ret;
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
            indexFilter: function(value) {
              if (!value)
                this.limitResults();
              this.search();
              this.focus();
            },
            onlyWithinGroup: function() {
              this.search();
              this.focus();
            }
          },
          methods: {
            limitResults: function() {
              if (!this.results)
                return;

              if (this.results.documents)
                this.results.documents = this.getPage(this.results.documents, 0, 20);
              if (this.results.events)
                this.results.events = this.getPage(this.results.events, 0, 10);
              if (this.results.pages)
                this.results.pages = this.getPage(this.results.pages, 0, 8);
              if (this.results.groups)
                this.results.groups = this.getPage(this.results.groups, 0, 8);
              if (this.results.contacts)
                this.results.contacts = this.getPage(this.results.contacts, 0, 6);

              // Limit "pages + groups" to a maximum of 8 results
              if (this.results.pages && this.results.groups) {
                this.results.pages = this.results.pages.slice(0, 8 - Math.min(this.results.groups.length, 4));
                this.results.groups = this.results.groups.slice(0, 8 - Math.min(this.results.pages.length, 4));
              }
            },
            getPage: function(items, page, items_per_page) {
              return items.slice(items_per_page * page, items_per_page * page + items_per_page);
            },
            focusHandler: function() {
              $('#cluster-search-mega-menu').addClass('force-visible').parent().addClass('disable-hover');
              if (this.hasResults)
                this.scroll();
            },
            blurHandler: function() {
              $('#cluster-search-mega-menu').removeClass('force-visible').parent().removeClass('disable-hover');
            },
            focus: function() {
              $('#cluster-search-mega-menu input').focus();
            },
            scroll: function() {
              $('html, body').animate({scrollTop: $('#cluster-search-mega-menu').offset().top}, 400);
              this.shouldScrollOnResults = false;
            },
            search: function() {
              var vue = this;
              vue.timeout = null;

              if ($.trim(this.query) === '') {
                vue.results = null;
                return;
              }

              var query = [];

              var searchQueries = {
                'Documents': !vue.indexFilter ? 20 : (vue.indexFilter === 'documents' ? 50 : 0),
                'Events': !vue.indexFilter ? 10 : (vue.indexFilter === 'events' ? 50 : 0),
                'Pages': !vue.indexFilter ? 8 : (vue.indexFilter === 'pages' ? 40 : 0),
                'Groups': !vue.indexFilter ? 8 : (vue.indexFilter === 'groups' ? 40 : 0),
                'Contacts': !vue.indexFilter ? 6 : (vue.indexFilter === 'contacts' ? 30 : 0)
              };

              for (var index in searchQueries) {
                var item = {
                  indexName: settings.cluster_search.algolia_prefix + index,
                  query: vue.query,
                  params: {
                    hitsPerPage: searchQueries[index]
                  }
                };

                if (vue.onlyWithinGroup && vue.groupNids) {
                  item.params.filters = vue.groupNids
                    .map(function(i) {return 'group_nids:' + i})
                    .join(' OR ');
                }

                query.push(item);
              }

              algolia_client.search(query, function searchDone(err, content) {
                if (err) {
                  vue.results = null;
                  return;
                }

                var ret = {
                  documents: [],
                  events: [],
                  pages: [],
                  groups: [],
                  contacts: []
                };

                if (content.results[0].hits.length > 0)
                  ret.documents = content.results[0].hits.map(processDocument);
                if (content.results[1].hits.length > 0)
                  ret.events = content.results[1].hits.map(processEvent);
                if (content.results[2].hits.length > 0)
                  ret.pages = content.results[2].hits.map(processPage);
                if (content.results[3].hits.length > 0)
                  ret.groups = content.results[3].hits.map(processGroup);
                if (content.results[4].hits.length > 0)
                  ret.contacts = content.results[4].hits.map(processContact);

                vue.results = ret;
                if (!vue.indexFilter)
                  vue.limitResults();
                vue.searching = false;
                if (vue.shouldScrollOnResults && vue.hasResults)
                  vue.scroll();
              });
            }
          }
        });
      });
    }
  }
})(jQuery);
