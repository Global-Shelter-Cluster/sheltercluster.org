<?php

class ClusterAPI_Type_User extends ClusterAPI_Type {

  protected static $type = 'user';
  protected static $related_def = [
    'groups' => ['type' => 'group', 'mode' => ClusterAPI_Object::MODE_PUBLIC],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist) {
    if ($this->current_user && $this->current_user->uid == $id) {
      // Force private mode and persist if the user is getting their object.
      $mode = ClusterAPI_Object::MODE_PRIVATE;
      $persist = TRUE;
    }
  }

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
  protected function generateObject($id, $mode) {
    $user = user_load($id);
    if (!$user)
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('user', $user);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:
        $convert_to_int = function($string) {
          return intval($string);
        };
        $groups = array_map($convert_to_int, array_values(og_get_groups_by_user($user, 'node')));
        $ret += ['groups' => $groups];

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $ret += [
          'mail' => $user->mail,
          'picture' => $user->picture ? image_style_url('medium', $user->picture->uri) : '',
          'org' => implode(', ', $wrapper->field_organisation_name->value()),
          'role' => implode(', ', $wrapper->field_role_or_title->value()),
        ];

      //Fall-through
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'name' => $user->name,
        ];
    }

    return $ret;
  }
}
