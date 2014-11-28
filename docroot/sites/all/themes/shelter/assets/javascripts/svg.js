(function ($) {
  Drupal.behaviors.injectSVGs = {
    attach: function (context, settings) {
      $('body').once('injectSVGs', function() {

        var to_inject = document.querySelectorAll('img.svg');

        var injector_options = {
          evalScripts: 'once'
        };

        SVGInjector(to_inject, injector_options, function (total_SVGs_injected) {
          // Callback after all SVGs are injected
        });

      });
    }
  };
})(jQuery);
