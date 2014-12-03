<?php

require_once dirname(__FILE__) . '/includes/shelter.helpers.inc';

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_page($variables) {
  // drupal_add_css();
  // drupal_add_js();
}

/**
 * Available view modes
 *
 * contact_member
 * related_hub
 * related_response
 */

/**
 * Implements hook_entity_info_alter().
 * Define available view modes.
 * @param $entity_info
 */
function shelter_entity_info_alter(&$entity_info) {
  $entity_info['node']['view modes']['response__content_banner'] = array(
    'label' => t('Response - Content Banner'),
    'custom settings' => TRUE,
  );
}

/**
 * Implements hook_preprocess().
 * Define view mode based templates and specific preprocesses
 * @param $variables
 */
function shelter_preprocess_node(&$variables) {
  $node = $variables['node'];

  if (og_is_group('node', $node)) {
    $variables['theme_hook_suggestions'][] = 'node__group';
  }

  // Adding view mode based theme suggestions and preprocesses
  $variables['theme_hook_suggestions'][] = 'node__' . $variables['view_mode'];
  $view_mode_based_preprocess = 'shelter_preprocess_node__' . $variables['view_mode'];
  if (function_exists($view_mode_based_preprocess)) {
    $view_mode_based_preprocess($variables);
  }

  dpm($variables);
}

/**
 * Implements hook_preprocess_node__[view mode]().
 * Define view mode based specific preprocess
 * @param $variables
 */
function shelter_preprocess_node__related_hub(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')) . ' ' . $node->title;
  $variables['link'] = l( $markup, 'node/' . $node->nid , array('html'=>true));
}

function shelter_preprocess_node__related_response(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')) . ' ' . $node->title;
  $variables['link'] = l( $markup, 'node/' . $node->nid , array('html'=>true));
}
