(function ($) {
  Drupal.behaviors.cluster_geo = {
    attach: function (context, settings) {
      navigator.geolocation.getCurrentPosition(this.populateWebformFields);
      this.showMap();
    },

    populateWebformFields: function(position) {
      $("#edit-submitted-test-lon").val(position.coords.longitude);
      $("#edit-submitted-test-lat").val(position.coords.latitude);
      // console.log(position);
    },

    showMap: function() {
      var map = L.map('map').setView([51.505, -0.09], 13);
      L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
        attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
      }).addTo(map);
      map.on('click', function(e) {
        alert(e.latlng);
      });
    }
  };
}(jQuery));
