<?php
/**
 * @file
 * cluster_docs.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_docs_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view document full node'.
  $permissions['view document full node'] = array(
    'name' => 'view document full node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cluster_docs',
  );

  return $permissions;
}
