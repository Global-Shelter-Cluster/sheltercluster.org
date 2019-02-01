(function ($) {
  Drupal.behaviors.cluster_geo = {

    coordinates: {
      lat: undefined,
      lon: undefined,
    },

    mapContainerIsInitialized: false,

    // @TODO make a hasmap of maps to support multiple instances of the component on the form.
    map: undefined,

    attach: function (context, settings) {
      const wrapper = $(".geolocation-coordinates");
      let useModal = wrapper.attr('data-use-modal') === 'true';
      let useCurrentCoordinates = wrapper.attr('data-current-coordinates') === 'true';

      if (useCurrentCoordinates) {
        navigator.geolocation.getCurrentPosition(this.setCoordinatesFromNavigator.bind(this));
      }

      if (useModal) {
        $("#modal_opener, .close_modal, .overlay").click(() => {
          $(".geolocation-map-modal").toggle();
          this.showMap();
        });
      }
      else {
        this.showMap();
      }
    },

    setCoordinatesFromNavigator: function(position) {
      this.setCoordinates(position.coords.latitude, position.coords.longitude);
    },

    setCoordinates: function (lat, lon) {
      this.coordinates.lat = lat;
      this.coordinates.lon = lon;
      this.updateDisplay();
      this.setMapCoordinates([lat, lon]);
    },

    // @TODO make a "two-way binging" so that changing the coordinates in the input updates the map
    // Validate realistic planetary ranges for lat and lon
    updateDisplay: function() {
      $("#webform-cluster_geo-latitude").val(this.coordinates.lat);
      $("#webform-cluster_geo-longitude").val(this.coordinates.lon);
    },

    coordinatesAreDefined: function() {
      return (this.coordinates.lat != undefined && this.coordinates.lon != undefined);
    },

    // @TODO wrap this in a promise
    initializeMapContainer: function() {
      const cluster_geo = this;
      this.map = L.map('geolocation-map');
      this.mapContainerIsInitialized = true;

      L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      }).addTo(this.map);

      this.map.on('click', function(e) {
        cluster_geo.setCoordinates(e.latlng.lat, e.latlng.lng);
      });
    },

    // @TODO add a marker on the Map when setting coordinates
    setMapCoordinates: function(map_coordinates) {
      this.map.setView(map_coordinates, 13);
    },

    showMap: function() {
      let map_coordinates = [51.4826, 0.0077];
      if (this.coordinatesAreDefined()) {
        map_coordinates = [this.coordinates.lat, this.coordinates.lon];
      }
      if (!this.mapContainerIsInitialized) {
        this.initializeMapContainer();
      }
      this.setMapCoordinates(map_coordinates);
    }
  };
}(jQuery));
