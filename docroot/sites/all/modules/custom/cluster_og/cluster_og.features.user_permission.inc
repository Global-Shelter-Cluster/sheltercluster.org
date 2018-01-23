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

  // Exported permission: 'create community_of_practice content'.
  $permissions['create community_of_practice content'] = array(
    'name' => 'create community_of_practice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create geographic_region content'.
  $permissions['create geographic_region content'] = array(
    'name' => 'create geographic_region content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create hub content'.
  $permissions['create hub content'] = array(
    'name' => 'create hub content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create response content'.
  $permissions['create response content'] = array(
    'name' => 'create response content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create strategic_advisory content'.
  $permissions['create strategic_advisory content'] = array(
    'name' => 'create strategic_advisory content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create working_group content'.
  $permissions['create working_group content'] = array(
    'name' => 'create working_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any community_of_practice content'.
  $permissions['delete any community_of_practice content'] = array(
    'name' => 'delete any community_of_practice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any geographic_region content'.
  $permissions['delete any geographic_region content'] = array(
    'name' => 'delete any geographic_region content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any hub content'.
  $permissions['delete any hub content'] = array(
    'name' => 'delete any hub content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any response content'.
  $permissions['delete any response content'] = array(
    'name' => 'delete any response content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any strategic_advisory content'.
  $permissions['delete any strategic_advisory content'] = array(
    'name' => 'delete any strategic_advisory content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any working_group content'.
  $permissions['delete any working_group content'] = array(
    'name' => 'delete any working_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own community_of_practice content'.
  $permissions['delete own community_of_practice content'] = array(
    'name' => 'delete own community_of_practice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own geographic_region content'.
  $permissions['delete own geographic_region content'] = array(
    'name' => 'delete own geographic_region content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own hub content'.
  $permissions['delete own hub content'] = array(
    'name' => 'delete own hub content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own response content'.
  $permissions['delete own response content'] = array(
    'name' => 'delete own response content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own strategic_advisory content'.
  $permissions['delete own strategic_advisory content'] = array(
    'name' => 'delete own strategic_advisory content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own working_group content'.
  $permissions['delete own working_group content'] = array(
    'name' => 'delete own working_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any community_of_practice content'.
  $permissions['edit any community_of_practice content'] = array(
    'name' => 'edit any community_of_practice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any geographic_region content'.
  $permissions['edit any geographic_region content'] = array(
    'name' => 'edit any geographic_region content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any hub content'.
  $permissions['edit any hub content'] = array(
    'name' => 'edit any hub content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any response content'.
  $permissions['edit any response content'] = array(
    'name' => 'edit any response content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any strategic_advisory content'.
  $permissions['edit any strategic_advisory content'] = array(
    'name' => 'edit any strategic_advisory content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any working_group content'.
  $permissions['edit any working_group content'] = array(
    'name' => 'edit any working_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own community_of_practice content'.
  $permissions['edit own community_of_practice content'] = array(
    'name' => 'edit own community_of_practice content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own geographic_region content'.
  $permissions['edit own geographic_region content'] = array(
    'name' => 'edit own geographic_region content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own hub content'.
  $permissions['edit own hub content'] = array(
    'name' => 'edit own hub content',
    'roles' => array(
      'administrator' => 'administrator',
      'trusted user' => 'trusted user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own response content'.
  $permissions['edit own response content'] = array(
    'name' => 'edit own response content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own strategic_advisory content'.
  $permissions['edit own strategic_advisory content'] = array(
    'name' => 'edit own strategic_advisory content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own working_group content'.
  $permissions['edit own working_group content'] = array(
    'name' => 'edit own working_group content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  return $permissions;
}
