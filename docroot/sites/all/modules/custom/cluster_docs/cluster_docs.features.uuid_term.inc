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
    'name' => 'Inter-Cluster',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 4,
    'uuid' => '1d5f2d64-dfb7-4695-a693-db8c232ade2b',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Inter-Cluster',
          'format' => NULL,
          'safe_value' => 'Inter-Cluster',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Inter-Cluster',
          'format' => NULL,
          'safe_value' => 'Inter-Cluster',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Inter-Cluster',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 138,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Non Food Items',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 5,
    'uuid' => '38efa47c-c6ef-4e0c-9747-8858eee7791f',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Non Food Items',
          'format' => NULL,
          'safe_value' => 'Non Food Items',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Non Food Items',
          'format' => NULL,
          'safe_value' => 'Non Food Items',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Non Food Items',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 140,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
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
    'name' => 'Toolkit',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 6,
    'uuid' => '655dbcc6-04d8-447f-9c8e-2aed8e14f12a',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Toolkit',
          'format' => NULL,
          'safe_value' => 'Toolkit',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Toolkit',
          'format' => NULL,
          'safe_value' => 'Toolkit',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Toolkit',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 141,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Case study',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '6dadc354-33ff-477a-861b-3f4e8173d0e7',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Case study',
          'format' => NULL,
          'safe_value' => 'Case study',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Case study',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 157,
          'language' => 'en',
          'source' => '',
          'uid' => 70,
          'status' => 1,
          'translate' => 0,
          'created' => 1425553477,
          'changed' => 1425553477,
        ),
      ),
    ),
    'description_original' => '',
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
    'name' => 'Coordination Management',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'c7a0e1d1-5103-4b5b-aae2-27d9d05565c5',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Coordination Management',
          'format' => NULL,
          'safe_value' => 'Coordination Management',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Coordination Management',
          'format' => NULL,
          'safe_value' => 'Coordination Management',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Coordination Management',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 144,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Information Management',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'c7f9469a-d1c7-408a-abab-06370828cc10',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Information Management',
          'format' => NULL,
          'safe_value' => 'Information Management',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Information Management',
          'format' => NULL,
          'safe_value' => 'Information Management',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Information Management',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 145,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Technical Support and Design',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'ca658eeb-8879-4d7a-a63a-26836c654086',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Technical Support and Design',
          'format' => NULL,
          'safe_value' => 'Technical Support and Design',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Technical Support and Design',
          'format' => NULL,
          'safe_value' => 'Technical Support and Design',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Technical Support and Design',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 146,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Cross-Cutting Issues',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'e7a29467-4d30-4037-8fc2-c86b4e1a0955',
    'vocabulary_machine_name' => 'document_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Cross-Cutting Issues',
          'format' => NULL,
          'safe_value' => 'Cross-Cutting Issues',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Cross-Cutting Issues',
          'format' => NULL,
          'safe_value' => 'Cross-Cutting Issues',
        ),
      ),
    ),
    'description_field' => array(
      'en' => array(
        0 => array(
          'value' => NULL,
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => '',
          'summary' => NULL,
          'format' => 'filtered_html',
          'safe_value' => '',
          'safe_summary' => '',
        ),
      ),
    ),
    'name_original' => 'Cross-Cutting Issues',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 147,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562671,
          'changed' => 1422562671,
        ),
      ),
    ),
    'description_original' => NULL,
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
