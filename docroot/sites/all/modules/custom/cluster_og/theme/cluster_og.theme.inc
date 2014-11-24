<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Theme a contact members user data.
 */
function theme_cluster_og_contact_member($vars) {
  if (! $members = $vars['element']['contact_members']) {
    return;
  }

  $output = '<div><div>' . t('Contact members') . '</div>';
  foreach ($vars['element']['contact_members'] as $user) {
    $output .= '<div>' . $user->name . '</div>';
  }
  return '</div>' . $output;
}