<?php
/**
 * @file
 * cluster_libraries.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_libraries_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view library full node'.
  $permissions['view library full node'] = array(
    'name' => 'view library full node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cluster_libraries',
  );

  return $permissions;
}
