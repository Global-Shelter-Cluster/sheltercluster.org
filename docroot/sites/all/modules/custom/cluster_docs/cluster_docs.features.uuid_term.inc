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
    'name' => 'Contact List',
    'description' => 'Contact list',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '4e7d9587-6210-44db-8db6-9e72749d6c40',
    'vocabulary_machine_name' => 'meeting_management',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Contact List',
          'format' => NULL,
          'safe_value' => 'Contact List',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Contact list',
          'summary' => '',
          'format' => 'filtered_html',
          'safe_value' => '<p>Contact list</p>
',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Contact List',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 151,
          'language' => 'en',
          'source' => '',
          'uid' => 70,
          'status' => 1,
          'translate' => 0,
          'created' => 1423848889,
          'changed' => 1423848889,
        ),
      ),
    ),
    'description_original' => 'Contact list',
  );
  $terms[] = array(
    'name' => 'Meeting Minutes',
    'description' => 'Minutes of meetings',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '50c07689-7803-457e-a6bc-20585d3b95bb',
    'vocabulary_machine_name' => 'meeting_management',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Meeting Minutes',
          'format' => NULL,
          'safe_value' => 'Meeting Minutes',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Minutes of meetings',
          'summary' => '',
          'format' => 'filtered_html',
          'safe_value' => '<p>Minutes of meetings</p>
',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Meeting Minutes',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 148,
          'language' => 'en',
          'source' => '',
          'uid' => 70,
          'status' => 1,
          'translate' => 0,
          'created' => 1423848586,
          'changed' => 1423848586,
        ),
      ),
    ),
    'description_original' => 'Minutes of meetings',
  );
  $terms[] = array(
    'name' => 'Attendance List',
    'description' => 'Attendance list',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a02c7a19-a1b8-4f81-be89-e892355f7a42',
    'vocabulary_machine_name' => 'meeting_management',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Attendance List',
          'format' => NULL,
          'safe_value' => 'Attendance List',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Attendance list',
          'summary' => '',
          'format' => 'filtered_html',
          'safe_value' => '<p>Attendance list</p>
',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Attendance List',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 150,
          'language' => 'en',
          'source' => '',
          'uid' => 70,
          'status' => 1,
          'translate' => 0,
          'created' => 1423848822,
          'changed' => 1423848822,
        ),
      ),
    ),
    'description_original' => 'Attendance list',
  );
  $terms[] = array(
    'name' => 'Meeting Agenda',
    'description' => 'Meeting Agenda',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ea79b9d7-e510-4143-a630-fcf66f532647',
    'vocabulary_machine_name' => 'meeting_management',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Meeting Agenda',
          'format' => NULL,
          'safe_value' => 'Meeting Agenda',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Meeting Agenda',
          'summary' => '',
          'format' => 'filtered_html',
          'safe_value' => '<p>Meeting Agenda</p>
',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Meeting Agenda',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 149,
          'language' => 'en',
          'source' => '',
          'uid' => 70,
          'status' => 1,
          'translate' => 0,
          'created' => 1423848615,
          'changed' => 1423848615,
        ),
      ),
    ),
    'description_original' => 'Meeting Agenda',
  );
  return $terms;
}
