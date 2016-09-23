<?php
/**
 * @file
 * shelter_base.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function shelter_base_user_default_roles() {
  $roles = array();

  // Exported role: Full HTML user.
  $roles['Full HTML user'] = array(
    'name' => 'Full HTML user',
    'weight' => 5,
  );

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
