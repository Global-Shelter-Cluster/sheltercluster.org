<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php require __DIR__.'/../../cluster_email/templates/notification-header.tpl.php'; ?>

  <p style="margin-top: 20px;">
    <?php print t('Click on the following link to confirm your subscription to @group:', [
      '@group' => $group_name,
    ]); ?>
  </p>

  <p style="margin-top: 20px;">
    <?php print l(url($confirm_path, ['absolute' => TRUE]), $confirm_path, [
      'absolute' => TRUE,
      'attributes' => [
        'style' => 'color: #7f1416; text-decoration: none;'
      ]
    ]); ?>
  </p>

</div>
