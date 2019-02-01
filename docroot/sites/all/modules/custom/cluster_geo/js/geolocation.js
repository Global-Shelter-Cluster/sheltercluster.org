(function ($) {
  Drupal.behaviors.cluster_geo = {

    coordinates: {
      lat: undefined,
      lon: undefined,
    },

    attach: function (context, settings) {
      navigator.geolocation.getCurrentPosition(this.setCoordinatesFromNavigator.bind(this));
      const cluster_geo = this;
      $("#modal_opener").click(function() {
        cluster_geo.showMap();
      });
    },

    setCoordinatesFromNavigator: function(position) {
      this.setCoordinates(position.coords.latitude, position.coords.longitude);
    },

    setCoordinates: function (lat, lon) {
      this.coordinates.lat = lat;
      this.coordinates.lon = lon;
      this.updateDisplay();
    },

    updateDisplay: function() {
      $("#edit-submitted-test-lon").val(this.coordinates.lat);
      $("#edit-submitted-test-lat").val(this.coordinates.lon);
    },

    showMap: function() {
      const cluster_geo = this;
      var map = L.map('map').setView([cluster_geo.coordinates.lat, cluster_geo.coordinates.lon], 13);
      L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      }).addTo(map);
      map.on('click', function(e) {
        cluster_geo.setCoordinates(e.latlng.lat, e.latlng.lng);
      });
    }
  };
}(jQuery));
