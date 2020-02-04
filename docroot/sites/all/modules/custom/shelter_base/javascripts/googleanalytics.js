(function ($) {

  /**
   * @param {Object} e
   * @param {string} e.category
   * @param {string} e.action
   * @param {string} [e.label]
   * @param {number} [e.value]
   */
  window.hitEvent = function(e) {
    if (!Drupal.googleanalytics)
      return;
    ga('send', 'event', e.category, e.action, e.label, e.value);
  };

  $(document).ready(function () {
    $('body.node-type-document .doc-download a').bind('click', function (event) {
      const node = $(this).closest('.node-document');
      const nid = node.attr('id').replace(/[^0-9]/g,'');
      const title = node.find('.doc-title .doc-attr-value').text();

      window.hitEvent({category: 'document', action: 'view', label: nid + ': ' + title});
    });

    $('body.node-type-event a.map-link').bind('click', function (event) {
      const node = $(this).closest('.content').find('.node-event');
      const nid = node.attr('id').replace(/[^0-9]/g,'');
      const title = node.find('h2').clone().children().remove().end().text();

      window.hitEvent({category: 'event', action: 'map', label: nid + ': ' + title});
    });

    $('.side-column a.follow').bind('click', function (event) {
      if (!Drupal.settings.cluster_nav)
        return;
      const nid = Drupal.settings.cluster_nav.group_nid;
      const title = Drupal.settings.cluster_nav.group_title;

      window.hitEvent({category: 'group', action: 'follow', label: nid + ': ' + title});
    });

    $('.side-column a.un-follow').bind('click', function (event) {
      if (!Drupal.settings.cluster_nav)
        return;
      const nid = Drupal.settings.cluster_nav.group_nid;
      const title = Drupal.settings.cluster_nav.group_title;

      window.hitEvent({category: 'group', action: 'unfollow', label: nid + ': ' + title});
    });

    $('body.node-type-webform input.webform-submit').bind('click', function (event) {
      const node = $(this).closest('.node-webform');
      const nid = node.attr('id').replace(/[^0-9]/g,'');
      const title = node.find('span[property="dc:title"]').attr('content');

      window.hitEvent({category: 'webform', action: 'submit', label: nid + ': ' + title});
    });

  });

})(jQuery);
