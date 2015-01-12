<?php

require_once 'common.inc';

function _shelter_migrate_import_group_documents($nid, $url) {
  set_time_limit(300);
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
      $doc_nid = _shelter_migrate_create_document($title, $link, _shelter_migrate_parse_description($description), $pubDate, $nid);
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

function _shelter_migrate_create_document($title, $url, $description, $pubDate, $group_nid) {
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
  $w->body->set(array('value' => strip_tags($description['Document Description']), 'format' => 'plain_text'));
  if (isset($description['Publishing Agency'])) {
    $w->field_document_source->set(t($description['Publishing Agency']));
  }
  if (isset($description['Is Key Document?']) && $description['Is Key Document?'] == 'Yes') {
    $w->field_key_document->set(TRUE);
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
    return array_combine($matches[1], $matches[2]);
  }

  throw new Exception('Could not parse RSS document description value.');
}