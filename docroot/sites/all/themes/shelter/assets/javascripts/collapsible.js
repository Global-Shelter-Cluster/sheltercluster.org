(function ($) {
  Drupal.behaviors.collapsibleSections = {
    attach: function (context, settings) {
      $('body').once('collapsibleSections', function() {
        var collapsible = $('[data-collapsible]');
        var collapsible_elements_count = collapsible.length;
        var current_pathname = window.location.pathname;

        // Returns an array of collapsible element states
        var get_collapsed_state = function(count) {
          var current_pathname = window.location.pathname;
          var default_state = Array.apply(null, new Array(count)).map(function() {return 0;} );
          var collapsible = $('[data-collapsible]');

          if ($.cookie(current_pathname + '_collapsed_state') != null) {
            return $.cookie(current_pathname + '_collapsed_state').split('');
          }
          collapsible.each( function(index, element) {
            var element = $(element);
            if (element.data('collapsible-default') == 'collapsed') {
              default_state[index] = 1;
            }
          });
          return default_state;
        };

        if ($.cookie(current_pathname + '_collapsed_state') != null) {
          var new_collapsed_state = $.cookie(current_pathname + '_collapsed_state').split('');

          collapsible.each( function(index, element) {
            var element = $(element);
            if (element.data('force-collapsible-default') == 'collapsed') {
              new_collapsed_state[index] = 1;
            }
          });

          $.cookie(current_pathname + '_collapsed_state', new_collapsed_state.toString().replace(/\,/gi,''), {
            expires: 7,
            secure: false
          });
        }

        collapsible.each( function(index, element) {
          var element = $(element);
          var collapsible_target_name = element.data().collapsible;
          var collapsible_target = $('#'+collapsible_target_name);
          var collapsed_state = get_collapsed_state(collapsible_elements_count);

          var collapse = function(event) {
            var element = $(event.currentTarget);
            var current_pathname = window.location.pathname;
            var count = event.data.collapsible_elements_count;
            var index =  event.data.collapsible_element_index;
            var collapsed_state = get_collapsed_state(count);
            var collapsible_target = $('#'+event.data.collapsible_target_name);
            var new_collapsed_state = Array.apply(null, new Array(count)).map(function(){return 0;});

            element.toggleClass('collapsed').toggleClass('collapsible');
            // Copy collapsed_state value over to the new state array
            for (var i = 0; i < collapsed_state.length; i++ ) {
              new_collapsed_state[i] = parseInt(collapsed_state[i]);
            }
            new_collapsed_state[index] = parseInt(collapsed_state[index]) ? 0 : 1;

            $.cookie(current_pathname + '_collapsed_state', new_collapsed_state.toString().replace(/\,/gi,''), {
              expires: 7,
              secure: false
            });

            if (new_collapsed_state[index] == 0) {
              collapsible_target.slideDown(300);
            } else {
              collapsible_target.slideUp(300);
            }
          };

          collapsible_target.css('overflow','hidden');// Fixes some dom jumping issue

          if (collapsed_state[index] == 1) {
            collapsible_target.hide();
            element.toggleClass('collapsed');
          } else {
            element.toggleClass('collapsible');
          }

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
