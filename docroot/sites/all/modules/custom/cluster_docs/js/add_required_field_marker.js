(function ($) {
  Drupal.behaviors.add_required_field_marker = {
    attach: function (context, settings) {
      $('#og-group-ref-add-more-wrapper fieldset .fieldset-wrapper').prepend('<span class="form-required" title="This field is required."> *</span>');
    }
  }
})(jQuery);


