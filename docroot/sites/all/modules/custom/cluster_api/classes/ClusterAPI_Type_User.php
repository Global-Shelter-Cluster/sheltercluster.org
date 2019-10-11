<?php

class ClusterAPI_Type_User extends ClusterAPI_Type {

  protected static $type = 'user';
  protected static $related_def = [
    'groups' => ['type' => 'group', 'mode' => ClusterAPI_Object::MODE_PRIVATE],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
    if (
      $previous_type === NULL // Only do this when the user is a top-level request
      && $this->current_user
      && $this->current_user->uid == $id
    ) {
      // Force private mode and persist if the user is getting their object.
      $mode = ClusterAPI_Object::MODE_PRIVATE;
      $persist = TRUE;
    }
  }

  static function getFollowedGroups($user) {
    if (!$user->uid)
      return []; // Logged out

    $convert_to_int = function($string) {
      return intval($string, 10);
    };

    $groups_by_user = (array) og_get_groups_by_user($user, 'node');
    $groups = array_map($convert_to_int, array_values($groups_by_user));

    $has_followed_role = function($gid) use ($user) {
      return in_array(CLUSTER_API_FOLLOWER_ROLE_NAME, og_get_user_roles('node', $gid, $user->uid));
    };

    return array_values(array_filter($groups, $has_followed_role));
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
   *   notifications: {
   *     app_daily: true,
   *     app_upcoming_events: true,
   *     email_daily: false,
   *     email_weekly: true,
   *   },
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
        $ret += ['groups' => self::getFollowedGroups($user)];
        $ret += ['timezone' => $user->timezone];

        $ret += ['notifications' => [
          'app_daily' => !!$wrapper->field_notif_push_daily->value(),
          'app_upcoming_events' => !!$wrapper->field_notif_push_upcevents->value(),
          'email_daily' => !!$wrapper->field_notif_email_daily->value(),
          'email_weekly' => !!$wrapper->field_notif_email_weekly->value(),
        ]];

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $ret += [
          'mail' => $user->mail,
          'picture' => $user->picture ? image_style_url('medium', $user->picture->uri) : '',
          'org' => $wrapper->field_organisation_name->value(),
          'role' => $wrapper->field_role_or_title->value(),
          'phone' => $wrapper->field_phone_number->value(),
          'full_name' => $wrapper->field_full_name->value(),
        ];

      //Fall-through
      default:
        $ret += [
          'name' => $user->name,
        ];
    }

    return $ret;
  }
}

