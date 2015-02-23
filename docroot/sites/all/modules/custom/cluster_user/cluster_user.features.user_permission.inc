<?php
/**
 * @file
 * cluster_user.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function cluster_user_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access devel information'.
  $permissions['access devel information'] = array(
    'name' => 'access devel information',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer group'.
  $permissions['administer group'] = array(
    'name' => 'administer group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'og',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer respondjs'.
  $permissions['administer respondjs'] = array(
    'name' => 'administer respondjs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'respondjs',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer uuid'.
  $permissions['administer uuid'] = array(
    'name' => 'administer uuid',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'uuid',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'create arbitrary_library content'.
  $permissions['create arbitrary_library content'] = array(
    'name' => 'create arbitrary_library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create contact content'.
  $permissions['create contact content'] = array(
    'name' => 'create contact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_featured'.
  $permissions['create field_featured'] = array(
    'name' => 'create field_featured',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_key_document'.
  $permissions['create field_key_document'] = array(
    'name' => 'create field_key_document',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create library content'.
  $permissions['create library content'] = array(
    'name' => 'create library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create nodes without cluster context'.
  $permissions['create nodes without cluster context'] = array(
    'name' => 'create nodes without cluster context',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'cluster_context',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete any arbitrary_library content'.
  $permissions['delete any arbitrary_library content'] = array(
    'name' => 'delete any arbitrary_library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact content'.
  $permissions['delete any contact content'] = array(
    'name' => 'delete any contact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any library content'.
  $permissions['delete any library content'] = array(
    'name' => 'delete any library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own arbitrary_library content'.
  $permissions['delete own arbitrary_library content'] = array(
    'name' => 'delete own arbitrary_library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact content'.
  $permissions['delete own contact content'] = array(
    'name' => 'delete own contact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own library content'.
  $permissions['delete own library content'] = array(
    'name' => 'delete own library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in assessment_monitoring_evaluation'.
  $permissions['delete terms in assessment_monitoring_evaluation'] = array(
    'name' => 'delete terms in assessment_monitoring_evaluation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in coordination_management'.
  $permissions['delete terms in coordination_management'] = array(
    'name' => 'delete terms in coordination_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in cross_cutting_issues'.
  $permissions['delete terms in cross_cutting_issues'] = array(
    'name' => 'delete terms in cross_cutting_issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in disaster_causes'.
  $permissions['delete terms in disaster_causes'] = array(
    'name' => 'delete terms in disaster_causes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in disaster_onset'.
  $permissions['delete terms in disaster_onset'] = array(
    'name' => 'delete terms in disaster_onset',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in disaster_type'.
  $permissions['delete terms in disaster_type'] = array(
    'name' => 'delete terms in disaster_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in document_type'.
  $permissions['delete terms in document_type'] = array(
    'name' => 'delete terms in document_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in geographic_region_type'.
  $permissions['delete terms in geographic_region_type'] = array(
    'name' => 'delete terms in geographic_region_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in information_management'.
  $permissions['delete terms in information_management'] = array(
    'name' => 'delete terms in information_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in inter_cluster'.
  $permissions['delete terms in inter_cluster'] = array(
    'name' => 'delete terms in inter_cluster',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in intervention_materials'.
  $permissions['delete terms in intervention_materials'] = array(
    'name' => 'delete terms in intervention_materials',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in intervention_programming'.
  $permissions['delete terms in intervention_programming'] = array(
    'name' => 'delete terms in intervention_programming',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in issues'.
  $permissions['delete terms in issues'] = array(
    'name' => 'delete terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in meeting_management'.
  $permissions['delete terms in meeting_management'] = array(
    'name' => 'delete terms in meeting_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in non_food_items'.
  $permissions['delete terms in non_food_items'] = array(
    'name' => 'delete terms in non_food_items',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in response_phase'.
  $permissions['delete terms in response_phase'] = array(
    'name' => 'delete terms in response_phase',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in settlement_type'.
  $permissions['delete terms in settlement_type'] = array(
    'name' => 'delete terms in settlement_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in technical_support_design'.
  $permissions['delete terms in technical_support_design'] = array(
    'name' => 'delete terms in technical_support_design',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in toolkit'.
  $permissions['delete terms in toolkit'] = array(
    'name' => 'delete terms in toolkit',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'edit any arbitrary_library content'.
  $permissions['edit any arbitrary_library content'] = array(
    'name' => 'edit any arbitrary_library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any contact content'.
  $permissions['edit any contact content'] = array(
    'name' => 'edit any contact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any library content'.
  $permissions['edit any library content'] = array(
    'name' => 'edit any library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_featured'.
  $permissions['edit field_featured'] = array(
    'name' => 'edit field_featured',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_key_document'.
  $permissions['edit field_key_document'] = array(
    'name' => 'edit field_key_document',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own arbitrary_library content'.
  $permissions['edit own arbitrary_library content'] = array(
    'name' => 'edit own arbitrary_library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own contact content'.
  $permissions['edit own contact content'] = array(
    'name' => 'edit own contact content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_featured'.
  $permissions['edit own field_featured'] = array(
    'name' => 'edit own field_featured',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_key_document'.
  $permissions['edit own field_key_document'] = array(
    'name' => 'edit own field_key_document',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own library content'.
  $permissions['edit own library content'] = array(
    'name' => 'edit own library content',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in assessment_monitoring_evaluation'.
  $permissions['edit terms in assessment_monitoring_evaluation'] = array(
    'name' => 'edit terms in assessment_monitoring_evaluation',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in coordination_management'.
  $permissions['edit terms in coordination_management'] = array(
    'name' => 'edit terms in coordination_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in cross_cutting_issues'.
  $permissions['edit terms in cross_cutting_issues'] = array(
    'name' => 'edit terms in cross_cutting_issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in disaster_causes'.
  $permissions['edit terms in disaster_causes'] = array(
    'name' => 'edit terms in disaster_causes',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in disaster_onset'.
  $permissions['edit terms in disaster_onset'] = array(
    'name' => 'edit terms in disaster_onset',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in disaster_type'.
  $permissions['edit terms in disaster_type'] = array(
    'name' => 'edit terms in disaster_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in document_type'.
  $permissions['edit terms in document_type'] = array(
    'name' => 'edit terms in document_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in geographic_region_type'.
  $permissions['edit terms in geographic_region_type'] = array(
    'name' => 'edit terms in geographic_region_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in information_management'.
  $permissions['edit terms in information_management'] = array(
    'name' => 'edit terms in information_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in inter_cluster'.
  $permissions['edit terms in inter_cluster'] = array(
    'name' => 'edit terms in inter_cluster',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in intervention_materials'.
  $permissions['edit terms in intervention_materials'] = array(
    'name' => 'edit terms in intervention_materials',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in intervention_programming'.
  $permissions['edit terms in intervention_programming'] = array(
    'name' => 'edit terms in intervention_programming',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in issues'.
  $permissions['edit terms in issues'] = array(
    'name' => 'edit terms in issues',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in meeting_management'.
  $permissions['edit terms in meeting_management'] = array(
    'name' => 'edit terms in meeting_management',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in non_food_items'.
  $permissions['edit terms in non_food_items'] = array(
    'name' => 'edit terms in non_food_items',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in response_phase'.
  $permissions['edit terms in response_phase'] = array(
    'name' => 'edit terms in response_phase',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in settlement_type'.
  $permissions['edit terms in settlement_type'] = array(
    'name' => 'edit terms in settlement_type',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in technical_support_design'.
  $permissions['edit terms in technical_support_design'] = array(
    'name' => 'edit terms in technical_support_design',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in toolkit'.
  $permissions['edit terms in toolkit'] = array(
    'name' => 'edit terms in toolkit',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'execute php code'.
  $permissions['execute php code'] = array(
    'name' => 'execute php code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select text formats on context aware forms'.
  $permissions['select text formats on context aware forms'] = array(
    'name' => 'select text formats on context aware forms',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'cluster_context',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch users'.
  $permissions['switch users'] = array(
    'name' => 'switch users',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'devel',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view field_featured'.
  $permissions['view field_featured'] = array(
    'name' => 'view field_featured',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_key_document'.
  $permissions['view field_key_document'] = array(
    'name' => 'view field_key_document',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_featured'.
  $permissions['view own field_featured'] = array(
    'name' => 'view own field_featured',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_key_document'.
  $permissions['view own field_key_document'] = array(
    'name' => 'view own field_key_document',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
