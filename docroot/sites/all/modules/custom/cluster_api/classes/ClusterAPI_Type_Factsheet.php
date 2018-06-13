<?php

class ClusterAPI_Type_Factsheet extends ClusterAPI_Type {

  protected static $type = 'factsheet';
  protected static $related_def = [
    'prev' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'next' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  /**
   * Example:
   *
   * {
   *   date: "2016-04",
   *   highlights: "<p>text in html format</p>",
   *   image: 'http://path/to/image.jpg',
   *   photo_credit: 'John Smith',
   *   map: 'http://path/to/image.jpg',
   *   prev: 23, // id of previous factsheet for this group
   *   next: 25,
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if (!$node || $node->type !== 'factsheet')
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

        //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $ret += [
          'highlights' => trim($wrapper->body->value()['safe_value']),
          'photo_credit' => (string) $wrapper->field_photo_credit->value(),
        ];

        if ($value = self::getFileValue('field_map', $wrapper, 'factsheet_map'))
          $ret['map'] = $value;

      //Fall-through
      default:
        $ret += [
          'date' => format_date($wrapper->field_date->value(), 'custom', 'Y-m'),
          'image' => self::getFileValue('field_image', $wrapper, 'factsheet_image'),
        ];
    }

    return $ret;
  }
}
