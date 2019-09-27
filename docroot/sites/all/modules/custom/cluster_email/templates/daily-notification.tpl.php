<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php include 'notification-header.tpl.php'; ?>

  <p style="margin-top: 20px;">
    <?php print t('Here\'s the latest activity for <a href="@link">@title</a>:', [
      '@title' => $group->title,
      '@link' => url('node/'.$group->nid, ['absolute' => TRUE]),
    ], ['langcode' => $langcode]); ?>
  </p>

  <?php include 'notification-common.tpl.php'; ?>

  <?php include 'notification-footer.tpl.php'; ?>
</div>
