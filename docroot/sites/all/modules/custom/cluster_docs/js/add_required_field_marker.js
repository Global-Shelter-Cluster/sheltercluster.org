(function ($) {
  Drupal.behaviors.cluster_docs_admin_title = {
    attach: function (context, settings) {
      $('#og-group-ref-add-more-wrapper fieldset .fieldset-wrapper').prepend('<span class="form-required" title="This field is required."> *</span>');
    }
  }
})(jQuery);


