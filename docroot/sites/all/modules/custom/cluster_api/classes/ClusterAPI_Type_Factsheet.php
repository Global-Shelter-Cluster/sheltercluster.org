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
   *   image: 'http://path/to/image.jpg',
   *   groups: [123, 234],
   *   prev: 23, // id of previous factsheet for this group
   *   next: 25,
   *   highlights: "<p>text in html format</p>", // HTML
   *   map: 'http://path/to/image.jpg',
   *   photo_credit: 'John Smith',
   *   need_analysis: '', // HTML
   *   response: '', // HTML
   *   gaps_challenges: '', // HTML
   *   key_dates: [['date' => 'Apr 1', 'description' => "April fools"], ['date' => 'Dec 23 to 31', description => "Holidays"]],
   *   key_documents: [56, 1238, 3380],
   *   key_links: [['url' => 'http://path/to/url', 'title' => "Resource"]],
   *   key_figures: [
   *     {type: 'number', label: 'Cluster partners', value: 21},
   *     {type: 'chart', title: 'People', description: 'Households. 4.35 people per household', chart: 'http://path/to/png'},
   *     {type: 'chart', title: 'Funding', smallImage: true, description: 'Total funding required: $ 6.5 M. Source: OCHA', chart: 'http://path/to/png'},
   *   ],
   *   coverage_against_targets: {
   *     description: 'Households. 4.35 people per household',
   *     chart: 'http://path/to/png',
   *   },
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
          'prev' => cluster_factsheets_prev_nid($node),
          'next' => cluster_factsheets_next_nid($node),
          'highlights' => trim($wrapper->body->value()['safe_value']),
          'map' => self::getFileValue('field_map', $wrapper, 'factsheet_map'),
          'full_map' => self::getFileValue('field_map', $wrapper),
          'full_image' => self::getFileValue('field_image', $wrapper),
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
          'key_figures' => cluster_factsheets_api_indicators($node),
          'coverage_against_targets' => cluster_factsheets_api_cat($node),
        ];

      //Fall-through
      default:
        // We add a couple of days so we don't have to deal with time zone issues. This is fine because we're only
        // showing the year and month.
        $format_date = format_date($wrapper->field_date->value() + 60 * 60 * 24 * 2, 'custom', 'Y-m');

        $ret += [
          'date' => $format_date,
          'image' => self::getFileValue('field_image', $wrapper, 'factsheet_image'),
        ];
    }

    return $ret;
  }
}
