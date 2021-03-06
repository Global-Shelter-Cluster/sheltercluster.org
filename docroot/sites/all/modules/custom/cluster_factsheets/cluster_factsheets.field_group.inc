<?php
/**
 * @file
 * cluster_factsheets.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_factsheets_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|factsheet|form';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '17',
    'children' => array(
      0 => 'field_fs_response',
      1 => 'field_gaps_challenges',
      2 => 'field_need_analysis',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_details|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_factsheet|node|factsheet|form';
  $field_group->group_name = 'group_factsheet';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Factsheet',
    'weight' => '15',
    'children' => array(
      0 => 'body',
      1 => 'field_date',
      2 => 'og_group_ref',
      3 => 'field_factsheet_is_visible',
      4 => 'field_factsheet_is_data_exported',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-factsheet field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_factsheet|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fields|node|factsheet|form';
  $field_group->group_name = 'group_fields';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Fields',
    'weight' => '2',
    'children' => array(
      0 => 'group_details',
      1 => 'group_factsheet',
      2 => 'group_indicators',
      3 => 'group_photos',
      4 => 'group_sidebar',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-fields field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fields|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fsi_funding|node|factsheet|form';
  $field_group->group_name = 'group_fsi_funding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_funding';
  $field_group->data = array(
    'label' => 'Funding inline fields',
    'weight' => '27',
    'children' => array(
      0 => 'field_fsi_funded',
      1 => 'field_fsi_funding_required',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Funding inline fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-inline',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_fsi_funding|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fsi_global|node|factsheet|form';
  $field_group->group_name = 'group_fsi_global';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indicators';
  $field_group->data = array(
    'label' => 'Global',
    'weight' => '19',
    'children' => array(
      0 => 'field_fsi_in_need',
      1 => 'field_fsi_targeted',
      2 => 'field_fsi_reached',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Global',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-inline',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_fsi_global|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fsi_nfi|node|factsheet|form';
  $field_group->group_name = 'group_fsi_nfi';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indicators';
  $field_group->data = array(
    'label' => 'NFI (Total)',
    'weight' => '20',
    'children' => array(
      0 => 'field_fsi_nfi_targeted',
      1 => 'field_fsi_nfi_reached',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'NFI (Total)',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-inline',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_fsi_nfi|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fsi_shelter|node|factsheet|form';
  $field_group->group_name = 'group_fsi_shelter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indicators';
  $field_group->data = array(
    'label' => 'Shelter (Total)',
    'weight' => '21',
    'children' => array(
      0 => 'field_fsi_shelter_targeted',
      1 => 'field_fsi_shelter_reached',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Shelter (Total)',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-inline',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_fsi_shelter|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_funding|node|factsheet|form';
  $field_group->group_name = 'group_funding';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indicators';
  $field_group->data = array(
    'label' => 'Funding',
    'weight' => '23',
    'children' => array(
      0 => 'field_funding_source',
      1 => 'group_fsi_funding',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Funding',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-funding field-group-fieldset',
        'description' => 'Provide information on the funding status based on your cluster appeal and OCHA’s Financial Tracking Service (if you use other sources do not forget to mention them).',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_funding|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_hh|node|factsheet|form';
  $field_group->group_name = 'group_hh';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_indicators';
  $field_group->data = array(
    'label' => 'Individual people / households',
    'weight' => '17',
    'children' => array(
      0 => 'field_household_figures',
      1 => 'field_people_per_household',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Individual people / households',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-hh field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_hh|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_indicators|node|factsheet|form';
  $field_group->group_name = 'group_indicators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Figures',
    'weight' => '19',
    'children' => array(
      0 => 'field_coverage_against_targets',
      1 => 'field_fsi_partners',
      2 => 'group_funding',
      3 => 'group_hh',
      4 => 'group_fsi_global',
      5 => 'group_fsi_nfi',
      6 => 'group_fsi_shelter',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Figures',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_indicators|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_inline|field_collection_item|field_coverage_against_targets|form';
  $field_group->group_name = 'group_inline';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_coverage_against_targets';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Inline fields',
    'weight' => '2',
    'children' => array(
      0 => 'field_cat_ongoing',
      1 => 'field_cat_planned',
      2 => 'field_cat_reached',
      3 => 'field_cat_targeted',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => 'Inline fields',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-inline',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_inline|field_collection_item|field_coverage_against_targets|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photos|node|factsheet|form';
  $field_group->group_name = 'group_photos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Photos',
    'weight' => '16',
    'children' => array(
      0 => 'field_image',
      1 => 'field_map',
      2 => 'field_photo_credit',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-photos field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_photos|node|factsheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|factsheet|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '18',
    'children' => array(
      0 => 'field_key_dates',
      1 => 'field_key_documents',
      2 => 'field_key_links',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-sidebar field-group-tab',
        'description' => 'Provide links to key documents and websites as well as key figures on the number of cluster partners (based on cluster 3W) and people in need / targeted (based on cluster strategy).',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_sidebar|node|factsheet|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Details');
  t('Factsheet');
  t('Fields');
  t('Figures');
  t('Funding');
  t('Funding inline fields');
  t('Global');
  t('Individual people / households');
  t('Inline fields');
  t('NFI (Total)');
  t('Photos');
  t('Shelter (Total)');
  t('Sidebar');

  return $field_groups;
}
