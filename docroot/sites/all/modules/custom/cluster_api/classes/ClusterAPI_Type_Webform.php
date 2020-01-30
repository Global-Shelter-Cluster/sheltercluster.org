<?php

class ClusterAPI_Type_Webform extends ClusterAPI_Type {

  protected static $type = 'webform';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'webform')
      return NULL;

    $wrapper = entity_metadata_wrapper('node', $node);

    return [
      'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
      'title' => $node->title,
      'description' => $wrapper->field_body->value(),
      'form' => cluster_webform_export($node),
    ];
  }
}
