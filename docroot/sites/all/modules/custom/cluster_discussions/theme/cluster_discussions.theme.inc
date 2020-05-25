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
  $is_list_page = $vars['element']['#is_list_page'];

  $output = '<div class="discussions-item clearfix">';

  $output .= '<div class="replies">' . $vars['element']['#replies'];
  if ($vars['element']['#is_latest']) {
    $output .= '<span class="new">' . t('Latest') . '</span>';
  }
  $output .= '</div>';

  $date = '<span class="date">';
  if ($is_list_page) {
    $date .= l($vars['element']['#author']['name'], $vars['element']['#author']['path']);
    $date .= ' &middot; ';
    $date .= format_date($vars['element']['#node']->created, 'short');
  } else {
    $date .= format_date($vars['element']['#node']->created, 'short');
  }
  $date .= '</span>';

  if ($is_list_page)
    $output .= $date;

  $output .= '<div class="information">';
  $output .= l($vars['element']['#node']->title, 'node/' . $vars['element']['#node']->nid, array(
    'attributes' => array(
      'class' => 'topic',
    ),
  ));

  if ($is_list_page) {
    $output .= text_summary(
      $vars['element']['body']['#items'][0]['safe_value'],
      $vars['element']['body']['#items'][0]['format'],
      200
    );
  }

  if (!$is_list_page)
    $output .= $date;

  $output .= '</div></div>';

  return $output;
}
