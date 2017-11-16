<?php

/**
 * This script will generate a report of document counts for each taxonomy term.
 */

$vocabularies = [
  'document_type',

  'coordination_management',
  'information_management',
  'technical_support_design',

  'assessment_monitoring_evaluation',
  'inter_cluster',
  'cross_cutting_issues',
  'response_phase',
  'intervention_materials',
  'intervention_programming',
  'settlement_type',
  'non_food_items',
  'issues',
  'toolkit',
  'meeting_management',

//  'disaster_causes',
//  'disaster_onset',
//  'disaster_type',
//  'geographic_region_type',
//  'tags',
];

$fields = array_filter(field_info_fields(), function($field) {
  return $field['type'] === 'taxonomy_term_reference'
    && isset($field['bundles']['node'])
    && in_array('document', $field['bundles']['node'])
    && isset($field['settings']['allowed_values'][0]);
});
$vocabulary_field_map = [];
foreach ($fields as $field_name => $field)
  $vocabulary_field_map[$field['settings']['allowed_values'][0]['vocabulary']] = $field_name;

foreach ($vocabularies as $vocabulary) {
  $v = taxonomy_vocabulary_machine_name_load($vocabulary);
  $out .= strtoupper($v->name).PHP_EOL;

  $query = new EntityFieldQuery();
  $result = $query->entityCondition('entity_type', 'taxonomy_term')
    ->entityCondition('bundle', $vocabulary)
    ->execute();
  $data = [];
  foreach ($result['taxonomy_term'] as $tid => $term) {
    $term = taxonomy_term_load($tid);

    $query = new EntityFieldQuery();
    $document_count = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition($vocabulary_field_map[$vocabulary], 'tid', $tid)
      ->count()
      ->execute();

    $data[$term->name] = $document_count;
  }

  arsort($data);
  foreach ($data as $term => $count)
    $out .= sprintf('%8d ', $count).$term.PHP_EOL;
}

dpm($out);
