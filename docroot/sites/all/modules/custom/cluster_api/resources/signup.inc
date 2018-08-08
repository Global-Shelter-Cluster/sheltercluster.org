<?php

use \Drupal\cluster_api\Authorization;

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

  // Create new user with supplied credentials and values.
  $fields = [
    'name' => $email,
    'mail' => $email,
    'pass' => $password,
    'status' => 1,
    'init' => $email,
    'roles' => [
      DRUPAL_AUTHENTICATED_RID => 'authenticated user',
    ],
    'name_field' => [
      'en' => [
        0 => [
          'value' => $account_values['name'],
        ],
      ],
    ],
    'field_organisation_name' => [
      'en' => [
        0 => [
          'value' => $account_values['organization'],
        ],
      ],
    ],
  ];

  $user = user_save('', $fields);

  cluster_api_track_users($user->uid, 'shelter_app');

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