<?php

require_once 'import_group_documents.inc';

function _shelter_migrate_batch_documents() {
  $batch = array(
    'operations' => array(
      array('_shelter_migrate_batch_documents_process', array()),
    ),
    'finished' => '_shelter_migrate_batch_documents_finished',
    'title' => t('Importing group documents'),
    'init_message' => t('Batch import is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Document import has encountered an error.'),
    'file' => drupal_get_path('module', 'shelter_migrate') . '/includes/batch_documents.inc',
  );
  batch_set($batch);
}

function _shelter_migrate_batch_documents_process(&$context) {
  if (!isset($context['sandbox']['progress'])) {

    // Clean the shelter_migrate_groups table
    $nids = db_select('shelter_migrate_groups', 'g')
      ->fields('g', array('nid'));
    $nids->leftJoin('node', 'n', 'n.nid = g.nid');
    $nids->condition('n.nid', NULL);
    $nids = $nids->execute()->fetchCol();
    if ($nids) {
      db_delete('shelter_migrate_groups')
        ->condition('nid', $nids)
        ->execute();
    }

    $context['sandbox']['progress'] = 0;
    $context['sandbox']['current_node'] = 0;
    $context['sandbox']['max'] = db_query('SELECT COUNT(DISTINCT nid) FROM {shelter_migrate_groups}')->fetchField();
  }

  // With each pass through the callback, retrieve the next nid.
  $nid = db_select('shelter_migrate_groups', 'a')
    ->fields('a', array('nid'))
    ->condition('nid', $context['sandbox']['current_node'], '>')
    ->orderBy('nid')
    ->range(0, 1)
    ->execute()
    ->fetchField();
  if (!$nid) {
    $context['finished'] = 1;
    return;
  }

  // Here we actually perform our processing on the current node.
  $node = node_load($nid);

  $url = db_select('shelter_migrate_rss', 'a')
    ->fields('a', array('url'))
    ->condition('nid', $node->nid)
    ->execute()
    ->fetchField();
  if (!$url) {
    // Figure out the RSS feed URL
    $group_url = db_select('shelter_migrate_groups', 'a')
      ->fields('a', array('path'))
      ->condition('nid', $node->nid)
      ->execute()
      ->fetchField();

    // Was this group also created as a response with a different nid?
    $query = db_select('shelter_migrate_groups', 'g');
    $query->join('node', 'n', 'n.nid = g.nid');
    $query->fields('g', array('nid'))
      ->condition('g.path', $group_url)
      ->condition('g.nid', $node->nid, '!=')
      ->condition('n.type', 'response');
    if (!$query->execute()->fetchField()) { // Only go on if there are no matches.
      $suffix = 'Pages/default.aspx';

      if (preg_match('/'.preg_quote($suffix, '/').'$/', $group_url)) {
        $all_docs_url = 'https://www.sheltercluster.org'
          . substr($group_url, 0, strlen($group_url) - strlen($suffix))
          . 'Documents/Forms/AllItems.aspx';

        $all_docs_html = file_get_contents($all_docs_url);
        if ($all_docs_html) {
          $doc = new DOMDocument();
          $doc->loadHTML($all_docs_html);
          $xpath = new DOMXPath($doc);
          $children = $xpath->query('//html/head/link[@rel="alternate"][@type="application/rss+xml"]');
          if ($children->length) {
            $href = $children->item(0)->getAttribute('href');
            if ($href) {
              $url = 'https://www.sheltercluster.org' . $href;

              db_merge('shelter_migrate_rss')
                ->key(array('nid' => $node->nid))
                ->fields(array('url' => $url))
                ->execute();
            }
          }
        }
      }
    }
  }

  $successful_docs = 0;
  if ($url) {
    $successful_docs = _shelter_migrate_import_group_documents($node->nid, $url, TRUE);
    if (!isset($context['results'])) {
      $context['results'] = array();
    }
    if (!isset($context['results'][$node->nid])) {
      $context['results'][$node->nid] = array('group' => $node->title);
    }
    $context['results'][$node->nid]['successful'] += $successful_docs;
  }

  // Update our progress information.
  if (!$url || !$successful_docs) {
    // No documents imported (or no RSS url available): move on to the next group.
    $context['sandbox']['progress']++;
    $context['sandbox']['current_node'] = $node->nid;
    $context['message'] = t('Now processing %node', array('%node' => $node->title));
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function _shelter_migrate_batch_documents_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $total_docs = 0;
    $total_groups = 0;
    $msg = array();
    foreach ($results as $nid => $data) {
      $total_docs += $data['successful'];
      if ($data['successful']) {
        $total_groups++;
      }
      if (!$data['successful']) {
        $msg[] = check_plain($data['group']) . ': No documents imported for this group';
      }
      else {
        $msg[] = check_plain($data['group']) . ': Imported ' . $data['successful'] . ' documents successfully';
      }
    }
    $message = $total_docs .' documents imported for ' . $total_groups . ' groups.';
    $message .= theme('item_list', array('items' => $msg));
    drupal_set_message($message);
  }
  else {
    // An error occurred.
    // $operations contains the operations that remained unprocessed.
    $error_operation = reset($operations);
    $message = t('An error occurred while processing %error_operation with arguments: @arguments', array('%error_operation' => $error_operation[0], '@arguments' => print_r($error_operation[1], TRUE)));
    drupal_set_message($message, 'error');
  }

}
