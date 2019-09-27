<hr style="
    height: 1px;
    border: none;
    background-color: #cccccc;
  "/>

<p style="
    width: 70%;
    min-width: 300px;
    margin: 30px auto 0;
    font-size: 11px;
    line-height: 1.5;
  ">
  <?php

  $text = t('You are receiving this email because you\'re following @group on the Shelter Cluster website or mobile app. To unsubscribe, please unfollow this group or change your notification settings by clicking here.', [
    '@group' => $group->title,
  ], [
    'langcode' => $langcode,
  ]);

  print l($text, 'user/me/edit', ['absolute' => TRUE, 'attributes' => [
    'style' => 'color: #575757; text-decoration: none;'
  ]]); ?>
</p>
