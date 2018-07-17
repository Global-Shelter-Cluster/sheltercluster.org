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

  // Exported og permission: 'node:community_of_practice:create arbitrary_library content'
  $permissions['node:community_of_practice:create arbitrary_library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:create contact content'
  $permissions['node:community_of_practice:create contact content'] = array(
    'roles' => array(
      'member' => 'member',
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

  // Exported og permission: 'node:community_of_practice:create event content'
  $permissions['node:community_of_practice:create event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:create kobo_form content'
  $permissions['node:community_of_practice:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:create library content'
  $permissions['node:community_of_practice:create library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:create page content'
  $permissions['node:community_of_practice:create page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any arbitrary_library content'
  $permissions['node:community_of_practice:delete any arbitrary_library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any contact content'
  $permissions['node:community_of_practice:delete any contact content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any discussion content'
  $permissions['node:community_of_practice:delete any discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any document content'
  $permissions['node:community_of_practice:delete any document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any event content'
  $permissions['node:community_of_practice:delete any event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any kobo_form content'
  $permissions['node:community_of_practice:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete any library content'
  $permissions['node:community_of_practice:delete any library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete any page content'
  $permissions['node:community_of_practice:delete any page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own arbitrary_library content'
  $permissions['node:community_of_practice:delete own arbitrary_library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own contact content'
  $permissions['node:community_of_practice:delete own contact content'] = array(
    'roles' => array(
      'member' => 'member',
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

  // Exported og permission: 'node:community_of_practice:delete own event content'
  $permissions['node:community_of_practice:delete own event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own kobo_form content'
  $permissions['node:community_of_practice:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:delete own library content'
  $permissions['node:community_of_practice:delete own library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:delete own page content'
  $permissions['node:community_of_practice:delete own page content'] = array(
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
    'roles' => array(
      'non-member' => 'non-member',
    ),
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

  // Exported og permission: 'node:community_of_practice:update any arbitrary_library content'
  $permissions['node:community_of_practice:update any arbitrary_library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any contact content'
  $permissions['node:community_of_practice:update any contact content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any discussion content'
  $permissions['node:community_of_practice:update any discussion content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any document content'
  $permissions['node:community_of_practice:update any document content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any event content'
  $permissions['node:community_of_practice:update any event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any kobo_form content'
  $permissions['node:community_of_practice:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update any library content'
  $permissions['node:community_of_practice:update any library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update any page content'
  $permissions['node:community_of_practice:update any page content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update group'
  $permissions['node:community_of_practice:update group'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own arbitrary_library content'
  $permissions['node:community_of_practice:update own arbitrary_library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own contact content'
  $permissions['node:community_of_practice:update own contact content'] = array(
    'roles' => array(
      'member' => 'member',
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

  // Exported og permission: 'node:community_of_practice:update own event content'
  $permissions['node:community_of_practice:update own event content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own kobo_form content'
  $permissions['node:community_of_practice:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:community_of_practice:update own library content'
  $permissions['node:community_of_practice:update own library content'] = array(
    'roles' => array(
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:community_of_practice:update own page content'
  $permissions['node:community_of_practice:update own page content'] = array(
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

  // Exported og permission: 'node:geographic_region:create arbitrary_library content'
  $permissions['node:geographic_region:create arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:create contact content'
  $permissions['node:geographic_region:create contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:create discussion content'
  $permissions['node:geographic_region:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:create document content'
  $permissions['node:geographic_region:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:create event content'
  $permissions['node:geographic_region:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:create kobo_form content'
  $permissions['node:geographic_region:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:create library content'
  $permissions['node:geographic_region:create library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:create page content'
  $permissions['node:geographic_region:create page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any arbitrary_library content'
  $permissions['node:geographic_region:delete any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any contact content'
  $permissions['node:geographic_region:delete any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:geographic_region:delete any event content'
  $permissions['node:geographic_region:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any kobo_form content'
  $permissions['node:geographic_region:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete any library content'
  $permissions['node:geographic_region:delete any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete any page content'
  $permissions['node:geographic_region:delete any page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own arbitrary_library content'
  $permissions['node:geographic_region:delete own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own contact content'
  $permissions['node:geographic_region:delete own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own discussion content'
  $permissions['node:geographic_region:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own document content'
  $permissions['node:geographic_region:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own event content'
  $permissions['node:geographic_region:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own kobo_form content'
  $permissions['node:geographic_region:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:delete own library content'
  $permissions['node:geographic_region:delete own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:delete own page content'
  $permissions['node:geographic_region:delete own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:geographic_region:update any arbitrary_library content'
  $permissions['node:geographic_region:update any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any contact content'
  $permissions['node:geographic_region:update any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:geographic_region:update any event content'
  $permissions['node:geographic_region:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any kobo_form content'
  $permissions['node:geographic_region:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update any library content'
  $permissions['node:geographic_region:update any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update any page content'
  $permissions['node:geographic_region:update any page content'] = array(
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

  // Exported og permission: 'node:geographic_region:update own arbitrary_library content'
  $permissions['node:geographic_region:update own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own contact content'
  $permissions['node:geographic_region:update own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own discussion content'
  $permissions['node:geographic_region:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own document content'
  $permissions['node:geographic_region:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own event content'
  $permissions['node:geographic_region:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own kobo_form content'
  $permissions['node:geographic_region:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:geographic_region:update own library content'
  $permissions['node:geographic_region:update own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:geographic_region:update own page content'
  $permissions['node:geographic_region:update own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:hub:create arbitrary_library content'
  $permissions['node:hub:create arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:create contact content'
  $permissions['node:hub:create contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:create discussion content'
  $permissions['node:hub:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:create document content'
  $permissions['node:hub:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:create event content'
  $permissions['node:hub:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:create kobo_form content'
  $permissions['node:hub:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:create library content'
  $permissions['node:hub:create library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:create page content'
  $permissions['node:hub:create page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete any arbitrary_library content'
  $permissions['node:hub:delete any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete any contact content'
  $permissions['node:hub:delete any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:hub:delete any event content'
  $permissions['node:hub:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete any kobo_form content'
  $permissions['node:hub:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete any library content'
  $permissions['node:hub:delete any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete any page content'
  $permissions['node:hub:delete any page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:delete own arbitrary_library content'
  $permissions['node:hub:delete own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:delete own contact content'
  $permissions['node:hub:delete own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:delete own discussion content'
  $permissions['node:hub:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:delete own document content'
  $permissions['node:hub:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:delete own event content'
  $permissions['node:hub:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:delete own kobo_form content'
  $permissions['node:hub:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:delete own library content'
  $permissions['node:hub:delete own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:delete own page content'
  $permissions['node:hub:delete own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:hub:update any arbitrary_library content'
  $permissions['node:hub:update any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update any contact content'
  $permissions['node:hub:update any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:hub:update any event content'
  $permissions['node:hub:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update any kobo_form content'
  $permissions['node:hub:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update any library content'
  $permissions['node:hub:update any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:hub:update any page content'
  $permissions['node:hub:update any page content'] = array(
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

  // Exported og permission: 'node:hub:update own arbitrary_library content'
  $permissions['node:hub:update own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:update own contact content'
  $permissions['node:hub:update own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:update own discussion content'
  $permissions['node:hub:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:update own document content'
  $permissions['node:hub:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:hub:update own event content'
  $permissions['node:hub:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:update own kobo_form content'
  $permissions['node:hub:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:hub:update own library content'
  $permissions['node:hub:update own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:hub:update own page content'
  $permissions['node:hub:update own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:response:create arbitrary_library content'
  $permissions['node:response:create arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:create contact content'
  $permissions['node:response:create contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:create discussion content'
  $permissions['node:response:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:create document content'
  $permissions['node:response:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:create event content'
  $permissions['node:response:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:create kobo_form content'
  $permissions['node:response:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:create library content'
  $permissions['node:response:create library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:create page content'
  $permissions['node:response:create page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete any arbitrary_library content'
  $permissions['node:response:delete any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete any contact content'
  $permissions['node:response:delete any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:response:delete any event content'
  $permissions['node:response:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete any kobo_form content'
  $permissions['node:response:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete any library content'
  $permissions['node:response:delete any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete any page content'
  $permissions['node:response:delete any page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:delete own arbitrary_library content'
  $permissions['node:response:delete own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:delete own contact content'
  $permissions['node:response:delete own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:delete own discussion content'
  $permissions['node:response:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:delete own document content'
  $permissions['node:response:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:delete own event content'
  $permissions['node:response:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:delete own kobo_form content'
  $permissions['node:response:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:delete own library content'
  $permissions['node:response:delete own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:delete own page content'
  $permissions['node:response:delete own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:response:update any arbitrary_library content'
  $permissions['node:response:update any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update any contact content'
  $permissions['node:response:update any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:response:update any event content'
  $permissions['node:response:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update any kobo_form content'
  $permissions['node:response:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update any library content'
  $permissions['node:response:update any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:response:update any page content'
  $permissions['node:response:update any page content'] = array(
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

  // Exported og permission: 'node:response:update own arbitrary_library content'
  $permissions['node:response:update own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:update own contact content'
  $permissions['node:response:update own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:update own discussion content'
  $permissions['node:response:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:update own document content'
  $permissions['node:response:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:response:update own event content'
  $permissions['node:response:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:update own kobo_form content'
  $permissions['node:response:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:response:update own library content'
  $permissions['node:response:update own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:response:update own page content'
  $permissions['node:response:update own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:strategic_advisory:create arbitrary_library content'
  $permissions['node:strategic_advisory:create arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create contact content'
  $permissions['node:strategic_advisory:create contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create discussion content'
  $permissions['node:strategic_advisory:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create document content'
  $permissions['node:strategic_advisory:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create event content'
  $permissions['node:strategic_advisory:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create kobo_form content'
  $permissions['node:strategic_advisory:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:create library content'
  $permissions['node:strategic_advisory:create library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:create page content'
  $permissions['node:strategic_advisory:create page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any arbitrary_library content'
  $permissions['node:strategic_advisory:delete any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any contact content'
  $permissions['node:strategic_advisory:delete any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:strategic_advisory:delete any event content'
  $permissions['node:strategic_advisory:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any kobo_form content'
  $permissions['node:strategic_advisory:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete any library content'
  $permissions['node:strategic_advisory:delete any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete any page content'
  $permissions['node:strategic_advisory:delete any page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own arbitrary_library content'
  $permissions['node:strategic_advisory:delete own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own contact content'
  $permissions['node:strategic_advisory:delete own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own discussion content'
  $permissions['node:strategic_advisory:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own document content'
  $permissions['node:strategic_advisory:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own event content'
  $permissions['node:strategic_advisory:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own kobo_form content'
  $permissions['node:strategic_advisory:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:delete own library content'
  $permissions['node:strategic_advisory:delete own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:delete own page content'
  $permissions['node:strategic_advisory:delete own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:strategic_advisory:update any arbitrary_library content'
  $permissions['node:strategic_advisory:update any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update any contact content'
  $permissions['node:strategic_advisory:update any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:strategic_advisory:update any event content'
  $permissions['node:strategic_advisory:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update any kobo_form content'
  $permissions['node:strategic_advisory:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update any library content'
  $permissions['node:strategic_advisory:update any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update any page content'
  $permissions['node:strategic_advisory:update any page content'] = array(
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

  // Exported og permission: 'node:strategic_advisory:update own arbitrary_library content'
  $permissions['node:strategic_advisory:update own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own contact content'
  $permissions['node:strategic_advisory:update own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own discussion content'
  $permissions['node:strategic_advisory:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own document content'
  $permissions['node:strategic_advisory:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own event content'
  $permissions['node:strategic_advisory:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own kobo_form content'
  $permissions['node:strategic_advisory:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:strategic_advisory:update own library content'
  $permissions['node:strategic_advisory:update own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:strategic_advisory:update own page content'
  $permissions['node:strategic_advisory:update own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:working_group:create arbitrary_library content'
  $permissions['node:working_group:create arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:create contact content'
  $permissions['node:working_group:create contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:create discussion content'
  $permissions['node:working_group:create discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:create document content'
  $permissions['node:working_group:create document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:create event content'
  $permissions['node:working_group:create event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:create kobo_form content'
  $permissions['node:working_group:create kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:create library content'
  $permissions['node:working_group:create library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:create page content'
  $permissions['node:working_group:create page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any arbitrary_library content'
  $permissions['node:working_group:delete any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any contact content'
  $permissions['node:working_group:delete any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:working_group:delete any event content'
  $permissions['node:working_group:delete any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any kobo_form content'
  $permissions['node:working_group:delete any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete any library content'
  $permissions['node:working_group:delete any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete any page content'
  $permissions['node:working_group:delete any page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own arbitrary_library content'
  $permissions['node:working_group:delete own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:delete own contact content'
  $permissions['node:working_group:delete own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:delete own discussion content'
  $permissions['node:working_group:delete own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own document content'
  $permissions['node:working_group:delete own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:delete own event content'
  $permissions['node:working_group:delete own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:delete own kobo_form content'
  $permissions['node:working_group:delete own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:delete own library content'
  $permissions['node:working_group:delete own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:delete own page content'
  $permissions['node:working_group:delete own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:working_group:update any arbitrary_library content'
  $permissions['node:working_group:update any arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update any contact content'
  $permissions['node:working_group:update any contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
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

  // Exported og permission: 'node:working_group:update any event content'
  $permissions['node:working_group:update any event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update any kobo_form content'
  $permissions['node:working_group:update any kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update any library content'
  $permissions['node:working_group:update any library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  // Exported og permission: 'node:working_group:update any page content'
  $permissions['node:working_group:update any page content'] = array(
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

  // Exported og permission: 'node:working_group:update own arbitrary_library content'
  $permissions['node:working_group:update own arbitrary_library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:update own contact content'
  $permissions['node:working_group:update own contact content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:update own discussion content'
  $permissions['node:working_group:update own discussion content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update own document content'
  $permissions['node:working_group:update own document content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'member' => 'member',
    ),
  );

  // Exported og permission: 'node:working_group:update own event content'
  $permissions['node:working_group:update own event content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:update own kobo_form content'
  $permissions['node:working_group:update own kobo_form content'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:working_group:update own library content'
  $permissions['node:working_group:update own library content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
      'content editor' => 'content editor',
    ),
  );

  // Exported og permission: 'node:working_group:update own page content'
  $permissions['node:working_group:update own page content'] = array(
    'roles' => array(
      'administrator member' => 'administrator member',
    ),
  );

  return $permissions;
}
