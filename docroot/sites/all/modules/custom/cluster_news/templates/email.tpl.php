<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php require __DIR__.'/../../cluster_email/templates/notification-header.tpl.php'; ?>

  <h1 style="
    margin: 20px 0 0;
  ">
    <?php print l($node->title, 'node/'.$node->nid, ['absolute' => TRUE, 'attributes' => [
      'style' => 'color: #7f1416; text-decoration: none;'
    ]]); ?>
  </h1>
  <small style="
    display: block;
    color: #575757;
    margin-bottom: 40px;
  ">
    <?php print format_date($date, 'custom', 'l, j F, Y', NULL, $langcode); ?>
  </small>

  <?php include __DIR__.'/../../cluster_paragraphs/templates/email.tpl.php'; ?>

  <?php isset($is_anon) && $is_anon
    ? include __DIR__.'/../../cluster_email/templates/notification-footer-anon.tpl.php'
    : include __DIR__.'/../../cluster_email/templates/notification-footer.tpl.php';
  ?>
</div>
