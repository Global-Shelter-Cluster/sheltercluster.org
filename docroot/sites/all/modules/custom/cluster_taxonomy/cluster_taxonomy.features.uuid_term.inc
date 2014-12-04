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
    'name' => 'Coordination information',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '24ffa33d-7216-4a69-a6ec-ab97fe67f5ea',
    'vocabulary_machine_name' => 'document_tags',
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
    'name' => 'Cold wave',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53527189-c3d6-437f-8fda-87659d8adf56',
    'vocabulary_machine_name' => 'disaster_causes',
    'field_disaster_type' => array(
      'und' => array(
        0 => array(
          'tid' => '2b53aeeb-f325-48f8-a9f7-f2a4d3dd4cd2',
        ),
      ),
    ),
  );
  $terms[] = array(
    'name' => 'Cluster Guidance',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b320f000-7cf8-46f5-9563-24e990178e66',
    'vocabulary_machine_name' => 'document_tags',
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
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ef3694d3-bdc8-4d97-9634-f64e8fd2c235',
    'vocabulary_machine_name' => 'disaster_causes',
    'field_disaster_type' => array(),
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
  return $terms;
}
