<?php

class ClusterAPI_Type_Group extends ClusterAPI_Type {

  /** @var int How many documents to return in the "recent_documents" property */
  const RECENT_DOCS_LIMIT = 50;
  protected static $type = 'group';
  protected static $related_def = [
    'associated_regions' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'parent_response' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'parent_region' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'latest_factsheet' => [
      'type' => 'factsheet',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'featured_documents' => [
      'type' => 'document',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'key_documents' => [
      'type' => 'document',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'recent_documents' => [
      'type' => 'document',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
    $came_from_logged_in_user = $this->current_user && $previous_type === 'user' && $this->current_user->nid === $previous_id;
    $is_top_level_request = $previous_type === NULL && $previous_id === NULL;

    if ($came_from_logged_in_user || $is_top_level_request) {
      $current_user_groups = $this->current_user
        ? array_values(og_get_groups_by_user($this->current_user, 'node'))
        : [];

      if (in_array($id, $current_user_groups)) {
        // Force private mode and persist if this is one of the current user's
        // followed groups.
        $mode = ClusterAPI_Object::MODE_PRIVATE;
        $persist = TRUE;
      }
      elseif ($mode === ClusterAPI_Object::MODE_STUB && in_array($id, cluster_og_get_hot_response_nids())) {
        // Force at least stubplus mode (and persist) if this is one of the
        // globally featured responses.
        $mode = ClusterAPI_Object::MODE_STUBPLUS;
        $persist = TRUE;
      }
    }
  }

  /**
   * Example:
   *
   * {
   *   _mode: OBJECT_MODE_PRIVATE,
   *   _persist: true,
   *   type: "response",
   *   id: 9175,
   *   title: "Ecuador Earthquake 2016",
   *   url: "https://www.sheltercluster.org/response/ecuador-earthquake-2016",
   *   associated_regions: [9104, 62],
   *   latest_factsheet: 13454,
   *   featured_documents: [30, 45],
   *   key_documents: [30, 45],
   *   recent_documents: [30, 45, 123, 693],
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if (!$node || !og_is_group('node', $node))
      // This id is not for a group node
      return NULL;

    $ret = [];
    //    $wrapper = entity_metadata_wrapper('node', $node);
    $manager = GroupContentManager::getInstance($node);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        if ($value = self::getReferenceIds('node', $node, 'field_associated_regions', TRUE))
          $ret['associated_regions'] = $value;

        if ($value = self::getReferenceIds('node', $node, 'field_parent_region'))
          $ret['parent_region'] = $value;

        if ($value = self::getReferenceIds('node', $node, 'field_parent_response'))
          $ret['parent_response'] = $value;

        $ret['featured_documents'] = array_filter((array) $manager->getFeaturedDocuments());
        $ret['key_documents'] = array_filter((array) $manager->getKeyDocumentIds());
        $ret['recent_documents'] = array_filter((array) $manager->getRecentDocuments(self::RECENT_DOCS_LIMIT, FALSE));

        $ret['url'] = url('node/' . $id, ['absolute' => TRUE]);

      //Fall-through
      case ClusterAPI_Object::MODE_STUBPLUS:
        $factsheets = $manager->getFactsheets(1);
        if ($factsheets)
          $ret['latest_factsheet'] = $factsheets[0];

      //Fall-through
      default:
        $ret += [
          'type' => $node->type,
          'title' => $node->title,
        ];
    }

    return $ret;
  }
}
