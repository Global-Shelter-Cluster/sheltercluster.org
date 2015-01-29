(function ($) {

  Drupal.behaviors.cluster_docs_search = {
    attach: function (context, settings) {
      $('.facet input[name=title]').once('cluster_docs_search').change(function() {
        var value = $(this).val();
        var href = window.location.href;

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