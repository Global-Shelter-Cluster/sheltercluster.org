<?php

class ClusterAPI_Type_Factsheet extends ClusterAPI_Type {

  protected static $type = 'factsheet';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'prev' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'next' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'key_documents' => [
      'type' => 'document',
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
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
          'highlights' => trim($wrapper->body->value()['safe_value']),
          'map' => self::getFileValue('field_map', $wrapper, 'factsheet_map'),
          'photo_credit' => (string) $wrapper->field_photo_credit->value(),
          'need_analysis' => trim($wrapper->field_need_analysis->value()['safe_value']),
          'response' => trim($wrapper->field_fs_response->value()['safe_value']),
          'gaps_challenges' => trim($wrapper->field_gaps_challenges->value()['safe_value']),
          'key_dates' => array_map(function($item) {
            return [
              'date' => $item['first'],
              'description' => $item['second'],
            ];
          }, $wrapper->field_key_dates->value()),
          'key_documents' => self::getReferenceIds('node', $node, 'field_key_documents', TRUE),
          'key_links' => array_map(function($item) {
            return [
              'url' => url($item['url'], ['absolute' => TRUE]),
              'title' => $item['title'],
            ];
          }, $wrapper->field_key_links->value()),
        ];

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
