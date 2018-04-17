<?php
/**
 * @file
 * cluster_user.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cluster_user_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:community_of_practice:create article content'
  $permissions['node:community_of_practice:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:create community_of_practice content'
  $permissions['node:community_of_practice:create community_of_practice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any article content'
  $permissions['node:community_of_practice:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete any community_of_practice content'
  $permissions['node:community_of_practice:delete any community_of_practice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own article content'
  $permissions['node:community_of_practice:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete own community_of_practice content'
  $permissions['node:community_of_practice:delete own community_of_practice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:manage_child_hub'
  $permissions['node:community_of_practice:manage_child_hub'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:manage_child_strategic_advisory'
  $permissions['node:community_of_practice:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:manage_child_working_group'
  $permissions['node:community_of_practice:manage_child_working_group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update any article content'
  $permissions['node:community_of_practice:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update any community_of_practice content'
  $permissions['node:community_of_practice:update any community_of_practice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own article content'
  $permissions['node:community_of_practice:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update own community_of_practice content'
  $permissions['node:community_of_practice:update own community_of_practice content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:create article content'
  $permissions['node:geographic_region:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:create community_of_practice content'
  $permissions['node:geographic_region:create community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete any article content'
  $permissions['node:geographic_region:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete any community_of_practice content'
  $permissions['node:geographic_region:delete any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete own article content'
  $permissions['node:geographic_region:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete own community_of_practice content'
  $permissions['node:geographic_region:delete own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:manage_child_hub'
  $permissions['node:geographic_region:manage_child_hub'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:manage_child_strategic_advisory'
  $permissions['node:geographic_region:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:manage_child_working_group'
  $permissions['node:geographic_region:manage_child_working_group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update any article content'
  $permissions['node:geographic_region:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update any community_of_practice content'
  $permissions['node:geographic_region:update any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update own article content'
  $permissions['node:geographic_region:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update own community_of_practice content'
  $permissions['node:geographic_region:update own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:create article content'
  $permissions['node:hub:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:create community_of_practice content'
  $permissions['node:hub:create community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete any article content'
  $permissions['node:hub:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete any community_of_practice content'
  $permissions['node:hub:delete any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete own article content'
  $permissions['node:hub:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete own community_of_practice content'
  $permissions['node:hub:delete own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:manage_child_hub'
  $permissions['node:hub:manage_child_hub'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:manage_child_strategic_advisory'
  $permissions['node:hub:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:manage_child_working_group'
  $permissions['node:hub:manage_child_working_group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update any article content'
  $permissions['node:hub:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update any community_of_practice content'
  $permissions['node:hub:update any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update own article content'
  $permissions['node:hub:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update own community_of_practice content'
  $permissions['node:hub:update own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:create article content'
  $permissions['node:response:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:create community_of_practice content'
  $permissions['node:response:create community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete any article content'
  $permissions['node:response:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete any community_of_practice content'
  $permissions['node:response:delete any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete own article content'
  $permissions['node:response:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete own community_of_practice content'
  $permissions['node:response:delete own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:manage_child_hub'
  $permissions['node:response:manage_child_hub'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:manage_child_strategic_advisory'
  $permissions['node:response:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:manage_child_working_group'
  $permissions['node:response:manage_child_working_group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update any article content'
  $permissions['node:response:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update any community_of_practice content'
  $permissions['node:response:update any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update own article content'
  $permissions['node:response:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update own community_of_practice content'
  $permissions['node:response:update own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:create article content'
  $permissions['node:strategic_advisory:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:create community_of_practice content'
  $permissions['node:strategic_advisory:create community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete any article content'
  $permissions['node:strategic_advisory:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete any community_of_practice content'
  $permissions['node:strategic_advisory:delete any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete own article content'
  $permissions['node:strategic_advisory:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete own community_of_practice content'
  $permissions['node:strategic_advisory:delete own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:manage_child_hub'
  $permissions['node:strategic_advisory:manage_child_hub'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:manage_child_strategic_advisory'
  $permissions['node:strategic_advisory:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:manage_child_working_group'
  $permissions['node:strategic_advisory:manage_child_working_group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update any article content'
  $permissions['node:strategic_advisory:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update any community_of_practice content'
  $permissions['node:strategic_advisory:update any community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update own article content'
  $permissions['node:strategic_advisory:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update own community_of_practice content'
  $permissions['node:strategic_advisory:update own community_of_practice content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create article content'
  $permissions['node:working_group:create article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create community_of_practice content'
  $permissions['node:working_group:create community_of_practice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any article content'
  $permissions['node:working_group:delete any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any community_of_practice content'
  $permissions['node:working_group:delete any community_of_practice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own article content'
  $permissions['node:working_group:delete own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own community_of_practice content'
  $permissions['node:working_group:delete own community_of_practice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage_child_hub'
  $permissions['node:working_group:manage_child_hub'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage_child_strategic_advisory'
  $permissions['node:working_group:manage_child_strategic_advisory'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:manage_child_working_group'
  $permissions['node:working_group:manage_child_working_group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update any article content'
  $permissions['node:working_group:update any article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any community_of_practice content'
  $permissions['node:working_group:update any community_of_practice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update own article content'
  $permissions['node:working_group:update own article content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own community_of_practice content'
  $permissions['node:working_group:update own community_of_practice content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
