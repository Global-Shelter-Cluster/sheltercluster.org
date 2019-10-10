<?php

use Drupal\cluster_api\Oauth\Authorization;

function _cluster_api_update_user($request) {
  $auth = new Authorization();
  $auth_response = $auth->authorize($request);
  $user = $auth_response['user'];
  $response['authorization'] = $auth_response['authorization'];

  if ($user && !empty($request['pushNotificationToken'])) {
    _cluster_api_set_push_notification_token($user, $request['pushNotificationToken']);
  }

  // Can't authorize.
  if (!$user || $response['authorization']['code'] != '200') {
    return $response;
  }

  $update_messages = [];
  $updates_performed = FALSE;
  try {
    foreach ($request['updates'] as $field => $new_value) {
      $update_function = '_cluster_api_update_user_' . $field;
      if (function_exists($update_function)) {
        $result = $update_function($user, $new_value);
        $updates_performed = $updates_performed || $result['do_update'];
        if ($result['update_message'])
          $update_messages[] = $result['update_message'];
      } else {
        $update_messages[] = t('Update not supported for field @field', ['@field' => $field], ['langcode' => $user->language]);
      }
    }
  } catch (Exception $e) {
    return services_error($e->getMessage(), 400);
  }

  if ($updates_performed) {
    user_save($user);
    // Return the updated user object and any related objects.
    $object_api = new ClusterAPI_Object($user);
    $requested_objects = [['type' => 'user', 'id' => $user->uid]];
    $response['objects'] = $object_api->getObjects($requested_objects);
  }

  $response['update_messages'] = $update_messages;

  return $response;
}

function _cluster_api_update_user_language($user, $lang) {
  $enabled_languages = variable_get('cluster_locale_mobile_enabled_languages', NULL);
  if (!array_key_exists($lang, $enabled_languages)) {
    return [
      'do_update' => FALSE,
      'update_message' => t('Language @lang is not available', ['@lang' => $lang], ['langcode' => $user->language]),
    ];
  }
  $user->language = $lang;
  return [
    'do_update' => TRUE,
    'update_message' => t('Language set to @lang', ['@lang' => $lang], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_timezone($user, $timezone) {
  $available_timezones = array_keys(system_time_zones());
  if (!in_array($timezone, $available_timezones)) {
    return [
      'do_update' => FALSE,
      'update_message' => t('Timezone @timezone is not available', ['@timezone' => $timezone], ['langcode' => $user->language]),
    ];
  }
  $user->timezone = $timezone;
  return [
    'do_update' => TRUE,
    'update_message' => t('Timezone set to @timezone', ['@timezone' => $timezone], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_picture($user, $data) {
  $fid = _cluster_api_receive_file($data, 'public://pictures', $user->uid);
  if ($fid) {
    $user->picture = file_load($fid);
    return [
      'do_update' => TRUE,
      'update_message' => t('Picture changed', [], ['langcode' => $user->language]),
    ];
  } else {
    return [
      'do_update' => FALSE,
    ];
  }
}

function _cluster_api_update_user_name($user, $data) {
  $data = trim($data);
  // Snippet taken from user.module:user_account_form_validate()
  if ($error = user_validate_name($data)) {
    throw new Exception(t('Invalid user name.', [], ['langcode' => $user->language]));
  }
  elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', $user->uid, '<>')->condition('name', db_like($data), 'LIKE')->range(0, 1)->execute()->fetchField()) {
    throw new Exception(t('The name @name is already taken.', ['@name' => $data], ['langcode' => $user->language]));
  }
  $user->name = $data;
  return [
    'do_update' => TRUE,
    'update_message' => t('Name changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_mail($user, $data) {
  $data = trim($data);
  // Snippet taken from user.module:user_account_form_validate()
  if ($error = user_validate_mail($data)) {
    throw new Exception(t('Invalid e-mail address.', [], ['langcode' => $user->language]));
  }
  elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', $user->uid, '<>')->condition('mail', db_like($data), 'LIKE')->range(0, 1)->execute()->fetchField()) {
    throw new Exception(t('The e-mail address @email is already taken.', ['@email' => $data], ['langcode' => $user->language]));
  }

  $user->mail = $data;
  return [
    'do_update' => TRUE,
    'update_message' => t('E-mail address changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_full_name($user, $data) {
  $data = trim($data);
  $user->name_field = [LANGUAGE_NONE => [['value' => $data]]];

  return [
    'do_update' => TRUE,
    'update_message' => t('Full name changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_phone($user, $data) {
  $data = array_filter(array_map('trim', (array) $data));

  $user->field_phone_number = [LANGUAGE_NONE => array_map(function($value) {
    return ['value' => $value];
  }, $data)];

  return [
    'do_update' => TRUE,
    'update_message' => t('Full name changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_org($user, $data) {
  $data = trim($data);
  $user->field_organisation_name = [LANGUAGE_NONE => [['value' => $data]]];

  return [
    'do_update' => TRUE,
    'update_message' => t('Organization changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_role($user, $data) {
  $data = trim($data);
  $user->field_role_or_title = [LANGUAGE_NONE => [['value' => $data]]];

  return [
    'do_update' => TRUE,
    'update_message' => t('Role changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_pass($user, $data) {
  $data = trim($data);

  // Snippet taken from user.module:user_save()
  if (strlen(trim($data)) > 0) {
    // Allow alternate password hashing schemes.
    require_once DRUPAL_ROOT . '/' . variable_get('password_inc', 'includes/password.inc');
    $data = user_hash_password(trim($data));
    // Abort if the hashing failed and returned FALSE.
    if (!$data)
      throw new Exception(t('Invalid password.', [], ['langcode' => $user->language]));
  }

  $user->pass = $data;

  return [
    'do_update' => TRUE,
    'update_message' => t('Password changed', [], ['langcode' => $user->language]),
  ];
}

function _cluster_api_update_user_notifications($user, $data) {
  $filtered = array_filter($data);

  $user->field_notif_push_daily = [LANGUAGE_NONE => [['value' => array_key_exists('app_daily', $filtered) ? '1' : '0']]];
  $user->field_notif_push_upcevents = [LANGUAGE_NONE => [['value' => array_key_exists('app_upcoming_events', $filtered) ? '1' : '0']]];
  $user->field_notif_email_daily = [LANGUAGE_NONE => [['value' => array_key_exists('email_daily', $filtered) ? '1' : '0']]];
  $user->field_notif_email_weekly = [LANGUAGE_NONE => [['value' => array_key_exists('email_weekly', $filtered) ? '1' : '0']]];

  return [
    'do_update' => TRUE,
    'update_message' => t('Notification preferences saved', [], ['langcode' => $user->language]),
  ];
}
