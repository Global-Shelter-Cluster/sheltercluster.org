<?php
/**
 * @file
 * cluster_kobo.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_kobo_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cluster_kobo_node_info() {
  $items = array(
    'kobo_form' => array(
      'name' => t('Kobo form'),
      'base' => 'node_content',
      'description' => t('Associate a kobo form with a Drupal content so that forms can be added to groups.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
