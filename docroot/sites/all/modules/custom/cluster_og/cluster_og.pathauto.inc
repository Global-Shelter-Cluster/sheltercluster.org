<?php

/**
 *  Implements hook_pathauto().
 */
function cluster_og_pathauto($op) {
  $settings = new stdClass();
  $settings->module = 'cluster_og';
  $settings->groupheader = t('Group paths');
  $settings->patterndescr = t('Default path pattern');
  $settings->patterndefault = '[node:content-type]/[node:title]/followers';
  $settings->token_type = 'node';
  $settings->patternitems = array('followers' => 'Group followers');
  $settings->batch_update_callback = 'cluster_og_pathauto_bulkupdate';
  return $settings;
}

/**
 * Helper function to create aliases for group og list pages.
 */
function cluster_og_create_alias($node, $op) {
  module_load_include('inc', 'pathauto');

  pathauto_create_alias('cluster_og', $op, 'node/'.$node->nid.'/followers', array('node' => $node), 'followers', $node->language);
}

/**
 * Refreshes all aliases.
 */
function cluster_og_pathauto_bulkupdate(&$context) {
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
    cluster_og_create_alias($node, 'bulkupdate');
  }

  $context['sandbox']['count'] += count($nids);
  $context['sandbox']['current'] = max($nids);
  $context['message'] = t('Updated alias for node @nid.', array('@nid' => end($nids)));

  if ($context['sandbox']['count'] != $context['sandbox']['total']) {
    $context['finished'] = $context['sandbox']['count'] / $context['sandbox']['total'];
  }

}
