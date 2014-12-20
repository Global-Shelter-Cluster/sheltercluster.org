<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * TRender the group contact members.
 * $vars['element']['#total']: the contact members total count.
 * $vars['element']['#children']: markup for all contact member accounts.
 * $vars['element'][UID]: each user account render array and markup.
 */
function theme_cluster_og_contact_member($vars) {
  $output = '<h3>' . t('Coordination Team') . '</h3>';
  $output .= '<h4>National Team</h4>';
  $output .= '<ul id="coordination-items" class="clearfix">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}

/**
 * Render a group's related responses.
 * $vars['element']['#total']: the responses total count.
 * $vars['element']['#children']: markup for all related response nodes.
 * $vars['element'][UID]: each response render array and markup.
 */
function theme_cluster_og_related_responses($vars) {
  $output = '<h3>' . t('Related Responses') . '</h3>';
  $output .= '<ul class="nav-items">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}

/**
 * Render a group's related hubs.
 * $vars['element']['#total']: the hubs total count.
 * $vars['element']['#children']: markup for all related hub nodes.
 * $vars['element'][UID]: each hub render array and markup.
 */
function theme_cluster_og_related_hubs($vars) {
  $output = '<h3>' . t('Hubs') . '</h3>';
  $output .= '<ul class="nav-items">';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}

/**
 * Render a group's recent discussions.
 * $vars['element']['#total']: the discussions total count (maximum of 2).
 * $vars['element']['#children']: markup for all discussion nodes.
 * $vars['element']['#all_discussions_link']: link for the "all discussions" page.
 * $vars['element'][UID]: each discussion render array and markup.
 */
function theme_cluster_og_recent_discussions($vars) {
  $output = '<div class="field"><div class="field-label">' . t('Discussions') . '</div>';
  $output .= $vars['element']['#children'];
  $output .= l(t('All other discussions'), $vars['element']['#all_discussions_link']);
  $output .= '</div>';
  return $output;
}

/**
 * Render a group's recent documents.
 * $vars['element']['#total']: the documents total count (maximum of 5).
 * $vars['element']['#children']: markup for all document nodes.
 * $vars['element']['#all_documents_link']: link for the "all documents" page.
 * $vars['element'][UID]: each document render array and markup.
 */
function theme_cluster_og_recent_documents($vars) {
  $output = '<div>';
  $output .= $vars['element']['#children'];
  $output .= l(t('Browse all documents'), $vars['element']['#all_documents_link'], array('attributes' => array('class' => array('browse-all-documents'))));
  $output .= '</div>';
  return $output;
}

/**
 * Theme wrapper for featured documents.
 */
function theme_cluster_og_featured_documents($vars) {
  $output = '<ul>';
  $output .= $vars['element']['#children'];
  $output .= '</ul>';
  return $output;
}

/**
 * Render a group's key document groups.
 * Doesn't render documents directly, but groups of documents which use the cluster_og_key_documents_by_tag theme.
 * $vars['element']['#children']: markup for all document groups.
 * $vars['element'][UID]: each document group render array and markup.
 */
function theme_cluster_og_key_documents($vars) {
  return $vars['element']['#children'];
}

/**
 * Render a group's key documents for a single Document Tag.
 * $vars['element']['#document_tag_name']: empty if these documents have no tag.
 * $vars['element']['#total']: the documents total count.
 * $vars['element']['#children']: markup for all document nodes.
 * $vars['element'][UID]: each document render array and markup.
 */
function theme_cluster_og_key_documents_by_tag($vars) {
  $output = '<h4>' . $vars['element']['#document_tag_name'] . '</h4>';
  $output .= '<ul class="document-cards clearfix">';
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
