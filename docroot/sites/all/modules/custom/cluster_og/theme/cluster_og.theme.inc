<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Theme a contact members user data.
 * $vars['element']['total']: the contact members total count.
 * $vars['element']['#children']: markup for all contact member accounts.
 * $vars['element'][UID]: each user account render array and markup.
 */
function theme_cluster_og_contact_member($vars) {
  $output = '<div><div>' . t('Contact members') . '</div>';
  $output .= $vars['element']['#children']; 
  $output .= '</div>';
  return $output;
}

function cluter_og_region_reference_field($vars) {
  return 'FNORD';
}

/**
 * Is wrapped by module implementation of hook_preprocess_page().
 */
function _cluster_og_preprocess_page(&$vars) {
  // Add the Region Groups menu to the page.
  $vars['page']['footer'][] = _cluster_og_get_regions_menu('menu-regions');
}

/**
 * Is wrapped by module implementation of  hook_preprocess_field().
 */
function _cluster_og_preprocess_field(&$vars) {
  // Change the path of region fields to use the custom hierarchy implementation.
  $region_fields = array('field_associated_regions', 'field_parent_region');
  if (in_array($vars['element']['#field_name'], $region_fields)) {
    $vars['element']['#theme'] = 'cluter_og_region_reference_field';
    foreach ($vars['items'] as $k => $item) {
      $wrapper = entity_metadata_wrapper('node', node_load($vars['element']['#items'][$k]['target_id']));
      $path = _cluster_og_generate_region_path($wrapper);
      $vars['items'][$k]['#markup'] = l($wrapper->label(), $path);
    }
  }
}
