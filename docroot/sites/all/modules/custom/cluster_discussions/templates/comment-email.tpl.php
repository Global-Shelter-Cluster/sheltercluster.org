<div style="
  font-family: sans-serif;
  width: 800px;
  max-width: 100%;
">
  <?php require __DIR__.'/../../cluster_email/templates/notification-header.tpl.php'; ?>

  <p style="margin-top: 20px;">
    <?php print t('A comment has been added to a discussion on <a href="@group_url">@group</a>. You can reply directly to this email to add a new comment, or '.
      '<a href="@url">click here</a> to see it and reply on the Shelter Cluster website.'.
      '<br>You can also create a new discussion on the group by sending an email to <a href="mailto:@email">@email</a>.', [
      '@group' => $group->title,
      '@group_url' => url('node/'.$group->nid, ['absolute' => TRUE]),
      '@url' => url('node/'.$node->nid, ['absolute' => TRUE, 'fragment' => 'comment-'.$comment->cid]),
      '@email' => cluster_email_inbound_address('discussion-'.$group->nid),
    ]); ?>

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
