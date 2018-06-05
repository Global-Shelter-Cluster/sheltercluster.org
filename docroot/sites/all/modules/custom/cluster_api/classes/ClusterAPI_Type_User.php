<?php

class ClusterAPI_Type_User extends ClusterAPI_Type {

  protected static $type = 'user';

  /**
   * Example:
   *
   * {
   *   _mode: OBJECT_MODE_PRIVATE,
   *   _persist: true,
   *   id: 733,
   *   name: 'Camilo',
   *   mail: 'hola@cambraca.com',
   *   picture: "https://www.sheltercluster.org/.../image.jpg",
   *   org: "International Federation of Red Crosses",
   *   role: "Software developer",
   *   groups: [9175, 10318],
   * }
   *
   */
  protected static function getById($id, $mode, $persist, &$objects, &$current_user) {
    if ($current_user && $current_user->uid == $id) {
      // Force private mode and persist if the user is getting their object.
      $mode = ClusterAPI_Object::MODE_PRIVATE;
      $persist = TRUE;
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

    $user = user_load($id);

    $related = [];
    $ret = [
      '_mode' => $mode,
      '_persist' => $persist,
    ];

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:
        // TODO: read 'groups' properly
        $ret += [
          'groups' => [9175, 10318],
        ];
        $related[] = [
          'type' => 'group',
          'id' => 9175,
          'mode' => ClusterAPI_Object::MODE_PUBLIC,
        ];
        $related[] = [
          'type' => 'group',
          'id' => 10318,
          'mode' => ClusterAPI_Object::MODE_PUBLIC,
        ];
      case ClusterAPI_Object::MODE_PUBLIC:
        $wrapper = entity_metadata_wrapper('user', $user);
        $ret += [
          'mail' => $user->mail,
          //          'picture' => $picture,
//          'org' => $wrapper->field_organisation_name->value(),
//          'role' => $wrapper->field_role_or_title->value(),
        ];
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'id' => $user->uid,
          'name' => $user->name,
        ];
    }

    $objects[self::$type][$id] = $ret;

    foreach ($related as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], $request['mode'], $persist, $objects, $current_user);
  }
}
