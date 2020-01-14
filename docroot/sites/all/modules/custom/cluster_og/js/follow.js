(function ($) {
  Drupal.behaviors.clusterFollow = {
    attach: function (context, settings) {
      $('body.not-logged-in #secondary-nav .nav-item .follow').once('clusterFollow', function() {
        

        $(this).click(function() {

        });
      });
    }
  }
})(jQuery);
