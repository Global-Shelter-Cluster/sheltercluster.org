<?php

/**
 *  Implements hook_pathauto().
 */
function cluster_events_pathauto($op) {
  $settings = new stdClass();
  $settings->module = 'cluster_events';
  $settings->groupheader = t('Group events paths');
  $settings->patterndescr = t('Default path pattern');
//  $settings->patterndefault = '[node:url:path]/events';
  $settings->patterndefault = '[node:content-type]/[node:title]/events';
  $settings->token_type = 'node';
  $settings->patternitems = array('events' => 'Group events');
  $settings->batch_update_callback = 'cluster_events_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group event list pages.
 */
function cluster_events_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');
  pathauto_create_alias('cluster_events', $op, 'node/'.$node->nid.'/events', array('node' => $node), 'events');
}

/**
 *  Implements hook_node_insert().
 */
function cluster_events_node_insert($node) {
  if (og_is_group('node', $node)) {
    cluster_events_create_alias($node, 'insert');
  }
}

/**
 *  Implements hook_node_update().
 */
function cluster_events_node_update($node) {
  if (og_is_group('node', $node)) {
    cluster_events_create_alias($node, 'update');
  }
}

/**
 * Refreshes all aliases.
 */
function cluster_events_pathauto_bulkupdate() {
  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('n.type', array('document', 'discussion', 'page', 'event'), 'NOT IN');
  $query->condition('n.status', NODE_PUBLISHED);
  $results = $query->execute()->fetchCol();
  $count = 0;
  foreach ($results as $nid) {
    $node = node_load($nid);
    if (og_is_group('node', $node)) { //TODO: move this logic to query
      cluster_events_create_alias($node, 'bulkupdate');
    }
    $count++;
  }
  drupal_set_message($count . ' event paths were updated.');
}