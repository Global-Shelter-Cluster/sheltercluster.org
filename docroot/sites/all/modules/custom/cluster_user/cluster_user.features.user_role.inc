<?php
/**
 * @file
 * cluster_user.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function cluster_user_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: trusted user.
  $roles['trusted user'] = array(
    'name' => 'trusted user',
    'weight' => 3,
  );

  return $roles;
}
