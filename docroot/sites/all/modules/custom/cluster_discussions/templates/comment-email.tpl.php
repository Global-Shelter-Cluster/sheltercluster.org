<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php require __DIR__.'/../../cluster_email/templates/notification-header.tpl.php'; ?>

  <p style="margin-top: 20px;">
    <?php print t('A comment has been added to a discussion on @group. You can reply directly to this email or click on the title to see it and reply on the Shelter Cluster website:', [
      '@group' => $group->title,
    ]); ?>
  </p>

  <h1 style="
    margin: 20px 0 0;
  ">
    <?php print l('Re: '.$node->title, 'node/'.$node->nid, ['absolute' => TRUE, 'attributes' => [
      'style' => 'color: #7f1416; text-decoration: none;'
    ],
    'fragment' => 'comment-'.$comment->cid]); ?>
  </h1>
  <small style="
    display: block;
    color: #575757;
    margin-bottom: 40px;
  ">
    <?php print format_date($date, 'custom', 'l, j F, Y', NULL, $langcode); ?>
  </small>

  <?php print $body; ?>

  <?php include __DIR__.'/../../cluster_email/templates/notification-footer.tpl.php'; ?>
</div>
