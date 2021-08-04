<?php

use \Drupal\cluster_api\Oauth\Authorization;

/**
 * Example:
 *
 * jQuery.ajax({
 *   type: "POST",
 *   url: "http://local.sheltercluster.org/api-v1/get-objects",
 *   dataType: "json",
 *   contentType: "application/json",
 *   success: console.log,
 *   data: JSON.stringify([
 *     {type: 'user', id: 1},
 *     {type: 'group', id: 2},
 *   ])
 * });
 *
 * @param $requests
 *
 * @return array
 */
function _cluster_api_get_objects($request) {
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

  // Add the authorized user id to the requested objects.
  $requested_objects = array_merge([['type' => 'user', 'id' => $user->uid]], $request['objects']);

  // Get all objects from API.
  $object_api = new ClusterAPI_Object($user);
  $response['objects'] = $object_api->getObjects($requested_objects);
  return $response;
}
