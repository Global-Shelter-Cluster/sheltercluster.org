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
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '19812f2a-b597-487c-adcd-35a420e1d5f2',
    'vocabulary_machine_name' => 'disaster_causes',
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
    'name' => 'Earthquake',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '3015c8d0-4652-486d-b932-39bb8ef8100a',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Country',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => '35142595-f137-4547-8b45-d9391c796b35',
    'vocabulary_machine_name' => 'geographic_region_type',
  );
  $terms[] = array(
    'name' => 'Technical Disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '53214ef4-78a1-46f5-94e8-0a481e2c7c99',
    'vocabulary_machine_name' => 'disaster_causes',
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
    'name' => 'Tropical Cyclone',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '64653863-481d-4d77-a304-1180b439889f',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Land Slide',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '9ba71478-70c9-41c4-bd45-c018ad7b0b49',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Snow Avalanche',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a265176e-7e90-4175-8ade-c311ed5e48b3',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Extratropical Cyclone',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a29a67bb-ae0c-4d99-9d5e-b1aff021f1ce',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Region',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'a7c99647-9ffa-40bb-b537-a01308e9cb40',
    'vocabulary_machine_name' => 'geographic_region_type',
  );
  $terms[] = array(
    'name' => 'Flood',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0119ed0-c464-45ee-880a-9a9d57a5a02f',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Heat Wave',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b0f3c4d4-d5ce-45ee-aaed-28da6a6f3436',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Volcano',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b2d236a3-e27b-48c0-804d-664353216597',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Storm Surge',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'b3babded-c097-40ed-8f73-82fd12f4f1d2',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Complex Crisis',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 2,
    'uuid' => 'c5493fd0-50aa-4393-a458-5f83d2deb506',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Mudslide',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cbc976f7-1c9c-471d-9532-0ab9410e84dc',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Tsunami',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'd2523ba5-8315-4559-aa08-061a251141d5',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Tornadoes',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'db282b19-3974-4590-be81-46515bc9fd5b',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Epidemic',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e109ec69-3c12-4d88-846d-4890f379a6c2',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Fire',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e2d3f186-bac8-4a62-af20-d1293fc5a5f1',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Drought',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e42b1631-061a-4639-93ce-9289f64c91cb',
    'vocabulary_machine_name' => 'disaster_causes',
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
    'name' => 'Flash Flood',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f10d0ee4-29b3-462b-92fc-613ed5a125af',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Man-made disaster',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 3,
    'uuid' => 'f684ff86-0cab-4044-8034-e46922bc972e',
    'vocabulary_machine_name' => 'disaster_type',
  );
  $terms[] = array(
    'name' => 'Insect Infestation',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'f6974de6-c1bb-4447-8dd1-595b0b9c42fb',
    'vocabulary_machine_name' => 'disaster_causes',
  );
  $terms[] = array(
    'name' => 'Conflict',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 1,
    'uuid' => 'f97152e6-9e51-4fd0-a2e1-2eaa78467efa',
    'vocabulary_machine_name' => 'disaster_type',
  );
  return $terms;
}
