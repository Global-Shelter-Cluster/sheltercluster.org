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