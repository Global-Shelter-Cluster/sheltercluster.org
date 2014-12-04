<?php
/**
 * @file
 * cluster_taxonomy.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cluster_taxonomy_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Template',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '082341aa-3100-4d3e-8963-2dfb268aba81',
    'vocabulary_machine_name' => 'toolkit',
  );
  $terms[] = array(
    'name' => 'Natural Disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b53aeeb-f325-48f8-a9f7-f2a4d3dd4cd2',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Secondary Data Review',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3d20e159-f152-4fad-8f22-a8fa70a29b4b',
    'vocabulary_machine_name' => 'assessment_monitoring_evaluation',
  );
  $terms[] = array(
    'name' => 'Technical Guidance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3d32ad02-1b19-443e-a6bb-28484d1febca',
    'vocabulary_machine_name' => 'technical_support_design',
  );
  $terms[] = array(
    'name' => 'Meeting Management',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '51cbff1f-021a-43a1-8429-e66c958b98e1',
    'vocabulary_machine_name' => 'coordination_management',
  );
  $terms[] = array(
    'name' => 'Cold wave',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53527189-c3d6-437f-8fda-87659d8adf56',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Relocations',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '58bf77fd-355f-45c9-a44e-db012198fb85',
    'vocabulary_machine_name' => 'issues',
  );
  $terms[] = array(
    'name' => 'Aggregates',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '5ca47229-9652-42df-a41d-63520fec5349',
    'vocabulary_machine_name' => 'intervention_materials',
  );
  $terms[] = array(
    'name' => 'Maps and GIS',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '79772c36-ed3f-4cbf-99f1-c3361a854563',
    'vocabulary_machine_name' => 'information_management',
  );
  $terms[] = array(
    'name' => 'Formal Camps',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a80f90df-0c7f-4e10-a22f-c1b901666f3e',
    'vocabulary_machine_name' => 'settlement_type',
  );
  $terms[] = array(
    'name' => 'Complex Crisis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c5493fd0-50aa-4393-a458-5f83d2deb506',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Beneficiary Communications',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd0048fc8-b03f-4176-bc06-fe0fad5ae975',
    'vocabulary_machine_name' => 'intervention_programming',
  );
  $terms[] = array(
    'name' => 'Clothing and Bedding',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2f73244-8861-461d-bc50-9b774e1f0c48',
    'vocabulary_machine_name' => 'non_food_items',
  );
  $terms[] = array(
    'name' => 'Inter-Cluster Coordination',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e33af16f-d37c-4875-9c8f-6793508df352',
    'vocabulary_machine_name' => 'inter_cluster',
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ef3694d3-bdc8-4d97-9634-f64e8fd2c235',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Gender',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f4794653-28d2-44fd-b41a-a4ed6a21769b',
    'vocabulary_machine_name' => 'cross_cutting_issues',
  );
  $terms[] = array(
    'name' => 'Man-made disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f684ff86-0cab-4044-8034-e46922bc972e',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f97152e6-9e51-4fd0-a2e1-2eaa78467efa',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Preparedness',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fb49a788-3b9b-4013-9159-a3df3753fb4b',
    'vocabulary_machine_name' => 'response_phase',
  );
  return $terms;
}
