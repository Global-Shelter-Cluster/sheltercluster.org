<?php
/**
 * @file
 * cluster_libraries.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_libraries_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced_tags|node|library|form';
  $field_group->group_name = 'group_advanced_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced tags',
    'weight' => '8',
    'children' => array(
      0 => 'field_assess_monitor_eval',
      1 => 'field_cross_cutting_issues',
      2 => 'field_inter_cluster',
      3 => 'field_intervention_materials',
      4 => 'field_intervention_programming',
      5 => 'field_issues',
      6 => 'field_non_food_items',
      7 => 'field_response_phase',
      8 => 'field_settlement_type',
      9 => 'field_toolkit',
      10 => 'field_meeting_management',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-advanced-tags field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_advanced_tags|node|library|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_tags|node|library|form';
  $field_group->group_name = 'group_basic_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'library';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic tags',
    'weight' => '7',
    'children' => array(
      0 => 'field_coordination_management',
      1 => 'field_information_management',
      2 => 'field_technical_support_design',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-tags field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_basic_tags|node|library|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced tags');
  t('Basic tags');

  return $field_groups;
}
