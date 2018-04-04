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
      0 => 'og_group_ref',
      1 => 'body',
      2 => 'field_date',
      3 => 'title',
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
      0 => 'group_indicators',
      1 => 'group_factsheet',
      2 => 'group_photos',
      3 => 'group_details',
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
  $field_group->identifier = 'group_indicators|node|factsheet|form';
  $field_group->group_name = 'group_indicators';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'factsheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fields';
  $field_group->data = array(
    'label' => 'Indicators',
    'weight' => '18',
    'children' => array(
      0 => 'field_fsi_partners',
      1 => 'field_fsi_people_targeted',
      2 => 'field_fsi_people_reached',
      3 => 'field_fsi_funding_required',
      4 => 'field_fsi_funded',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_indicators|node|factsheet|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Factsheet');
  t('Fields');
  t('Indicators');

  return $field_groups;
}
