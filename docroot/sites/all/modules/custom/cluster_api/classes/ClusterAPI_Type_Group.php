<?php

class ClusterAPI_Type_Group extends ClusterAPI_Type {

  protected static $type = 'group';
  protected static $related_def = [
    'associated_regions' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'parent_response' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'parent_region' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    //    'latest_factsheet' => ['type' => 'factsheet', 'mode' => ClusterAPI_Object::MODE_PUBLIC],
  ];

  /**
   * Example:
   *
   * {
   *   _mode: OBJECT_MODE_PRIVATE,
   *   _persist: true,
   *   type: "response",
   *   id: 9175,
   *   title: "Ecuador Earthquake 2016",
   *   associated_regions: [9104, 62],
   *   latest_factsheet: 13454,
   * }
   *
   */
  protected function getById($id, $mode, $persist, &$objects, $level) {
    if ($this->current_user) {
      $current_user_groups = array_values(og_get_groups_by_user($this->current_user, 'node'));
      if (in_array($id, $current_user_groups)) {
        // Force public mode and persist if this is one of the current user's followed groups.
        $mode = ClusterAPI_Object::MODE_PUBLIC;
        $persist = TRUE;
      }
    }

    if (array_key_exists($id, $objects[self::$type])) {
      $existing = $objects[self::$type];

      $is_higher_detail_level = ClusterAPI_Object::detailLevel($mode) > ClusterAPI_Object::detailLevel($existing['_mode']);
      if (!$is_higher_detail_level) {
        $persist_changed_to_true = !$existing['_persist'] && $persist;
        if (!$persist_changed_to_true) {
          // No reason to calculate this object again.
          return;
        }
      }
    }

    $node = node_load($id);
    if (!og_is_group('node', $node))
      // This id is not for a group node
      return;

    $ret = [
      '_mode' => $mode,
      '_persist' => $persist,
    ];

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

        //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:

        //Fall-through
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'type' => $node->type,
          'id' => $node->nid,
          'title' => $node->title,
        ];
    }

    $objects[self::$type][$id] = $ret;

    foreach ($this->related($ret) as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], $request['mode'], $persist, $objects, $this->current_user, $level);
  }
}
