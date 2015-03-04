<h3 data-collapsible="coordination-items"><?php print t('Coordination Team Member'); ?></h3>
<div id="coordination-items">
  <ul class="clearfix">
    <?php foreach($contacts as $nid => $contact): ?>
      <li class="coordination-item">
        <div class="avatar">
          <?php if (TRUE): ?>
            <?php print render($contact['field_image']); ?>
          <?php endif; ?>
        </div>
        <div class="information">
          <?php print render($contact['title_field']); ?>
          <?php print render($contact['field_role_or_title']); ?>
          <?php print render($contact['field_organisation_name']); ?>
          <?php print render($contact['field_phone_number']); ?>
          <?php print render($contact['field_email']); ?>
        </div>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
