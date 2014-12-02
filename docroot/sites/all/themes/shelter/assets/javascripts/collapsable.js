(function ($) {
  Drupal.behaviors.secondaryNav = {
    attach: function (context, settings) {
      $('#secondary-nav').once('secondaryNav', function() {
        $('#secondary-nav').on('click', function() {
          var collapsed_menu = $(this).find('.collapsable');
          collapsed_menu.toggleClass('hide-this');
        });
      });
    }
  };
})(jQuery);
