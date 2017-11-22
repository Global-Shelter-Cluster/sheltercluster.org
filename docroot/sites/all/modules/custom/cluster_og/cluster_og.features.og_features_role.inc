<?php
/**
 * @file
 * cluster_og.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function cluster_og_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:geographic_region:contact member'.
  $roles['node:geographic_region:contact member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'geographic_region',
    'name' => 'contact member',
  );

  // Exported OG Role: 'node:geographic_region:content editor'.
  $roles['node:geographic_region:content editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'geographic_region',
    'name' => 'content editor',
  );

  // Exported OG Role: 'node:hub:contact member'.
  $roles['node:hub:contact member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hub',
    'name' => 'contact member',
  );

  // Exported OG Role: 'node:hub:content editor'.
  $roles['node:hub:content editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'hub',
    'name' => 'content editor',
  );

  // Exported OG Role: 'node:response:contact member'.
  $roles['node:response:contact member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'response',
    'name' => 'contact member',
  );

  // Exported OG Role: 'node:response:content editor'.
  $roles['node:response:content editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'response',
    'name' => 'content editor',
  );

  // Exported OG Role: 'node:strategic_advisory:contact member'.
  $roles['node:strategic_advisory:contact member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'strategic_advisory',
    'name' => 'contact member',
  );

  // Exported OG Role: 'node:strategic_advisory:content editor'.
  $roles['node:strategic_advisory:content editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'strategic_advisory',
    'name' => 'content editor',
  );

  // Exported OG Role: 'node:working_group:contact member'.
  $roles['node:working_group:contact member'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'working_group',
    'name' => 'contact member',
  );

  // Exported OG Role: 'node:working_group:content editor'.
  $roles['node:working_group:content editor'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'working_group',
    'name' => 'content editor',
  );

  return $roles;
}
