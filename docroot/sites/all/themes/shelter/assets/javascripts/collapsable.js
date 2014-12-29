/*! http://git.io/jcda v1.0.0 by @mathias */
;jQuery.fn.dataAttr=function(a,b){return b?this.attr("data-"+a,b):this.attr("data-"+a)};

(function ($) {
  Drupal.behaviors.secondaryNav = {
    dud: function (context, settings) {
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
      });
    }
  };
})(jQuery);

(function ($) {
  Drupal.behaviors.collapsibleSections = {
    attach: function (context, settings) {
      $('body').once('collapsibleSections', function() {
        var collapsible = $('[data-collapsible]');
        var collapsible_elements_count = collapsible.length;

        collapsible.each( function(index, element) {
          var element = $(element);
          var collapsible_target_name = element.data().collapsible;
          var collapsible_target = $('#'+collapsible_target_name);
          var collapsed_state = $.cookie('collapsed_state').split('');

          collapsible_target.css('overflow','hidden');
          if (collapsed_state[index] == 1) {
            collapsible_target.hide();
            element.toggleClass('collapsed');
          } else {
            element.toggleClass('collapsible');
          }

          var collapse = function(event) {
            var element = $(event.currentTarget);
            var current_domain = window.location.host;
            var current_pathname = window.location.pathname;
            var collapsed_state = $.cookie('collapsed_state').split('');
            var count = event.data.collapsible_elements_count;
            var index =  event.data.collapsible_element_index;
            var collapsible_target = $('#'+event.data.collapsible_target_name);
            var new_collapsed_state = Array.apply(null, new Array(count)).map(function(){return 0;});

            element.toggleClass('collapsed').toggleClass('collapsible');
            // Copy collapsed_state value over to the new state array
            for (var i = 0; i < collapsed_state.length; i++ ) {
              new_collapsed_state[i] = parseInt(collapsed_state[i]);
            }
            new_collapsed_state[index] = parseInt(collapsed_state[index]) ? 0 : 1;

            $.cookie('collapsed_state', new_collapsed_state.toString().replace(/\,/gi,''), {
              expires: 365,
              path: current_pathname,
              domain: current_domain,
              secure: false
            });

            if (new_collapsed_state[index] == 0) {
              collapsible_target.slideDown(300);
            } else {
              collapsible_target.slideUp(300);
            }

          };

          //injectCSS('#'+collapsible_target_name+'{ max-height: '+(collapsible_target.height()+100)+'px; }');

          element.on('click', {
            collapsible_target_name: collapsible_target_name,
            collapsible_elements_count: collapsible_elements_count,
            collapsible_element_index: index
          }, collapse);

        });
      });
    }
  };
})(jQuery);
