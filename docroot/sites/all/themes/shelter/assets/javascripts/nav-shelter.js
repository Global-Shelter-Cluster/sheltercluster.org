(function ($) {
  Drupal.behaviors.shelterNav = {
    attach: function (context, settings) {
      $('#nav-shelter').once('shelterNav', function() {
        var shelterNavReference = $("#nav-shelter .list-container").html();

        var divide_menu_into = function(reference, size) {
          var list_markup = $();
          var list = $(reference).find('li');
          var list_length = list.length;

          for (i = 0; i < list_length; i += size) {
            var list_slice = list.slice(i,i+size).wrapAll('<ul class="nav-items"></ul>').parent();
            list_markup = list_markup.add( list_slice );
          }
          return list_markup;
        };

        $(window).bind('resize', function() {
          if (resize_event_id != undefined) {
            clearTimeout(resize_event_id);
          }

          var resize_event_id = _.delay( function(reference) {
            var window_size = $(window).width();
            var markup_output = '';
            var divisions = 6;

            if (window_size >= 460 && window_size <= 650) {
              divisions = 2;
            } else if (window_size >= 461 && window_size <= 1215) {
              divisions = 3;
            }

            $('#nav-shelter .list-container').html(
              divide_menu_into(reference, divisions).parent().html()
            );

          }, 100, shelterNavReference);

        });

        $(window).resize();

      });
    }
  };
})(jQuery);
