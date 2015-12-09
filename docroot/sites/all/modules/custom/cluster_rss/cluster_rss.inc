<?php
/**
 * @file
 * Cluster RSS.
 */

/**
 * Render function for RSS templates.
 */
function cluster_rss($node, $type) {
  $entity = new GroupContentManagerRSS($node);

  switch ($type) {
    case 'discussions':
      list($items, $created) = $entity->getDiscussionsRSSData();
      break;

    case 'events':
      list($items, $created) = $entity->getEventsRSSData();
      break;

    case 'documents':
      list($items, $created) = $entity->getDocsRSSData();
      break;

    default:
      drupal_not_found();
      drupal_exit();
  }

  global $base_root;
  $date = format_date($created, 'custom', 'D, d M Y H:i:s O');
  $title = $node->title;
  $path = $base_root . request_uri();
  return theme(
    'cluster_rss',
    array(
      'items' => $items,
      'date' => $date,
      'title' => $title,
      'path' => $path,
      'type' => ucfirst($type),
    )
  );
}


/**
 * Delivery callback to custom print xml content.
 */
function cluster_rss_deliver($content) {
  // Some sites use xml only on content type, but application/rss+xml is the
  // value that should be used for RSS readers.
  drupal_add_http_header('Content-Type', 'application/rss+xml; charset=utf-8');
  drupal_send_headers();
  print $content;
  drupal_exit();
}
