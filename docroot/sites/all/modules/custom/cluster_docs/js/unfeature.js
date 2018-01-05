(function ($) {

  Drupal.behaviors.cluster_docs_unfeature = {
    attach: function (context, settings) {
      var $wrapper = $(".field-name-field-featured-date.form-wrapper", context);
      var $select = $('.unfeatured-select', $wrapper);
      $select.parent().css('padding-right', '12px');
      $select.change(function(e) {
        var date = $select.find(":selected").val();
        $select.parents('fieldset.form-wrapper')
          .find('.date-date .date-clear')
          .val(date);
      });

      var $featured = $('#edit-field-featured-und');
      var showHide = function() {
        if ($featured.is(':checked')) {
          $wrapper.show();
        }
        else {
          $wrapper.hide();
        }
      }

      $featured.on('change', function() {
        showHide();
      });
      showHide();
      
    }
  }
})(jQuery);
