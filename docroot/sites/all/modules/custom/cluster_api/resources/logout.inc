<?php

use \Drupal\cluster_api\Authorization;

function _cluster_api_logout($request) {
  watchdog('cluster_api_logout', json_encode($request));

  if (empty($request['pushNotificationToken'])) {
    return;
  }

  $auth = new Authorization();
  $auth_response = $auth->authorize($request);
  $response['authorization'] = $auth_response['authorization'];

  $user = $auth_response['user'];
  // Can't authorize.
  if (!$user || $response['authorization']['code'] != '200') {
    return;
  }

  // Remove the push notification token from the user.
  _cluster_api_clear_push_token_for_user($request['pushNotificationToken'], $user->uid);
}
