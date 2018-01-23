<?php
/**
 * @file
 * cluster_home.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_home_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cluster_home_image_default_styles() {
  $styles = array();

  // Exported image style: highlight.
  $styles['highlight'] = array(
    'label' => 'Highlight (880x440)',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 880,
          'height' => 440,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function cluster_home_node_info() {
  $items = array(
    'homepage' => array(
      'name' => t('Homepage'),
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
