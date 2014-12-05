<?php
/**
 * @file
 * cluster_discussions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_discussions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cluster_discussions_node_info() {
  $items = array(
    'discussion' => array(
      'name' => t('Discussion'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
