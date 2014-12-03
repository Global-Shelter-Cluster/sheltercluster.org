<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Render a group's discussions.
 * $vars['element']['#total']: the discussions total count.
 * $vars['element']['#children']: markup for all discussion nodes.
 * $vars['element'][UID]: each discussion render array and markup.
 */
function theme_cluster_discussions_all($vars) {
  $output = '<div class="field">';
  $output .= $vars['element']['#children'];
  $output .= '</div>';
  return $output;
}
