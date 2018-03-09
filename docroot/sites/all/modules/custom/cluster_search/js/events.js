(function ($) {
  Drupal.behaviors.clusterSearchEvents = {
    processEvent: function(result) {
      var group = typeof result._highlightResult.og_group_ref !== 'undefined' && result._highlightResult.og_group_ref.length > 0
        ? result._highlightResult.og_group_ref[0].value
        : null;

      var canEdit = false, canDelete = false;
      if (typeof Drupal.settings.cluster_search.event_permissions_by_group !== 'undefined') {
        for (var i in result.group_nids) {
          if (typeof Drupal.settings.cluster_search.event_permissions_by_group[result.group_nids[i]] !== 'undefined') {
            if (Drupal.settings.cluster_search.event_permissions_by_group[result.group_nids[i]].edit)
              canEdit = true;
            if (Drupal.settings.cluster_search.event_permissions_by_group[result.group_nids[i]].delete)
              canDelete = true;
            if (canEdit && canDelete)
              break;
          }
        }
      }
      result.can_edit = canEdit;
      result.can_delete = canDelete;

      var location = '';
      if (result['field_postal_address:postal_code'])
        location += ' ' + result['field_postal_address:postal_code'];
      if (result['field_postal_address:locality'])
        location += ' ' + result['field_postal_address:locality'];
      if (result['field_postal_address:country'])
        location += ' ' + result['field_postal_address:country'];
      result.location = $.trim(location);

      result.nid = result.objectID;
      result.title = result._highlightResult.title.value;
      result.group = group;
      result.date = Drupal.behaviors.clusterSearchAlgolia.dateHelperWithTime(result['event_date']);
      result.short_date = Drupal.behaviors.clusterSearchAlgolia.dateHelperShortWithTime(result['event_date']);

      return result;
    },
    attach: function (context, settings) {
      Vue.filter('strip_tags', function (html) {
        return $('<div />').html(html).text();
      });

      $('.cluster-search-events-list').closest('#content').once('clusterSearchEvents', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);

        var hitsPerPage = 30;

        var historyApiAvailable = typeof history.pushState !== 'undefined';

        var data = {
          mode: 'upcoming', //upcoming | all | descendants ("all", including subgroups)
          display: 'preview', //preview (event blocks) | list (table)
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
          showGroup: false,
          nowTS: 0
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
          }
        }

        var query = (new URI()).search(true);
        processQuery(data, query, 'mode', ['upcoming', 'all', 'descendants']);
        processQuery(data, query, 'display', ['preview', 'list']);
        processQuery(data, query, 'search', 'string');
        var page = typeof query.page !== 'undefined' ? parseInt(query.page) - 1 : 0;

        var vue = new Vue({
          el: '#content',
          data: data,
          computed: {
            showModes: function() {
              return true;
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
            initNow: function() {
              var vue = this;
              var setNow = function() {
                var date = new Date;
                vue.nowTS = parseInt(date.valueOf() / 1000);
              };

              setNow();
              setInterval(setNow, 1000 * 60);
            },
            focus: function() {
              $('#content .facet input[type=search]').first().focus();
            },
            doSearch: function(pageChange) {
              var vue = this;
              vue.timeout = null;
              vue.searching = true;

              var attributesToRetrieve = [
                'url',
                'event_date',
                'event_map_image',
                'event_map_link',
                'event_location_html',
                'group_nids'
              ];

              var indexName = settings.cluster_search.algolia_prefix + 'Events';
              if (vue.mode === 'upcoming')
                indexName += '_reverseSort';

              var query = [{
                indexName: indexName,
                query: vue.search,
                params: {
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

              if (vue.mode === 'upcoming')
                query[0].params.numericFilters = "event_date>" + vue.nowTS;

              algolia_client.search(query, function searchDone(err, content) {
                if (err) {
                  vue.facets = {};
                  vue.results = null;
                  return;
                }

                if (content.results[0].hits.length > 0)
                  vue.results = content.results[0].hits.map(Drupal.behaviors.clusterSearchEvents.processEvent);
                else
                  vue.results = null;

                vue.pages = content.results[0].nbPages;
                vue.hits = content.results[0].nbHits;
                vue.page = content.results[0].page;
                vue.showGroup = vue.mode === 'descendants';

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
                } else if ($.inArray(value, possibleValues) !== -1)
                  data[key] = value;
              };

              process(data, vue.mode, 'mode', ['all', 'descendants']);
              process(data, vue.display, 'display', ['list']);
              process(data, vue.search, 'search', 'string');

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

              this.mode = 'upcoming';
              this.display = 'preview';
              this.search = '';

              processQuery(this, data, 'mode', ['upcoming', 'all', 'descendants']);
              processQuery(this, data, 'display', ['preview', 'list']);
              processQuery(this, data, 'search', 'string');
              var page = typeof data.page !== 'undefined' ? parseInt(data.page) - 1 : 0;

              this.initializing = false;
              this.doSearch(page);
            }
          }
        });

        window.addEventListener('popstate', function(e) {
          vue.popHistory(e.state);
        });

        vue.initNow();
        vue.doSearch(page);
      });

      $('#shelter-calendar').once('clusterSearchEvents', function() {
        if (!settings.cluster_search.algolia_app_id || !settings.cluster_search.algolia_search_key || !settings.cluster_search.algolia_prefix) {
          $(this).remove();
          return;
        }

        var algolia_client = algoliasearch(settings.cluster_search.algolia_app_id, settings.cluster_search.algolia_search_key);

        var data = {
          results: null,
          groupNid: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.group_nid : null,
          descendantNids: typeof settings.cluster_nav !== 'undefined' ? settings.cluster_nav.search_group_nids : null,
          showGroup: true,
          nowTS: 0
        };

        var vue = new Vue({
          el: '#shelter-calendar',
          data: data,
          computed: {
            hasSubgroups: function() {
              return this.descendantNids.length > 1;
            }
          },
          methods: {
            initNow: function() {
              var vue = this;
              var setNow = function() {
                var date = new Date;
                vue.nowTS = parseInt(date.valueOf() / 1000);
              };

              setNow();
              setInterval(setNow, 1000 * 60);
            },
            doSearch: function() {
              var vue = this;

              var attributesToRetrieve = [
                'url',
                'event_date',
                'event_map_image',
                'event_map_link',
                'event_location_html',
                'group_nids'
              ];

              var indexName = settings.cluster_search.algolia_prefix + 'Events_reverseSort';

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

              // Only show upcoming events
              query[0].params.numericFilters = "event_date>" + vue.nowTS;
              query[1].params.numericFilters = "event_date>" + vue.nowTS;

              algolia_client.search(query, function searchDone(err, content) {
                if (err) return;

                if (content.results[0].hits.length > 0)
                  vue.results = content.results[0].hits.map(Drupal.behaviors.clusterSearchEvents.processEvent);
                else if (content.results[1].hits.length > 0)
                  vue.results = content.results[1].hits.map(Drupal.behaviors.clusterSearchEvents.processEvent);
              });
            }
          }
        });

        vue.initNow();
        vue.doSearch();
      });
    }
  }
})(jQuery);
