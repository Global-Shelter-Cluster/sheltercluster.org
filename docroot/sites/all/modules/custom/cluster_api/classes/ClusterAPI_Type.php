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
    'global' => 'ClusterAPI_Type_Global',
    'user' => 'ClusterAPI_Type_User',
    'group' => 'ClusterAPI_Type_Group',
    'factsheet' => 'ClusterAPI_Type_Factsheet',
    'document' => 'ClusterAPI_Type_Document',
    'event' => 'ClusterAPI_Type_Event',
    'kobo_form' => 'ClusterAPI_Type_KoboForm',
    'alert' => 'ClusterAPI_Type_Alert',
    'contact' => 'ClusterAPI_Type_Contact',
  ];
  /** @var \stdClass User object */
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
  public static function getReferenceIds($entity_type, $entity, $field_name, $multiple = FALSE) {
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
   * @param string $field_name
   * @param EntityMetadataWrapper $wrapper
   * @param string|null $image_style
   *
   * @return string|null
   */
  protected static function getFileValue($field_name, $wrapper, $image_style = NULL) {
    $node = $wrapper->raw();
    $uri = $node->$field_name ? $wrapper->$field_name->file->value()->uri : NULL;

    if (!$uri)
      return NULL;

    if ($image_style)
      return image_style_url($image_style, $uri);
    else
      return file_create_url($uri);
  }

  /**
   * @param string|int $field_name_or_timestamp
   * @param EntityMetadataWrapper|null $wrapper
   * @param string|null $custom_format
   *
   * @return string|null
   */
  protected static function getDateValue($field_name_or_timestamp, $wrapper = NULL, $custom_format = 'c') {
    if (!is_numeric($field_name_or_timestamp)) {
      switch ($field_name_or_timestamp) {
        case 'field_recurring_event_date2':
          $field_name_or_timestamp = strtotime($wrapper->$field_name_or_timestamp->value()[0]['value']);
          break;
        default:
          $field_name_or_timestamp = $wrapper->$field_name_or_timestamp->value(); // returns a timestamp in UTC
      }
    }

    // 'c' means ISO8601-formatted date
    return format_date($field_name_or_timestamp, 'custom', $custom_format);
  }

  /**
   * @param integer $id
   * @param string $mode
   * @param boolean $persist
   * @param array $objects
   * @param integer $level
   * @param string|NULL $previous_type
   * @param integer|NULL $previous_id
   *
   * @return null
   */
  protected function getById($id, $mode, $persist, &$objects, $level, $previous_type, $previous_id) {
    $this->preprocessModeAndPersist($id, $mode, $persist, $previous_type, $previous_id);

    if (array_key_exists($id, $objects[static::$type])) {
      $existing = $objects[static::$type];

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

    $objects[static::$type][$id] = array_filter($object);

    foreach ($this->related($object) as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], $request['mode'], $persist, $objects, $this->current_user, $level, static::$type, $id);
  }

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
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

      foreach ((array) $object[$property] as $id) {
        $related_mode = $def['mode'];

        if (is_array($related_mode)) {
          foreach ($related_mode as $source_mode => $target_mode) {
            if ($source_mode === $object['_mode']) {
              $related_mode = $target_mode;
              break;
            }
          }
        }

        if (is_array($related_mode))
          continue;

        $ret[] = [
          'type' => $def['type'],
          'id' => $id,
          'mode' => $related_mode,
        ];
      }
    }
    return $ret;
  }

  static function get($type, $id, $mode, $persist, &$objects, &$current_user, $level = 0, $previous_type = NULL, $previous_id = NULL) {
    if ($level > 20) {
      // Infinite loop protection
      return;
    }

    if (!array_key_exists($type, self::$types)) {
      return;
    }

    if (array_key_exists($id, $objects[$type])) {
      $object_details_level = ClusterAPI_Object::detailLevel($objects[$type][$id]['_mode']);
      $requested_details_level = ClusterAPI_Object::detailLevel($mode);
      if ($object_details_level >= $requested_details_level) {
        // We already have this object, in the same or higher level of detail.
        return;
      }
    }

    $class = self::$types[$type];
    if (is_string($class)) {
      $class = self::$types[$type] = $class::create($current_user);
    }

    $class->getById($id, $mode, $persist, $objects, $level + 1, $previous_type, $previous_id);
  }

  /**
   * @param $current_user
   *
   * @return \ClusterAPI_Type
   */
  protected static final function create($current_user) {
    $class = get_called_class();
    return new $class($current_user);
  }
}
