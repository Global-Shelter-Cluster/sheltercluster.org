<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php include 'notification-header.tpl.php'; ?>

  <p style="margin-top: 20px;">
    <?php print t('Here is this week\'s activity for %title:', ['%title' => $group->title]); ?>
  </p>

  <?php include 'notification-common.tpl.php'; ?>

  <?php include 'notification-footer.tpl.php'; ?>
</div>
