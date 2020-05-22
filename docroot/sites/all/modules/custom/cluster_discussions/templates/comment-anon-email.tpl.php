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
    <?php print t('A comment has been added to a discussion on <a href="@group_url">@group</a>. '.
      'If you would like to add another comment, you will need to <a href="@signup_url">create an account on the Shelter Cluster website</a>.', [
      '@group' => $group->title,
      '@group_url' => url('node/'.$group->nid, ['absolute' => TRUE]),
      '@signup_url' => url('user/register', ['absolute' => TRUE]),
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
    <?php print check_plain($comment->registered_name) ?>
    &middot;
    <?php print format_date($date, 'custom', 'l, j F, Y', NULL, $langcode); ?>
  </small>

  <?php print $body; ?>

  <?php if ($previous): ?>
    <div style="margin: 40px 0 0 30px">
      <?php foreach ($previous as $previous_item): ?>

        <div style="
          font-size: 90%;
          color: #888888;
          margin-top: 20px;
          padding-top: 10px;
          border-top: 1px solid #CCCCCC;
        ">
          <small style="
            display: block;
          ">
            <a style="
              color: #AAAAAA;
              text-decoration: none;
            " href="<?php print $previous_item['url']; ?>">
              <?php print check_plain($previous_item['author']) ?>
              &middot;
              <?php print format_date($previous_item['date'], 'custom', 'l, j F, Y', NULL, $langcode); ?>
            </a>
          </small>

          <?php print $previous_item['body']; ?>
        </div>

      <?php endforeach; ?>
    </div>
  <?php endif; ?>

  <?php include __DIR__.'/../../cluster_email/templates/notification-footer-anon.tpl.php'; ?>
</div>
