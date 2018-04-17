(function ($) {
  Drupal.behaviors.humanitarianIdSearchUsers = {
    attach: function (context) {
      $("input#edit-name", context).bind('autocompleteSelect', function(event, node) {
        let id = $(this).val();
        $(this).val('');
        $.get("/hid-ajax-get-user-by-id/" + id, function(data) {
          $("#edit-user-data").hide().html(data).fadeIn(250);;
        });
      });

      $(document).on('click', 'a.create-new-hid-user', function(e, selector) {
        let id = $(this).attr('data-humid');
        $('a.create-new-hid-user').html('Now creating user...');
        e.preventDefault();
        $.get("/create-new-user-from-hid-id/" + id, function(data) {
          $.get("/hid-ajax-get-user-by-id/" + id, function(data) {
            $("#edit-user-data").hide().html(data).fadeIn(250);
          });
        });
      });

      $(document).on('click', 'a.update-hid-user', function(e, selector) {
        let id = $(this).attr('data-humid');
        $('a.update-hid-user').html('Now updating user...');
        e.preventDefault();
        $.get("/update-user-from-hid-id/" + id, function(data) {
          $.get("/hid-ajax-get-user-by-id/" + id, function(data) {
            $("#edit-user-data").hide().html(data).fadeIn(250);
          });
        });
      });

    }

  };
})(jQuery);
