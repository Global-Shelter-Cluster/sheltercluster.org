<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php require __DIR__.'/../../cluster_email/templates/notification-header.tpl.php'; ?>

  <p style="
    width: 70%;
    min-width: 300px;
    margin: 30px auto 0;
    font-size: 11px;
    line-height: 1.5;
    color: #575757;
  ">
    <?php print t('A new discussion has been created on <a href="@group_url">@group</a>. '.
      'If you would like to add a comment, you will need to <a href="@signup_url">create an account on the Shelter Cluster website</a>.', [
      '@group' => $group->title,
      '@group_url' => url('node/'.$group->nid, ['absolute' => TRUE]),
      '@signup_url' => url('user/register', ['absolute' => TRUE]),
    ]); ?>
  </p>

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
    <?php print check_plain($node->name) ?>
    &middot;
    <?php print format_date($date, 'custom', 'l, j F, Y', NULL, $langcode); ?>
  </small>

  <?php print $body; ?>

  <?php include __DIR__.'/../../cluster_email/templates/notification-footer-anon.tpl.php'; ?>
</div>
