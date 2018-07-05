<?php
/**
 * @file
 * cluster_alert.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_alert_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cluster_alert_node_info() {
  $items = array(
    'alert' => array(
      'name' => t('Alert'),
      'base' => 'node_content',
      'description' => t('Group alert pushed to followers on the mobile app.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
