<?php

class ClusterAPI_Type_KoboForm extends ClusterAPI_Type {

  protected static $type = 'kobo_form';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'kobo_form')
      return NULL;

    $wrapper = entity_metadata_wrapper('node', $node);

    return [
      'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
      'title' => $node->title,
      'description' => strip_tags($wrapper->body->value()['safe_value']),
      'kobo_form_url' => $wrapper->field_kobo_form_url->value(),
    ];
  }
}
