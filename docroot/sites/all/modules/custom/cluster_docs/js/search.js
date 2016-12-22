(function ($) {

  Drupal.behaviors.cluster_docs_search = {
    attach: function (context, settings) {
      $('.facet input[name=title]').once('cluster_docs_search').change(function () {
            $(this).closest('.facet').find('input[name=title_search]').click();
        });

      $('.facet input[name=title_search]').once('cluster_docs_search').click(function () {
        var value = $(this).closest('.facet').find('input[name=title]').val();
        var href = window.location.href;

        // Remove title parameter from current URL, if any
        href = href.replace(/\?f\[\d*\]=title%3A[^&]*&/, '?').replace(/&f\[\d*\]=title%3A[^&]*/, '').replace(/\?f\[\d*\]=title%3A[^&]*$/, '');
        href = href.replace(/\?f\[\d*\]=attachments_field_file%3A[^&]*&/, '?').replace(/&f\[\d*\]=attachments_field_file%3A[^&]*/, '').replace(/\?f\[\d*\]=attachments_field_file%3A[^&]*$/, '');

        if (value) {
          var connector = href.indexOf('?') == -1 ? '?' : '&';
          href = href + connector + 'f[]=title%3A' + encodeURIComponent(value);
        }

        window.location.href = href;
      });

      $('.facet input[name=document_search]').once('cluster_docs_search').click(function () {
        var value = $(this).closest('.facet').find('input[name=document]').val();
        var href = window.location.href;

        href = href.replace(/\?f\[\d*\]=title%3A[^&]*&/, '?').replace(/&f\[\d*\]=title%3A[^&]*/, '').replace(/\?f\[\d*\]=title%3A[^&]*$/, '');
        href = href.replace(/\?f\[\d*\]=attachments_field_file%3A[^&]*&/, '?').replace(/&f\[\d*\]=attachments_field_file%3A[^&]*/, '').replace(/\?f\[\d*\]=attachments_field_file%3A[^&]*$/, '');

        if (value) {
          var connector = href.indexOf('?') == -1 ? '?' : '&';
          href = href + connector + 'f[]=attachments_field_file%3A' + encodeURIComponent(value);
        }

        window.location.href = href;
      });
    }
  }
})(jQuery);
