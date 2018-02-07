/**
 * @file
 * Addressfield map widget fix.
 *
 * Properly saves the zoom value set manually by a user.
 */

(function($) {

  Drupal.behaviors.addressfield_autocomplete_zoom_fix = {
    attach: function(context, settings) {
      $('.addressfield-autocomplete-input', context).bind("geocode:idle", function(event, result) {
        var zoom = $(this).geocomplete('map').getZoom();
        var parent_id = $(this).attr('id').replace('-autocomplete', '');
        $('#' + parent_id).find('.zoom').val(zoom);
      });
    }
  };
      
})(jQuery);
