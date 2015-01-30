<?php

require_once 'common.inc';

function _shelter_migrate_import_regions_responses() {
  set_time_limit(300); // Just in case

  $both_response_and_country = array(
    'Central African Republic',
    'Chad',
    'Democratic Republic of Congo',
    'Ethiopia',
    'Kenya',
    'Mali',
    'Somalia',
    'South Sudan',
    'Sudan',
    'Afghanistan',
    'Ukraine',
    'Iraq',
    'Palestine',
    'Yemen',
  );

  $counts = array(
    'responses' => array('count' => 0, 'singular' => 'response'),
    'regions'   => array('count' => 0, 'singular' => 'region'  ),
    'countries' => array('count' => 0, 'singular' => 'country' ),
  );

  $html = file_get_contents('https://www.sheltercluster.org/Pages/default.aspx');
  if (!$html) {
    throw new Exception('Page could not be loaded.');
  }

  $doc = new DOMDocument();
  $doc->loadHTML($html);
  $xpath = new DOMXPath($doc);

  // Read regions, then countries, then responses. The menu has this structure.

  // Prepare the two terms for the region type
  $region_type_region = current(taxonomy_get_term_by_name('Region', 'geographic_region_type'));
  $region_type_country = current(taxonomy_get_term_by_name('Country', 'geographic_region_type'));

  $region_links = array();
  $regions = _shelter_migrate_dom_children($xpath, null, '//div[@class="menu horizontal menu-horizontal"]/ul/li/ul/li', 'a/span/span[@class="menu-item-text"]', 'a', $region_links);
  if (count($regions) < 4) {
    throw new Exception('Could not parse main menu');
  }
  array_shift($regions); //About us
  array_shift($regions); //Global
  array_pop($regions); //References

  foreach ($regions as $region => $e_region) {
    $nid_region = _shelter_migrate_create_region($region, $region_type_region);
    if (!$nid_region) {
      throw new Exception('Error creating region: '.$region);
    }
    _shelter_migrate_store_path($nid_region, $region, $region_links);
    $counts['regions']['count']++;

    $country_links = array();
    $countries = _shelter_migrate_dom_children($xpath, $e_region, 'ul/li', 'a/span/span[@class="menu-item-text"]', 'a', $country_links);
    foreach ($countries as $country => $e_country) {
      $nid_country = _shelter_migrate_create_country($country, $nid_region, $region_type_country);
      if (!$nid_country) {
        throw new Exception('Error creating country: '.$country);
      }
      _shelter_migrate_store_path($nid_country, $country, $country_links);
      $counts['countries']['count']++;

      if (in_array($country, $both_response_and_country)) {
        $nid_response = _shelter_migrate_create_response($country, $nid_country);
        if (!$nid_response) {
          throw new Exception('Error creating response: '.$country);
        }
        _shelter_migrate_store_path($nid_response, $country, $country_links);
        $counts['responses']['count']++;
      }

      $response_links = array();
      $responses = _shelter_migrate_dom_children($xpath, $e_country, 'ul/li', 'a/span/span[@class="menu-item-text"]', 'a', $response_links);
      foreach ($responses as $response => $e_response) {
        $nid_response = _shelter_migrate_create_response($response, $nid_country);
        if (!$nid_response) {
          throw new Exception('Error creating response: '.$response);
        }
        _shelter_migrate_store_path($nid_response, $response, $response_links);
        $counts['responses']['count']++;
      }
    }
  }

  // Report results.
  $counts_text = array();
  foreach ($counts as $plural => $data) {
    $counts_text[] = format_plural(
      $data['count'],
      '1 ' . $data['singular'],
      '@count ' . $plural
    );
  }
  return 'Imported ' . implode(', ', $counts_text) . ' successfully.';
}

function _shelter_migrate_create_region($title, $region_type) {
  $e = entity_create('node', array('type' => 'geographic_region'));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
  $w->language->set('en');
  $w->field_geographic_region_type->set($region_type);
  $w->save();
  return $w->nid->value();
}

function _shelter_migrate_create_country($title, $nid_region, $region_type) {
  $e = entity_create('node', array('type' => 'geographic_region'));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
  $w->language->set('en');
  $w->field_geographic_region_type->set($region_type);
  $w->field_parent_region->set(node_load($nid_region));
  $w->save();
  return $w->nid->value();
}

function _shelter_migrate_create_response($title, $nid_country) {
  $e = entity_create('node', array('type' => 'response'));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
  $w->field_associated_regions->set(node_load_multiple(array($nid_country)));
  $w->save();
  return $w->nid->value();
}

function _shelter_migrate_store_path($nid, $key, $paths) {
  if (!is_array($paths))
    return;
  if (!array_key_exists($key, $paths))
    return;

  db_merge('shelter_migrate_groups')
    ->key(array('nid' => $nid))
    ->fields(array(
      'path' => $paths[$key],
    ))
    ->execute();
}
