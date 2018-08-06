<?php
/**
 * @file
 * cluster_search.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_search_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  return $permissions;
}
