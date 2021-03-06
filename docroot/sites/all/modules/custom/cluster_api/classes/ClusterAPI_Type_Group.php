<?php

class ClusterAPI_Type_Group extends ClusterAPI_Type {

  /** @var int How many documents to return in the "recent_documents" property */
  const RECENT_DOCS_LIMIT = 30;
  const UPCOMING_EVENTS_LIMIT = 10;
  const UPCOMING_EVENTS_DAYS_LIMIT = 14;
  const ALERTS_LIMIT = 40;
  const ALERTS_DAYS_LIMIT = 60;
  const NEWS_LIMIT = 20;
  const NEWS_DAYS_LIMIT = 30;
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
    'hubs' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'responses' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'working_groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'regions' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'communities_of_practice' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'strategic_advisory' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'latest_factsheet' => [
      'type' => 'factsheet',
      'mode' => [
        ClusterAPI_Object::MODE_STUBPLUS => ClusterAPI_Object::MODE_STUB,
        ClusterAPI_Object::MODE_PUBLIC => ClusterAPI_Object::MODE_PUBLIC,
        ClusterAPI_Object::MODE_PRIVATE => ClusterAPI_Object::MODE_PUBLIC,
      ],
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
    'upcoming_events' => [
      'type' => 'event',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'kobo_forms' => [
      'type' => 'kobo_form',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'webforms' => [
      'type' => 'webform',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'alerts' => [
      'type' => 'alert',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'news' => [
      'type' => 'news',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'contacts' => [
      'type' => 'contact',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'followers' => [
      'type' => 'user',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
    'pages' => [
      'type' => 'page',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'child_pages' => [
      'type' => 'page',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  protected function preprocessModeAndPersist($id, &$mode, &$persist, $previous_type, $previous_id) {
    $came_from_logged_in_user = $this->current_user && $previous_type === 'user' && $this->current_user->nid === $previous_id;
    $is_top_level_request = $previous_type === NULL && $previous_id === NULL;

    if ($came_from_logged_in_user || $is_top_level_request) {
      $current_user_groups = ClusterAPI_Type_User::getFollowedGroups($this->current_user);

      if (in_array($id, $current_user_groups)) {
        // Force private mode and persist if this is one of the current user's
        // followed groups.
        $mode = ClusterAPI_Object::MODE_PRIVATE;
        $persist = TRUE;
      } elseif ($mode === ClusterAPI_Object::MODE_STUB && in_array($id, cluster_og_get_hot_response_nids())) {
        // Force at least stubplus mode (and persist) if this is one of the
        // globally featured responses.
        $mode = ClusterAPI_Object::MODE_STUBPLUS;
        $persist = TRUE;
      }
    }

    if (variable_get('cluster_og_resources_id') == $id)
      $persist = TRUE;
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
   *   useful_links: [{url: "http://example.com", title: "Example"}, {url: "http://example.com/2"}]
   * }
   *
   * @param int $id
   * @param string $mode
   *
   * @return array|null
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if (!$node || !og_is_group('node', $node))
      // This id is not for a group node
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);
    $manager = GroupContentManager::getInstance($node);
    $display = GroupDisplayProvider::getDisplayProvider($node);

    $convert_to_int = function ($string) {
      return intval($string);
    };

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:
      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        if (method_exists($manager, 'getKoboForms') && $value = $manager->getKoboForms()) {
          $ret['kobo_forms'] = array_values(array_filter(array_map($convert_to_int, $value)));
        }

        if (method_exists($manager, 'getWebforms') && $value = $manager->getWebforms()) {
          $ret['webforms'] = array_values(array_filter(array_map($convert_to_int, $value)));
        }

        $ret['alerts'] = array_filter((array)$manager->getLatestAlerts(self::ALERTS_LIMIT, self::ALERTS_DAYS_LIMIT));
        $ret['news'] = array_filter((array)$manager->getLatestNews(self::NEWS_LIMIT, self::NEWS_DAYS_LIMIT));

        $ret['followers'] = self::getFollowers($id);

        $ret['search_group_nids'] = $display->getSearchGroupNids();

        if ($value = self::getReferenceIds('node', $node, 'field_associated_regions', TRUE))
          $ret['associated_regions'] = $value;

        if ($value = self::getReferenceIds('node', $node, 'field_parent_region'))
          $ret['parent_region'] = $value;

        if ($value = self::getReferenceIds('node', $node, 'field_parent_response'))
          $ret['parent_response'] = $value;

        foreach ([
                   'hubs' => 'getRelatedHubs',
                   'responses' => 'getRelatedResponses',
                   'working_groups' => 'getRelatedWorkingGroups',
                   'regions' => 'getRelatedRegions',
                   'communities_of_practice' => 'getCommunitiesOfPractice',
                 ] as $property => $method) {
          if (method_exists($manager, $method) && $value = $manager->$method()) {
            $ret[$property] = array_values(array_filter(array_map($convert_to_int, $value)));
          }
        }

        if ($node->type === 'geographic_region') {
          $hierarchy = $manager->getResponseRegionHierarchy();
          $hierarchy2 = [];
          foreach ($hierarchy as $region_nid => $response_nids)
            $hierarchy2[] = [
              'region' => $region_nid,
              'responses' => $response_nids,
            ];
          $ret['response_region_hierarchy'] = $hierarchy2;
        }

        if (method_exists($manager, 'getStrategicAdvisory') && $sag = $manager->getStrategicAdvisory()) {
          $ret['strategic_advisory'] = intval($sag->nid);
        }

        $ret['featured_documents'] = array_filter((array)$manager->getFeaturedDocuments());
        $ret['key_documents'] = array_filter((array)$manager->getKeyDocumentIds());
        $ret['recent_documents'] = array_filter((array)$manager->getRecentDocuments(self::RECENT_DOCS_LIMIT, FALSE));
        $ret['upcoming_events'] = array_filter((array)$manager->getUpcomingEvents(self::UPCOMING_EVENTS_LIMIT, self::UPCOMING_EVENTS_DAYS_LIMIT));

        $ret['contacts'] = array_filter((array)$manager->getContactMembers());

        $ret['url'] = url('node/' . $id, ['absolute' => TRUE]);

        $useful_links = [];
        foreach ((array)field_get_items('node', $node, 'field_useful_links') as $item) {
          if (!$item['url'])
            continue;

          $useful_link = ['url' => $item['url']];
          if ($item['title'])
            $useful_link['title'] = $item['title'];

          $useful_links[] = $useful_link;
        }
        if ($useful_links)
          $ret['useful_links'] = $useful_links;

        $page_ids = array_merge($manager->getPages(), $manager->getLibraries(), $manager->getPhotoGalleries());
        $ret['pages'] = shelter_base_sort_nids_by_weight($page_ids);
        if ($ret['pages']) {
          $ret['child_pages'] = [];
          $ret['all_child_pages'] = [];
          $all_child_pages = $display->getAllChildPagesIds($ret['pages']);
          foreach ($all_child_pages as $parent_id => $children) {
            $children_ids = shelter_base_sort_nids_by_weight(array_keys($children));
            $ret['child_pages'] = array_merge($ret['child_pages'], $children_ids);
            $ret['all_child_pages'][$parent_id] = $children_ids;
          }
        }

      //Fall-through
      case ClusterAPI_Object::MODE_STUBPLUS:
        $factsheets = $manager->getFactsheets(1);
        if ($factsheets)
          $ret['latest_factsheet'] = $factsheets[0];

        $ret['image'] = self::getFileValue('field_image', $wrapper, 'large');

      //Fall-through
      default:
        $ret += [
          'type' => $node->type,
          'title' => $node->title,
        ];

        if ($node->type === 'geographic_region') {
          $region_type = $wrapper->field_geographic_region_type->value();
          if ($region_type)
            $ret['region_type'] = $region_type->name;
        }

        if ($node->type === 'response') {
          $ret['response_status'] = $wrapper->field_response_status->value();
        }

        if (variable_get('cluster_og_global_id') == $node->nid)
          $ret['is_global'] = TRUE;

        if (variable_get('cluster_og_resources_id') == $node->nid)
          $ret['is_resources'] = TRUE;
    }

    return $ret;
  }

  static function getFollowers($group_nid) {
    $convert_to_int = function ($string) {
      return intval($string);
    };

    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'user')
      ->fieldCondition('og_user_node', 'target_id', $group_nid);

    $results = $query->execute();

    if (!isset($results['user']))
      return [];

    $uids = array_map(function ($item) {
      return $item->uid;
    }, $results['user']);

    $has_followed_role = function ($uid) use ($group_nid) {
      return in_array(CLUSTER_API_FOLLOWER_ROLE_NAME, og_get_user_roles('node', $group_nid, $uid));
    };

    return array_map($convert_to_int, array_values(array_filter($uids, $has_followed_role)));
  }
}
