(function ($) {
  Drupal.behaviors.matchHeight = {
    attach: function (context, settings) {
      
      // Equal Heights
      $('#shelter-coordination-team .coordination-item').matchHeight({
        byRow: true,
        property: 'height',
        target: null,
        remove: false
      });
      
    }
  };
})(jQuery);
