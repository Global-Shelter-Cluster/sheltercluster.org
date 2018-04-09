(function ($) {
  Drupal.behaviors.cluster_docs_admin_title = {
    attach: function (context, settings) {
      var $file = $('.field-name-field-file .file-widget .file a', context);
      var $title = $('.form-item-title input', context);
      // This doesn't work with context because ajax will trigger it again, we
      // add once here to the ajax response, so it loads once per ajax response.
      $file.once('shelter-title', function() {
        var title = $file.text().replace(/\.[^/.]+$/, "");
        if ($title.val() == '') {
          $title.val(title);
        }
      });
    }
  }
})(jQuery);
