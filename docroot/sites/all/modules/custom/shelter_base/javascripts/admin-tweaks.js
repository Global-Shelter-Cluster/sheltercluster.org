(function ($) {
  Drupal.behaviors.betterTagging = {
    attach: function (context, settings) {
      $('.field-widget-options-buttons').once('betterTagging', function() {
        $(this).find('.form-checkbox').each( function() {
          var element = $(this);
          if (element.attr('checked')) {
            element.parent().toggleClass('selected');
          }
        });

        $(this).find('.form-checkbox').on('change', function(){
          $(this).parent().toggleClass('selected');
        });
      });
    }
  }
})(jQuery);
