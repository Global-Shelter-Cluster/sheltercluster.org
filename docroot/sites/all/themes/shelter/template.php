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
  $entity_info['node']['view modes']['contextual_navigation'] = array(
    'label' => t('Contextual Navigation'),
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
  $view_mode = $variables['view_mode'];

  if ($view_mode == 'full'){
    if (og_is_group('node', $node)) {
      $variables['theme_hook_suggestions'][] = 'node__group';
    }
  }
  else {
    // Adding view mode based theme suggestions and preprocesses
    $variables['theme_hook_suggestions'][] = 'node__partial__' . $variables['view_mode'];
    $view_mode_based_preprocess = 'shelter_preprocess_node_partial__' . $variables['view_mode'];
    if (function_exists($view_mode_based_preprocess)) {
      $view_mode_based_preprocess($variables);
    }
  }
}

/**
 * Implements hook_preprocess_node__[view mode]().
 * Define view mode based specific preprocess
 * @param $variables
 */
function shelter_preprocess_node_partial__related_hub(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')) . ' ' . $node->title;
  $variables['link'] = l( $markup, 'node/' . $node->nid , array('html'=>true));
}

function shelter_preprocess_node_partial__related_response(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')) . ' ' . $node->title;
  $variables['link'] = l( $markup, 'node/' . $node->nid , array('html'=>true));
}

function shelter_preprocess_node_partial__contextual_navigation(&$variables) {
  $node = $variables['node'];
  try {
    $node_wrapper = entity_metadata_wrapper('node', $node);

    if (isset($node_wrapper->field_parent_response)) {
      //dpm('response');
    }
    if (isset($node_wrapper->field_parent_region)) {
      //dpm('region');
    }
    if (isset($node_wrapper->field_associated_regions )) {
      //dpm('associated regions');
    }

    //dpm($node_wrapper->getPropertyInfo());
  }
  catch (EntityMetadataWrapperException $exception) {
    _log_entity_metadata_wrapper_error($exception, 'po_promoted');
  }
}
