<?php
/**
 * @file
 * cluster_taxonomy.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cluster_taxonomy_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_entity_taxonomy_term';
  $strongarm->value = array(
    'disaster_type' => 'disaster_type',
    'disaster_causes' => 'disaster_causes',
    'information_management' => 'information_management',
    'assessment_monitoring_evaluation' => 'assessment_monitoring_evaluation',
    'technical_support_design' => 'technical_support_design',
    'inter_cluster' => 'inter_cluster',
    'cross_cutting_issues' => 'cross_cutting_issues',
    'response_phase' => 'response_phase',
    'intervention_materials' => 'intervention_materials',
    'intervention_programming' => 'intervention_programming',
    'settlement_type' => 'settlement_type',
    'non_food_items' => 'non_food_items',
    'issues' => 'issues',
    'toolkit' => 'toolkit',
    'disaster_onset' => 'disaster_onset',
    'coordination_management' => 'coordination_management',
    'tags' => 0,
  );
  $export['uuid_features_entity_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_vocabulary_terms';
  $strongarm->value = 0;
  $export['uuid_features_vocabulary_terms'] = $strongarm;

  return $export;
}
