<?php

require_once drupal_get_path('module', 'shelter_migrate') . '/shelter_migrate.node.inc';
require_once 'import_group_documents.inc';

function _shelter_migrate_batch_group_documents($group_nid) {
  $group_node = node_load($group_nid);
  $batch = array(
    'operations' => array(
      array('_shelter_migrate_batch_group_documents_process', array($group_nid)),
    ),
    'finished' => '_shelter_migrate_batch_group_documents_finished',
    'title' => t('Importing group documents for ') . t($group_node->title),
    'init_message' => t('Batch import is starting.'),
    'progress_message' => t('Processed @current out of @total.'),
    'error_message' => t('Document import has encountered an error.'),
    'file' => drupal_get_path('module', 'shelter_migrate') . '/includes/batch_group_documents.inc',
  );
  batch_set($batch);
}

function _shelter_migrate_batch_group_documents_process($nid, &$context) {
  if (!isset($context['sandbox']['progress'])) {
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = 1;
  }

  $node = node_load($nid);
  $url = _shelter_migrate_node_rss_url($nid);

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

  $context['message'] = t('Imported documents: %docs', array('%docs' => $successful_docs));

  // Update our progress information.
  if (!$url || !$successful_docs) {
    // No documents imported (or no RSS url available): done.
    $context['sandbox']['progress']++;
    $context['finished'] = 1;
    return;
  }

  // Inform the batch engine that we are not finished,
  // and provide an estimation of the completion level we reached.
  if ($context['sandbox']['progress'] != $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }
}

function _shelter_migrate_batch_group_documents_finished($success, $results, $operations) {
  if ($success) {
    // Here we do something meaningful with the results.
    $total_docs = 0;
    $msg = array();
    foreach ($results as $nid => $data) {
      $total_docs += $data['successful'];
      if ($data['successful']) {
        $msg[] = check_plain($data['group']) . ': Imported ' . $data['successful'] . ' documents successfully';
      }
    }
    $message = $total_docs .' documents imported.';
    $message .= theme('item_list', array('items' => $msg));
    if ($total_docs) {
      $message .= '<p>You might want to ' . l('check the search index', 'admin/config/search/search_api/index/default_node_index') . '</p>';
    }
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
