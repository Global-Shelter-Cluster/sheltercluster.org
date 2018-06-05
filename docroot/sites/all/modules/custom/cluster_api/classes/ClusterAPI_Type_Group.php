<?php

class ClusterAPI_Type_Group extends ClusterAPI_Type {

  protected static $type = 'group';

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
  protected static function getById($id, $mode, $persist, &$objects, &$current_user) {
    // TODO:
//    if ($current_user && $current_user->id == $id) {
//      // Force private mode and persist if the user is getting a group they're following.
//      $mode = Object::MODE_PRIVATE;
//      $persist = TRUE;
//    }

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

    $related = [];
    $ret = [
      '_mode' => $mode,
      '_persist' => $persist,
    ];

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:
//        // TODO: read 'groups' properly
//        $ret += [
//          'groups' => [9175, 10318],
//        ];
//        $related[] = [
//          'type' => 'group',
//          'id' => 9175,
//          'mode' => Object::MODE_PUBLIC,
//        ];
//        $related[] = [
//          'type' => 'group',
//          'id' => 10318,
//          'mode' => Object::MODE_PUBLIC,
//        ];
      case ClusterAPI_Object::MODE_PUBLIC:
        //        $wrapper = entity_metadata_wrapper('node', $node);
        //        $ret += [
        //          'mail' => $node->mail,
        //          //          'picture' => $picture,
        //          'org' => $wrapper->field_organisation_name->value(),
        //          'role' => $wrapper->field_role_or_title->value(),
        //        ];
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'type' => $node->type,
          'id' => $node->nid,
          'title' => $node->title,
        ];
    }

    $objects[self::$type][$id] = $ret;

    foreach ($related as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], $request['mode'], $persist, $objects, $current_user);
  }
}
