<?php

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

  public function __construct($node) {
    $this->node = $node;
  }

  public function getRelatedResponses() {
    return NULL;
  }

  public function getRelatedHubs() {
    return NULL;
  }

  public function getContactMembers() {
    $contact_members_ids = self::getUsersByRole('contact member', $this->node);
    return GroupPageContent::getList($contact_members_ids, 'contact_member', 'cluster_og_contact_member', 'user');
  }

  public function getRecentDocuments() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->range(0, 5) // This is a hard limit, not a paginator.
      ->execute();

    if (!isset($res['node'])) {
      return NULL;
    }

    $ret = GroupPageContent::getList(array_keys($res['node']), 'teaser', 'cluster_og_recent_documents');
    $ret['#all_documents_link'] = 'node/' . $this->node->nid . '/documents';

    return $ret;
  }

  /**
   * Returns the Key Documents for this group, grouped by Document Tags.
   * The outer array uses the cluster_og_key_documents theme wrapper;
   * the inner arrays (which render the actual documents), use cluster_og_key_documents_by_tag.
   * @return Nested render array.
   */
  public function getKeyDocuments() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->fieldCondition('field_key_document', 'value', 1)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->execute();

    if (!isset($res['node'])) {
      return NULL;
    }

    $documents = entity_load('node', array_keys($res['node']));

    uasort($documents, function($a, $b) {
      $a_wrapper = entity_metadata_wrapper('node', $a);
      $b_wrapper = entity_metadata_wrapper('node', $b);
      $a_tag = $a_wrapper->field_document_tag->value();
      $b_tag = $b_wrapper->field_document_tag->value();
      return ($a_tag ? $a_tag->weight : -99999) - ($b_tag ? $b_tag->weight : -99999);
    });

    $ret = array(
      '#theme_wrappers' => array('cluster_og_key_documents'),
    );

    $current_document_tag = NULL;
    $current_document_group = array();
    foreach ($documents as $document) {
      $wrapper = entity_metadata_wrapper('node', $document);
      $tag = $wrapper->field_document_tag->value();

      if (is_null($current_document_tag) && !$tag) {
        $current_document_group[] = $document->nid;
      }
      elseif (is_null($current_document_tag) && $tag) {
        // First group (no tag) is over, render it.
        $ret[] = GroupPageContent::getList($current_document_group, 'teaser', 'cluster_og_key_documents_by_tag');

        $current_document_group = array($document->nid);
        $current_document_tag = $tag;
      }
      elseif ($current_document_tag->tid == $tag->tid) {
        $current_document_group[] = $document->nid;
      }
      else {
        // Group is over, render it and move on.
        $group = GroupPageContent::getList($current_document_group, 'teaser', 'cluster_og_key_documents_by_tag');
        $group['#document_tag_name'] = $current_document_tag->name;
        $ret[] = $group;

        $current_document_group = array($document->nid);
        $current_document_tag = $tag;
      }
    }
    if ($current_document_group) {
      if (is_null($current_document_tag)) {
        $ret[] = GroupPageContent::getList($current_document_group, 'teaser', 'cluster_og_key_documents_by_tag');
      }
      else {
        $group = GroupPageContent::getList($current_document_group, 'teaser', 'cluster_og_key_documents_by_tag');
        $group['#document_tag_name'] = $current_document_tag->name;
        $ret[] = $group;
      }
    }

    return $ret;
  }

  /**
   * Get the role id for a group from the role name.
   * @param $role_name
   *  The role name as stored in the database.
   * @param $group_bundle
   *  The bundle (e.g. content type) as a string.
   * @return Integer representing the role ID.
   */
  static public function getRoleIdByName($role_name, $group_bundle) {
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
  static public function getUsersByRole($role_name, $node) {
    $rid = self::getRoleIdByName($role_name, $node->type);
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
      default:
        return new GroupContentManager($node);
    }
  }

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

      // We call array_unique just in case there are duplicates. There shouldn't.
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

class GroupContentManagerResponse extends GroupContentManager {
  protected $parent_field = 'field_parent_response';

  public function getRelatedResponses() {
    $nids = $this->getDescendantIds(FALSE);
    return GroupPageContent::getList($nids, 'related_response', 'cluster_og_related_responses');
  }

  public function getRelatedHubs() {
    $nids = $this->queryChildren($this->getDescendantIds(TRUE), 'field_parent_response', 'hub');
    return GroupPageContent::getList($nids, 'related_hub', 'cluster_og_related_hubs');
  }
}

class GroupContentManagerGeographicRegion extends GroupContentManager {
  protected $parent_field = 'field_parent_region';

  public function getRelatedResponses() {
    $nids = self::queryChildren($this->getDescendantIds(TRUE), 'field_associated_regions', 'response');
    return GroupPageContent::getList($nids, 'related_response', 'cluster_og_related_responses');
  }

  public function getRelatedHubs() {
    $nids = self::queryChildren($this->getDescendantIds(TRUE), 'field_parent_region', 'hub');
    return GroupPageContent::getList($nids, 'related_hub', 'cluster_og_related_hubs');
  }
}

class GroupPageContent {

  protected $node;
  protected $view_mode;

  /**
   * @var GroupContentManager implementation.
   */
  private $manager;

  function __construct($node, $view_mode) {
    $this->node = $node;
    $this->manager = GroupContentManager::getInstance($node);
    $this->view_mode = $view_mode;
  }

  public function getContactMembers() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getContactMembers();
  }

  public function getRelatedResponses() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getRelatedResponses();
  }

  public function getRelatedHubs() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getRelatedHubs();
  }

  public function getKeyDocuments() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getKeyDocuments();
  }

  public function getRecentDocuments() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getRecentDocuments();
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
  static public function getList($ids, $view_mode = 'teaser', $theme_wrapper = NULL, $entity_type = 'node') {
    if (!$ids) {
      return NULL;
    }

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