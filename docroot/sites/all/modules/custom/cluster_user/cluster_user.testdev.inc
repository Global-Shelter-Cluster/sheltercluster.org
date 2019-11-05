<?php

/**
 * @file This is only meant for development.
 *
 * Use module_load_include('inc', 'cluster_user', 'cluster_user.testdev'); to load it.
 */

/**
 * This is meant to block "bad" users (e.g. ones created during an attack), from an email list.
 * It will only block users who are active, and have never logged in (looking at the "access" property).
 */
function cluster_user_block_bad_users($all_emails) {
  $all_emails = array_unique($all_emails);
  $all_count = count($all_emails);
  $count = 0;

  foreach ($all_emails as $email) {
    $uid = db_select('users', 'u')
      ->fields('u', ['uid'])
      ->condition('mail', '%'.trim($email).'%', 'LIKE')
      ->condition('status', 1)
      ->condition('access', 0)
      ->execute()
      ->fetchField();

    if (!$uid)
      continue;

    user_user_operations_block([$uid]);
    $count++;
  }

  dpm('Blocked '.$count.' account(s), '.$all_count.' email(s) given.');
}
