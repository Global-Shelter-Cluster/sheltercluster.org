<?php

/**
 *  Implements hook_pathauto().
 */
function cluster_docs_pathauto($op) {
  $settings = new stdClass();
  $settings->module = 'cluster_docs';
  $settings->groupheader = t('Group documents paths');
  $settings->patterndescr = t('Default path pattern');
//  $settings->patterndefault = '[node:url:path]/documents';
  $settings->patterndefault = '[node:content-type]/[node:title]/documents';
  $settings->token_type = 'node';
  $settings->patternitems = array('docs' => 'Group documents');
  if (module_exists('cluster_rss')) {
    $settings->patternitems += array('rssdocs' => 'Group RSS documents');
  }
  $settings->batch_update_callback = 'cluster_docs_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group document list pages.
 */
function cluster_docs_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');
  pathauto_create_alias('cluster_docs', $op, 'node/'.$node->nid.'/documents', array('node' => $node), 'docs');
  if (module_exists('cluster_rss')) {
    pathauto_create_alias('cluster_docs', $op, 'node/'.$node->nid.'/rss/documents', array('node' => $node), 'rssdocs');
  }
}

/**
 *  Implements hook_node_insert().
 */
function cluster_docs_node_insert($node) {
  if (og_is_group('node', $node)) {
    cluster_docs_create_alias($node, 'insert');
  }
}

/**
 *  Implements hook_node_update().
 */
function cluster_docs_node_update($node) {
  if (og_is_group('node', $node)) {
    cluster_docs_create_alias($node, 'update');
  }
}

/**
 * Refreshes all aliases.
 */
function cluster_docs_pathauto_bulkupdate(&$context) {
  if (!isset($context['sandbox']['current'])) {
    $context['sandbox']['count'] = 0;
    $context['sandbox']['current'] = 0;
  }

  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('n.nid', $context['sandbox']['current'], '>');
  $query->orderBy('n.nid');

  // Get the total amount of items to process.
  if (!isset($context['sandbox']['total'])) {
    $context['sandbox']['total'] = $query->countQuery()->execute()->fetchField();

    // If there are no nodes to update, the stop immediately.
    if (!$context['sandbox']['total']) {
      $context['finished'] = 1;
      return;
    }
  }

  $query->range(0, 25);
  $nids = $query->execute()->fetchCol();

  foreach ($nids as $nid) {
    $node = node_load($nid);
    if (og_is_group('node', $node)) {
      cluster_docs_create_alias($node, 'bulkupdate');
    }
  }

  $context['sandbox']['count'] += count($nids);
  $context['sandbox']['current'] = max($nids);
  $context['message'] = t('Updated alias for node @nid.', array('@nid' => end($nids)));

  if ($context['sandbox']['count'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['count'] / $context['sandbox']['total'];
  }

}
