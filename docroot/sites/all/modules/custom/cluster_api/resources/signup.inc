<?php

use Drupal\cluster_api\Oauth\Authorization;

function _cluster_api_signup($requests) {
  watchdog('cluster_api_signup', json_encode($requests));
  $response = [
    'authorization' => [],
    'objects' => [],
    'code' => [],
    'error' => '',
  ];

  $account_values = $requests['credentials']['account_values'];

  if (empty($account_values['email']) || empty($account_values['password'])) {
    $response['authorization'] = _cluster_api_signup_error_response('400', 'Bad request', 'Missing credentials');
    return $response;
  }

  $email = $account_values['email'];
  $password = $account_values['password'];

  if (!valid_email_address($email)) {
    $response['authorization'] = _cluster_api_signup_error_response('400', 'Bad request', 'Invalid email address');
    return $response;
  }

  if (user_load_by_mail($email)) {
    $response['authorization'] = _cluster_api_signup_error_response('403', 'Forbidden', 'User already exists');
    return $response;
  }

  if (cluster_user_is_mail_blocked_from_registering($email, "api_signup, name: {$account_values['name']}, IP: {$_SERVER['REMOTE_ADDR']}")) {
    $response['authorization'] = _cluster_api_signup_error_response('403', 'Forbidden', 'Email address blocked. Please contact an administrator if you believe this is a mistake.');
    return $response;
  }

  // Create new user with supplied credentials and values.
  $fields = [
    'name' => $account_values['name'],
    'mail' => $email,
    'pass' => $password,
    'status' => 1,
    'init' => $email,
    'roles' => [
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ],
    'field_organisation_name' => [LANGUAGE_NONE => [['value' => $account_values['organization']]]],
  ];

  // Auto-follow Global group
  // In theory, cluster_user_user_insert() should handle this. In practice, it just doesn't work. For some reason...
  if ($global_id = variable_get('cluster_og_global_id')) {
    $global_group = node_load($global_id);
    if ($global_group && og_is_group('node', $global_group)) {
      $fields['og_user_node1'] = [
        LANGUAGE_NONE => [
          0 => [
            'target_id' => $global_id,
          ],
        ],
      ];
    }
    else {
      $global_group = NULL;
    }
  }

  $user = user_save('', $fields);

  cluster_api_track_users($user->uid, 'shelter_app');

  // Grant "follower" role for global group
  if ($global_group) {
    try {
      og_role_grant('node', $global_group->nid, $user->uid, cluster_api_get_follower_role_by_bundle($global_group->type));
    } catch (Exception $e) {
      watchdog('cluster_api_signup', 'Error in Global group auto-follow', [
        'exception' => $e,
        'uid' => $user->uid,
      ], WATCHDOG_ERROR);
    }
  }

  // Generate oauth credentials for the new user.
  $auth = new Authorization();
  $auth_response = $auth->authorize([
    'credentials' => [
      'type' => 'password',
      'username' => $email,
      'password' => $password,
      'client_id' => $requests['credentials']['client_id'],
      'scope' => $requests['credentials']['scope'],
    ],
  ]);

  $response['authorization'] = $auth_response['authorization'];

  if (!empty($requests['pushNotificationToken'])) {
    watchdog('cluster_api_signup', $requests['pushNotificationToken']);
    _cluster_api_set_push_notification_token($user, $requests['pushNotificationToken']);
  }

  // Add the authorized user id to the requested objects.
  $requested_objects = $requests['objects'];
  $requested_objects[] = ['type' => 'user', 'id' => $user->uid];

  // Get all objects from API.
  $object_api = new ClusterAPI_Object($user);
  $response['objects'] = $object_api->getObjects($requested_objects);
  return $response;
}

function _cluster_api_signup_error_response($code, $message, $description) {
  return [
    'code' => $code,
    'response_error' => $message,
    'status_message' => $message,
    'error_description' => $description,
  ];
}
