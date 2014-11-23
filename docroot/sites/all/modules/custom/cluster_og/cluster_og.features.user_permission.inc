<?php
/**
 * @file
 * cluster_og.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_og_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any node geographic_region page'.
  $permissions['view any node geographic_region page'] = array(
    'name' => 'view any node geographic_region page',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'restrict_node_page_view',
  );

  return $permissions;
}
