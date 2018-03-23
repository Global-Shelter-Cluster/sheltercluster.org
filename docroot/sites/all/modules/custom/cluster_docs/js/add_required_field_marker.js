(function ($) {
  Drupal.behaviors.cluster_docs_admin_title = {
    attach: function (context, settings) {
      $('.vertical-tab-button.last a strong').after('<span class="form-required" title="This field is required."> *</span>');
    }
  }
})(jQuery);


