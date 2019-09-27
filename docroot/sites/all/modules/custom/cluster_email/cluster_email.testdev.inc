<?php

/**
 * @file This is only meant for development.
 */

function cluster_email_cron_test() {
  $gid = 9175;

  // Daily notifications
  $last_notification_field = 'last_daily_email_notification';
  $enabled_field = 'field_notif_email_daily';
  $timezones = cluster_api_timezones(CLUSTER_EMAIL_DAILY_NOTIFICATION_FROM, CLUSTER_EMAIL_DAILY_NOTIFICATION_TO);

  $objects_by_gid = [];
  $objects_by_gid[$gid]['cluster_docs'] = [500, 600, 800, 911, 9175];
  $objects_by_gid[$gid]['cluster_factsheets'] = [500, 17031];
  $objects_by_gid[$gid]['cluster_og'] = range(9000,9250);
//  drupal_alter('daily_email_notification_objects', $objects_by_gid);

  foreach ($objects_by_gid as $gid => $objects_by_module) {
    $group = node_load($gid);
    if (!og_is_group('node', $group))
      continue; // shouldn't happen
    $manager = GroupContentManager::getInstance($group);

    $all_uids = cluster_api_get_followers(
      $manager,
      $timezones,
      $last_notification_field,
      22,
      $enabled_field
    );

    $all_uids = [733];
    if (!$all_uids)
      continue;

    foreach (cluster_api_split_users_by_langcode($all_uids) as $langcode => $uids) {
      $data = _cluster_email_daily_notification_body_data($objects_by_module, $langcode);
      if (!$data)
        continue;

      try {
        $params = [
          'group' => $group,
          'data' => $data,
          'langcode' => $langcode,
        ];
        $to = _cluster_email_recipients_string($uids);

        drupal_mail('cluster_email', 'daily_notification', $to, $langcode, $params);
      } catch (Exception $e) {
        watchdog('cluster_email', 'Error sending daily email notifications for gid @gid: @error', [
          '@gid' => $gid,
          '@error' => $e->getMessage(),
        ], WATCHDOG_ERROR);
      }

      $manager->updateUsersTimestamp(CLUSTER_API_FOLLOWER_ROLE_NAME, $uids, $last_notification_field);
    }
  }
}
