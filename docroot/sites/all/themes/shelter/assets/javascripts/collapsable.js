(function ($) {
  Drupal.behaviors.secondaryNav = {
    attach: function (context, settings) {
      $('#secondary-nav').once('secondaryNav', function() {
        var secondary_menu_state = function(event) {
          var collapsed_menu = $('#secondary-nav .collapsable');
          collapsed_menu.toggleClass('hide-this');

          // Stop event propagation if its the menu link
          if (event.currentTarget.className == 'collapse-menu') {
            return false;
          }
        }
        $('.collapse-menu').on('click', secondary_menu_state );
        $('#secondary-nav').on('click', secondary_menu_state );
      });
    }
  };
})(jQuery);
