<?php
/**
 * @file
 * cluster_photo_gallery.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_photo_gallery_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_caption|field_collection_item|field_photos|default';
  $field_group->group_name = 'group_caption';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_photos';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_caption',
      1 => 'field_author',
      2 => 'field_taken',
    ),
    'format_type' => 'html-element',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'element-invisible',
        'element' => 'div',
        'show_label' => '0',
        'label_element' => 'div',
        'attributes' => '',
      ),
    ),
  );
  $field_groups['group_caption|field_collection_item|field_photos|default'] = $field_group;

  return $field_groups;
}
