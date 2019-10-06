(function ($) {
  /**
   * Automatically open a section based on URL hash value (e.g. http://example.com/user/123/edit#preferences),
   * or on whether this is a password-reset.
   */
  Drupal.behaviors.clusterUserEdit = {
    attach: function (context, settings) {
      $('#user-profile-form', context).once('clusterUserEdit', function() {
        let value;

        if (location.hash)
          value = location.hash
            .substr(1) // remove the hash symbol
            .replace(/[^a-z\-]/g, ''); // a bit of sanitization

        if (location.search.match(/pass-reset-token=/))
          // We come from a password reset operation, let's auto-open the password section
          value = 'user';

        $(document).ready(function() {
          $('.section-' + value + ':not(.ui-accordion-content-active)').prev('h3').click();
        });
      });
    }
  }
})(jQuery);
