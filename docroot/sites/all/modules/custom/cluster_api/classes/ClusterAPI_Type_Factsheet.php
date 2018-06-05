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
        $map_uri = $node->field_map ? $wrapper->field_map->file->value()->uri : NULL;

        $ret += [
          'highlights' => trim($wrapper->body->value()['safe_value']),
          'map' => $map_uri ? image_style_url('factsheet_map', $map_uri) : '',
          'photo_credit' => (string) $wrapper->field_photo_credit->value(),
        ];

      //Fall-through
      case ClusterAPI_Object::MODE_STUB:
        $image_uri = $node->field_image ? $wrapper->field_image->file->value()->uri : NULL;

        $ret += [
          'date' => format_date($wrapper->field_date->value(), 'custom', 'Y-m'),
          'image' => $image_uri ? image_style_url('factsheet_image', $image_uri) : '',
        ];
    }

    return $ret;
  }
}
