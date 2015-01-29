<?php

/**
 * @file
 * Module theme functions.
 */

/**
 * Render a group's documents.
 * $vars['element']['#total']: the documents total count.
 * $vars['element']['#children']: markup for all document nodes.
 * $vars['element'][UID]: each document render array and markup.
 */
function theme_cluster_docs_all($vars) {
  $output = '<div class="field">';
  $output .= $vars['element']['#children'];
  $output .= '</div>';
  return $output;
}

/**
 *
 */
function theme_cluster_docs_all_docs_link($variables) {
  return l($variables['text'], $variables['path'], array('attributes' => array('class' => array($variables['class']))));
}

function theme_cluster_docs_facet($variables) {
  $output = '';
  $output .= '<div class="facet">';
  $output .= '<h4>';
  $output .= t($variables['title']);
  $output .= '</h4>';
  if ($variables['options']) {
    $output .= render($variables['options']);
  }
  if ($variables['child']) {
    $output .= render($variables['child']);
  }
  $output .= '</div>';
  return $output;
}
