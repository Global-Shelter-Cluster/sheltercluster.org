(function ($) {
  /**
   * Automatically open a section based on URL hash value (e.g. http://example.com/user/123/edit#preferences)
   */
  Drupal.behaviors.clusterUserEdit = {
    attach: function (context, settings) {
      $('#user-profile-form', context).once('clusterUserEdit', function() {
        if (!location.hash)
          return;

        const value = location.hash
          .substr(1) // remove the hash symbol
          .replace(/[^a-z\-]/g, ''); // a bit of sanitization

        $(document).ready(function() {
          $('.section-' + value + ':not(.ui-accordion-content-active)').prev('h3').click();
        });
      });
    }
  }
})(jQuery);
