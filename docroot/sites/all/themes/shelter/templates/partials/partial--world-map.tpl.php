<script type="text/javascript"
  src="https://maps.googleapis.com/maps/api/js?key=AIzaSyBlUATUG3UJqcpXIrzBkKvVKxN8-1IwfKM">
</script>
<script type="text/javascript">
  function initialize() {
    var mapOptions = {
      center: { lat: 20, lng: 30},
      zoom: 2,
      scrollwheel: false,
      zoomControl: false,
      panControl: false,
      addressControl: false,
      streetViewControl: false
    };
    var map = new google.maps.Map(document.getElementById('map-canvas'),
        mapOptions);
  }
  google.maps.event.addDomListener(window, 'load', initialize);
</script>
<section id="map">
  <div id="map-canvas"></div>
  <div id="regions-overlay">
    <div class="background"></div>
    <?php print render($page['footer']['menu_regions']); ?>
  </div>
</section>