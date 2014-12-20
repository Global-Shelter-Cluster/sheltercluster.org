<?php

/**
 * Provides theme layer integration for group content.
 */
class GroupDisplayProvider {
  public static function getDisplayProvider($node, $view_mode = 'full') {
    
    switch ($view_mode) {
      case 'full':
        return new GroupPageDisplayProvider($node, $view_mode);
        break;
      default:
        return new GroupDisplayProvider();
    }
  }

  /**
   * Magic callback.
   * Provides a default return value of FALSE for all methods that are not implemented in a specific view mode
   * descendent class.
   */
  public function __call($name, $arguments) {
    return FALSE;
  }
}

/**
 * Provide renderable content for full page view mode. 
 */
class GroupPageDisplayProvider extends GroupDisplayProvider{

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

  /**
   * Get the contact members for the group.
   * @return
   *  Render array of contact members or FALSE if none exist.
   */
  public function getContactMembers() {
    if ($contact_members_ids = $this->manager->getContactMembers()) {
      return self::getList($contact_members_ids, 'contact_member', 'cluster_og_contact_member', 'user');
    }
    return FALSE;
  }

  /**
   * 
   */
  public function getRelatedResponses() {
    if ($nids = $this->manager->getRelatedResponses()) {
      return self::getList($nids, 'related_response', 'cluster_og_related_responses');
    }
    return FALSE;
  }

  /**
   * 
   */
  public function getRelatedHubs() {
    if ($nids = $this->manager->getRelatedHubs()) {
      return self::getList($nids, 'related_hub', 'cluster_og_related_hubs');
    }
    return FALSE;
  }

  /**
   * Returns the Key Documents for this group, grouped by Vocabularies.
   * @return render array of key documents. 
   */
  public function getKeyDocuments() {
    if ($docs = $this->manager->getKeyDocuments()) {
      return array('docs' => $docs);
    }
    return FALSE;
  }

  /**
   * @TODO delegate theming completely to cluster_docs. 
   */
  public function getFeaturedDocuments() {
    if ($nids = $this->manager->getFeaturedDocuments()) {
      return array(
        '#theme' => 'cluster_docs_featured_documents',
        '#theme_wrappers' => array('cluster_og_featured_documents'),
        '#docs' => cluster_docs_prepare_card_data($nids),
        '#all_documents_link' => 'node/' . $this->node->nid . '/documents',
      );
    }
    return FALSE;
  }

  /**
   * @TODO delegate theming completely to cluster_docs. 
   */
  public function getRecentDocuments() {
    if ($nids = $this->manager->getRecentDocuments()) {
      return array(
        '#theme' => 'cluster_docs_cards_list',
        '#theme_wrappers' => array('cluster_og_recent_documents'),
        '#docs' => cluster_docs_prepare_card_data($nids),
        '#all_documents_link' => 'node/' . $this->node->nid . '/documents',
      );
    }
    return FALSE;
  }

  /**
   * Provide recent discussion nodes for the group.
   * @return render array of discussions. 
   */
  public function getRecentDiscussions() {
    $content = FALSE;
    if ($nodes = $this->manager->getRecentDiscussions()) {
      $content = GroupPageContent::getList($nodes, 'teaser', 'cluster_og_recent_discussions');
      $content['#all_discussions_link'] = 'node/' . $this->node->nid . '/discussions';
    }
    return $content;
  }

  /**
   * Generate the dashboard links for a group node.
   * @return
   *  Render array of dashboard links.
   */
  public function getDashboardMenu() {
    $items = array();

    $items[] = array(
      'label' => t('Dashboard'),
      'path' => 'node/'.$this->node->nid,
    );

    $items[] = array(
      'label' => t('Documents'),
      'path' => 'node/'.$this->node->nid.'/documents',
      'total' => $this->manager->getDocumentCount(),
    );

    $items[] = array(
      'label' => t('Discussions'),
      'path' => 'node/'.$this->node->nid.'/discussions',
      'total' => $this->manager->getDiscussionCount(),
    );

    $items[] = array(
      'label' => t('Events'),
      'path' => '/', //TODO: change this to actual events calendar link
//      'total' => $total,
    );

    // This is a reference to the Strategic Advisory "parent" group. Disabled because the link is in the breadcrumb.
    
    // @TODO, if link is in breadcrumb, can we delete this code ?

//    if ($parent = $this->getStrategicAdvisoryParent()) {
//      $items[] = array(
//        'label' => t('Parent'),
//        'path' => 'node/'.$parent->nid,
//      );
//    }

    if ($strategic_advisory = $this->manager->getStrategicAdvisory()) {
      $items[] = array(
        'label' => t('Strategic Advisory Group'),
        'path' => 'node/' . $strategic_advisory->nid,
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


  /**
   * Generates contextual navigation (breadcrumb-like) for groups.
   * @return
   *  Render array of contextual navigation elements.
   */
  public function getContextualNavigation() {
    $wrapper = entity_metadata_wrapper('node', $this->node);

    $output = array(
      '#theme' => 'cluster_contextual_nav',
    );

    // The the group parent region.
    if (isset($wrapper->field_parent_region)) {
      $region = $wrapper->field_parent_region->value();
      if ($region) {
        $output['#regions'] = array(
          array(
            'title' => $region->title,
            'path' => 'node/' . $region->nid,
          )
        );
      }
    }

    // Add the group associated regions.
    elseif (isset($wrapper->field_associated_regions)) {
      $output['#regions'] = array();

      foreach ($wrapper->field_associated_regions->value() as $region) {
        $output['#regions'][] = array(
          'title' => $region->title,
          'path' => 'node/' . $region->nid,
        );
      }
    }

    // Add the group parent response.
    if (isset($wrapper->field_parent_response)) {
      $response = $wrapper->field_parent_response->value();
      if (!empty($response)) {
        $output['#response'] = array(
          'title' => $response->title,
          'path' => 'node/' . $response->nid,
        );
      }
    }

    return $output;
  }

  /**
   * Helper function. Returns a list of entities as a render array using the given
   * view mode and theme wrapper.
   *
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