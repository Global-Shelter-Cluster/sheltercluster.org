<?php

/**
 * @file
 *  Menu / controler generating code.
 */

/**
 * Generate the regions menu.
 */
function cluster_og_menu_region() {
  $items = array();
  // Generate the geographic_regions menu.
  $query = new EntityFieldQuery();
  $res = $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'geographic_region')
    ->propertyCondition('status', NODE_PUBLISHED)
    ->execute();

  if (isset($res['node'])) {
    // Loop over all geographic_region nodes to create menu items.
    foreach (node_load_multiple(array_keys($res['node'])) as $node) {
      $wrapper = entity_metadata_wrapper('node', $node);
      $path = _cluster_og_generate_region_path($wrapper);
      $items[$path] = array(
        'title' => $wrapper->label(),
        'page callback' => 'cluster_og_geographic_region',
        'page arguments' => array("$node->nid", "$path"),
        'access callback' => TRUE,
        'type' => MENU_NORMAL_ITEM,
        'menu_name' => 'menu-regions',
      );
    }
  }
  return $items;
}