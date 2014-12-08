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
  $settings->batch_update_callback = 'cluster_docs_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function.
 */
function cluster_docs_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');
  pathauto_create_alias('cluster_docs', $op, 'node/'.$node->nid.'/documents', array('node' => $node), 'docs');
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

function cluster_docs_pathauto_bulkupdate() {
  $query = db_select('node', 'n');
  //TODO: filter only group nodes
  $query->fields('n', array('nid'));
  $results = $query->execute()->fetchCol();
  $count = 0;
  foreach ($results as $nid) {
    $node = node_load($nid);
    if (og_is_group('node', $node)) { //TODO: move this logic to query
      cluster_docs_create_alias($node, 'bulkupdate');
    }
    $count++;
  }
  drupal_set_message($count . ' document paths were updated.');
}