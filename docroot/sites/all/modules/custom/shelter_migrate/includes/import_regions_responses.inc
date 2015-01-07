<?php

function _shelter_migrate_import_regions_responses() {
  set_time_limit(300);

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
  $region_type_region = current(taxonomy_get_term_by_name('Region', 'geographic_region_type'))
  $region_type_country = current(taxonomy_get_term_by_name('Country', 'geographic_region_type'))

  $regions = _shelter_migrate_dom_children($xpath, null, '//div[@class="menu horizontal menu-horizontal"]/ul/li/ul/li', 'a/span/span[@class="menu-item-text"]');
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
    $counts['regions']['count']++;

    $countries = _shelter_migrate_dom_children($xpath, $e_region, 'ul/li', 'a/span/span[@class="menu-item-text"]');
    foreach ($countries as $country => $e_country) {
      $nid_country = _shelter_migrate_create_country($country, $nid_region, $region_type_country);
      if (!$nid_country) {
        throw new Exception('Error creating country: '.$country);
      }
      $counts['countries']['count']++;

      $responses = _shelter_migrate_dom_children($xpath, $e_country, 'ul/li', 'a/span/span[@class="menu-item-text"]');
      foreach ($responses as $response => $e_response) {
        $nid_response = _shelter_migrate_create_response($response, $nid_country);
        if (!$nid_response) {
          throw new Exception('Error creating response: '.$response);
        }
        $counts['responses']['count']++;
      }
    }
  }

  // Report results.
  $counts_text = array();
  foreach ($counts as $plural => $data) {
    $counts_text[] = format_plural(
      $data['count'],
      '@count ' . $data['singular'],
      '@count ' . $plural
    );
  }
  return 'Imported ' . implode(', ', $counts_text) . ' successfully.';
}

function _shelter_migrate_create_region($title, $region_type) {
  $e = entity_create('node', array('type' => 'geographic_region'));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
  $w->field_geographic_region_type->set($region_type);
  $w->save();
  return $w->nid->value();
}

function _shelter_migrate_create_country($title, $nid_region, $region_type) {
  $e = entity_create('node', array('type' => 'geographic_region'));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
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

/**
 * Looks for children using the provided DOMXPath object and queries.
 * @param DOMXPath $xpath
 * @param DOMNode|null $context
 * @param string $xpath_children
 *  Query to get the children elements (returned as array values)
 * @param string $xpath_label
 *  Query to get the label (returned as array keys)
 * @return array
 */
function _shelter_migrate_dom_children($xpath, $context, $xpath_children, $xpath_label) {
  $children = $xpath->query($xpath_children, $context);
  $ret = array();

  for ($i = 0; $i < $children->length; $i++) {
    /**
     * @var DOMElement
     */
    $e_child = $children->item($i);

    if ($e_child->nodeType != XML_ELEMENT_NODE) {
      continue;
    }

    $labels = $xpath->query($xpath_label, $e_child);
    if ($labels->length != 1) {
      throw new Exception('something is wrong!');
      continue;
    }

    $ret[trim($labels->item(0)->nodeValue)] = $e_child;
  }

  return $ret;
}