<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Render a group's events.
 * $vars['element']['#total']: the events total count.
 * $vars['element']['#children']: markup for all event nodes.
 * $vars['element'][UID]: each event render array and markup.
 */
function theme_cluster_events_all($vars) {
  $output = '<div class="events"><ul>';
  $output .= $vars['element']['#children'];
  $output .= '</ul></div>';
  return $output;
}

/**
 * Render a single event teaser to be shown in a group's page.
 */
function theme_cluster_events_teaser($vars) {
  $output = '<div class="event-item clearfix">';

  $output .= l($vars['element']['#node']->title, 'node/' . $vars['element']['#node']->nid, array(
    'attributes' => array(
      'class' => 'event',
    ),
  ));

  $output .= '</div>';

  return $output;
}
