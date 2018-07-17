<?php

class ClusterAPI_Type_Event extends ClusterAPI_Type {

  protected static $type = 'event';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  /**
   * Example:
   *
   * {
   *   title: "PASSA training",
   *   date: "2016-05-02T08:22:29+00:00", //ISO 8601
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'event')
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);
    $algolia_fields = [];
    cluster_events_add_algolia_fields(['nid' => ['value' => $id]], $algolia_fields);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $geo = _cluster_events_get_geocoordinates_from_address_field($wrapper->field_postal_address->value());
        foreach ($geo as $k => $v)
          $geo[$k] = $k === 'zoom' ? intval($v) : floatval($v);

        $ret += [
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
          'description' => $wrapper->body->value()['safe_value'],
          'address' => isset($algolia_fields['event_location_html']) ? $algolia_fields['event_location_html'] : '',
          'geo' => $geo,
        ];

      //Fall-through
      default:
        $ret += [
          'title' => $node->title,
          'date' => self::getDateValue('field_recurring_event_date2', $wrapper),
          'map' => $algolia_fields['event_map_image'],
        ];
    }

    return $ret;
  }
}
