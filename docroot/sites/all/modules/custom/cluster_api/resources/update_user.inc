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
  foreach ($request['updates'] as $field => $new_value) {
    $update_function = '_cluster_api_update_user_' . $field;
    if (function_exists($update_function)) {
      $result = $update_function($user, $new_value);
      $updates_performed = $result['do_update'];
      $update_messages[] = $result['update_message'];
    } else {
      $update_messages[] = t('Update not supported for field @field', ['@field' => $field], ['langcode' => $user->language]);
    }
  }

  if ($updates_performed) {
    user_save($user);
  }
  return $response['update_messages'] = $update_messages;
}

function _cluster_api_update_user_language($user, $lang) {
  $enabled_languages = variable_get('cluster_locale_mobile_enabled_languages', NULL);
  if (!array_key_exists($lang, $enabled_languages)) {
    return [
      'do_update' => FALSE,
      'update_message' => t('Language @lang is not available', ['@lang' => $lang], ['langcode' => $lang]),
    ];
  }
  $user->language = $lang;
  return [
    'do_update' => TRUE,
    'update_message' => t('Language set to @lang', ['@lang' => $lang], ['langcode' => $lang]),
  ];
}
