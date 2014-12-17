<?php
/**
 * @file
 * cluster_discussions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_discussions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view any node discussion page'.
  $permissions['view any node discussion page'] = array(
    'name' => 'view any node discussion page',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'restrict_node_page_view',
  );

  return $permissions;
}
