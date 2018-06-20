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

    return $ret;
  }
}
