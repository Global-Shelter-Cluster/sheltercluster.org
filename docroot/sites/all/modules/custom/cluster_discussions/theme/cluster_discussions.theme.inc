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

/**
 * Render a single discussion teaser to be shown in a group's page.
 */
function theme_cluster_discussions_teaser($vars) {
  $output = '<li class="discussions-item">';

  $output .= '<div class="replies">' . $vars['element']['#replies'];
  if ($vars['element']['#is_latest']) {
    $output .= '<span class="new">' . t('Latest') . '</span>';
  }
  $output .= '</div>';

  $output .= '<div class="information">';
  $output .= l($vars['element']['#node']->title, 'node/' . $vars['element']['#node']->nid, array(
    'attributes' => array(
      'class' => 'topic',
    ),
  ));
  $output .= '<span class="date">';
  $output .= format_date($vars['element']['#node']->created, 'short');
  $output .= t(' by ');
  $output .= l($vars['element']['#author']['name'], $vars['element']['#author']['path']);
  $output .= '</span>';
  $output .= '</div>';

  $output .= '</li>';
  return $output;
}
