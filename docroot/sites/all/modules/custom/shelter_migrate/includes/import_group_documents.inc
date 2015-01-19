<?php

require_once 'common.inc';

function _shelter_migrate_import_group_documents($nid, $url) {
  set_time_limit(300);
  $taxonomy_mapping = _shelter_migrate_prepare_taxonomy_mapping();

  $successful_count = 0;
  $skip_count = 0;

  $node = node_load($nid);
  if (!og_is_group('node', $node)) {
    throw new Exception('Node is not a group.');
  }

  $xml = file_get_contents($url);
  if (!$xml) {
    throw new Exception('Page could not be loaded.');
  }

  $doc = new DOMDocument();
  $doc->loadXML($xml);
  $xpath = new DOMXPath($doc);

  $docs = _shelter_migrate_dom_children($xpath, null, '//rss/channel/item');
  for ($i = 0; $i < count($docs); $i++) {
    foreach (array('title', 'link', 'description', 'pubDate') as $field) {
      $$field = _shelter_migrate_dom_children($xpath, $docs[$i], $field);
      if (!count($$field) || !is_a(current($$field), 'DOMElement')) {
        throw new Exception('Field not found for document #' . $i . ': ' . $field);
      }

      $$field = current($$field);
      $$field = $$field->nodeValue;
    }

    /** @var string $title */
    /** @var string $link */
    /** @var string $description */
    /** @var string $pubDate */

    // If the document was already imported, and it exists as a node, skip it.
    $query = db_select('shelter_migrate_docs', 'd');
    $query->fields('d', array('doc_nid'));
    $query->join('node', 'n', 'd.doc_nid = n.nid');
    $query->condition('n.status', NODE_PUBLISHED);
    $query->condition('d.nid', $nid);
    $query->condition('d.url_hash', md5($link));
    $query->condition('d.url', $link);
    $doc_nid = $query->execute()->fetchField();
    if ($doc_nid) {
      $skip_count++;
    }
    else {
      // Document did not exist in the system, download it.
      $doc_nid = _shelter_migrate_create_document($title, $link, _shelter_migrate_parse_description($description), $pubDate, $nid, $taxonomy_mapping);
      if (is_numeric($doc_nid) && $doc_nid > 0) {
        $successful_count++;

        db_merge('shelter_migrate_docs')
          ->key(array(
            'nid' => $nid,
            'url_hash' => md5($link),
          ))
          ->fields(array(
            'url' => $link,
            'doc_nid' => $doc_nid,
          ))
          ->execute();
      }
    }

//    if ($i == 3) break;
  }

  return 'Imported '.format_plural($successful_count, '1 document', '@count documents').' successfully (skipped '.$skip_count.').';
}

function _shelter_migrate_create_document($title, $url, $description, $pubDate, $group_nid, &$taxonomy_mapping) {
  $e = entity_create('node', array(
    'type' => 'document',
    'created' => strtotime($pubDate),
    'status' => NODE_PUBLISHED,

    'uid' => 1,
  ));
  $w = entity_metadata_wrapper('node', $e);
  $w->title = $title;
  $w->field_document_source->set(t('Shelter Cluster'));

  // Process $description values
  if (isset($description['Document Description'])) {
    $w->body->set(array('value' => strip_tags($description['Document Description']), 'format' => 'plain_text'));
  }
  if (isset($description['Report Date'])) {
    $w->field_report_meeting_date->set(strtotime(str_replace('/', '-', $description['Report Date'])));
  }
  if (isset($description['Created'])) {
    $w->created = (strtotime(str_replace('/', '-', $description['Created'])));
  }
  if (isset($description['Publishing Agency'])) {
    $w->field_document_source->set(t($description['Publishing Agency']));
  }
  if (isset($description['Is Key Document?']) && $description['Is Key Document?'] == 'Yes') {
    $w->field_key_document->set(TRUE);
  }
  if (isset($description['Is Reference Doc?']) && $description['Is Reference Doc?'] == 'Yes') {
    $w->field_is_reference_document->set(TRUE);
  }
  // Taxonomies
  foreach ($taxonomy_mapping as $key => $data) {
    if (!isset($description[$key])) {
      continue;
    }

    if (!isset($data[$description[$key]])) {
      continue;
    }

    foreach ($data[$description[$key]] as $field => $terms) {
      $field_info = field_info_field($field);
      $vocabulary = NULL;
      if (isset($field_info['settings']['allowed_values'][0]['vocabulary']))
        $vocabulary = $field_info['settings']['allowed_values'][0]['vocabulary'];

      $term_objects = array();
      foreach (is_array($terms) ? $terms : array($terms) as $term) {
        $term_objects += taxonomy_get_term_by_name($term, $vocabulary);
      }
      if (count($term_objects)) {
        $w->$field->set(array_keys($term_objects));
      }
    }
  }

  // Download the actual file
  $directory = file_build_uri('docs');
  if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
    throw new Exception('Could not create "docs" directory.');
  }
  $content = _shelter_migrate_download_file($url);
  if (!$content) {
    drupal_set_message('Error downloading: '.$url, 'error');
    return;
  }
  $uri = $directory . '/' . pathinfo($url, PATHINFO_BASENAME);
  $file = file_save_data($content, $uri);
  $w->field_file->file->set($file);

  $w->save();

  // Trigger a node_save() too, otherwise the document doesn't show in the frontend.
  $node = node_load($w->nid->value(), NULL, TRUE);
  node_save($node);

  // Add document to group.
  og_group('node', $group_nid, array(
    'entity_type' => 'node',
    'entity' => node_load($w->nid->value()),
    'field_name' => 'og_group_ref',
    'state' => 1,
  ));

  return $w->nid->value();
}

function _shelter_migrate_download_file($url) {
  // Give ourselves enough time to download the files, every time.
  set_time_limit(300);

  $ch = curl_init();

  // Windows server needs "%20" character instead of spaces, otherwise it
  // returns with code 400.
  curl_setopt($ch, CURLOPT_URL, str_replace(' ', '%20', $url));

//  // Turn 'verbose mode' on, to debug the request
//  curl_setopt($ch, CURLOPT_VERBOSE, 1);
//  $verbose = fopen('/tmp/tempcurl', 'a
//  ');
//  curl_setopt($ch, CURLOPT_STDERR, $verbose);

  curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

  $output = curl_exec($ch);
  $http_status = curl_getinfo($ch, CURLINFO_HTTP_CODE);
  curl_close($ch);
  return $http_status == 200 ? $output : NULL;
}

function _shelter_migrate_parse_description($html_value) {
  $div = preg_quote('<div>', '/');
  $ddiv = preg_quote('</div>', '/');
  $b = preg_quote('<b>', '/');
  $bb = preg_quote('</b>', '/');
  $regex = "/$div$b([^\\:\\<]+)\\:$bb (.+)$ddiv\n/";

  preg_match_all($regex, $html_value, $matches);

  if ($matches) {
    foreach ($matches[1] as &$key) {
      $key = html_entity_decode($key);
    }

    return array_combine($matches[1], $matches[2]);
  }

  throw new Exception('Could not parse RSS document description value.');
}

function _shelter_migrate_prepare_taxonomy_mapping() {
  $taxonomy_mapping = array(
    'Is A,M and E?' => array(
      'Yes' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
      ),
    ),
    'Is Communications?' => array(
      'Yes' => array(
        'field_information_management' => 'Communications Messaging',
      ),
    ),
    'Is Coordination?' => array(
      'Yes' => array(
        'field_document_type' => 'Coordination Management',
      ),
    ),
    'Is Cross Cutting?' => array(
      'Yes' => array(
        'field_document_type' => 'Cross-Cutting Issues',
      ),
    ),
    'Is IM?' => array(
      'Yes' => array(
        'field_document_type' => 'Information Management',
      ),
    ),
    'Is Inter Cluster?' => array(
      'Yes' => array(
        'field_document_type' => 'Inter-Cluster',
      ),
    ),
    'Is NFI Guidance?' => array(
      'Yes' => array(
        'field_technical_support_design' => 'Technical Guidance',
      ),
    ),
    'Is Shelter Planning?' => array(
      'Yes' => array(
        'field_document_type' => 'Technical Support and Design',
      ),
    ),
    'Is Shelter Programming' => array(
      'Yes' => array(
        'field_technical_support_design' => 'Shelter Programming',
      ),
    ),
    'Is Shelter Specifications?' => array(
      'Yes' => array(
        'field_technical_support_design' => 'Design Specifications',
      ),
    ),
    'AM&E' => array( // Key from $description array ($key)
      'Assessment' => array( // Value, e.g. $description['AM&E'] ($value)
        // Drupal field names and taxonomy term names ($field => $term)
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
      ),
      'Evaluation' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
        'field_assess_monitor_eval' => 'Cluster Evaluation',
      ),
      'Hazard/Risk' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
      ),
      'Monitoring' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
      ),
      'REACH' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
        'field_assess_monitor_eval' => 'Shelter Cluster Assessment',
      ),
    ),
    'Communications' => array(
      'Audio' => array(
      ),
      'Key Messages' => array(
        'field_coordination_management' => 'Advisory Note',
      ),
      'Photos' => array(
      ),
      'Tools' => array(
      ),
      'Video' => array(
      ),
    ),
    'Coordination' => array(
      'Advocacy' => array(
        'field_coordination_management' => 'Advisory Note',
      ),
      'Appeal' => array(
        'field_coordination_management' => 'Resource Mobilization',
      ),
      'Attendance list' => array(
        'field_coordination_management' => 'Meeting Management',
      ),
      'Beneficiary Selection' => array(
        'field_coordination_management' => 'Beneficiary Selection',
      ),
      'Cluster Review' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
        'field_assess_monitor_eval' => 'Cluster Evaluation',
      ),
      'Contact List' => array(
        'field_coordination_management' => 'Meeting Management',
      ),
      'Contingency Planning' => array(
      ),
      'Donor Relations' => array(
        'field_coordination_management' => 'Resource Mobilization',
      ),
      'Government Relations' => array(
        'field_coordination_management' => 'Government and regulatory policy', //spreadsheet says: 'Government policy'
      ),
      'Guidance' => array(
      ),
      'Meeting Agenda' => array(
        'field_coordination_management' => 'Meeting Management',
      ),
      'Meeting Minutes' => array(
        'field_coordination_management' => 'Meeting Management',
      ),
      'Performance Monitoring' => array(
      ),
      'Situation Report' => array(
        'field_coordination_management' => 'Situation Report',
      ),
      'Strategy' => array(
        'field_coordination_management' => 'Strategy',
      ),
      'Toolkit' => array(
      ),
    ),
    'Information Management' => array(
      'Analysis Report' => array(
        'field_information_management' => 'IM reports and analysis',
      ),
      'Dataset' => array(
        'field_information_management' => 'Dataset',
      ),
      'Guidance' => array(
        'field_information_management' => 'Reporting Tools and Guidance',
      ),
      'Mapping' => array(
        'field_information_management' => 'Maps and GIS',
      ),
      'Matrix or Graphic' => array(
        'field_information_management' => 'IM reports and analysis',
      ),
      'Reporting Template' => array(
        'field_information_management' => 'Reporting Tools and Guidance',
      ),
      'Toolkit' => array(
        'field_information_management' => 'Reporting Tools and Guidance',
      ),
      'Who, What, Where, When' => array(
        'field_information_management' => 'IM reports and analysis',
      ),
    ),
    'InterCluster' => array(
      'CCCM' => array(
        'field_inter_cluster' => 'CCCM',
      ),
      'Early Recovery' => array(
        'field_inter_cluster' => 'Early Recovery',
      ),
      'Education' => array(
        'field_inter_cluster' => 'Education',
      ),
      'Health' => array(
        'field_inter_cluster' => 'Health',
      ),
      'InterCluster Coordination' => array(
        'field_inter_cluster' => 'Inter-Cluster Coordination',
      ),
      'Logistics' => array(
        'field_inter_cluster' => 'Logistics',
      ),
      'Protection' => array(
        'field_inter_cluster' => 'Protection',
      ),
      'WASH' => array(
        'field_inter_cluster' => 'WASH',
      ),
    ),
    'NFI Guidance' => array(
      'Clothing and Bedding' => array(
        'field_non_food_items' => 'Clothing and Bedding',
      ),
      'Cooking and Eating Utensils' => array(
        'field_non_food_items' => 'Cooking and Eating Utensils',
      ),
      'General Household Support' => array(
        'field_non_food_items' => 'General Household Support',
      ),
      'Stoves, Fuel, and Lighting' => array(
        'field_non_food_items' => 'Stoves, Fuel, and Lighting',
      ),
      'Tools and Fixing' => array(
        'field_non_food_items' => 'Tools and Fixing',
      ),
    ),
    'Cross Cutting' => array(
      'Age' => array(
        'field_cross_cutting_issues' => 'Age',
      ),
      'Disabilities' => array(
        'field_cross_cutting_issues' => 'Disabilities',
      ),
      'Environment' => array(
        'field_cross_cutting_issues' => 'Environment',
      ),
      'Gender' => array(
        'field_cross_cutting_issues' => 'Gender',
      ),
      'HIV/AIDS' => array(
        'field_cross_cutting_issues' => 'HIV/AIDS',
      ),
      'Housing, Land and Property' => array(
        'field_cross_cutting_issues' => 'Housing, Land, and Property Rights',
      ),
      'Human Rights' => array(
        'field_cross_cutting_issues' => 'Human Rights',
      ),
      'Livestock' => array(
        'field_cross_cutting_issues' => 'Livestock',
      ),
      'Mental Health' => array(
        'field_cross_cutting_issues' => 'Mental Health',
      ),
      'Mines and other explosives' => array(
        'field_cross_cutting_issues' => 'Mines and other explosives',
      ),
    ),
    'Document Category' => array(
      'A,M and E' => array(
        'field_information_management' => 'Assessment, Monitoring, and Evaluation',
      ),
      'Communications' => array(
        'field_information_management' => 'Communications Messaging',
      ),
      'Coordination' => array(
        'field_document_type' => 'Coordination Management',
      ),
      'Cross Cutting' => array(
        'field_document_type' => 'Cross-Cutting Issues',
      ),
      'IASC Guidance' => array(
        'field_inter_cluster' => 'Inter-Cluster Coordination',
      ),
      'Information Management' => array(
        'field_document_type' => 'Information Management',
      ),
      'InterCluster' => array(
        'field_document_type' => 'Inter-Cluster',
      ),
      'NFI Guidance' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_document_type' => 'Non Food Items',
      ),
      'Settlement Planning' => array(
        'field_document_type' => 'Technical Support and Design',
      ),
      'Shelter Cluster Policy' => array(
        'field_document_type' => 'Technical Support and Design',
      ),
      'Shelter Programming' => array(
        'field_technical_support_design' => 'Shelter Programming',
      ),
      'Shelter Specifications' => array(
        'field_technical_support_design' => 'Design Specifications',
      ),
      'Training' => array(
        'field_technical_support_design' => 'Training Materials',
      ),
    ),
    'Miscellaneous Terms' => array(
      'Checklist' => array(
        'field_toolkit' => 'Checklist',
      ),
      'Coordination Toolkit' => array(
        'field_document_type' => array('Coordination Management', 'Toolkit'),
      ),
      'Example' => array(
        'field_toolkit' => 'Example',
      ),
      'Guidance' => array(
        'field_toolkit' => 'Guidance',
      ),
      'IM Toolkit' => array(
        'field_document_type' => array('Information Management', 'Toolkit'),
      ),
      'Template' => array(
        'field_toolkit' => 'Template',
      ),
    ),
    'Shelter Planning' => array(
      'Camp Planning' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Camp Planning',
      ),
      'Collective Centres' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_settlement_type' => 'Collective Centres',
      ),
      'Covered Living Spaces' => array(
        'field_technical_support_design' => 'Technical Guidance',
      ),
      'Land Tenure' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_cross_cutting_issues' => 'Housing, Land, and Property Rights',
      ),
      'Site Selection' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Settlement planning',
      ),
      'Urban Planning' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Urban Planning',
      ),
    ),
    'Shelter Programming' => array(
      'Beneficiary Outreach' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Beneficiary Communications',
      ),
      'Built Environment Professionals' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Built Environment Professionals',
      ),
      'Camp Management' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Camp Management',
      ),
      'Cash and Vouchers' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Cash and Vouchers',
      ),
      'Community Participation' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Beneficiary Communications',
      ),
      'Conflict' => array(
        'field_document_type' => 'Technical Support and Design',
      ),
      'Construction' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_response_phase' => 'Reconstruction',
      ),
      'Contingency Planning' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_response_phase' => 'Preparedness',
      ),
      'Demolition' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Demolition',
      ),
      'Distributions' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Distribution',
      ),
      'Early Recovery' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_response_phase' => 'Early Recovery',
      ),
      'Host Families' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_settlement_type' => 'Host Families',
      ),
      'IEC' => array(
        'field_technical_support_design' => 'IEC Materials',
      ),
      'Owner-driven' => array(
        'field_technical_support_design' => 'Shelter Programming',
        'field_intervention_programming' => 'Owner Driven',
      ),
      'Procurement and Logisitics' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_inter_cluster' => 'Logistics',
      ),
      'Reconstruction' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_response_phase' => 'Reconstruction',
      ),
      'Recovery' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_response_phase' => 'Recovery',
      ),
      'Risk Reduction' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Risk Reduction',
      ),
      'Rubble Removal' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Rubble Removal',
      ),
      'Shelter Repair' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Repairs and Retrofitting',
      ),
      'Training' => array(
        'field_technical_support_design' => 'Training materials',
        'field_intervention_programming' => 'Technical Training',
      ),
    ),
    'Shelter Specifications' => array(
      'Design Library' => array(
        'field_technical_support_design' => 'Technical Guidance',
      ),
      'Emergency Shelter' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_response_phase' => 'Emergency',
      ),
      'Material Guidance' => array(
        'field_technical_support_design' => 'Technical Guidance',
      ),
      'Permanent Housing' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Permanent Housing',
      ),
      'Tents' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_materials' => 'Tents',
      ),
      'Transitional Shelter' => array(
        'field_technical_support_design' => 'Technical Guidance',
        'field_intervention_programming' => 'Transitional Shelter',
      ),
    ),
  );

  // Check if every term exists and that they can be added to the appropriate fields
  foreach ($taxonomy_mapping as $key => $data) {
    foreach ($data as $value => $term_data) {
      foreach ($term_data as $field => $terms) {
        $field_info = field_info_field($field);
        $vocabulary = NULL;
        if (isset($field_info['settings']['allowed_values'][0]['vocabulary']))
          $vocabulary = $field_info['settings']['allowed_values'][0]['vocabulary'];

        foreach (is_array($terms) ? $terms : array($terms) as $term) {
          $term_objects = taxonomy_get_term_by_name($term, $vocabulary);

          if (!count($term_objects)) {
            throw new Exception('Error preparing import: Term not found for field `'.$field.'`: "'.$term.'"');
          }
        }
      }
    }
  }

  return $taxonomy_mapping;
}