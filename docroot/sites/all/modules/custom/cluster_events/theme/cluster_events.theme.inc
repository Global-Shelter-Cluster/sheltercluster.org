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

/**
 * Render a list of upcoming events.
 * $vars['element']['#total']: the number of events shown.
 * $vars['element']['#children']: markup for all events shown.
 * $vars['element'][NID]: each event render array and markup.
 */
function theme_cluster_events_upcoming($vars) {
  $output = '<section id="shelter-calendar">';
  $output .= '<div id="box-calendar">';
  $output .= _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.')));
  $output .= '<div id="date-calendar">' . t('Upcoming events') . '</div>';
  $output .= '<div class="information-card">';
  $output .= $vars['element']['#children'];
  $output .= '</div>';
  $output .= '</div>';
  $output .= '</section>';
  return $output;
}
