<?php
/**
 * @file
 * cluster_paragraphs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_paragraphs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text|field_collection_item|field_team_members|default';
  $field_group->group_name = 'group_text';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_team_members';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_full_name',
      1 => 'field_organisation_name',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => '',
        'attributes' => '',
        'required_fields' => 1,
      ),
      'formatter' => '',
    ),
  );
  $field_groups['group_text|field_collection_item|field_team_members|default'] = $field_group;

  return $field_groups;
}
