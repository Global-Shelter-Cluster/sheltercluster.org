<?php
/**
 * @file
 * cluster_docs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_docs_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced_tags|node|document|form';
  $field_group->group_name = 'group_advanced_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced tags',
    'weight' => '23',
    'children' => array(
      0 => 'field_inter_cluster',
      1 => 'field_cross_cutting_issues',
      2 => 'field_response_phase',
      3 => 'field_intervention_materials',
      4 => 'field_intervention_programming',
      5 => 'field_settlement_type',
      6 => 'field_non_food_items',
      7 => 'field_issues',
      8 => 'field_toolkit',
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
  $export['group_advanced_tags|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_tags|node|document|form';
  $field_group->group_name = 'group_basic_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic tags',
    'weight' => '22',
    'children' => array(
      0 => 'field_information_management',
      1 => 'field_assess_monitor_eval',
      2 => 'field_technical_support_design',
      3 => 'field_coordination_management',
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
  $export['group_basic_tags|node|document|form'] = $field_group;

  return $export;
}
