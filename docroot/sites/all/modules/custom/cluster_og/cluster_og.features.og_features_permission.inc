<?php
/**
 * @file
 * cluster_og.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function cluster_og_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:community_of_practice:add user'
  $permissions['node:community_of_practice:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:administer group'
  $permissions['node:community_of_practice:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:approve and deny subscription'
  $permissions['node:community_of_practice:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:create discussion content'
  $permissions['node:community_of_practice:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:create document content'
  $permissions['node:community_of_practice:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any discussion content'
  $permissions['node:community_of_practice:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any document content'
  $permissions['node:community_of_practice:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own discussion content'
  $permissions['node:community_of_practice:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own document content'
  $permissions['node:community_of_practice:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:manage members'
  $permissions['node:community_of_practice:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:manage permissions'
  $permissions['node:community_of_practice:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:manage roles'
  $permissions['node:community_of_practice:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:subscribe'
  $permissions['node:community_of_practice:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:subscribe without approval'
  $permissions['node:community_of_practice:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:unsubscribe'
  $permissions['node:community_of_practice:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any discussion content'
  $permissions['node:community_of_practice:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any document content'
  $permissions['node:community_of_practice:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update group'
  $permissions['node:community_of_practice:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own discussion content'
  $permissions['node:community_of_practice:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own document content'
  $permissions['node:community_of_practice:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:add user'
  $permissions['node:geographic_region:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:administer group'
  $permissions['node:geographic_region:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:approve and deny subscription'
  $permissions['node:geographic_region:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:create discussion content'
  $permissions['node:geographic_region:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:create document content'
  $permissions['node:geographic_region:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any discussion content'
  $permissions['node:geographic_region:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any document content'
  $permissions['node:geographic_region:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own discussion content'
  $permissions['node:geographic_region:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own document content'
  $permissions['node:geographic_region:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:manage members'
  $permissions['node:geographic_region:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:manage permissions'
  $permissions['node:geographic_region:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:manage roles'
  $permissions['node:geographic_region:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:subscribe'
  $permissions['node:geographic_region:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:geographic_region:subscribe without approval'
  $permissions['node:geographic_region:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:geographic_region:unsubscribe'
  $permissions['node:geographic_region:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any discussion content'
  $permissions['node:geographic_region:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any document content'
  $permissions['node:geographic_region:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update group'
  $permissions['node:geographic_region:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own discussion content'
  $permissions['node:geographic_region:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own document content'
  $permissions['node:geographic_region:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:add user'
  $permissions['node:hub:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:administer group'
  $permissions['node:hub:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:approve and deny subscription'
  $permissions['node:hub:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:create discussion content'
  $permissions['node:hub:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:create document content'
  $permissions['node:hub:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:delete any discussion content'
  $permissions['node:hub:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete any document content'
  $permissions['node:hub:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete own discussion content'
  $permissions['node:hub:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:delete own document content'
  $permissions['node:hub:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:manage members'
  $permissions['node:hub:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:manage permissions'
  $permissions['node:hub:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:manage roles'
  $permissions['node:hub:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:subscribe'
  $permissions['node:hub:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:hub:subscribe without approval'
  $permissions['node:hub:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:hub:unsubscribe'
  $permissions['node:hub:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:update any discussion content'
  $permissions['node:hub:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update any document content'
  $permissions['node:hub:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update group'
  $permissions['node:hub:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update own discussion content'
  $permissions['node:hub:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:update own document content'
  $permissions['node:hub:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:add user'
  $permissions['node:response:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:administer group'
  $permissions['node:response:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:approve and deny subscription'
  $permissions['node:response:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:create discussion content'
  $permissions['node:response:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:create document content'
  $permissions['node:response:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:delete any discussion content'
  $permissions['node:response:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete any document content'
  $permissions['node:response:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete own discussion content'
  $permissions['node:response:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:delete own document content'
  $permissions['node:response:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:manage members'
  $permissions['node:response:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:manage permissions'
  $permissions['node:response:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:manage roles'
  $permissions['node:response:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:subscribe'
  $permissions['node:response:subscribe'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:response:subscribe without approval'
  $permissions['node:response:subscribe without approval'] = array(
    'roles' => array(
      'non-member' => 'non-member',
    ),
  );

  // Exported og permission: 'node:response:unsubscribe'
  $permissions['node:response:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:update any discussion content'
  $permissions['node:response:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update any document content'
  $permissions['node:response:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update group'
  $permissions['node:response:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update own discussion content'
  $permissions['node:response:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:update own document content'
  $permissions['node:response:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:add user'
  $permissions['node:strategic_advisory:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:administer group'
  $permissions['node:strategic_advisory:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:approve and deny subscription'
  $permissions['node:strategic_advisory:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create discussion content'
  $permissions['node:strategic_advisory:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create document content'
  $permissions['node:strategic_advisory:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any discussion content'
  $permissions['node:strategic_advisory:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any document content'
  $permissions['node:strategic_advisory:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own discussion content'
  $permissions['node:strategic_advisory:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own document content'
  $permissions['node:strategic_advisory:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:manage members'
  $permissions['node:strategic_advisory:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:manage permissions'
  $permissions['node:strategic_advisory:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:manage roles'
  $permissions['node:strategic_advisory:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:subscribe'
  $permissions['node:strategic_advisory:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:subscribe without approval'
  $permissions['node:strategic_advisory:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:unsubscribe'
  $permissions['node:strategic_advisory:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update any discussion content'
  $permissions['node:strategic_advisory:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update any document content'
  $permissions['node:strategic_advisory:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update group'
  $permissions['node:strategic_advisory:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own discussion content'
  $permissions['node:strategic_advisory:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own document content'
  $permissions['node:strategic_advisory:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:add user'
  $permissions['node:working_group:add user'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:administer group'
  $permissions['node:working_group:administer group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:approve and deny subscription'
  $permissions['node:working_group:approve and deny subscription'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:create discussion content'
  $permissions['node:working_group:create discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:create document content'
  $permissions['node:working_group:create document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any discussion content'
  $permissions['node:working_group:delete any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any document content'
  $permissions['node:working_group:delete any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own discussion content'
  $permissions['node:working_group:delete own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own document content'
  $permissions['node:working_group:delete own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:manage members'
  $permissions['node:working_group:manage members'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage permissions'
  $permissions['node:working_group:manage permissions'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:manage roles'
  $permissions['node:working_group:manage roles'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:subscribe'
  $permissions['node:working_group:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:subscribe without approval'
  $permissions['node:working_group:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:unsubscribe'
  $permissions['node:working_group:unsubscribe'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update any discussion content'
  $permissions['node:working_group:update any discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update any document content'
  $permissions['node:working_group:update any document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update group'
  $permissions['node:working_group:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update own discussion content'
  $permissions['node:working_group:update own discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update own document content'
  $permissions['node:working_group:update own document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  return $permissions;
}
