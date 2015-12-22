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
  if (module_exists('cluster_rss')) {
    $settings->patternitems += array('rssevents' => 'Group RSS events');
  }
  $settings->batch_update_callback = 'cluster_events_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group event list pages.
 */
function cluster_events_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');
  pathauto_create_alias('cluster_events', $op, 'node/'.$node->nid.'/events', array('node' => $node), 'events');
  if (module_exists('cluster_rss')) {
    pathauto_create_alias('cluster_events', $op, 'node/'.$node->nid.'/rss/events', array('node' => $node), 'rssevents');
  }
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
function cluster_events_pathauto_bulkupdate(&$context) {
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
      cluster_events_create_alias($node, 'bulkupdate');
    }
  }

  $context['sandbox']['count'] += count($nids);
  $context['sandbox']['current'] = max($nids);
  $context['message'] = t('Updated alias for node @nid.', array('@nid' => end($nids)));

  if ($context['sandbox']['count'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['count'] / $context['sandbox']['total'];
  }
}