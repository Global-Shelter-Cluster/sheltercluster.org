(function ($) {
  Drupal.behaviors.cluster_geo = {

    coordinates: {
      lat: undefined,
      lon: undefined,
    },

    mapContainerIsInitialized: false,

    map: undefined,

    attach: function (context, settings) {
      navigator.geolocation.getCurrentPosition(this.setCoordinatesFromNavigator.bind(this));
      const cluster_geo = this;
      $("#modal_opener").click(function() {
        cluster_geo.showMap();
      });
    },

    setCoordinatesFromNavigator: function(position) {
      this.setCoordinates(position.coords.latitude, position.coords.longitude);
      //this.showMap();
    },

    setCoordinates: function (lat, lon) {
      this.coordinates.lat = lat;
      this.coordinates.lon = lon;
      this.updateDisplay();
    },

    updateDisplay: function() {
      $("#webform-cluster_geo-latitude").val(this.coordinates.lat);
      $("#webform-cluster_geo-longitude").val(this.coordinates.lon);
    },

    coordinatesAreDefined: function() {
      return (this.coordinates.lat != undefined && this.coordinates.lon != undefined);
    },

    initializeMapContainer: function() {
      const cluster_geo = this;
      this.map = L.map('map');
      this.mapContainerIsInitialized = true;
      L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      }).addTo(this.map);
      this.map.on('click', function(e) {
        cluster_geo.setCoordinates(e.latlng.lat, e.latlng.lng);
      });
    },

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
