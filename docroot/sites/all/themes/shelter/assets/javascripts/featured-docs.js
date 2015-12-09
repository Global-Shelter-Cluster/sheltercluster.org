(function ($) {
  Drupal.behaviors.shelterFeaturedDocs = {
    attach: function (context, settings) {
      $('#featured-documents').once('shelterFeaturedDocs', function() {
        var carousel = $('.featured-document-slider');
        carousel.jcarousel();

        carousel.on('jcarousel:create jcarousel:reload', function() {
          var element = $(this),
          width = element.innerWidth();
          element.jcarousel('items').css('width', width + 'px');
        });

        $('.jcarousel-control-prev')
          .on('jcarouselcontrol:active', function() {
              $(this).removeClass('inactive');
          })
          .on('jcarouselcontrol:inactive', function() {
              $(this).addClass('inactive');
          })
          .jcarouselControl({
              target: '-=1'
          });

        $('.jcarousel-control-next')
          .on('jcarouselcontrol:active', function() {
              $(this).removeClass('inactive');
          })
          .on('jcarouselcontrol:inactive', function() {
              $(this).addClass('inactive');
          })
          .jcarouselControl({
              target: '+=1'
          });

        $('.jcarousel-pagination')
          .on('jcarouselpagination:active', 'a', function() {
              $(this).addClass('active');
          })
          .on('jcarouselpagination:inactive', 'a', function() {
              $(this).removeClass('active');
          })
          .jcarouselPagination();
      });
    }
  };
})(jQuery);
