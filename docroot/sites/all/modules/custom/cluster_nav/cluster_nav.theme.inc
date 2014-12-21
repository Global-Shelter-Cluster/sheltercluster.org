<?php

/**
 *  Implements hook_theme().
 */
function cluster_nav_theme($existing, $type, $theme, $path) {
  return array(
    'cluster_dashboard_nav' => array(
      'variables' => array(
        'items' => array(),
        'secondary' => array(),
      ),
      'template' => 'theme/cluster_nav',
    ),
    'cluster_contextual_nav' => array(
      'variables' => array(
        'regions' => array(),
        'response' => array(),
      ),
      'template' => 'theme/cluster_contextual_nav',
    ),
  );
}

/**
 *  Implements hook_preprocess_cluster_dashboard_nav().
 */
function template_preprocess_cluster_dashboard_nav(&$variables) {
  foreach ($variables['items'] as &$item) {
    $text = t($item['label']);

    if (isset($item['total'])) {
      $text .= ' <span class="total">(' . $item['total'] . ')</span>';
    }

    $item = l($text, $item['path'], array('html' => TRUE));
  }
}

/**
 *  Implements hook_preprocess_cluster_nav().
 */
function template_preprocess_cluster_contextual_nav(&$variables) {
  foreach ($variables['regions'] as &$item) {
    $item = l($item['title'], $item['path']);
  }
  if ($variables['response']) {
    $variables['response'] = l($variables['response']['title'], $variables['response']['path']);
  }
}
