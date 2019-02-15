(function ($) {
  Drupal.behaviors.cluster_geo = {

    shelterMap: function(fieldset) {

      this.wrapper = $(fieldset).parents('.form-item');

      this.marker = null;

      this.coordinates = {
        lat: $(".webform-cluster_geo-latitude", this.wrapper).val() || undefined,
        lon: $(".webform-cluster_geo-longitude", this.wrapper).val() || undefined,
      };

      this.mapContainerIsInitialized = false;

      this.map = null;

      this.showMap = function() {
        let map_coordinates = [51.4826, 0.0077];
        if (this.coordinatesAreDefined()) {
          map_coordinates = [this.coordinates.lat, this.coordinates.lon];
        }
        if (!this.mapContainerIsInitialized) {
          this.initializeMapContainer();
        }
        // Init with zoom 13.
        this.map.setView(map_coordinates, 13);
      };

      this.setCoordinatesFromNavigator = function(position) {
        this.wrapper.find(".throbber").removeClass("throbber");
        this.setCoordinates(position.coords.latitude, position.coords.longitude, 13);
      };

      // Valid longitudes are from -180 to 180 degrees.
      // Valid latitudes are from -85.05112878 to 85.05112878 degrees.
      this.setCoordinates = function (lat, lon, zoom = null) {
        if (lon < -180) {
          lon = -180;
        }
        else if (lon > 180) {
          lon = 180;
        }

        if (lat < -85.05112878) {
          lat = -85.05112878;
        }
        else if (lat > 85.05112878) {
          lat = 85.05112878;
        }

        this.coordinates.lat = lat;
        this.coordinates.lon = lon;
        if (this.coordinatesAreDefined()) {
          this.updateDisplay();
          this.updateMarker();
          this.setMapCoordinates([lat, lon], zoom);
        }
      };

      this.updateDisplay = function() {
        $(".webform-cluster_geo-latitude", this.wrapper).val(this.coordinates.lat);
        $(".webform-cluster_geo-longitude", this.wrapper).val(this.coordinates.lon);
      };

      this.updateMarker = function() {
        if (this.coordinatesAreDefined()) {
          if (this.marker) {
            this.marker.setLatLng([this.coordinates.lat, this.coordinates.lon]);
          }
          else {
            this.marker = L.marker([this.coordinates.lat, this.coordinates.lon]).addTo(this.map);
          }
        }
      };

      this.coordinatesAreDefined = function() {
        return !isNaN(this.coordinates.lat) && !isNaN(this.coordinates.lon);
      };

      this.initializeMapContainer = function() {
        const cluster_geo = this;

        const id = $('.geolocation-map-container', this.wrapper).attr('id');
        this.map = L.map(id);
        this.mapContainerIsInitialized = true;

        L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
          attribution: '&copy; <a href="https://www.openstreetmap.org/copyright">OpenStreetMap</a> contributors'
        }).addTo(this.map);

        this.updateMarker();

        this.map.on('click', function(e) {
          cluster_geo.setCoordinates(e.latlng.lat, e.latlng.lng);
        });

        this.map.addControl(new this.centerOnMyPositionControl());

        var typeTimeout = null;
        $(".webform-cluster_geo-latitude, .webform-cluster_geo-longitude", this.wrapper).on('keyup', function() {
          if (typeTimeout != null) {
            clearTimeout(typeTimeout);
          }
          let wrapper = this.wrapper;

          typeTimeout = setTimeout(function() {
            let lat = $(".webform-cluster_geo-latitude", this.wrapper).val() || undefined;
            let lon = $(".webform-cluster_geo-longitude", this.wrapper).val() || undefined;
            if (!isNaN(lat) && !isNaN(lon)) {
              cluster_geo.setCoordinates(lat, lon, 13);
            }
          }, 500);
        })
        .on('keypress', function(e) {
          // Prevent submission on enter at these fields.
          return e.keyCode != 13;
        });
      };

      this.setMapCoordinates = function(map_coordinates, zoom = null) {
        if (zoom) {
          this.map.setView(map_coordinates, zoom);
        }
        else {
          this.map.flyTo(map_coordinates);
        }
      };

      var _this = this;
      this.centerOnMyPositionControl = L.Control.extend({
        options: {
          position: 'topleft'
        },

        onAdd: function (map) {
          var container = L.DomUtil.create('div', 'leaflet-bar leaflet-control leaflet-control-custom');

          container.style.backgroundColor = 'white';
          container.style.backgroundImage = "url('data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABIAAAASCAYAAABWzo5XAAAABmJLR0QA/wD/AP+gvaeTAAAACXBIWXMAAC4jAAAuIwF4pT92AAAAB3RJTUUH4wIMDBEFRrsBrwAAABl0RVh0Q29tbWVudABDcmVhdGVkIHdpdGggR0lNUFeBDhcAAAHcSURBVDjLvVMxTBRBFH1vZyZUQHFGY0EiBVFqK7kacnuXuYrESAyxoTEUNnTGwlhoZ2WlCSEBpby9gMf1h5WhoMCrLCgMS66SYo/x77fZEFSOM8bwy/fevD/z/nzgqsp7v+q9Xx2mi/5XQ14Elsvl0VKp9ERVHwC4U8BfSL7v9XqvO53O96FGlUrltnPuI4AbJNdUdRcASM6o6iKAoxBC3Gq1ugOfFsfxmHNuh+QJgOkkSZZFZF9E9pMkWQYwTfLEObcTx/HYQCPn3ArJUgihKiLj3vsDa+2etXbPe38gIuMhhCqAa865lcvCfgjgXZqmR8aYBsmpswzIKWNMI03TI5JvC+2vGXnvV0kSwKKq3lfVwyiKdi8aRJ7nMyQnSG4CWFNVbTabj85upKosOv9QVTtozAUn58/8MbV6vX6Y5/mGiDxzzn0FcPM3n28hhEljzPMoihaSJJm4MCNV/UByyVo7KiLzANJzdCoi89baUZJLqrp5WdivAJySbGRZ1j0+Pr4lIrMiMquqk1mWdUk2AJwCeHnph6zVaneNMdsAjKq+AfCpoO6RfAxARKS6tbX1eeiKzM3NXR8ZGXlKcgFAqYB7qrrR7/dftNvt9F+2f917vz5MZ//CK+Aq6yfOHs1316J96gAAAABJRU5ErkJggg==')";
          container.style.backgroundSize = "18px 18px";
          container.style.backgroundRepeat = "no-repeat";
          container.style.backgroundPosition = "center";
          container.style.width = "34px";
          container.style.height = "34px";
          container.style.cursor = "pointer";

          container.onclick = function(e) {
            e.stopPropagation();
            $("input", _this.wrapper).addClass("throbber");
            navigator.geolocation.getCurrentPosition(_this.setCoordinatesFromNavigator.bind(_this));
          };

          return container;
        }
      });

    },

    // Hold the shelterMap objects.
    shelterMaps: {},

    attach: function (context, settings) {
      const _this = this;
      let id = 0;
      $(".geolocation-coordinates").once('leaflet-init').each(function() {
        const wrapper = $(this).parent();
        wrapper.data('id', id);
        _this.shelterMaps[id] = new _this.shelterMap($(this));

        let useModal = $(this).data('use-modal');
        let useCurrentCoordinates = $(this).data('current-coordinates');

        _this.shelterMaps[id].showMap();
        if (useModal) {
          $(".modal_opener, .close_modal, .overlay", wrapper).click(function() {
            $(".geolocation-map-modal", wrapper).toggle();
            _this.shelterMaps[wrapper.data('id')].map.invalidateSize();
          });
        }
        if (useCurrentCoordinates) {
          $("input", wrapper).addClass("throbber");
          navigator.geolocation.getCurrentPosition(_this.shelterMaps[id].setCoordinatesFromNavigator.bind(_this.shelterMaps[id]));
        }
        id++;
      });

    },

  };
}(jQuery));
