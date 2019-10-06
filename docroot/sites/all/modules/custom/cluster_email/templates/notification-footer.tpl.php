<hr style="
  margin-top: 60px;
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
  color: #575757;
">
  <?php

  print t('You are receiving this email because you\'re following @group on the Shelter Cluster website or mobile app.'
    .' To unsubscribe, please <a href="@group_link">unfollow this group</a> or'
    .' <a href="@notification_settings">change your notification settings</a>.', [
    '@group' => $group->title,
    '@group_link' => url('node/'.$group->nid, ['absolute' => TRUE]),
    '@notification_settings' => url('user/me/edit', ['absolute' => TRUE, 'fragment' => 'notifications']),
  ], [
    'langcode' => $langcode,
  ]);

  ?>
</p>
