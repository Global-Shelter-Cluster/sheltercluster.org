<?php

/**
 * @file
 * Theme hook, theme preprocessor and theme functions for the cluster_nav module.
 */

/**
 * Wrapped by hook_theme() implementation.
 */
function _cluster_nav_theme($existing, $type, $theme, $path) {
  $items = array(
    'cluster_nav_dashboard' => array(
      'variables' => array(
        'items' => array(),
        'secondary' => array(),
      ),
      'template' => 'theme/cluster-nav-dashboard',
      'file' => 'theme/cluster_nav.theme.inc',
    ),
    'cluster_nav_contextual' => array(
      'variables' => array(
        'regions' => array(),
        'response' => array(),
      ),
      'template' => 'theme/cluster-nav-contextual',
      'file' => 'theme/cluster_nav.theme.inc',
    ),
    'cluster_nav_related_links' => array(
      'variables' => array(
        'header' => FALSE,
        'node' => FALSE,
        'type' => FALSE,
        'related_nodes' => array(),
        'related_type' => FALSE,
        'links' => array(),
      ),
      'template' => 'theme/cluster-nav-related-links',
      'file' => 'theme/cluster_nav.theme.inc',
    ),
    'cluster_nav_related_link' => array(
      'variables' => array(
        'node' => FALSE,
        'link' => FALSE,
        'icon' => FALSE,
      ),
      'template' => 'theme/cluster-nav-related-link',
      'file' => 'theme/cluster_nav.theme.inc',
    ),
  );
  return $items;
}

/**
 * Implements hook_preprocess_cluster_nav_related_links().
 */
function template_preprocess_cluster_nav_related_links(&$variables) {
  // Generate the icon for the individual links.
  // Test if _svg() function is available.
  if (function_exists('_svg')) {
    switch ($variables['related_type']) {
      case 'hub':
        $link_icon = _svg('icons/grid-three-up', array('alt' => 'Icon for hubs'));
        break;
      case 'response':
        $link_icon = _svg('icons/globe', array('alt' => 'Icon for related responses'));
        break;
      case 'working_group':
      case 'strategic_advisory':
      default:
       $link_icon = _svg('icons/grid-three-up', array('alt' => 'Icon for links'));
    }
  }

  global $language;
  // Prepare the individual links render arrays.
  foreach ($variables['related_nodes'] as $node) {
    global $language;
    $wrapper = entity_metadata_wrapper('node', $node);
    $variables['links'][] = array(
      '#theme' => 'cluster_nav_related_link__' . $variables['related_type'],
      '#node' => $node,
      '#link' => l($link_icon . $wrapper->label(), 'node/' . $node->nid , array('html'=>true)),
    );
  }
}

/**
 *  Implements hook_preprocess_cluster_nav_dashboard().
 */
function template_preprocess_cluster_nav_dashboard(&$variables) {
  foreach ($variables['items'] as &$item) {
    if (!isset($item['label']) || !isset($item['path']))
      continue; // Not a normal item

    $text = t($item['label']);

    if (isset($item['total'])) {
      $text .= ' <span class="total">(' . $item['total'] . ')</span>';
    }
    $item['link'] = array(
      '#type' => 'link',
      '#title' => $text,
      '#href' => $item['path'],
      '#options' => $item['options'],
    );

    if (isset($item['#suffix']))
      $item['link']['#suffix'] = $item['#suffix'];
  }
}

/**
 *  Implements hook_preprocess_cluster_nav().
 */
function template_preprocess_cluster_nav_contextual(&$variables) {
  foreach ($variables['regions'] as &$item) {
    $item = l($item['title'], $item['path']);
  }
  if ($variables['response']) {
    $variables['response'] = l($variables['response']['title'], $variables['response']['path']);
  }
}
