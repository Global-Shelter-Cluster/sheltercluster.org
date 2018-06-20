<?php

/**
 * Returns the group object (with persist=true) and all its related objects.
 *
 * @param int $id
 *
 * @throws \OgException
 * @throws \Exception
 */
function _cluster_api_follow($id) {
  global $user;

  $id = intval($id, 10);
  if ($id <= 0)
    throw new Exception('Wrong group id');

  $user = user_load(733); // 733: Camilo, 74: Shirin, 70: Neil, 531: Bo

  $group = node_load($id);
  if (!$group || !og_is_group('node', $group))
    throw new Exception('Wrong group id');

  if (!og_is_member('node', $id, 'user', $user)) {
    $m = og_membership_create('node', $id, 'user', $user->uid, 'og_user_node1');
    $m->save();
  }
  if (!in_array($id, ClusterAPI_Type_User::getFollowedGroups($user)))
    og_role_grant('node', $id, $user->uid, _cluster_api_get_follower_role_by_bundle($group->type));

  $object = new ClusterAPI_Object($user);
  return $object->getObjects([['type' => 'group', 'id' => $id]]);
}

/**
 * Returns the same as logging in (i.e. everything the user sees, plus the
 * global object).
 *
 * @param int $id
 *
 * @throws \Exception
 */
function _cluster_api_unfollow($id) {
  global $user;

  $id = intval($id, 10);
  if ($id <= 0)
    throw new Exception('Wrong group id');

  $user = user_load(733); // 733: Camilo, 74: Shirin, 70: Neil, 531: Bo

  $group = node_load($id);
  if (!$group || !og_is_group('node', $group))
    throw new Exception('Wrong group id');

  if (in_array($id, ClusterAPI_Type_User::getFollowedGroups($user)))
    og_role_revoke('node', $id, $user->uid, _cluster_api_get_follower_role_by_bundle($group->type));

  //TODO: if the user was only involved with the group as a follower, remove them from it altogether.

  $object = new ClusterAPI_Object($user);
  return $object->getObjects([
    ['type' => 'user', 'id' => $user->uid],
    ['type' => 'global', 'id' => 1],
    ['type' => 'group', 'id' => $id], // Include the group being un-followed, so the app can keep showing it.
  ]);
}
