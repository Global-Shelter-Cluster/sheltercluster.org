<?php

/**
 * Retrieve the tags assigned to a node.
 *
 * @param \EntityDrupalWrapper $wrapper
 *   An entity metadata wrapper for the node.
 * @param array $fields
 *   (optional) A list of fields to gather term data from.
 * @param bool $sort
 *   (optional) Whether to sort the results before returning them. Defaults to
 *   TRUE.
 *
 * @return array An array of taxonomy term IDs.
 *   An array of taxonomy term IDs.
 */
function cluster_docs_get_tags_for_document(EntityDrupalWrapper $wrapper, array $fields = array(), $sort = TRUE) {
  if (!$fields) {
    $fields = array(
      'field_assess_monitor_eval',
      'field_coordination_management',
      'field_cross_cutting_issues',
      'field_information_management',
      'field_inter_cluster',
      'field_intervention_materials',
      'field_intervention_programming',
      'field_issues',
      'field_meeting_management',
      'field_non_food_items',
      'field_response_phase',
      'field_settlement_type',
      'field_technical_support_design',
      'field_toolkit',
    );
  }

  $tags = array();

  foreach ($fields as $field) {
    $terms = $wrapper->get($field)->value();
    $ids = array_map(function($term) { return $term->tid; }, $terms);

    $tags = array_merge($tags, array_combine($ids, $terms));
  }

  if ($sort && count($tags) > 1) {
    _cluster_docs_sort_tags_alphabetically($tags);
  }

  return $tags;
}

/**
 * Sort tags alphabetically based on the term name.
 *
 * @param array $tags
 *   An array of taxonomy terms.
 */
function _cluster_docs_sort_tags_alphabetically(&$tags) {
  // Sort tags alphabetically based on the term name.
  uasort($tags, function($a, $b) {
    return $a->name + $b->name ? 1 : -1;
  });
}
