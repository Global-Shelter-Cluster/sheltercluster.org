<?php
/**
 * @file
 * cluster_factsheets.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cluster_factsheets_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:community_of_practice:create factsheet content'
  $permissions['node:community_of_practice:create factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete any factsheet content'
  $permissions['node:community_of_practice:delete any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete own factsheet content'
  $permissions['node:community_of_practice:delete own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update any factsheet content'
  $permissions['node:community_of_practice:update any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update own factsheet content'
  $permissions['node:community_of_practice:update own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:create factsheet content'
  $permissions['node:geographic_region:create factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any factsheet content'
  $permissions['node:geographic_region:delete any factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own factsheet content'
  $permissions['node:geographic_region:delete own factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any factsheet content'
  $permissions['node:geographic_region:update any factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own factsheet content'
  $permissions['node:geographic_region:update own factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:create factsheet content'
  $permissions['node:hub:create factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete any factsheet content'
  $permissions['node:hub:delete any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete own factsheet content'
  $permissions['node:hub:delete own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update any factsheet content'
  $permissions['node:hub:update any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update own factsheet content'
  $permissions['node:hub:update own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:create factsheet content'
  $permissions['node:response:create factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:delete any factsheet content'
  $permissions['node:response:delete any factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete own factsheet content'
  $permissions['node:response:delete own factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:update any factsheet content'
  $permissions['node:response:update any factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update own factsheet content'
  $permissions['node:response:update own factsheet content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create factsheet content'
  $permissions['node:strategic_advisory:create factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete any factsheet content'
  $permissions['node:strategic_advisory:delete any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete own factsheet content'
  $permissions['node:strategic_advisory:delete own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update any factsheet content'
  $permissions['node:strategic_advisory:update any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update own factsheet content'
  $permissions['node:strategic_advisory:update own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create factsheet content'
  $permissions['node:working_group:create factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any factsheet content'
  $permissions['node:working_group:delete any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own factsheet content'
  $permissions['node:working_group:delete own factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any factsheet content'
  $permissions['node:working_group:update any factsheet content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own factsheet content'
  $permissions['node:working_group:update own factsheet content'] = array(
    'roles' => array(),
  );

  return $permissions;
}
