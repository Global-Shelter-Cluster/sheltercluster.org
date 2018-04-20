(function ($) {
  Drupal.behaviors.autocompleteSupervisor = {
    attach: function (context) {
      $("input#edit-name", context).bind('autocompleteSelect', function(event, node) {
        let id = $(this).val();
        $(this).val('');
        $.get("/hid-ajax-get-user-by-id/" + id, function(data) {
          $("#edit-user-data").html(data);
        });
      });

      $(document).on('click', 'a.create-new-hid-user', function(e, selector) {
        let id = $(this).attr('data-humid');
        $('a.create-new-hid-user').html('Now creating user...');
        e.preventDefault();
        $.get("/create-new-user-from-hid-id/" + id, function(data) {
          $('a.create-new-hid-user').html('User id: ' + data)
            .attr('href', '/user/' + data)
            .removeClass('create-new-hid-user');
        });
      });
    }

  };
})(jQuery);
