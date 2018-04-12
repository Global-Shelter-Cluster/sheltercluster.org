<?php

/**
 *  Implements hook_pathauto().
 */
function cluster_factsheets_pathauto($op) {
  $settings = new stdClass();
  $settings->module = 'cluster_factsheets';
  $settings->groupheader = t('Group factsheets paths');
  $settings->patterndescr = t('Default path pattern');
  $settings->patterndefault = '[node:content-type]/[node:field_title]/factsheets';
  $settings->token_type = 'node';
  $settings->patternitems = array('factsheets' => 'Group factsheets');
  $settings->batch_update_callback = 'cluster_factsheets_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group factsheet list pages.
 */
function cluster_factsheets_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');

  pathauto_create_alias('cluster_factsheets', $op, 'node/'.$node->nid.'/factsheets', array('node' => $node), 'factsheets', $node->language);
}

/**
 *  Implements hook_node_insert().
 */
function cluster_factsheets_node_insert($node) {
  if (og_is_group('node', $node)) {
    cluster_factsheets_create_alias($node, 'insert');
  }
}

/**
 *  Implements hook_node_update().
 */
function cluster_factsheets_node_update($node) {
  if (og_is_group('node', $node)) {
    cluster_factsheets_create_alias($node, 'update');
  }
}

/**
 * Refreshes all aliases.
 */
function cluster_factsheets_pathauto_bulkupdate(&$context) {
  if (!isset($context['sandbox']['current'])) {
    $context['sandbox']['count'] = 0;
    $context['sandbox']['current'] = 0;
  }

  $all_group_bundles = og_get_all_group_bundle();
  $group_node_types = array_keys($all_group_bundles['node']);

  $query = db_select('node', 'n');
  $query->fields('n', array('nid'));
  $query->condition('n.nid', $context['sandbox']['current'], '>');
  $query->condition('n.type', $group_node_types);
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
    cluster_factsheets_create_alias($node, 'bulkupdate');
  }

  $context['sandbox']['count'] += count($nids);
  $context['sandbox']['current'] = max($nids);
  $context['message'] = t('Updated alias for node @nid.', array('@nid' => end($nids)));

  if ($context['sandbox']['count'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['count'] / $context['sandbox']['total'];
  }

}
