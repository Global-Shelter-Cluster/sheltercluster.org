<?php

require_once dirname(__FILE__) . '/includes/shelter.helpers.inc';

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_html(&$variables) {

  // Adding Roboto Google Font Normal 400 and Bold 700
  drupal_add_css('http://fonts.googleapis.com/css?family=Roboto:700,400', array('group' => CSS_THEME));
}

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_page(&$variables) {
  // Adding the viewport for mobile view.
  $viewport = array(
    '#tag' => 'meta',
    '#attributes' => array(
      'name' => 'viewport',
      'content' => 'width=device-width, initial-scale=1, maximum-scale=1, minimal-ui',
    ),
  );
  drupal_add_html_head($viewport, 'viewport');

  libraries_load('underscore');
  drupal_add_library('underscore', 'underscore');
  drupal_add_library('system', 'jquery.cookie');
  $variables['hot_responses'] = FALSE;
  if ($variables['is_front']) {
    $variables['hot_responses'] = cluster_og_hot_responses();
  }
}

/**
 * Implements hook_preprocess_user_profile().
 */
function shelter_preprocess_user_profile(&$variables) {

  if (isset($variables['elements']['#view_mode'])) {
    $view_mode = $variables['elements']['#view_mode'];

    $variables['theme_hook_suggestions'][] = 'user_profile__' . $view_mode;

    $account = $variables['elements']['#account'];
    $variables['user_profile']['name']['#prefix'] = '<span class="name">';
    $variables['user_profile']['name']['#markup'] = $account->name;
    $variables['user_profile']['name']['#suffix'] = '</span>';
    $variables['user_profile']['email']['#markup'] = l($account->mail, 'mailto:' . $account->mail, array('class' => array('email'), 'absolute' => TRUE));
    if (empty($account->picture)) {
      $variables['user_profile']['user_picture']['#markup'] = _svg('icons/person', array('class' => 'person-avatar', 'alt' => 'Team member\'s people picture missing.'));
    }
    else {
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
 * Implements hook_preprocess_node().
 */
function shelter_preprocess_node(&$variables) {
  $node = $variables['node'];
  $view_mode = $variables['view_mode'];
  $is_group = og_is_group('node', $node);

  if ($is_group) {
    $variables['theme_hook_suggestions'][] = 'node__group';
  }

  // Adding view mode based theme suggestions and preprocesses.
  $variables['theme_hook_suggestions'][] = 'node__partial__' . $variables['view_mode'];
  $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];

  $view_mode_based_preprocess = 'shelter_preprocess_node_partial__' . $variables['view_mode'];
  if (function_exists($view_mode_based_preprocess)) {
    $view_mode_based_preprocess($variables);
  }

  if ($is_group && $view_mode == 'full') {
    if ($variables['content']['featured_documents']) {

    }
    try {
      $group_wrapper = entity_metadata_wrapper('node', $node);

      if ($group_image = $group_wrapper->field_image->value()) {

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

    }
    catch (EntityMetadataWrapperException $exception) {
      _log_entity_metadata_wrapper_error($exception, 'shelter');
    }
  }

  if ($view_mode == 'full') {
    if (og_is_group('node', $node)) {
      $variables['theme_hook_suggestions'][] = 'node__group';
    }
  }
  else {
    // Adding view mode based theme suggestions and preprocesses.
    $variables['theme_hook_suggestions'][] = 'node__partial__' . $variables['view_mode'];
    $view_mode_based_preprocess = 'shelter_preprocess_node_partial__' . $variables['view_mode'];
    if (function_exists($view_mode_based_preprocess)) {
      $view_mode_based_preprocess($variables);
    }
  }

}

/**
 * Implements hook_preprocess_node__[view mode]().
 */
function shelter_preprocess_node_partial__related_hub(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')) . ' ' . $node->title;
  $variables['link'] = l($markup, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Implements hook_preprocess_node__[view mode]().
 */
function shelter_preprocess_node_partial__related_response(&$variables) {
  $node = $variables['node'];
  $markup = _svg('icons/globe', array('alt' => 'Icon for Related Responses')) . ' ' . $node->title;
  $variables['link'] = l($markup, 'node/' . $node->nid, array('html' => TRUE));
}

/**
 * Redefine menu theme functions.
 */
function shelter_menu_tree($variables) {
  return '<ul class="nav-items menu">' . $variables['tree'] . '</ul>';
}
/**
 * Redefine menu theme functions.
 */
function shelter_menu_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $element['#attributes']['class'][] = 'nav-item';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
