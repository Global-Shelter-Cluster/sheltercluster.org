(function ($) {
  Drupal.behaviors.clusterPhotoGallery = {
    attach: function (context, settings) {
      $('.field-name-field-photos > .field-items').once('clusterPhotoGallery', function () {
        $(this).magnificPopup({
          type: 'image',
          delegate: 'a',
          callbacks: {
            elementParse: function (item) {
              item.src = item.el.parent('.photo_gallery_image').attr('data-url-full');
            }
          },
          closeOnContentClick: true,
          closeBtnInside: false,
          gallery: {enabled: true},
          image: {
            titleSrc: function (item) {
              var container = item.el.closest('.content');
              var caption = container.find('.field-name-field-caption').text().trim();

              var details = $('<small/>');
              var detailsContainsSomething = false;

              var author = container.find('.field-name-field-author').text().trim();
              if (author) {
                details.append($('<span/>').text(author));
                detailsContainsSomething = true;
              }

              var taken = container.find('.field-name-field-taken').text().trim();
              if (taken) {
                if (detailsContainsSomething)
                  details.append($('<span/>').html(' &middot; '));
                details.append($('<span/>').text(taken));
                detailsContainsSomething = true;
              }

              if (detailsContainsSomething)
                details.append($('<span/>').html(' &middot; '));
              details.append($('<a/>', {href: item.el.get(0).href, target: '_blank'}).text('original'));

              var ret = $('<div/>');
              if (caption) {
                ret.append($('<em/>').text(caption));
              }
              ret.append(details);

              return ret;
            }
          },
          mainClass: 'mfp-with-zoom',
          zoom: {
            enabled: true,
            duration: 300,
            easing: 'ease-in-out',
            opener: function (openerElement) {
              return openerElement.is('img') ? openerElement : openerElement.find('img');
            }
          }
        });
      });
    }
  }
})(jQuery);
