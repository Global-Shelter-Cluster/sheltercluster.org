<?php
/**
 * @file
 * cluster_contact.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_contact_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function cluster_contact_image_default_styles() {
  $styles = array();

  // Exported image style: contact_avatar.
  $styles['contact_avatar'] = array(
    'label' => 'Contact Avatar',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 120,
          'height' => 120,
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
function cluster_contact_node_info() {
  $items = array(
    'contact' => array(
      'name' => t('Contact'),
      'base' => 'node_content',
      'description' => t('Content type describing an individual and his or her role within the context of a group.'),
      'has_title' => '1',
      'title_label' => t('Full name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
