<?php
/**
 * @file
 * cluster_kobo.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cluster_kobo_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_kobo_form_url'.
  $field_bases['field_kobo_form_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_kobo_form_url',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'url',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'url',
  );

  return $field_bases;
}