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
   * Get the node to which a Strategic Advisory Group is associated. 
   * @return
   *   The parent node for Strategic Advisory group or FALSE if none exist.
   */
  public function getStrategicAdvisoryParent() {
    return FALSE;
  }

  /**
   * 
   */
  public function getRelatedResponses() {
    return FALSE;
  }

  /**
   * 
   */
  public function getRelatedHubs() {
    return FALSE;
  }

  /**
   * Finds a strategic advisory node for the current group.
   * If there is more than one, it is not defined which one will be returned.
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
   * Provide a count value for all pubished document nodes added to the group.
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
   * Provide a count value for all pubished discussion nodes added to the group.
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
   * Get users with the contact member role for the group.
   *  @return 
   */
  public function getContactMembers() {
    return $this->getUsersByRole('contact member', $this->node);
  }

  /**
   * Get recent discussions for a group node.
   * @return
   *  array of discussion node ids, FALSE if none exist.
   */
  public function getRecentDiscussions($range = 2) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'discussion')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->range(0, $range) // This is a hard limit, not a paginator.
      ->execute();

    if (!isset($result['node'])) {
      return FALSE;
    }

    return array_keys($result['node']);
  }

  /**
   * Get latest document nodes added to a group.
   * @TODO expose admin settings form for range default argument.
   *  @return
   *    Document node ids for group or FALSE if none exist.
   */
  public function getRecentDocuments($range = 5) {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->range(0, $range) // This is a hard limit, not a paginator.
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return array_keys($res['node']);
  }

  /**
   * Get documents with the 'field_featured' flag for the current group.
   *  @return
   *   Return render array of featured documents.
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

    return $res['node'];
  }

  /**
   * Delegates key documents management to the cluster_docs module.
   * @return render array of documents.
   */
  public function getKeyDocuments() {
    return cluster_docs_get_grouped_key_docs($this->node->nid);
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

  /**
   * @TODO write doc for this method.
   */
  public function getDescendantIds($include_self = FALSE, &$collected_nids = array()) {
    if (!$this->parent_field) {
      return NULL;
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
  static function queryChildren($parent_nids, $field, $bundle) {
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

      // We call array_unique just in case there are duplicates. There shouldn't be any.
      return array_unique($return_nids);

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

}

/**
 * @TODO describe class.
 */
class GroupContentManagerResponse extends GroupContentManager {
  protected $parent_field = 'field_parent_response';

  public function getRelatedResponses() {
    return $this->getDescendantIds(FALSE);
  }

  public function getRelatedHubs() {
    return $this->queryChildren($this->getDescendantIds(TRUE), 'field_parent_response', 'hub');
  }
}

/**
 * @TODO describe class.
 */
class GroupContentManagerGeographicRegion extends GroupContentManager {
  protected $parent_field = 'field_parent_region';

  public function getRelatedResponses() {
    return self::queryChildren($this->getDescendantIds(TRUE), 'field_associated_regions', 'response');
  }

  public function getRelatedHubs() {
    return self::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'hub');
  }
}

/**
 * @TODO describe class.
 */
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