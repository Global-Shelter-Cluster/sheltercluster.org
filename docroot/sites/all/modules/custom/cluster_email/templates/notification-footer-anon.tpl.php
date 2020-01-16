<?php
/**
 * This is used for email subscriptions (i.e. by anonymous users who just enter their email
 * to subscribe to a specific group using field_subscribers).
 */
?>
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

  print t('You are receiving this email because you\'ve subscribed to @group on the Shelter Cluster website.'
    .' To unsubscribe, please <a href="@unsubscribe_link">click here</a>.', [
    '@group' => $group->title,
    '@unsubscribe_link' => url('unsubscribe/'.$group->nid.'/'.$subscriber_email, ['absolute' => TRUE]),
  ], [
    'langcode' => $langcode,
  ]);

  ?>
</p>
