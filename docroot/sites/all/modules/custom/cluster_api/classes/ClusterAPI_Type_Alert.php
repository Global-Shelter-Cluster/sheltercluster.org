<?php

class ClusterAPI_Type_Alert extends ClusterAPI_Type {

  protected static $type = 'alert';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'document' => [
      'type' => 'document',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'event' => [
      'type' => 'event',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'factsheet' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'kobo_form' => [
      'type' => 'kobo_form',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'webform' => [
      'type' => 'webform',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'group' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUBPLUS,
    ],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
    $current_user_groups = ClusterAPI_Type_User::getFollowedGroups($this->current_user);

    $node = node_load($id);
    if ($node->type !== 'alert')
      return;
    $alert_groups = self::getReferenceIds('node', $node, 'og_group_ref', TRUE);

    if (count(array_intersect($alert_groups, $current_user_groups)) > 0) {
      // Force persist if any of this alert's groups match the current user's.
      $persist = TRUE;
    }
  }

  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'alert')
      return NULL;

    $wrapper = entity_metadata_wrapper('node', $node);

    $ret = [
      'created' => self::getDateValue($node->created),
      'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
      'title' => $node->title,
      'description' => $wrapper->body->value()['safe_value'],
    ];

    $link_type = $wrapper->field_link_type->value();

    switch ($link_type) {
      case 'document':
      case 'event':
      case 'factsheet':
      case 'kobo_form':
      case 'webform':
      case 'group':
        $ret[$link_type] = self::getReferenceIds('node', $node, 'field_' . $link_type);
        break;
      case 'url':
        $items = field_get_items('node', $node, 'field_url');
        if (count($items) > 0)
          $ret['url'] = $items[0]['value'];
        break;
    }

    return $ret;
  }
}
