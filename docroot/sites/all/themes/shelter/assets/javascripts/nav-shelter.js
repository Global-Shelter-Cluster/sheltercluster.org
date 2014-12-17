(function ($) {
  Drupal.behaviors.shelterNav = {
    attach: function (context, settings) {
      $('#nav-shelter').once('shelterNav', function() {

        var shelterNavReference = $("#nav-shelter").clone();
        var target = $('#nav-master');
        var shelterNavLength = $("#nav-shelter ul li").length;

        var divideTo = function(reference, size) {
          var list_markup = $();
          var list = reference.find('li');
          var list_length = list.length;

          for (i = 0; i < list_length; i += size) {
            var list_slice = list.slice(i,i+size).wrapAll('<ul class="nav-items"></ul>').parent();
            list_markup = list_markup.add( list_slice );
          }
          return list_markup;
        };

          $(window).bind('resize', function(e) {
            if (resize_event_id != undefined) {
              clearTimeout(resize_event_id);
            }

            var resize_event_id = _.delay( function(shelterNavReference) {
              var windowsize = $(window).width();
              var divisions = 6;
              var markup_output = '';

              if (windowsize >= 460 && windowsize <= 650) {
                divisions = 2;
              } else if (windowsize >= 461 && windowsize <= 1215) {
                divisions = 3;
              }
              results = divideTo(shelterNavReference, divisions);
              results.each( function() {
                markup_output += $(this).parent().html();
              });

              $('#nav-shelter .list-container').html(markup_output);

            }, 50, shelterNavReference);

          });

        $(window).resize();

      });
    }
  };
})(jQuery);
