<?php

/**
 * @file
 * Shelter theme template.php.
 */

require_once dirname(__FILE__) . '/includes/shelter.helpers.inc';

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_html(&$variables) {

  // Adding Roboto Google Font Normal 400 and Bold 700
  drupal_add_css('//fonts.googleapis.com/css?family=Roboto:700,400', array('group' => CSS_THEME));
}

/**
 * Implements hook_preprocess_page().
 */
function shelter_preprocess_page(&$variables) {
  // Put the language switcher in a variable.
  $block = module_invoke('locale', 'block_view', 'language_content');
  $variables['language_switcher'] = $block['content'];
  global $base_url;
  $variables['base_url'] = $base_url;
  $current_path = current_path();
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
  $variables['is_regions_and_countries'] = FALSE;
  $variables['is_user_profile_pages'] = FALSE;

  if ($variables['is_front']) {
    $variables['hot_responses'] = cluster_og_hot_responses();
    $variables['upcoming_events'] = cluster_events_upcoming();
  }
  if ($current_path == 'regions-countries') {
    $variables['is_regions_and_countries'] = TRUE;
  }
  if (arg(0) == 'user') {
    $variables['is_user_profile_pages'] = TRUE;
  }

  $variables['extra'] = FALSE;
  if (isset($variables['page']['content']['system_main']['side-column'])) {
    $variables['extra'] = $variables['page']['content']['system_main']['side-column'];
    unset($variables['page']['content']['system_main']['side-column']);
  }
  elseif ($node = menu_get_object()) {
    if (isset($variables['page']['content']['system_main']['nodes'][$node->nid][0]['side-column'])) {
      $variables['extra'] = $variables['page']['content']['system_main']['nodes'][$node->nid][0]['side-column'];
      unset($variables['page']['content']['system_main']['nodes'][$node->nid][0]['side-column']);
    }
  }
}

/**
 * Implements partial__{name}_preprocess().
 */
function partial__homepage_preprocess(&$variables) {
  // Not using Tableau for now
  // drupal_add_js('https://public.tableau.com/javascripts/api/viz_v1.js', 'external');

  $homepage_menu = menu_tree('menu-homepage');
  $variables['homepage_menu'] = render($homepage_menu);
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
  $variables['edit_link'] = FALSE;
  // Add an edit link users having the appropriate permission.
  if (node_access('update', $node)) {
    $variables['edit_link'] = l(t('Edit'), 'node/' . $node->nid . '/edit', array('attributes' => array('class' => array('edit-link'))));
  }
  $view_mode = $variables['view_mode'];
  $is_group = og_is_group('node', $node);

  if ($is_group) {
    $variables['theme_hook_suggestions'][] = 'node__group';
  }

  // Adding view mode based theme suggestions and preprocesses.
  $variables['theme_hook_suggestions'][] = 'node__' . $node->type . '__' . $variables['view_mode'];

  $view_mode_based_preprocess = 'shelter_preprocess_node' . $node->type . '_' . $variables['view_mode'];
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
 * Implements hook_form_FORM_ID_alter().
 */
function shelter_form_search_form_alter(&$form, $form_state) {
  $form['basic']['#attributes']['class'][] = 'clearfix';
  $form['advanced']['keywords']['#prefix'] = '<div class="criterion clearfix">';
  $form['advanced']['type']['#prefix'] = '<div class="criterion checkboxlist clearfix">';
  $form['advanced']['language']['#prefix'] = '<div class="criterion checkboxlist clearfix">';
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

/**
 * Implements hook suggestion for local block links.
 *
 * Replace full language name with abreviation.
 */
function shelter_links__locale_block(&$variables) {
  $links = $variables['links'];
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,

          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }
    $attributes['class'][] = 'language';
    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);
      $class[] = 'language';
      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page())) && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['language']->language, $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>";
    }

    $output .= '</ul>';
  }

  return $output;
}

/**
 * Partial preprocessor.
 */
function shelter_partial__contact_members_preprocess(&$variables) {
  $variables['contacts'] = FALSE;
  foreach ($variables['nodes'] as $node) {
    $variables['contacts'][$node->nid] = node_view($node);
  }
}

/**
 * Theme override.
 */
function shelter_field__field_role_or_title(&$variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }

  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    $classes = ($delta % 2 ? 'odd' : 'even');
    $output .= '<span class="job-title ' . $classes . '"' . $variables['item_attributes'][$delta] . '">' . drupal_render($item) . '</span>';
  }

  return $output;
}

/**
 * Theme override.
 */
function shelter_field__field_phone_number(&$variables) {
  $output = '';

  // Render the label, if it's not hidden.
  if (!$variables['label_hidden']) {
    $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
  }
  // Render the items.
  foreach ($variables['items'] as $delta => $item) {
    $value = drupal_render($item);
    $classes = ($delta % 2 ? 'odd' : 'even');
    $output .= '<a class="telephone ' . $classes . '"' . $variables['item_attributes'][$delta] . ' href="tel:+' . $value . '">' . $value . '</a>';
  }

  return $output;
}
