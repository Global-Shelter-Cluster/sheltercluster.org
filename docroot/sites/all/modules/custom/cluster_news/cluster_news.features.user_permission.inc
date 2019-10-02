<?php
/**
 * @file
 * cluster_news.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_news_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_is_sent'.
  $permissions['create field_is_sent'] = array(
    'name' => 'create field_is_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create news content'.
  $permissions['create news content'] = array(
    'name' => 'create news content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any news content'.
  $permissions['delete any news content'] = array(
    'name' => 'delete any news content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own news content'.
  $permissions['delete own news content'] = array(
    'name' => 'delete own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any news content'.
  $permissions['edit any news content'] = array(
    'name' => 'edit any news content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_is_sent'.
  $permissions['edit field_is_sent'] = array(
    'name' => 'edit field_is_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_is_sent'.
  $permissions['edit own field_is_sent'] = array(
    'name' => 'edit own field_is_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own news content'.
  $permissions['edit own news content'] = array(
    'name' => 'edit own news content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view field_is_sent'.
  $permissions['view field_is_sent'] = array(
    'name' => 'view field_is_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_is_sent'.
  $permissions['view own field_is_sent'] = array(
    'name' => 'view own field_is_sent',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}
