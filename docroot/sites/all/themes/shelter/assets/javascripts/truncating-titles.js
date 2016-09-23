(function ($) {
  Drupal.behaviors.truncatingtitles = {
    attach: function (context, settings) {

        $('.document-row .information-title a').each(function() {
            var title = $.trim($(this).text());
            var max = 50;

            if (title.length > max) {
                var shortText = jQuery.trim(title).substring(0, max - 3) + '...';
                $(this).html('<span>' + shortText + '</span>');
            }
        });
  
    }
  };
})(jQuery);
