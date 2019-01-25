/**
 * @file
 * Fetch location data.
 */

(function ($) {
  Drupal.behaviors.gpslocation_component = {
    attach: function (context, settings) {
      var geoLocation = false;

      // Determine once if geolocation is supported by the user agent.
      if ("geolocation" in navigator) {
        geoLocation = true;
      }

      for (var i = 0; i < settings.webform_gpslocation.length; i++) {
        var elementSetting = settings.webform_gpslocation[i];

        var leafletMap = undefined;
        // Find the corresponding leafletMap settings item. This holds the
        // map objects we need.
        for (var m = 0; m < settings.leaflet.length; m++) {
          if (settings.leaflet[m].mapId == elementSetting.mapId) {
            leafletMap = settings.leaflet[m];
          }
        }

        // Add a crosshair to the map.
        var crosshairIcon = L.icon({
          iconUrl: elementSetting.crossHair.iconUrl,
          iconSize: elementSetting.crossHair.iconSize,
          iconAnchor: elementSetting.crossHair.iconAnchor
        });

        var lMap = leafletMap.lMap;
        var crossHair = new L.marker(lMap.getCenter(), {
          icon: crosshairIcon,
          clickable: false
        });
        crossHair.addTo(lMap);

        // Subscribe to the leaflet move event to always center the marker
        // and update the hidden lat/lon fields.
        lMap.on('move', function (map, crossHair, elementSetting) {
          return function (e) {
            var center = map.getCenter();
            crossHair.setLatLng(center);
            $('#' + elementSetting.formKey + '-lat').val(center.lat);
            $('#' + elementSetting.formKey + '-lon').val(center.lng);
            $('#' + elementSetting.formKey + '-zoom').val(map.getZoom());
          };
        }(lMap, crossHair, elementSetting));

        var $button = $('#' + elementSetting.buttonId);

        // Setup a DOM observer to check for 'class' changes on the webform
        // component. Assume the change means a hide/show event and invalidate
        // maps size. This fixes partially tiled maps on Android.
        if (typeof MutationObserver === 'function') {
          var observer = new MutationObserver(function (map) {
            return function (mutations) {
              map.invalidateSize(false);
            };
          } (lMap));

          var observerConfig = {
            childList: false,
            attributes: true,
            characterData: false,
            subtree: false,
            attributeOldValue: false,
            characterDataOldValue: false,
            attributeFilter: ['class']
          };

          var $webformComponent = $button.closest('.webform-component-gpslocation');
          observer.observe($webformComponent[0], observerConfig);
        }

        if (geoLocation) {
          $button.click(function (leafletMap, setting) {
            return function (e) {
              var $target = $(e.target);

              // Use the 'waiting' class as a semaphore.
              if ($target.hasClass('waiting')) {
                return;
              }

              $target.addClass('waiting');

              // Add throbber and message after removing old messages.
              $target.siblings('.location-status').remove();
              $target.after('<div class="location-status"><div class="throbber">&nbsp;</div><div class="message message-busy">' + Drupal.t('Retrieving your current location.') + '</div></div>');

              // TODO: for Firefox consider setting a timeout to remove throbber
              // and message when the permission dialog is ignored or when the
              // close button or the option "Not now" are used.
              // See https://bugzilla.mozilla.org/show_bug.cgi?id=675533 .
              // Obtain the current position.
              if ("geolocation" in navigator) {
                // Kick off navigation request.
                navigator.geolocation.getCurrentPosition(
                  function (position) {
                    // Remove messages and semaphore.
                    $target.siblings('.location-status').remove();
                    $target.removeClass('waiting');

                    // Update center. This updates the crossHair marker and
                    // hidden lat/lon fields via a move event.
                    leafletMap.lMap.setView(L.latLng(position.coords.latitude, position.coords.longitude), setting.zoomOnLocation);
                  },
                  function (error) {
                    // Replace throbber and retrieving message with an error.
                    $target.removeClass('waiting');
                    $target.siblings('.location-status').remove();
                    $target.after('<div class="location-status"><div class="message message-error">' + Drupal.t('Your location could not be determined. Indicate the location on the map.') + '</div></div>');
                  },
                  {
                    enableHighAccuracy: true,
                    maximumAge: 30000,
                    timeout: 27000
                  }
                );
              }

              return e.preventDefault();
            };
          } (leafletMap, elementSetting));
        }
        else {
          // Hide the use current location button when geolocation is not
          // possible.
          $button.hide();
        }
      }
    }
  };
}(jQuery));
