<?php

/**
 * Generates a content manager appropriate to the viewed content.
 * Provides related entity data, typically node ids, for the viewed content.
 */
class GroupContentManager {

  protected $node;

  /**
   * @var Array of descendant IDs, stored for caching purposes in a single request.
   */
  protected $descendant_ids;

  /**
   * @var Entity reference field name used to get children for the node.
   * Classes that inherit from this will need to override this value to make
   * $this->getDescendantIds() work.
   */
  protected $parent_field = NULL;

  /**
   * Constructor.
   */
  public function __construct($node) {
    $this->node = $node;
  }

  /**
   * Builder for class implementation of the appropriate type for the node.
   * @param $node
   *  Drupal node object.
   */
  static public function getInstance($node) {
    switch ($node->type) {
      case 'geographic_region':
        return new GroupContentManagerGeographicRegion($node);
      case 'response':
        return new GroupContentManagerResponse($node);
      case 'strategic_advisory':
        return new GroupContentManagerStategicAdvisory($node);
      default:
        return new GroupContentManager($node);
    }
  }

  /**
   * Magic callback.
   * Provides a default return value of FALSE for all methods that are not implemented in a specific bundle
   * subclass.
   */
  public function __call($name, $arguments) {
    return FALSE;
  }

  public function getChildrenPages($currently_visible_node_id) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->fieldCondition('field_parent_content', 'target_id', $currently_visible_node_id)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();
    if (isset($result['node'])) {
      return array_keys($result['node']);
    }
    return [];
  }

  /**
   * Get all the page nodes that are content for the group.
   */
  public function getPages() {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'page')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();
    if (isset($result['node'])) {
      return array_keys($result['node']);
    }
    return array();
  }

  /**
   * Get useful links, if any.
   */
  public function getUsefulLinks() {
    if (!isset($this->node->field_useful_links)) {
      return array();
    }

    $wrapper = entity_metadata_wrapper('node', $this->node);
    $links = array();
    foreach ($wrapper->field_useful_links->value() as $link) {

      $new_link = new stdClass;
      $new_link->title = $link['title'] ? $link['title'] : $link['display_url'];
      $new_link->url = $link['url'];
      $links[] = $new_link;
    }

    return $links;
  }

  /**
   * Get one strategic advisory node for the current group.
   *
   * @return
   *   Loaded node object of bundle type strategic_advisory, or FALSE if none exist.
   */
  public function getStrategicAdvisory() {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'strategic_advisory')
      ->fieldCondition('field_parent_response', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();

    if (isset($result['node'])) {
      return node_load(key($result['node']));
    }

    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'strategic_advisory')
      ->fieldCondition('field_parent_region', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->execute();

    if (isset($result['node'])) {
      return node_load(key($result['node']));
    }
    return FALSE;
  }

  /**
   * Provide a count value for all published document nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getDocumentCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Provide a count value for all published discussion nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getDiscussionCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'discussion')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Provide a count value for all published event nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getEventCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'event')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Get contact content for the group.
   *  @return
   */
  public function getContactMembers() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'contact')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get recent discussions for a group node.
   * @return
   *  array of discussion node ids, FALSE if none exist.
   */
  public function getRecentDiscussions($range = 2) {
    $query = db_select('node', 'n');
    $query->join('og_membership', 'g', 'g.etid = n.nid');
    $query->fields('n', array('nid'));
    $query->condition('n.status', NODE_PUBLISHED);
    $query->condition('n.type', 'discussion');
    $query->condition('g.field_name', 'og_group_ref');
    $query->condition('g.entity_type', 'node');
    $query->condition('g.group_type', 'node');
    $query->condition('g.gid', $this->node->nid);
    $query->orderBy('n.changed', 'DESC');
    $query->range(0, $range);
    $nids = $query->execute()->fetchCol(0);

    if (!count($nids)) {
      return FALSE;
    }

    return $nids;
  }

  /**
   * Get the next upcoming event for the group, if any.
   * @return
   *  nid, FALSE if none exist.
   */
  public function getUpcomingEvents($range = 3) {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'event')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_recurring_event_date2', 'value', date('Y-m-d'), '>')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_recurring_event_date2', 'value', 'ASC')
      ->range(0, $range)
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get latest document nodes added to a group.
   * @TODO expose admin settings form for range default argument.
   *  @return
   *    Document node ids for group or FALSE if none exist.
   */
  public function getRecentDocuments($range = 6, $even = TRUE) {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_report_meeting_date', 'value', 'DESC')
      ->range(0, $range) // This is a hard limit, not a paginator.
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    // Insure an even number of recent documents.
    if ($even) {
      if ((count($res['node']) % 2) == 1) {
        array_pop($res['node']);
        if (count($res['node']) == 0) {
          return FALSE;
        }
      }
    }
    return array_keys($res['node']);
  }

  /**
   * Get documents with the 'field_featured' flag for the current group.
   *  @return
   *   Return a list of featured document nids.
   */
  public function getFeaturedDocuments() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_featured', 'value', 1)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get document libraries, including arbitrary content libraries, related to the current group.
   *  @return
   *   Return a list of library nids.
   */
  public function getLibraries() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', array('library', 'arbitrary_library'), 'IN')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      // Include only libraries that are 'Top Level' content, i.e. no parents
      ->addTag('node_has_no_parent')
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();

    if (!isset($res['node'])) {
      return array();
    }

    return array_keys($res['node']);
  }

  /**
   * Delegates key documents management to the cluster_docs module.
   * @return render array of documents.
   */
  public function getKeyDocuments() {
    return cluster_docs_get_grouped_key_docs($this->node->nid);
  }

  /**
   * @return bool
   */
  public function hasKeyDocuments() {
    $query = new EntityFieldQuery();
    $count = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_key_document', 'value', 1)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->range(0, 1)
      ->count()
      ->execute();

    return $count > 0;
  }

  /**
   * Get the role id for a group from the role name.
   * @param $role_name
   *  The role name as stored in the database.
   * @param $group_bundle
   *  The bundle (e.g. content type) as a string.
   * @return Integer representing the role ID.
   */
  public function getRoleIdByName($role_name, $group_bundle) {
    return db_select('og_role', 'og_r')
      ->fields('og_r', array('rid'))
      ->condition('group_bundle', $group_bundle)
      ->condition('name', $role_name)
      ->execute()->fetchField();
  }

  /**
   * Get all users with specified role for a group.
   * @param $role_name
   *  The role name as stored in the database.
   * @return Array of user IDs.
   */
  public function getUsersByRole($role_name, $node) {
    $rid = $this->getRoleIdByName($role_name, $node->type);
    if (!$rid) {
      return;
    }

    return db_select('og_users_roles', 'og_ur')
      ->fields('og_ur', array('uid'))
      ->condition('gid', $node->nid)
      ->condition('rid', $rid)
      ->execute()->fetchCol();
  }

  public function getDescendantIds($include_self = FALSE, &$collected_nids = array()) {
    if (!$this->parent_field) {
      return $include_self ? [$this->node->nid] : NULL;
    }

    if (is_null($this->descendant_ids)) {
      $this->descendant_ids = self::queryDescendants(array($this->node->nid), $this->parent_field, $this->node->type);
    }

    if ($include_self) {
      $ret = $this->descendant_ids;
      $ret[] = $this->node->nid;
      return $ret;
    }
    else {
      return $this->descendant_ids;
    }
  }

  /**
   * Helper function. Queries the DB to find children of a specific content type,
   * by parent ID.
   * @param $parent_nids
   *  Array of node IDs for which to find children.
   * @param $field
   *  Entity reference field name to use.
   * @param $bundle
   *  Content type to look for.
   * @return Array of node IDs.
   */
  public function queryChildren($parent_nids, $field, $bundle) {
    return self::queryDescendants($parent_nids, $field, $bundle, FALSE, TRUE);
  }

  /**
   * Recursively look for children that have any of the argued $nids for parent.
   * @param $parent_nids
   *  Array of node IDs to find descendants on.
   * @param $field
   *  Entity reference field name to use.
   * @param $bundle
   *  Content type to look for.
   * @param $include_self
   *  Whether to include $parent_nids in the result.
   * @param $only_children
   *  Don't do the recursive call.
   * @return Array of node IDs.
   */
  private static function queryDescendants($parent_nids, $field, $bundle, $include_self = FALSE, $only_children = FALSE) {
    if (!$parent_nids) {
      return array();
    }

    $query = new EntityFieldQuery();

    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', $bundle)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition($field, 'target_id', $parent_nids, 'IN')
      ->execute();

    if (isset($res['node'])) {

      // We found children nodes.
      if ($only_children) {
        $return_nids = array_keys($res['node']);
      }
      else {
        // Do a recursive call to get all descendants.
        $return_nids = self::queryDescendants(array_keys($res['node']), $field, $bundle, TRUE);
      }

      if ($include_self) {
        $return_nids = array_merge($return_nids, $parent_nids);
      }

      $return_sorted_nids = shelter_base_sort_nids_by_weight($return_nids);

      return array_unique($return_sorted_nids);

    }
    elseif ($include_self) {
      // No results from the query but we were asked to include parents in the result.
      return $parent_nids;
    }
    else {
      // No results and no parents are to be returned, so return empty.
      return array();
    }
  }

  /**
   * Returns TRUE if the specified module (documents, discussions, events) is enabled.
   * @param string $module
   * @return bool
   */
  public function isEnabled($module) {
    if (!isset($this->node->field_group_modules)) {
      return TRUE;
    }

    $wrapper = entity_metadata_wrapper('node', $this->node);
    $disabled = $wrapper->field_group_modules->value();
    return !in_array($module, $disabled);
  }

  /**
   * Retrieve all community_of_practice nodes associated with the current
   * group.
   *
   * @return array
   */
  public function getCommunitiesOfPractice() {
    $query = new EntityFieldQuery();

    $result = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'community_of_practice')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->addTag('node_access')
      ->execute();

    if (!isset($result['node'])) {
      return array();
    }

    return array_keys($result['node']);
  }

}

class GroupContentManagerResponse extends GroupContentManager {
  protected $parent_field = 'field_parent_response';

  public function getRelatedResponses() {
    return $this->getDescendantIds(FALSE);
  }

  public function getRelatedHubs() {
    return $this->queryChildren($this->getDescendantIds(TRUE), 'field_parent_response', 'hub');
  }

  public function getRelatedWorkingGroups() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_parent_response', 'working_group');
  }
}

class GroupContentManagerGeographicRegion extends GroupContentManager {
  protected $parent_field = 'field_parent_region';

  public function getRelatedResponses() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_associated_regions', 'response');
  }

  public function getRelatedHubs() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'hub');
  }

  public function getRelatedWorkingGroups() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'working_group');
  }
}

class GroupContentManagerStategicAdvisory extends GroupContentManager {
  //protected $parent_field = 'field_parent_region';

  /**
   * Get the node to which a Strategic Advisory Group is associated.
   * @return
   *   The parent node for Strategic Advisory group or FALSE if none exist.
   */
  public function getStrategicAdvisoryParent() {
    // @TODO wrap in try / catch.
    $wrapper = entity_metadata_wrapper('node', $this->node);
    if ($wrapper->field_parent_response->value()) {
      return $wrapper->field_parent_response->value();
    }
    elseif ($wrapper->field_parent_region->value()) {
      return $wrapper->field_parent_region->value();
    }
  }
}

class GroupContentManagerRSS extends GroupContentManager {

  /**
   * Return the summary or the trimmed body.
   */
  private function rssSummaryOrTrimmed($body, $summary) {
    if (!empty($summary)) {
      return drupal_html_to_text($summary);
    }
    return text_summary($body, 'plain_text');
  }

  /**
   * Basic query to select common fields.
   *
   * @return object
   *   Returns a SelectQuery.
   */
  private function getRSSBasicQuery($nids) {
    $query = db_select('node', 'n');
    $query->condition('n.nid', $nids, 'IN');
    $query->join('field_data_body', 'b', 'b.entity_id = n.nid');
    $query->fields('n', array('nid', 'title', 'created'));
    $query->fields('b', array('body_value', 'body_summary'));
    return $query;
  }

  /**
   * Returns RSS data for discussions.
   */
  public function getDiscussionsRSSData() {
    $cache_name = implode(':', array(__FUNCTION__, $this->node->nid));
    $cache = cache_get($cache_name);
    if ($cache && time() < $cache->expire) {
      $results = $cache->data;
    }
    else {
      global $language;

      $build_date = time();

      $nids_query = search_api_query('default_node_index', array(
        'languages' => array($language->language),
      ));
      $filter = $nids_query->createFilter();
      $filter->condition('og_group_ref', $this->node->nid);
      $filter->condition('type', 'discussion');
      $nids_query->filter($filter);
      $nids_query->sort('changed', 'DESC');

      $nids_results = $nids_query->execute();

      if (!isset($nids_results['results'])
      || !count($nids_results['results'])) {
        return array(array(), REQUEST_TIME);
      }

      $nids = array_keys($nids_results['results']);
      $query = $this->getRSSBasicQuery($nids);
      $results = $query->execute()->fetchAllAssoc('nid');

      global $base_root;

      // Using the items selected in the query, we compute some other fields
      // that should be exported to the templates.
      foreach ($results as $nid => &$result) {
        $result->url = $base_root . '/' . drupal_get_path_alias('node/' . $nid);
        $result->guid = $base_root . '/node/' . $nid;
        $result->pubDate = format_date($result->created, 'custom', 'D, d M Y H:i:s O');
        $result->description = $this->rssSummaryOrTrimmed($result->body_value, $result->body_summary);
      }
      cache_set($cache_name, $results, 'cache', time() + 60);
    }
    return array(
      $results,
      isset($cache->created) ? $cache->created : REQUEST_TIME,
    );
  }

  /**
   * Returns RSS data for documents.
   */
  public function getDocsRSSData() {
    $cache_name = implode(':', array(__FUNCTION__, $this->node->nid));
    $cache = cache_get($cache_name);
    if ($cache && time() < $cache->expire) {
      $results = $cache->data;
    }
    else {
      $nids_query = cluster_docs_query();
      $filter = $nids_query->createFilter();
      $filter->condition('og_group_ref', $this->node->nid);
      $nids_query->filter($filter);
      $nids_results = $nids_query->execute();

      if (!isset($nids_results['results'])
      || !count($nids_results['results'])) {
        return array(array(), REQUEST_TIME);
      }

      $nids = array_keys($nids_results['results']);
      $query = $this->getRSSBasicQuery($nids);
      $results = $query->execute()->fetchAllAssoc('nid');

      global $base_root;

      // Using the items selected in the query, we compute some other fields
      // that should be exported to the templates.
      foreach ($results as $nid => &$result) {
        $result->url = $base_root . '/' . drupal_get_path_alias('node/' . $nid);
        $result->guid = $base_root . '/node/' . $nid;
        $result->pubDate = format_date($result->created, 'custom', 'D, d M Y H:i:s O');
        $result->description = $this->rssSummaryOrTrimmed($result->body_value, $result->body_summary);
      }
      cache_set($cache_name, $results, 'cache', time() + 60);
    }
    return array(
      $results,
      isset($cache->created) ? $cache->created : REQUEST_TIME,
    );
  }

  /**
   * Returns RSS data for Events.
   */
  public function getEventsRSSData() {
    $cache_name = implode(':', array(__FUNCTION__, $this->node->nid));
    $cache = cache_get($cache_name);
    if ($cache && time() < $cache->expire) {
      $results = $cache->data;
    }
    else {
      $nids_query = new EntityFieldQuery();
      $nids_query->entityCondition('entity_type', 'node')
        ->entityCondition('bundle', 'event')
        ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
        ->propertyCondition('status', NODE_PUBLISHED)
        ->fieldOrderBy('field_recurring_event_date2', 'value', 'DESC');

      $nids_results = $nids_query->execute();
      if (!isset($nids_results['node'])
      || !count($nids_results['node'])) {
        return array(array(), REQUEST_TIME);
      }

      $nids = array_keys($nids_results['node']);
      $query = $this->getRSSBasicQuery($nids);
      $query->join('field_data_field_recurring_event_date2', 'e', 'e.entity_id = n.nid');
      $query->fields('e', array('field_recurring_event_date2_value'));
      $results = $query->execute()->fetchAllAssoc('nid');

      global $base_root;

      // Using the items selected in the query, we compute some other fields
      // that should be exported to the templates.
      foreach ($results as $nid => &$result) {
        $result->url = $base_root . '/' . drupal_get_path_alias('node/' . $nid);
        $result->guid = $base_root . '/node/' . $nid;
        $result->pubDate = format_date($result->created, 'custom', 'D, d M Y H:i:s O');
        $time = new DateTime($result->field_recurring_event_date2_value);
        $unixdate = $time->getTimestamp();
        $result->eventDate = format_date($unixdate, 'custom', 'D, d M Y H:i:s O');
        $result->description = $this->rssSummaryOrTrimmed($result->body_value, $result->body_summary);
      }
      cache_set($cache_name, $results, 'cache', time() + 60);
    }
    return array(
      $results,
      isset($cache->created) ? $cache->created : REQUEST_TIME,
    );
  }

}
