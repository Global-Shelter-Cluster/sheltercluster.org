<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Render the group contact members.
 * $vars['element']['#total']: the contact members total count.
 * $vars['element']['#children']: markup for all contact member accounts.
 * $vars['element'][UID]: each user account render array and markup.
 */
function theme_cluster_og_contact_member($vars) {
  $output = '<h3 data-collapsible="coordination-items">' . t('Coordination Team') . '</h3>';
  $output .= '<div id="coordination-items">';
  $output .= '<ul class="clearfix">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  $output .= '</div>';
  return $output;
}

/**
 * Render a group's recent discussions.
 * @TODO delegate theme responsibility completely to cluster_discussions.
 * This theme implementation has been declared as expecting a render array.
 * $vars['element']['#total']: the discussions total count (maximum of 2).
 * $vars['element']['#children']: markup for all discussion nodes.
 * $vars['element']['#all_discussions_link']: link for the "all discussions" page.
 * $vars['element'][UID]: each discussion render array and markup.
 */
function theme_cluster_og_recent_discussions($vars) {
  $output = '<section id="shelter-discussions">';
  $output .= _svg('icons/discussion', array('id' => 'discussion-icon', 'alt' => t('An icon representing discussions.')));
  $output .= '<h3>' . t('Discussions') . '</h3>';
  $output .= '<ul id="discussions-items">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  $output .= l(t('All other discussions'), $vars['element']['#all_discussions_link'], array(
    'attributes' => array(
      'class' => 'see-all',
    ),
  ));
  $output .= '</section>';
  return $output;
}

function theme_cluster_og_upcoming_events($vars) {
  return partial('upcoming_events', array(
    'title' => t('Upcoming events'),
    'events' => $vars['events'],
    'all_events_link' => l(t('All calendar event'), $vars['all_events_link'], array('attributes' => array('class' => array('see-all'))))
  ));
}

function theme_cluster_og_recent_documents($vars) {
  return partial('recent_documents', array(
    'title' => t('Latest documents'),
    'docs' => $vars['docs'],
    'all_documents_link' => l(t('All documents'), $vars['all_documents_link'], array('attributes' => array('class' => array('see-all'))))
  ));
}

function theme_cluster_og_all_events($vars) {
  return partial('all_events', array(
    'title' => t('All events'),
    'events' => $vars['events'],
  ));
}

function theme_cluster_og_no_upcoming_event($vars) {
  return partial('upcoming_events', array(
    'title' => t('No Upcoming Events'),
    'events' => $vars['events'],
    'all_events_link' => l(t('All calendar event'), $vars['all_events_link'], array('attributes' => array('class' => array('see-all'))))
  ));
}

/**
 * Theme wrapper for featured documents.
 * @TODO delegate to cluster_docs module.
 */
function theme_cluster_og_featured_documents($vars) {
  $output = '<ul>';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}

/**
 * Is wrapped by module implementation of hook_preprocess_page().
 */
function _cluster_og_preprocess_page(&$vars) {
  // Add the Region Groups menu to the page.
  $vars['page']['footer']['menu_regions'] = _cluster_og_get_regions_menu('menu-regions', FALSE);
  $vars['page']['footer']['hot_responses'] = cluster_og_hot_responses_list();
  $vars['page']['footer']['general_information'] = _cluster_og_get_regions_menu('menu-general-information', FALSE);
}
