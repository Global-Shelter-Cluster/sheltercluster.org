(function ($) {
  Drupal.behaviors.shelterNav = {
    attach: function (context, settings) {
      $('#nav-shelter').once('shelterNav', function() {

      var shelterNavReference = $();
      shelterNavReference = shelterNavReference.add($("#nav-shelter"));
      var target = $('#nav-master');
      var shelterNavLength = $("#nav-shelter ul li").length;

      var divideTo = function(shelterNavReference, size) {
        console.log(size);
        var list_markup = $();
        var list = shelterNavReference.find('li');
        var list_length = list.length;
        for (i = 0; i < list_length; i += size) {
          var list_slice = list.slice(i,i+size).wrapAll('<ul class="nav-items"></ul>').parent();
          list_markup = list_markup.add( list_slice );
        }
        return list_markup;
      };

      (function (shelterNavReference) {
        $(window).bind('resize', function(e) {
          window.resizeEvt;
          clearTimeout(window.resizeEvt);
          window.resizeEvt = setTimeout(function(event) {
            var windowsize = $(window).width();
            if (windowsize >= 460 && windowsize <= 650) {
              result = divideTo(shelterNavReference,2);
            } else if (windowsize >= 461 && windowsize <= 1215) {
              result = divideTo(shelterNavReference,3);
            } else {
              // result = divideTo(shelterNavReference,0);
            }
            $('#nav-shelter .nav-items').replaceWith(result.parent().html());
          }, 250);
        });
      })(shelterNavReference);

      $(window).resize();

      // test = divideTo(shelterNavReference,3);



      });
    }
  };
})(jQuery);
