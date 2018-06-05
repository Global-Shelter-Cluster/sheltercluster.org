<?php

abstract class ClusterAPI_Type {

  protected static $type;
  protected static $types = [
    'user' => 'ClusterAPI_Type_User',
    'group' => 'ClusterAPI_Type_Group',
    //    'document' => 'ClusterAPI_Type_Document',
    //    'event' => 'ClusterAPI_Type_Event',
    //    'factsheet' => 'ClusterAPI_Type_Factsheet',
  ];

  static function allTypes() {
    return array_keys(self::$types);
  }

  static function get($type, $id, $mode, $persist, &$objects, &$current_user) {
    if (!array_key_exists($type, self::$types))
      return;

    $class = self::$types[$type];
    $class::getById($id, $mode, $persist, $objects, $current_user);
  }

  abstract protected static function getById($id, $mode, $persist, &$objects, &$current_user);
}
