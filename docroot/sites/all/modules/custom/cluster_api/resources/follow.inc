<?php

use \Drupal\cluster_api\Oauth\Authorization;

/**
 * Returns the group object (with persist=true) and all its related objects.
 *
 * @param int $id
 */
function _cluster_api_follow($id, $request) {
  watchdog('cluster_api_follow_actions_request', json_encode(func_get_args()));
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
    watchdog('cluster_api_follow_auth_fail', json_encode($response));
    return $response;
  }

  $group = node_load($id);
  if (!$group || !og_is_group('node', $group)) {
    return services_error('Wrong group id', 400);
  }

  if (!og_is_member('node', $id, 'user', $user)) {
    $m = og_membership_create('node', $id, 'user', $user->uid, 'og_user_node1');
    $m->save();
  }
  if (!in_array($id, ClusterAPI_Type_User::getFollowedGroups($user))) {
    og_role_grant('node', $id, $user->uid, _cluster_api_get_follower_role_by_bundle($group->type));
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
    watchdog('cluster_api_unfollow_auth_fail', json_encode($response));
    return $response;
  }

  $group = node_load($id);
  if (!$group || !og_is_group('node', $group)) {
    return services_error('Wrong group id', 400);
  }

  if (in_array($id, ClusterAPI_Type_User::getFollowedGroups($user))) {
    og_role_revoke('node', $id, $user->uid, _cluster_api_get_follower_role_by_bundle($group->type));
  }

  //TODO: if the user was only involved with the group as a follower, remove them from it altogether.

  $object = new ClusterAPI_Object($user);
  $response['objects'] = $object->getObjects([
    ['type' => 'user', 'id' => $user->uid],
    ['type' => 'global', 'id' => 1],
    ['type' => 'group', 'id' => $id], // Include the group being un-followed, so the app can keep showing it.
  ]);
  watchdog('cluster_api_unfollow_response', $response);
  return $response;
}
