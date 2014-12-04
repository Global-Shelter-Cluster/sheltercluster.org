<?php
/**
 * @file
 * cluster_docs.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cluster_docs_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Meeting Management',
    'description' => 'Meeting minutes, agendas, attendence lists, or presentations made at a meeting or event',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '06b0ac22-adb0-45ee-891a-b26a831ad2b3',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Strategy',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '95b289e4-950e-4d64-bd7f-21dcc750e623',
    'vocabulary_machine_name' => 'coordination_management',
  );
  return $terms;
}
