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
    <?php
    if ($is_moderate)
      print t('A new discussion needs moderation on <a href="@group_url">@group</a>.', [
        '@group' => $group->title,
        '@group_url' => url('node/'.$group->nid.'/moderate', ['absolute' => TRUE]),
      ]);
    else
      print t('A new discussion has been created on <a href="@group_url">@group</a>. You can reply directly to this email to add a comment, or '.
        '<a href="@url">click here</a> to see it and reply on the Shelter Cluster website.'.
        '<br>You can also create a new discussion on the group by sending an email to <a href="mailto:@email">@email</a>.', [
        '@group' => $group->title,
        '@group_url' => url('node/'.$group->nid, ['absolute' => TRUE]),
        '@url' => url('node/'.$node->nid, ['absolute' => TRUE]),
        '@email' => cluster_email_inbound_address('discussion-'.$group->field_email_address_identifier['und'][0]['value']),
      ]);
    ?>
  </p>

  <?php if ($is_moderate) print '<div style="background-color: #ffdddd; padding: 0 10px 1px;">'; ?>

  <h1 style="
    margin: 20px 0 0;
  ">
    <?php print l($node->title, $is_moderate ? 'node/'.$group->nid.'/moderate' : 'node/'.$node->nid, ['absolute' => TRUE, 'attributes' => [
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

  <?php if ($is_moderate) print '</div>'; ?>

  <?php include __DIR__.'/../../cluster_email/templates/notification-footer.tpl.php'; ?>
</div>
