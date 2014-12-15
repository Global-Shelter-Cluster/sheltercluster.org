<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Render the user menu.
 * $vars['element']['#children']: markup for all menu items.
 * $vars['element'][UID]: each menu item.
 */
function theme_cluster_user_menu($vars) {
  $output = '<ul id="profile-menu-items">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}
