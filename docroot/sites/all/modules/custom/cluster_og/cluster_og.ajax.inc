<?php

/**
 * Autocomplete callback for "groups".
 * Used by the "documents" view from the cluster_docs feature.
 * @param string $string
 */
function cluster_og_groups_autocomplete($string = '') {
  $all_types = node_type_get_types();
  $types = array(); // Groups
  foreach (array_keys($all_types) as $type) {
    if (og_is_group_type('node', $type)) {
      $types[] = $type;
    }
  }

  $matches = array();
  if ($string) {
    $result = db_select('node')
      ->fields('node', array('nid', 'title', 'type'))
      ->condition('title', db_like($string) . '%', 'LIKE')
      ->condition('type', $types)
      ->range(0, 10)
      ->execute();

    foreach ($result as $node) {
      $key = $node->nid . ': ' . $node->title . ' (' . $all_types[$node->type]->name . ')';
      $label = $node->title . ' (' . $all_types[$node->type]->name . ')';
      $matches[$key] = $label;
    }
  }

  drupal_json_output($matches);
}