<?php

require_once dirname(__FILE__) . '/includes/shelter.helpers.inc';

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_html(&$variables) {
  $file = drupal_get_path('module', 'sb_carousel').'/js/slide.js';
  $options = array(
    'weight' => -1000, // High number to push this file to the bottom of the list
    'scope' => 'footer' // This will output the JS file in the footer scope, so at the end of the document
  );
  drupal_add_js($file, $options);

  //Adding Roboto Google Font Normal 400 and Bold 700
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto:700,400', array('group' => CSS_THEME));

}

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_page($variables) {
  // drupal_add_css();
    $theme_path = drupal_get_path('theme', 'shelter');
    $variables['theme_path'] = $theme_path;
  // Adding the viewport for mobile view
    $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, maximum-scale=1, minimal-ui',
    ),
  );
  drupal_add_html_head($viewport, 'viewport');
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

function shelter_preprocess_user_profile(&$variables) {

  if (isset($variables['elements']['#view_mode'])) {
    $view_mode = $variables['elements']['#view_mode'];

    $variables['theme_hook_suggestions'][] = 'user_profile__' . $view_mode;

    $account = $variables['elements']['#account'];
    $variables['user_profile']['name']['#prefix'] = '<span class="name">';
    $variables['user_profile']['name']['#markup'] = $account->name;
    $variables['user_profile']['name']['#suffix'] = '</span>';
    $variables['user_profile']['email']['#markup'] = l($account->mail, 'mailto:' . $account->mail, array('class' => array('email'), 'absolute' => TRUE));
    if ( empty($account->picture)) {
      $variables['user_profile']['user_picture']['#markup'] = _svg('icons/person', array('class'=>'person-avatar', 'alt' => 'Team member\'s people picture missing.'));
    } else {
      $variables['user_profile']['user_picture']['#markup'] = theme('image_style', array(
        'style_name' => 'thumbnail',
        'path' => $account->picture->uri,
        'width' => 100,
        'height' => 100,
        'alt' => t('@name\'s picture', array('@name' => $account->name))
      ));
    }
  }
}

/**
 * Implements hook_preprocess().
 * Define view mode based templates and specific preprocesses
 * @param $variables
 */
function shelter_preprocess_node(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];
  $is_group = og_is_group('node', $node);

  if ($is_group) {
    $variables['theme_hook_suggestions'][] = 'node__group';
  }

  // Adding view mode based theme suggestions and preprocesses
  $variables['theme_hook_suggestions'][] = 'node__partial__' . $variables['view_mode'];
  $view_mode_based_preprocess = 'shelter_preprocess_node_partial__' . $variables['view_mode'];
  if (function_exists($view_mode_based_preprocess)) {
    $view_mode_based_preprocess($variables);
  }

  // Create some contextual navigation if viewing a group
  if ($is_group && $view_mode == 'full'){

    try {
      $group_wrapper = entity_metadata_wrapper('node', $node);

      if ( isset($group_wrapper->field_image)) {
        $group_image = $group_wrapper->field_image->value();
        $variables['group_image'] = theme('image_style', array(
          'style_name' => 'large',
          'path' => $group_image['uri'],
          'width' => 290,
          'alt' => t('A picture representing @group_name', array('@group_name' => $group_wrapper->title->value())),
          'attributes' => array(
            'class' => array('operation-image'),
          ),
        ));
      }

      $variables['contextual_navigation'] = '<nav id="contextual-navigation">';

      if (isset($group_wrapper->field_parent_region)) {
        $nid = $group_wrapper->field_parent_region->nid->value();
        $title = $group_wrapper->field_parent_region->title->value();
        $variables['contextual_navigation'] .= '<span>'. t('In ') . l($title, 'node/' . $nid ) . '</span>';
      }
      if (isset($group_wrapper->field_associated_regions )) {
        $variables['contextual_navigation'] .= '<span>' . t('In ');
        $regions = $group_wrapper->field_associated_regions->value();
        $region_count = count($regions);
        foreach ($regions as $index => $region) {
          $nid = $region->nid;
          $title = $region->title;
          $variables['contextual_navigation'] .= l($title, 'node/' . $nid );
          if ($index+1 == $region_count-1) {
            $variables['contextual_navigation'] .= t(' and ');
          } elseif ($index+1 < $region_count) {
            $variables['contextual_navigation'] .= ', ';
          }
        }
        $variables['contextual_navigation'] .= '</span>';
      }
      if (isset($group_wrapper->field_parent_response)) {
        $response = $group_wrapper->field_parent_response->value();
        if (!empty($response)) {
          $variables['contextual_navigation'] .= '<span>' . t('and related to ' ) . l($response->title, 'node/' . $response->nid ) . '</span>';
        }
      }

      $variables['contextual_navigation'] .= '</nav>';
    }
    catch (EntityMetadataWrapperException $exception) {
      _log_entity_metadata_wrapper_error($exception, 'shelter');
    }
  }

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
  $markup = _svg('icons/globe', array('alt' => 'Icon for Related Responses')) . ' ' . $node->title;
  $variables['link'] = l( $markup, 'node/' . $node->nid , array('html'=>true));
}
