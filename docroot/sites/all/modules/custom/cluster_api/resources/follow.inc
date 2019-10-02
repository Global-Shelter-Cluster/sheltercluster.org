<?php

use \Drupal\cluster_api\Oauth\Authorization;

/**
 * Returns the group object (with persist=true) and all its related objects.
 *
 * @param int $id
 */
function _cluster_api_follow($id, $request) {
  switch ($request['action']) {
    case 'follow':
      return _cluster_api_follow_action($id, $request);
    case 'unfollow':
      return _cluster_api_unfollow_action($id, $request);
  }
}

function _cluster_api_follow_action($id, $request) {
  $id = intval($id, 10);
  if ($id <= 0) {
    return services_error('Wrong group id', 400);
  }

  $auth = new Authorization();
  $auth_response = $auth->authorize($request);
  $user = $auth_response['user'];
  $response['authorization'] = $auth_response['authorization'];

  // Can't authorize.
  if (!$user || $response['authorization']['code'] != '200') {
    return $response;
  }

  $group = node_load($id);
  try {
    cluster_og_follow($user, $group);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 400);
  }

  $object = new ClusterAPI_Object($user);
  $response['objects'] = $object->getObjects([['type' => 'group', 'id' => $id]]);
  return $response;
}

/**
 * Returns the same as logging in (i.e. everything the user sees, plus the
 * global object).
 *
 * @param int $id
 */
function _cluster_api_unfollow_action($id, $request) {
  $id = intval($id, 10);
  if ($id <= 0) {
    return services_error('Wrong group id', 400);
  }
  $auth = new Authorization();
  $auth_response = $auth->authorize($request);
  $user = $auth_response['user'];
  $response['authorization'] = $auth_response['authorization'];

  // Can't authorize.
  if (!$user || $response['authorization']['code'] != '200') {
    return $response;
  }

  $group = node_load($id);
  try {
    cluster_og_unfollow($user, $group);
  } catch (Exception $e) {
    return services_error($e->getMessage(), 400);
  }

  $object = new ClusterAPI_Object($user);
  $response['objects'] = $object->getObjects([
    ['type' => 'user', 'id' => $user->uid],
    ['type' => 'global', 'id' => 1],
    ['type' => 'group', 'id' => $id], // Include the group being un-followed, so the app can keep showing it.
  ]);

  return $response;
}
