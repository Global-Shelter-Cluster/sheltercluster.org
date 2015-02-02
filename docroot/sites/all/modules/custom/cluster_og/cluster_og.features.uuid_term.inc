<?php
/**
 * @file
 * cluster_og.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function cluster_og_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Severe Local Storm',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '19812f2a-b597-487c-adcd-35a420e1d5f2',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Severe Local Storm',
          'format' => NULL,
          'safe_value' => 'Severe Local Storm',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Severe Local Storm',
          'format' => NULL,
          'safe_value' => 'Severe Local Storm',
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
    'name_original' => 'Severe Local Storm',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 30,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Natural Disaster',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '2b53aeeb-f325-48f8-a9f7-f2a4d3dd4cd2',
    'vocabulary_machine_name' => 'disaster_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Natural Disaster',
          'format' => NULL,
          'safe_value' => 'Natural Disaster',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Natural Disaster',
          'format' => NULL,
          'safe_value' => 'Natural Disaster',
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
    'name_original' => 'Natural Disaster',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 4,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562782,
          'changed' => 1422562782,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Earthquake',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3015c8d0-4652-486d-b932-39bb8ef8100a',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Earthquake',
          'format' => NULL,
          'safe_value' => 'Earthquake',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Earthquake',
          'format' => NULL,
          'safe_value' => 'Earthquake',
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
    'name_original' => 'Earthquake',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 39,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Country',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '35142595-f137-4547-8b45-d9391c796b35',
    'vocabulary_machine_name' => 'geographic_region_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Country',
          'format' => NULL,
          'safe_value' => 'Country',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Country',
          'format' => NULL,
          'safe_value' => 'Country',
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
    'name_original' => 'Country',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 135,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562815,
          'changed' => 1422562815,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Technical Disaster',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53214ef4-78a1-46f5-94e8-0a481e2c7c99',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Technical Disaster',
          'format' => NULL,
          'safe_value' => 'Technical Disaster',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Technical Disaster',
          'format' => NULL,
          'safe_value' => 'Technical Disaster',
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
    'name_original' => 'Technical Disaster',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 54,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Cold wave',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53527189-c3d6-437f-8fda-87659d8adf56',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Cold wave',
          'format' => NULL,
          'safe_value' => 'Cold wave',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Cold wave',
          'format' => NULL,
          'safe_value' => 'Cold wave',
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
    'name_original' => 'Cold wave',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 8,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Tropical Cyclone',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '64653863-481d-4d77-a304-1180b439889f',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Tropical Cyclone',
          'format' => NULL,
          'safe_value' => 'Tropical Cyclone',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Tropical Cyclone',
          'format' => NULL,
          'safe_value' => 'Tropical Cyclone',
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
    'name_original' => 'Tropical Cyclone',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 61,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Land Slide',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9ba71478-70c9-41c4-bd45-c018ad7b0b49',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Land Slide',
          'format' => NULL,
          'safe_value' => 'Land Slide',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Land Slide',
          'format' => NULL,
          'safe_value' => 'Land Slide',
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
    'name_original' => 'Land Slide',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 77,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Snow Avalanche',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a265176e-7e90-4175-8ade-c311ed5e48b3',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Snow Avalanche',
          'format' => NULL,
          'safe_value' => 'Snow Avalanche',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Snow Avalanche',
          'format' => NULL,
          'safe_value' => 'Snow Avalanche',
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
    'name_original' => 'Snow Avalanche',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 81,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Extratropical Cyclone',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a29a67bb-ae0c-4d99-9d5e-b1aff021f1ce',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Extratropical Cyclone',
          'format' => NULL,
          'safe_value' => 'Extratropical Cyclone',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Extratropical Cyclone',
          'format' => NULL,
          'safe_value' => 'Extratropical Cyclone',
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
    'name_original' => 'Extratropical Cyclone',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 82,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Region',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a7c99647-9ffa-40bb-b537-a01308e9cb40',
    'vocabulary_machine_name' => 'geographic_region_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Region',
          'format' => NULL,
          'safe_value' => 'Region',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Region',
          'format' => NULL,
          'safe_value' => 'Region',
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
    'name_original' => 'Region',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 136,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562815,
          'changed' => 1422562815,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Flood',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0119ed0-c464-45ee-880a-9a9d57a5a02f',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Flood',
          'format' => NULL,
          'safe_value' => 'Flood',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Flood',
          'format' => NULL,
          'safe_value' => 'Flood',
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
    'name_original' => 'Flood',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 93,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Heat Wave',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0f3c4d4-d5ce-45ee-aaed-28da6a6f3436',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Heat Wave',
          'format' => NULL,
          'safe_value' => 'Heat Wave',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Heat Wave',
          'format' => NULL,
          'safe_value' => 'Heat Wave',
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
    'name_original' => 'Heat Wave',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 94,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Volcano',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b2d236a3-e27b-48c0-804d-664353216597',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Volcano',
          'format' => NULL,
          'safe_value' => 'Volcano',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Volcano',
          'format' => NULL,
          'safe_value' => 'Volcano',
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
    'name_original' => 'Volcano',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 96,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Storm Surge',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3babded-c097-40ed-8f73-82fd12f4f1d2',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Storm Surge',
          'format' => NULL,
          'safe_value' => 'Storm Surge',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Storm Surge',
          'format' => NULL,
          'safe_value' => 'Storm Surge',
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
    'name_original' => 'Storm Surge',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 97,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Complex Crisis',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c5493fd0-50aa-4393-a458-5f83d2deb506',
    'vocabulary_machine_name' => 'disaster_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Complex Crisis',
          'format' => NULL,
          'safe_value' => 'Complex Crisis',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Complex Crisis',
          'format' => NULL,
          'safe_value' => 'Complex Crisis',
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
    'name_original' => 'Complex Crisis',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 13,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562782,
          'changed' => 1422562782,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Mudslide',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbc976f7-1c9c-471d-9532-0ab9410e84dc',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Mudslide',
          'format' => NULL,
          'safe_value' => 'Mudslide',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Mudslide',
          'format' => NULL,
          'safe_value' => 'Mudslide',
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
    'name_original' => 'Mudslide',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 109,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Tsunami',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2523ba5-8315-4559-aa08-061a251141d5',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Tsunami',
          'format' => NULL,
          'safe_value' => 'Tsunami',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Tsunami',
          'format' => NULL,
          'safe_value' => 'Tsunami',
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
    'name_original' => 'Tsunami',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 112,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Tornadoes',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'db282b19-3974-4590-be81-46515bc9fd5b',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Tornadoes',
          'format' => NULL,
          'safe_value' => 'Tornadoes',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Tornadoes',
          'format' => NULL,
          'safe_value' => 'Tornadoes',
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
    'name_original' => 'Tornadoes',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 118,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Epidemic',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e109ec69-3c12-4d88-846d-4890f379a6c2',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Epidemic',
          'format' => NULL,
          'safe_value' => 'Epidemic',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Epidemic',
          'format' => NULL,
          'safe_value' => 'Epidemic',
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
    'name_original' => 'Epidemic',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 122,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Fire',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2d3f186-bac8-4a62-af20-d1293fc5a5f1',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Fire',
          'format' => NULL,
          'safe_value' => 'Fire',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Fire',
          'format' => NULL,
          'safe_value' => 'Fire',
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
    'name_original' => 'Fire',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 123,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Drought',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e42b1631-061a-4639-93ce-9289f64c91cb',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Drought',
          'format' => NULL,
          'safe_value' => 'Drought',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Drought',
          'format' => NULL,
          'safe_value' => 'Drought',
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
    'name_original' => 'Drought',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 124,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'ef3694d3-bdc8-4d97-9634-f64e8fd2c235',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Conflict',
          'format' => NULL,
          'safe_value' => 'Conflict',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Conflict',
          'format' => NULL,
          'safe_value' => 'Conflict',
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
    'name_original' => 'Conflict',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 17,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Flash Flood',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f10d0ee4-29b3-462b-92fc-613ed5a125af',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Flash Flood',
          'format' => NULL,
          'safe_value' => 'Flash Flood',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Flash Flood',
          'format' => NULL,
          'safe_value' => 'Flash Flood',
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
    'name_original' => 'Flash Flood',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 127,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Man-made disaster',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'f684ff86-0cab-4044-8034-e46922bc972e',
    'vocabulary_machine_name' => 'disaster_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Man-made disaster',
          'format' => NULL,
          'safe_value' => 'Man-made disaster',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Man-made disaster',
          'format' => NULL,
          'safe_value' => 'Man-made disaster',
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
    'name_original' => 'Man-made disaster',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 19,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562782,
          'changed' => 1422562782,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Insect Infestation',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f6974de6-c1bb-4447-8dd1-595b0b9c42fb',
    'vocabulary_machine_name' => 'disaster_causes',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Insect Infestation',
          'format' => NULL,
          'safe_value' => 'Insect Infestation',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Insect Infestation',
          'format' => NULL,
          'safe_value' => 'Insect Infestation',
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
    'name_original' => 'Insect Infestation',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 130,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562763,
          'changed' => 1422562763,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => NULL,
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'f97152e6-9e51-4fd0-a2e1-2eaa78467efa',
    'vocabulary_machine_name' => 'disaster_type',
    'name_field' => array(
      'en' => array(
        0 => array(
          'value' => 'Conflict',
          'format' => NULL,
          'safe_value' => 'Conflict',
        ),
      ),
      'und' => array(
        0 => array(
          'value' => 'Conflict',
          'format' => NULL,
          'safe_value' => 'Conflict',
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
    'name_original' => 'Conflict',
    'translations' => array(
      'original' => 'en',
      'data' => array(
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => 20,
          'language' => 'en',
          'source' => '',
          'uid' => 1,
          'status' => 1,
          'translate' => 0,
          'created' => 1422562782,
          'changed' => 1422562782,
        ),
      ),
    ),
    'description_original' => NULL,
  );
  return $terms;
}
