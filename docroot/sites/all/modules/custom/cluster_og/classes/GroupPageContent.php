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

  public function getDashboardMenu() {
    $items = array();

    $items[] = array(
      'label' => t('Dashboard'),
      'path' => 'node/'.$this->node->nid,
    );

    $items[] = array(
      'label' => t('Documents'),
      'path' => 'node/'.$this->node->nid.'/documents',
      'total' => $this->getDocumentCount(),
    );

    $items[] = array(
      'label' => t('Discussions'),
      'path' => 'node/'.$this->node->nid.'/discussions',
      'total' => $this->getDiscussionCount(),
    );

    $items[] = array(
      'label' => t('Agenda'),
      'path' => 'node/'.$this->node->nid.'/edit', //TODO: change this to actual Agenda link
//      'total' => $total,
    );

    // This is a reference to the Strategic Advisory "parent" group. Disabled because the link is in the breadcrumb.
//    if ($parent = $this->getStrategicAdvisoryParent()) {
//      $items[] = array(
//        'label' => t('Parent'),
//        'path' => 'node/'.$parent->nid,
//      );
//    }

    if ($strategic_advisory = $this->getStrategicAdvisory()) {
      $items[] = array(
        'label' => t('Strategic Advisory'),
        'path' => 'node/'.$strategic_advisory->nid,
      );
    }

    $secondary = array();

    $secondary['hubs'] = $this->getRelatedHubs();
    $secondary['responses'] = $this->getRelatedResponses();

    return array(
      '#theme' => 'cluster_nav',
      '#items' => $items,
      '#secondary' => $secondary,
    );
  }

  public function getContextualNavigation() {
    $wrapper = entity_metadata_wrapper('node', $this->node);

    $ret = array(
      '#theme' => 'cluster_contextual_nav',
    );

    if (isset($wrapper->field_parent_region)) {
      $region = $wrapper->field_parent_region->value();
      if ($region) {
        $ret['#regions'] = array(
          array(
            'title' => $region->title,
            'path' => 'node/'.$region->nid,
          )
        );
      }
    } elseif (isset($wrapper->field_associated_regions)) {
      $ret['#regions'] = array();

      foreach ($wrapper->field_associated_regions->value() as $region) {
        $ret['#regions'][] = array(
          'title' => $region->title,
          'path' => 'node/'.$region->nid,
        );
      }
    }

    if (isset($wrapper->field_parent_response)) {
      $response = $wrapper->field_parent_response->value();
      if (!empty($response)) {
        $ret['#response'] = array(
          'title' => $response->title,
          'path' => 'node/'.$response->nid,
        );
      }
    }

    return $ret;
  }

  /**
   * Returns the parent node. Only works if the current node is a Strategic Advisory group.
   */
  public function getStrategicAdvisoryParent() {
    if ($this->node->type != 'strategic_advisory') {
      return;
    }

    $wrapper = entity_metadata_wrapper('node', $this->node);
    if ($wrapper->field_parent_response->value()) {
      return $wrapper->field_parent_response->value();
    } elseif ($wrapper->field_parent_region->value()) {
      return $wrapper->field_parent_region->value();
    }
  }

  /**
   * Finds a strategic advisory node for the current group.
   * Only works if the current group is not a strategic advisory itself.
   * If there is more than one, it is not defined which one will be returned.
   */
  public function getStrategicAdvisory() {
    if ($this->node->type == 'strategic_advisory') {
      return;
    }

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
  }

  public function getDocumentCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'document')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
  }

  public function getDiscussionCount() {
    $query = new EntityFieldQuery();
    return $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'discussion')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->count()
      ->execute();
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

  public function getRecentDiscussions() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'discussion')
      ->fieldCondition('og_group_ref', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('changed', 'DESC')
      ->range(0, 2) // This is a hard limit, not a paginator.
      ->execute();

    if (!isset($res['node'])) {
      return NULL;
    }

    $ret = GroupPageContent::getList(array_keys($res['node']), 'teaser', 'cluster_og_recent_discussions');
    $ret['#all_discussions_link'] = 'node/' . $this->node->nid . '/discussions';

    return $ret;
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

    return array(
      '#theme' => 'cluster_docs_cards_list',
      '#theme_wrappers' => array('cluster_og_recent_documents'),
      '#heading' => t('Recent Documents'),
      '#docs' => cluster_docs_prepare_card_data(array_keys($res['node'])),
      '#all_documents_link' => 'node/' . $this->node->nid . '/documents',
    );
  }

  /**
   * Returns the Key Documents for this group, grouped by Vocabularies.
   * The outer array uses the cluster_og_key_documents theme wrapper;
   * The document rendering is provided by cluster_docs module.
   * @return Nested render array.
   */
  public function getKeyDocuments() {
    $ret = array(
      '#theme_wrappers' => array('cluster_og_key_documents'),
      'docs' => cluster_docs_get_grouped_key_docs($this->node->nid),
    );
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

  public function getRecentDiscussions() {
    if ($this->view_mode != 'full') {
      return NULL;
    }
    return $this->manager->getRecentDiscussions();
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