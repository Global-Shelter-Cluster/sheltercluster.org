(function ($) {
  Drupal.behaviors.classifierAutotag = {
    loadFromDOM: function () {
      var element = $('#autotag-results');
      var data_element = $('#edit-field-document-type-autotag');
      element.find('*').remove();

      var tids_by_field = data_element.data('tids');
      var values_shown = false;

      var ul = $('<ul/>');

      for (var field in tids_by_field) {
        for (var i in tids_by_field[field]) {
          var tid = tids_by_field[field][i];
          var checkbox_name = field + '[und][' + tid + ']';
          var checkbox = $('input[type=checkbox][name="' + checkbox_name + '"]');
          if (checkbox.length && !checkbox.is(':checked')) {
            values_shown = true;
            var li = $('<li/>').text(checkbox.next('label').text());
            li.data('checkbox', checkbox);
            li.attr('data-tid', tid);
            li.click(function () {
              var has_siblings = $(this).siblings('li').length;
              $(this).data('checkbox').click();
              if (has_siblings)
                $(this).remove();
              else
                $('#autotag-results').find('*').remove();
              Drupal.behaviors.classifierAutotag.fetch();
            });
            ul.append(li);
          }
        }
      }

      if (values_shown) {
        element.append($('<span/>').text(Drupal.t("Suggested") + ":"));
        element.append(ul);
      }
    },
    fetch: function() {
      jQuery('#edit-field-document-type-autotag').mousedown(); // Trigger "fetch autotags" button (Drupal AJAX functionality)
    },
    search: function(event) {
      if (event && event.keyCode === 27) {
        $('#edit-field-document-type-tag-search').val('');
      }

      var query = $('#edit-field-document-type-tag-search').val().trim().toLowerCase();
      var results = $('#autotag-search-results');
      results.find('*').remove();

      if (!query) {
        results.removeClass('has-results');
        return;
      }

      results.addClass('has-results');
      var ul = $('<ul/>');

      $('#document-node-form .form-type-checkboxes .form-type-checkbox label')
        .filter(function() {
          var checkbox = $(this).prev('input:checkbox');
          if (checkbox.is(':checked'))
            return false;
          var match = checkbox.attr('name').match(/^[^\[]+\[und\]\[(\d+)\]$/);
          if (!match)
            return false;

          if ($(this).text().toLowerCase().indexOf(query) !== -1)
            return true;

          var tooltip = $(this).closest('.cluster-tag-tooltip');
          if (tooltip.length > 0 && tooltip.attr('title').toLowerCase().indexOf(query) !== -1)
            return true;

          return false;
        })
        .slice(0, 3)
        .map(function() {
          var checkbox = $(this).prev('input:checkbox');
          var match = checkbox.attr('name').match(/^[^\[]+\[und\]\[(\d+)\]$/);
          var tid = match[1];

          var li = $('<li/>').text($(this).text());
          li.data('checkbox', checkbox);
          li.attr('data-tid', tid);
          li.click(function () {
            $(this).data('checkbox').click();
            $('#edit-field-document-type-tag-search').val('').keyup();
          });
          ul.append(li);
        });

      if (ul.html()) {
        results.append($('<span/>').text(Drupal.t("Search results") + ":"));
        results.append(ul);
      } else {
        results.append($('<span/>').text(Drupal.t("No results")));
      }
    },
    attach: function (context, settings) {
      $('#edit-field-document-type-autotag').once('classifierAutotag').each(function () {
        // The "change" handler is triggered by the AJAX call (see cluster_classifier_autotag() in cluster_classifier.module).
        $(this).change(Drupal.behaviors.classifierAutotag.loadFromDOM);

        // When a tag is checked manually, if it's one of the "suggested" ones, remove it and re-calculate that list.
        $('#document-node-form .form-type-checkboxes .form-type-checkbox input').change(function() {
          if (!$(this).is(':checked'))
            return;
          var match = $(this).attr('name').match(/^[^\[]+\[und\]\[(\d+)\]$/);
          if (!match)
            return;

          var tid = match[1];

          var li = $('#autotag-results li[data-tid=' + tid + ']');
          if (li.length > 0) {
            var has_siblings = li.siblings('li').length;
            li.remove();
            if (!has_siblings)
              $('#autotag-results *').remove();
            Drupal.behaviors.classifierAutotag.fetch();
          }

          var li = $('#autotag-search-results li[data-tid=' + tid + ']');
          if (li.length > 0) {
            var has_siblings = li.siblings('li').length;
            li.remove();
            if (!has_siblings)
              $('#autotag-search-results *').remove();
            Drupal.behaviors.classifierAutotag.search();
          }
        });

        // When the title or body change, load tag suggestions.
        //TODO: make wysiwyg changes trigger this
        $('#edit-title-field-und-0-value, #edit-body-und-0-value').change(Drupal.behaviors.classifierAutotag.fetch);

        // Trigger the classifier automatically when the page loads.
        Drupal.behaviors.classifierAutotag.fetch();
      });

      $('#edit-field-document-type-tag-search').once('classifierAutotag').each(function() {
        $(this).keyup(Drupal.behaviors.classifierAutotag.search);
        Drupal.behaviors.classifierAutotag.search();
      });
    }
  }
})
(jQuery);
