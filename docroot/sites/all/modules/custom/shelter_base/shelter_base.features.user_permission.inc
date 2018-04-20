<?php
/**
 * @file
 * shelter_base.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function shelter_base_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'use hybridauth'.
  $permissions['use hybridauth'] = array(
    'name' => 'use hybridauth',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'hybridauth',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Full HTML user' => 'Full HTML user',
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
