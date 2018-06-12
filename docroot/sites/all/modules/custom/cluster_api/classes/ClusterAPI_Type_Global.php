<?php

class ClusterAPI_Type_Global extends ClusterAPI_Type {

  protected static $type = 'global';
  protected static $related_def = [
    'featured_groups' => ['type' => 'group', 'mode' => ClusterAPI_Object::MODE_PUBLIC],
  ];

  /**
   * Example:
   *
   * {
   *   featured_groups: [123, 456],
   * }
   *
   */
  protected function generateObject($id, $mode) {
    if ($id != 1 || $mode !== ClusterAPI_Object::MODE_PUBLIC)
      throw new Exception("Global object must be public and have id = 1");

    $ret = [];

    $featured_groups = cluster_og_get_hot_response_nodes();
    if ($featured_groups === FALSE)
      $featured_groups = [];
    else
      $featured_groups = array_values(array_map(function($node) {return intval($node->nid);}, $featured_groups));
    $ret['featured_groups'] = $featured_groups;

    return $ret;
  }
}
