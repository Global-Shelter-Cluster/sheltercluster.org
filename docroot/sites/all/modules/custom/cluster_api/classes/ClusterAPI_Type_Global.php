<?php

class ClusterAPI_Type_Global extends ClusterAPI_Type {

  protected static $type = 'global';
  protected static $related_def = [
    'featured_groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUBPLUS,
    ],
    'top_regions' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUBPLUS,
    ],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
    // Always persist global object
    $persist = TRUE;
  }

  /**
   * Example:
   *
   * {
   *   featured_groups: [123, 456],
   *   top_regions: [4290, ...],
   *   algolia_app_id: 'abc123',
   *   algolia_search_key: 'abc123',
   *   algolia_prefix: 'abc123',
   * }
   *
   */
  protected function generateObject($id, $mode) {
    if ($id != 1 || $mode !== ClusterAPI_Object::MODE_PUBLIC)
      throw new Exception("Global object must be public and have id = 1");

    $ret = [];

    $ret['featured_groups'] = cluster_og_get_hot_response_nids();

    $ret['top_regions'] = array_values(array_filter(array_unique(array_map(function($data) {
      $path = $data['link']['link_path'];
      return substr($path, 0, 5) === 'node/'
        ? intval(substr($path, 5))
        : NULL;
    }, menu_tree_page_data('menu-regions', 1)))));

    $ret += [
      'algolia_app_id' => variable_get('cluster_search_algolia_app_id'),
      'algolia_search_key' => variable_get('cluster_search_algolia_search_key'),
      'algolia_prefix' => variable_get('cluster_search_algolia_prefix'),
    ];

    $ret += [
      'global_id' => intval(variable_get('cluster_og_global_id', '4290'), 10),
      'resources_id' => intval(variable_get('cluster_og_resources_id', '4652'), 10),
    ];

    return $ret;
  }
}
