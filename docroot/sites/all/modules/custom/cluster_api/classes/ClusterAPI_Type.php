<?php

abstract class ClusterAPI_Type {

  /**
   * @var string
   */
  protected static $type;
  /**
   * @var array keyed by property name, value is [type => object type, mode =>
   *   stub|public|private].
   */
  protected static $related_def;
  /**
   * @var array of either class names or their corresponding instantiated
   *   objects.
   */
  protected static $types = [
    'user' => 'ClusterAPI_Type_User',
    'group' => 'ClusterAPI_Type_Group',
    'factsheet' => 'ClusterAPI_Type_Factsheet',
    'document' => 'ClusterAPI_Type_Document',
    'event' => 'ClusterAPI_Type_Event',
  ];
  protected $current_user;

  protected function __construct($current_user) {
    $this->current_user = $current_user;
  }

  static function allTypes() {
    return array_keys(self::$types);
  }

  /**
   * @param string $entity_type
   * @param $entity
   * @param string $field_name
   * @param bool $multiple
   *
   * @return array|integer|null
   */
  protected static function getReferenceIds($entity_type, $entity, $field_name, $multiple = FALSE) {
    $items = field_get_items($entity_type, $entity, $field_name);
    if (!$items)
      return NULL;

    $get_target_id = function($i) {
      return intval($i['target_id']);
    };

    $items = array_unique(array_values(array_map($get_target_id, $items)));
    if (!$items)
      return NULL;

    return $multiple ? $items : $items[0];
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
  protected function getById($id, $mode, $persist, &$objects, $level) {
    $this->preprocessModeAndPersist($id, $mode, $persist);

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

    $object = $this->generateObject($id, $mode);
    if (is_null($object))
      return;

    $object += [
      '_mode' => $mode,
      '_persist' => $persist,
      'id' => intval($id),
    ];

    $objects[static::$type][$id] = $object;

    foreach ($this->related($object) as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], $request['mode'], $persist, $objects, $this->current_user, $level);
  }

  protected function preprocessModeAndPersist($id, &$mode, &$persist) {
    return;
  }

  /**
   * @param int $id
   * @param string $mode
   *
   * @return array|null
   */
  protected abstract function generateObject($id, $mode);

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
   * @param $current_user
   *
   * @return \ClusterAPI_Type
   */
  protected final function create($current_user) {
    $class = get_called_class();
    return new $class($current_user);
  }
}
