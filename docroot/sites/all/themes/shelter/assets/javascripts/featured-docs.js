(function ($) {
  Drupal.behaviors.shelterFeaturedDocs = {
    attach: function (context, settings) {

      var carousel = $('.featured-document-slider', context);
      carousel.jcarousel();

      carousel.on('jcarousel:reload', function() {
        var totalWidth = $('#content', context).innerWidth();
        var sideColumn = $('.side-column', context).outerWidth(true);
        var width = totalWidth - sideColumn;
        carousel.css('width', width + 'px');
        carousel.jcarousel('items').css('width', width + 'px');
      });
      carousel.trigger('jcarousel:reload');

      carousel.jcarouselAutoscroll({
        interval: 5000
      });

      $('.jcarousel-control-prev', context)
        .on('jcarouselcontrol:active', function() {
            $(this).removeClass('inactive');
        })
        .on('jcarouselcontrol:inactive', function() {
            $(this).addClass('inactive');
        })
        .jcarouselControl({
            target: '-=1'
        });

      $('.jcarousel-control-next', context)
        .on('jcarouselcontrol:active', function() {
            $(this).removeClass('inactive');
        })
        .on('jcarouselcontrol:inactive', function() {
            $(this).addClass('inactive');
        })
        .jcarouselControl({
            target: '+=1'
        });

      $('.jcarousel-pagination', context)
        .on('jcarouselpagination:active', 'a', function() {
            $(this).addClass('active');
        })
        .on('jcarouselpagination:inactive', 'a', function() {
            $(this).removeClass('active');
        })
        .jcarouselPagination();

    }
  };
})(jQuery);
