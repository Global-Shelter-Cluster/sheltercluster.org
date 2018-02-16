(function ($) {
  Drupal.behaviors.autocompleteSupervisor = {
    attach: function (context) {
      $("input#edit-name", context).bind('autocompleteSelect', function(event, node) {
        let id = $(this).val();
        $.get("/hid-ajax-get-user-by-id/" + id, function(data) {
          console.log(data);
          $("#edit-user-data").html(data);
        });
      });
    }
  };
})(jQuery);