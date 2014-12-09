<?php

/**
 *  Implements hook_pathauto().
 */
function cluster_discussions_pathauto($op) {
  $settings = new stdClass();
  $settings->module = 'cluster_discussions';
  $settings->groupheader = t('Group discussions paths');
  $settings->patterndescr = t('Default path pattern');
//  $settings->patterndefault = '[node:url:path]/discussions';
  $settings->patterndefault = '[node:content-type]/[node:title]/discussions';
  $settings->token_type = 'node';
  $settings->patternitems = array('discussions' => 'Group discussions');
  $settings->batch_update_callback = 'cluster_discussions_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group discussion list pages.
 */
function cluster_discussions_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');
  pathauto_create_alias('cluster_discussions', $op, 'node/'.$node->nid.'/discussions', array('node' => $node), 'discussions');
}

/**
 *  Implements hook_node_insert().
 */
function cluster_discussions_node_insert($node) {
  if (og_is_group('node', $node)) {
    cluster_discussions_create_alias($node, 'insert');
  }
}

/**
 *  Implements hook_node_update().
 */
function cluster_discussions_node_update($node) {
  if (og_is_group('node', $node)) {
    cluster_discussions_create_alias($node, 'update');
  }
}

/**
 * Refreshes all aliases.
 */
function cluster_discussions_pathauto_bulkupdate() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $results = $query->execute()->fetchCol();
  $count = 0;
  foreach ($results as $nid) {
    $node = node_load($nid);
    if (og_is_group('node', $node)) { //TODO: move this logic to query
      cluster_discussions_create_alias($node, 'bulkupdate');
    }
    $count++;
  }
  drupal_set_message($count . ' discussion paths were updated.');
}