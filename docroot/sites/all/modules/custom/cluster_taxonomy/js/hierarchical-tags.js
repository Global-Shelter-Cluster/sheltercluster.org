(function ($) {
  Drupal.behaviors.hierarchicalTags = {
    attach: function (context, settings) {
      $('.field-type-taxonomy-term-reference[data-parent-field]').once('hierarchicalTags').each(function () {
        var html_name = $(this).attr('data-parent-field') + '[und][' + $(this).attr('data-parent-tid') + ']';
        var parent = $('.form-type-checkbox input:checkbox[name="' + html_name + '"]');
        var tags = $(this).find('.form-type-checkbox input:checkbox');

        // For any of the tags from this field, select the parent if selected
        tags.change(function () {
          if (!$(this).is(':checked'))
            return; // Only when selecting a tag

          parent.filter(':not(:checked)').click();
        });

        // Deselect all the tags from this field when the parent is deselected
        parent.change(function() {
          if ($(this).is(':checked'))
            return; // Only when deselecting the tag
          // debugger;

          tags.filter(':checked').click();
        });

      });
      $('.form-type-checkbox input:checkbox:checked').change();
    }
  }
})(jQuery);
