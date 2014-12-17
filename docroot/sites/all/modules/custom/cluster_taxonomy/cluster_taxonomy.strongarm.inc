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
    'assessment_monitoring_evaluation' => 'assessment_monitoring_evaluation',
    'coordination_management' => 'coordination_management',
    'cross_cutting_issues' => 'cross_cutting_issues',
    'disaster_causes' => 'disaster_causes',
    'disaster_onset' => 'disaster_onset',
    'disaster_type' => 'disaster_type',
    'information_management' => 'information_management',
    'inter_cluster' => 'inter_cluster',
    'intervention_materials' => 'intervention_materials',
    'intervention_programming' => 'intervention_programming',
    'issues' => 'issues',
    'non_food_items' => 'non_food_items',
    'response_phase' => 'response_phase',
    'settlement_type' => 'settlement_type',
    'technical_support_design' => 'technical_support_design',
    'toolkit' => 'toolkit',
    'geographic_region_type' => 'geographic_region_type',
    'tags' => 0,
  );
  $export['uuid_features_entity_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_file_taxonomy_term';
  $strongarm->value = array(
    'tags' => 0,
    'assessment_monitoring_evaluation' => 0,
    'coordination_management' => 0,
    'cross_cutting_issues' => 0,
    'disaster_causes' => 0,
    'disaster_onset' => 0,
    'disaster_type' => 0,
    'information_management' => 0,
    'inter_cluster' => 0,
    'intervention_materials' => 0,
    'intervention_programming' => 0,
    'issues' => 0,
    'non_food_items' => 0,
    'response_phase' => 0,
    'settlement_type' => 0,
    'technical_support_design' => 0,
    'toolkit' => 0,
    'geographic_region_type' => 0,
  );
  $export['uuid_features_file_taxonomy_term'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uuid_features_vocabulary_terms';
  $strongarm->value = 1;
  $export['uuid_features_vocabulary_terms'] = $strongarm;

  return $export;
}
