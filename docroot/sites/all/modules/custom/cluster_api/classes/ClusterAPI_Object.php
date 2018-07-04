<?php

class ClusterAPI_Object {

  const MODE_PRIVATE = 'private';
  const MODE_PUBLIC = 'public';
  const MODE_STUBPLUS = 'stubplus';
  const MODE_STUB = 'stub';

  /** @var \stdClass User object */
  protected $current_user;

  public function __construct($current_user) {
    $this->current_user = $current_user;
  }

  static function detailLevel($mode) {
    $levels = [
      self::MODE_PRIVATE => 3,
      self::MODE_PUBLIC => 2,
      self::MODE_STUBPLUS => 1,
      self::MODE_STUB => 0,
    ];

    return $levels[$mode];
  }

  /**
   * @param array $requests Each request has a type and an id, e.g.
   *   ['type' => 'user', 'id' => 123]
   *
   * @return array keyed by type, each object is keyed by its id, and contains
   *   the object in the appropriate detail level for the current user.
   */
  function getObjects(array $requests) {
    $objects = [];

    foreach (ClusterAPI_Type::allTypes() as $type) {
      $objects[$type] = [];
    }

    foreach ($requests as $request)
      ClusterAPI_Type::get($request['type'], $request['id'], self::MODE_PUBLIC, FALSE, $objects, $this->current_user);

    return array_filter($objects);
  }
}
