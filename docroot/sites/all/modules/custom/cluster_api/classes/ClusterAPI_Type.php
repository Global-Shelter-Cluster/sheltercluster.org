<?php

abstract class ClusterAPI_Type {

  /**
   * @var string
   */
  protected static $type;
  /**
   * @var array keyed by property name, value is [type => object type, mode => stub|public|private].
   */
  protected static $related_def;
  /**
   * @var array of either class names or their corresponding instantiated
   *   objects.
   */
  protected static $types = [
    'user' => 'ClusterAPI_Type_User',
    'group' => 'ClusterAPI_Type_Group',
    //    'document' => 'ClusterAPI_Type_Document',
    //    'event' => 'ClusterAPI_Type_Event',
    //    'factsheet' => 'ClusterAPI_Type_Factsheet',
  ];
  protected $current_user;

  protected function __construct($current_user) {
    $this->current_user = $current_user;
  }

  static function allTypes() {
    return array_keys(self::$types);
  }

  static function get($type, $id, $mode, $persist, &$objects, &$current_user, $level = 0) {
    if ($level > 20)
      // Infinite loop protection
      return;

    if (!array_key_exists($type, self::$types))
      return;

    $class = self::$types[$type];
    if (is_string($class))
      $class = self::$types[$type] = $class::create($current_user);

    $class->getById($id, $mode, $persist, $objects, $level + 1);
  }

  /**
   * @param integer $id
   * @param string $mode
   * @param boolean $persist
   * @param array $objects
   * @param integer $level
   *
   * @return null
   */
  protected abstract function getById($id, $mode, $persist, &$objects, $level);

  /**
   * @param $current_user
   *
   * @return \ClusterAPI_Type
   */
  protected final function create($current_user) {
    $class = get_called_class();
    return new $class($current_user);
  }

  protected function related($object) {
    $ret = [];
    foreach (static::$related_def as $property => $def) {
      if (!array_key_exists($property, $object) || !$object[$property])
        continue;

      foreach ((array) $object[$property] as $id)
        $ret[] = [
          'type' => $def['type'],
          'id' => $id,
          'mode' => $def['mode'],
        ];
    }
    return $ret;
  }
}
