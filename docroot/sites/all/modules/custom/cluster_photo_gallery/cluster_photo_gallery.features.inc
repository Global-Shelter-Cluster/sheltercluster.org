<?php
/**
 * @file
 * cluster_photo_gallery.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_photo_gallery_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cluster_photo_gallery_image_default_styles() {
  $styles = array();

  // Exported image style: photo_gallery_full.
  $styles['photo_gallery_full'] = array(
    'label' => 'Photo gallery full',
    'effects' => array(
      5 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1920,
          'height' => 1080,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: photo_gallery_medium.
  $styles['photo_gallery_medium'] = array(
    'label' => 'Photo gallery medium',
    'effects' => array(
      4 => array(
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

  // Exported image style: photo_gallery_thumbnail.
  $styles['photo_gallery_thumbnail'] = array(
    'label' => 'Photo gallery thumbnail',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 125,
          'height' => 125,
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
function cluster_photo_gallery_node_info() {
  $items = array(
    'photo_gallery' => array(
      'name' => t('Photo gallery'),
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
