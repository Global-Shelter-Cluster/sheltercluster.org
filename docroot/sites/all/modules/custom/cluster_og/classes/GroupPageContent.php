<?php

class GroupPageContent_Response extends GroupPageContent {
  protected $parent_field = 'field_parent_response';

  public function getRelatedResponses($view_mode = 'related_response') {
    $nids = $this->getDescendantIds(FALSE);
    return $this->getList($nids, $view_mode, 'cluster_og_related_responses');
  }

  public function getRelatedHubs($view_mode = 'related_hub') {
    $nids = $this->queryChildren($this->getDescendantIds(TRUE), 'field_parent_response', 'hub');
    return $this->getList($nids, $view_mode, 'cluster_og_related_hubs');
  }
}

class GroupPageContent_GeographicRegion extends GroupPageContent {
  protected $parent_field = 'field_parent_region';

  public function getRelatedResponses($view_mode = 'related_response') {
    $nids = self::queryChildren($this->getDescendantIds(TRUE), 'field_associated_regions', 'response');
    return self::getList($nids, $view_mode, 'cluster_og_related_responses');
  }

  public function getRelatedHubs($view_mode = 'related_hub') {
    $nids = self::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'hub');
    return self::getList($nids, $view_mode, 'cluster_og_related_hubs');
  }
}

class GroupPageContent {

  protected $node;

  /**
   * @var Entity reference field name used to get children for the node.
   * Classes that inherit from this will need to override this value to make
   * $this->getDescendantIds() work.
   */
  protected $parent_field = NULL;

  /**
   * @var Array of descendant IDs, stored for caching purposes in a single request.
   */
  protected $descendant_ids;

  function __construct($node) {
    $this->node = $node;
  }

  public function getContactMembers($view_mode = 'contact_member') {
    $contact_members_ids = $this->getUsersByRole('contact member');
    return self::getList($contact_members_ids, $view_mode, 'cluster_og_contact_member', 'user');
  }

  /**
   * Get the role id for a group from the role name.
   * @param $role_name
   *  The role name as stored in the database.
   * @return Integer representing the role ID.
   */
  private function getRoleIdByName($role_name) {
    return db_select('og_role', 'og_r')
      ->fields('og_r', array('rid'))
      ->condition('group_bundle', $this->node->type)
      ->condition('name', $role_name)
      ->execute()->fetchField();
  }

  /**
   * Get all users with specified role for a group.
   * @param $role_name
   *  The role name as stored in the database.
   * @return Array of user IDs.
   */
  private function getUsersByRole($role_name) {
    $rid = $this->getRoleIdByName($role_name);
    if (!$rid) {
      return;
    }

    return db_select('og_users_roles', 'og_ur')
      ->fields('og_ur', array('uid'))
      ->condition('gid', $this->node->nid)
      ->condition('rid', $rid)
      ->execute()->fetchCol();
  }

  protected function getDescendantIds($include_self = FALSE, &$collected_nids = array()) {
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
    } else {
      return $this->descendant_ids;
    }
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
      } else {
        // Do a recursive call to get all descendants.
        $return_nids = self::queryDescendants(array_keys($res['node']), $field, $bundle, TRUE);
      }

      if ($include_self) {
        $return_nids = array_merge($return_nids, $parent_nids);
      }

      // We call array_unique just in case there are duplicates. There shouldn't.
      return array_unique($return_nids);

    } elseif ($include_self) {
      // No results from the query but we were asked to include parents in the result.
      return $parent_nids;
    } else {
      // No results and no parents are to be returned, so return empty.
      return array();
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
  protected static function queryChildren($parent_nids, $field, $bundle) {
    return self::queryDescendants($parent_nids, $field, $bundle, FALSE, TRUE);
  }

  /**
   * Helper function. Returns a list of entities as a render array using the given
   * view mode and theme wrapper.
   * @param $ids
   *  Array of entity IDs to show in the list.
   * @param $view_mode
   *  What view mode to use for showing the entities.
   * @param $theme_wrapper
   *  An optional theme wrapper.
   * @param $entity_type
   *  The entity type for the given IDs.
   * @return Render array.
   */
  protected static function getList($ids, $view_mode = 'teaser', $theme_wrapper = NULL, $entity_type = 'node') {
    if (!$ids)
      return NULL;

    $entities = entity_load($entity_type, $ids);

    $ret = array(
      '#total' => count($entities),
    );

    $info = entity_get_info($entity_type);
    foreach ($entities as $entity) {
      $ret[$entity->{$info['entity keys']['id']}] = entity_view($entity_type, array($entity), $view_mode);
    }

    if ($theme_wrapper) {
      $ret['#theme_wrappers'] = array($theme_wrapper);
    }

    return $ret;
  }

}