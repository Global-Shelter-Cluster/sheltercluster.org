<?php
/**
 * @file
 * cluster_factsheets.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_factsheets_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cluster_factsheets_image_default_styles() {
  $styles = array();

  // Exported image style: factsheet_image.
  $styles['factsheet_image'] = array(
    'label' => 'Factsheet Image',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 800,
          'height' => 600,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: factsheet_map.
  $styles['factsheet_map'] = array(
    'label' => 'Factsheet Map',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 600,
          'height' => 600,
          'upscale' => 0,
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
function cluster_factsheets_node_info() {
  $items = array(
    'factsheet' => array(
      'name' => t('Factsheet'),
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
