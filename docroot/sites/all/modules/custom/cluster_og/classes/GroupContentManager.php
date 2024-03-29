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

  public function getParentPage($currently_visible_node_id) {
    $node = node_load($currently_visible_node_id);
    if (isset($node->field_parent_content)) {
      return $node->field_parent_content[LANGUAGE_NONE][0]['target_id'];
    }
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
   * Get all factsheet nodes that belong the group, ordered by date (recent first).
   *
   * @return array of node ids
   */
  public function getFactsheets($limit = NULL) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'factsheet')
      ->fieldCondition('field_factsheet_is_visible', 'value', 1)
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_date', 'value', 'DESC')
      ->propertyOrderBy('created', 'DESC');
    if ($limit)
      $query->range(NULL, $limit);

    $result = $query->execute();
    if (isset($result['node'])) {
      return array_keys($result['node']);
    }
    return [];
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
   * Provide a count value for all published news nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getNewsCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'news')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Provide a count value for all users following the group.
   * @return
   *  Count result.
   */
  public function getFollowersCount() {
    $query = db_select('og_users_roles', 'our');
    $query->fields('n', array('nid'));
    $query->condition('our.group_type', 'node');
    $query->condition('our.gid', $this->node->nid);
    $query->condition('our.rid', cluster_api_get_follower_role_by_bundle($this->node->type));

    $query->join('users', 'u', 'u.uid = our.uid');
    $query->condition('u.status', 1);

    return $query->countQuery()->execute()->fetchField();
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

  protected function isDiscussionsEnabled() {
    $wrapper = entity_metadata_wrapper('node', $this->node);
    return (bool) $wrapper->field_enable_discussions->value();
//    $v = $wrapper->field_email_address_identifier->value();
//    return !empty($v);
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
   * Provide a count value for all published factsheet nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getFactsheetsCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'factsheet')
      ->fieldCondition('field_factsheet_is_visible', 'value', 1)
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Provide a count value for all published kobo form nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getKoboFormsCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'kobo_form')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  /**
   * Provide a count value for all published kobo form nodes added to the group.
   * @return
   *  Count query result.
   */
  public function getWebformsCount($skip_resource_check = FALSE) {
    if (!$skip_resource_check && variable_get('cluster_og_resources_id') == $this->node->nid)
      // Forms in the Resources group are just "templates".
      return 0;

    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'webform')
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
   * @return []int|FALSE
   *  nid, FALSE if none exist.
   */
  public function getUpcomingEvents($range = 3, $days_limit = NULL) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'event')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_recurring_event_date2', 'value', date('Y-m-d'), '>')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_recurring_event_date2', 'value', 'ASC');

    if (!is_null($range))
      $query->range(0, $range);

    if (!is_null($days_limit)) {
      $end_date = date('Y-m-d', time() + (3600 * 24 * ($days_limit + 1)));
      $query->fieldCondition('field_recurring_event_date2', 'value', $end_date, '<');
    }

    $res = $query
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get the latest alerts, if any.
   * @return []int|FALSE
   *  nid, FALSE if none exist.
   */
  public function getLatestAlerts($limit = 10, $days_limit = 7) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'alert')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('created', 'DESC');

    if (!is_null($limit))
      $query->range(0, $limit);

    if (!is_null($days_limit)) {
      $timestamp_limit = REQUEST_TIME - (3600 * 24 * $days_limit);
      $query->propertyCondition('created', $timestamp_limit, '>');
    }

    $res = $query
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get the latest news, if any.
   * @return []int|FALSE
   *  nid, FALSE if none exist.
   */
  public function getLatestNews($limit = 10, $days_limit = 7) {
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'news')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('created', 'DESC');

    if (!is_null($limit))
      $query->range(0, $limit);

    if (!is_null($days_limit)) {
      $timestamp_limit = REQUEST_TIME - (3600 * 24 * $days_limit);
      $query->propertyCondition('created', $timestamp_limit, '>');
    }

    $res = $query
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

  public function getPhotoGalleries() {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'photo_gallery')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldOrderBy('field_sorting_weight', 'value', 'ASC')
      ->execute();
    if (isset($result['node'])) {
      return array_keys($result['node']);
    }
    return array();
  }

  public function getWebforms($skip_resource_check = FALSE) {
    if (!$skip_resource_check && variable_get('cluster_og_resources_id') == $this->node->nid)
      // Forms in the Resources group are just "templates".
      return [];

    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'webform')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->execute();

    if (!isset($res['node'])) {
      return array();
    }

    return array_keys($res['node']);
  }

  public function getKoboForms() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'kobo_form')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
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
   * Get documents with the 'field_key_document' flag for the current group.
   *  @return
   *   Return a list of key document nids.
   */
  public function getKeyDocumentIds() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_key_document', 'value', 1)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
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
   * Get all active users with specified role for a group.
   *
   * @param string|array $role_names
   *  The role name(s) as stored in the database.
   * @param NULL|string[] $filter_user_timezones
   *  Only return users with one of the given timezones, e.g. ["Europe/Budapest", "Americas/New_York"]
   * @param NULL|int $filter_access_threshold
   *  Only return users who have accessed the site (or mobile app) in the last X seconds.
   * @param NULL|callable $query_alter
   *  Callback that alters the query (e.g. can add conditions to it).
   *
   * @return Array of user IDs.
   */
  public function getUsersByRole($role_names, $filter_user_timezones = NULL, $filter_access_threshold = NULL, $query_alter = NULL) {
    $rids = [];
    foreach ((array) $role_names as $role_name)
      $rids[] = $this->getRoleIdByName($role_name, $this->node->type);
    $rids = array_values(array_filter($rids));
    if (!$rids)
      return [];

    $query = db_select('og_users_roles', 'og_ur')
      ->fields('og_ur', array('uid'));

    if (!is_null($filter_user_timezones) || !is_null($filter_access_threshold))
      $query->join('users', 'u', 'og_ur.uid = u.uid');

    if (!is_null($filter_user_timezones))
      $query->condition('u.timezone', $filter_user_timezones, 'IN');

    if (!is_null($filter_access_threshold))
      $query->condition('u.access', REQUEST_TIME - $filter_access_threshold, '>');

    $query->condition('u.status', 1);
    $query->condition('og_ur.gid', $this->node->nid);
    $query->condition('og_ur.rid', $rids, 'IN');

    if (!is_null($query_alter))
      $query_alter($query);

    return $query->execute()->fetchCol();
  }

  /**
   * Set the current timestamp (using the REQUEST_TIME const) into a field on the og_users_roles table,
   * for the given role and user ids.
   *
   * In order for this to work, the field name must already exist in the table (see cluster_api.install
   * for an example).
   *
   * @param string $role_name See self::getUsersByRole()
   * @param $uids int[]
   * @param $field_name string E.g. "last_daily_push_notification"
   */
  public function updateUsersTimestamp($role_name, $uids, $field_name) {
    $rid = $this->getRoleIdByName($role_name, $this->node->type);
    if (!$rid)
      return;

    $query = db_update('og_users_roles')
      ->fields([
        $field_name => REQUEST_TIME,
      ])
      ->condition('uid', $uids, 'IN')
      ->condition('gid', $this->node->nid)
      ->condition('rid', $rid);

    $query->execute();
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
      if ($module === 'discussions')
        return $this->isDiscussionsEnabled();
      else
        return TRUE;
    }

    $wrapper = entity_metadata_wrapper('node', $this->node);
    $disabled = $wrapper->field_group_modules->value();
    $ret = !in_array($module, $disabled);

    if ($ret && $module === 'discussions')
      return $this->isDiscussionsEnabled();

    return $ret;
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

  /**
   * @return array keys are region nids, values are arrays of response ids
   */
  public function getResponseRegionHierarchy() {
    $regions = $this->getRelatedRegions();
    $responses = $this->getRelatedResponses();

    $get_target_id = function($i) {
      return intval($i['target_id']);
    };

    $ret = [];

    foreach ($responses as $response_id) {
      $response = node_load($response_id);

      $response_regions = field_get_items('node', $response, 'field_associated_regions');
      if (!$response_regions)
        continue;
      $response_regions = array_unique(array_values(array_map($get_target_id, $response_regions)));
      $response_regions = array_filter($response_regions, function($id) use ($regions) {
        return in_array($id, $regions);
      });
      if (count($response_regions) === 0)
        continue;

      $found = FALSE;
      foreach ($response_regions as $id) {
        if (array_key_exists($id, $ret)) {
          $ret[$id][] = $response_id;
          $found = TRUE;
          break;
        }
      }

      if (!$found) {
        reset($response_regions);
        $ret[current($response_regions)] = [$response_id];
      }
    }

    return $ret;
  }

  public function getRelatedResponses() {
    $nids = $this::queryChildren($this->getDescendantIds(TRUE), 'field_associated_regions', 'response');
    cluster_og_sort_response_nids_active_first($nids);
    return $nids;
  }

  public function getRelatedHubs() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'hub');
  }

  public function getRelatedWorkingGroups() {
    return $this::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'working_group');
  }

  public function getRelatedRegions() {
    return $this::queryChildren([$this->node->nid], 'field_parent_region', 'geographic_region');
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
