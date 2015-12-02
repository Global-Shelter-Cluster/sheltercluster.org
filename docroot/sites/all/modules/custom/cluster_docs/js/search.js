(function ($) {

  Drupal.behaviors.cluster_docs_search = {
    attach: function (context, settings) {
      var nodeId = Drupal.settings.cluster_docs.node_id;
      var nodeType = Drupal.settings.cluster_docs.node_type;

      console.log(nodeId);
      console.log(nodeType);

      $('.facet input[name=title]').once('cluster_docs_search').click(function() {
        var value = $(this).closest('.facet').find('input[name=title]').val();

        $(this).autocomplete({
          source: function (request, response) {
            jQuery.get("search-documents/autocomplete", {
                query: value
            }, function (data) {
              console.log(value);
              console.log(response(data));
            });
          },
          minLength: 3
        });
      });
      $('.facet input[name=title_search]').once('cluster_docs_search').click(function() {
        var href = window.location.href;
        var value = $(this).closest('.facet').find('input[name=title]').val();

        // Remove title parameter from current URL, if any
        href = href.replace(/\?f\[\d*\]=title%3A[^&]*&/, '?').replace(/&f\[\d*\]=title%3A[^&]*/, '').replace(/\?f\[\d*\]=title%3A[^&]*$/, '');

        if (value) {
          var connector = href.indexOf('?') == -1 ? '?' : '&';
          href = href + connector + 'f[]=title%3A' + encodeURIComponent(value);
        }

        window.location.href = href;
      });
    }
  }

})(jQuery);
