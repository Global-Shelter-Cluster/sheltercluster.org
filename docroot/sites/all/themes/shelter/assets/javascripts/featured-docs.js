(function ($) {
  Drupal.behaviors.shelterFeaturedDocs = {
    attach: function (context, settings) {
      $('#featured-documents').once('shelterFeaturedDocs', function() {
        console.log('featured slider');
      });
    }
  };
})(jQuery);
