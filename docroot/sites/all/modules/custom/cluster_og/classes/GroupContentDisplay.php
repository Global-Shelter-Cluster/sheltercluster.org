
<?php

/**
 * Provides theme layer integration for group content.
 */
class GroupDisplayProvider {
  protected $node;
  protected $view_mode;

  /**
   * @var GroupContentManager implementation.
   */
  protected $manager;

  /**
   * Get a provider instance of the appropriate subclass for the view mode.
   */
  public static function getDisplayProvider($node, $view_mode = FALSE) {
    switch ($view_mode) {
      // When not operating within a view mode, for example to print at the page level.
      case FALSE:
        return new GroupDisplayProvider($node, $view_mode);
      // 'full' view mode node theming.
      case 'full':
        return new GroupFullDisplayProvider($node, $view_mode);
      // Defensive default for view modes which are not managed.
      default:
        return new GroupNotImplementedDisplayProvider($node, $view_mode);
    }
  }

  function __construct($node, $view_mode) {
    $this->node = $node;
    $this->manager = GroupContentManager::getInstance($node);
    $this->view_mode = $view_mode;
  }

  /**
   * Magic callback.
   * Provides a default return value of FALSE for all methods that are not implemented in a specific view mode
   * subclass.
   */
  public function __call($name, $arguments) {
    return FALSE;
  }

  /**
   * Get related response type nodes for the viewed group.
   * @return
   *  Render array of nodes.
   */
  public function getRelatedResponses() {
    if ($nids = $this->manager->getRelatedResponses()) {
      return $nids;
    }
    return FALSE;
  }

  /**
   * Get related hub type nodes for the viewed group.
   * @return
   *  Render array of nodes.
   */
  public function getRelatedWorkingGroups() {
    if ($nids = $this->manager->getRelatedWorkingGroups()) {
      return $nids;
    }
    return FALSE;
  }

  /**
   * Get related hub type nodes for the viewed group.
   * @return
   *  Render array of nodes.
   */
  public function getRelatedHubs() {
    if ($nids = $this->manager->getRelatedHubs()) {
      return $nids;
    }
    return FALSE;
  }

  /**
   * Generate the dashboard links for a group node.
   * Delegates theme implementation to cluster_nav module.
   * @return
   *  Render array of dashboard links.
   */
  public function getDashboardMenu() {
    $items = array();

    $items[] = array(
      'label' => t('Dashboard'),
      'path' => 'node/'.$this->node->nid,
    );

    if ($this->manager->isEnabled('documents')) {
      $items[] = array(
        'label' => t('Documents'),
        'path' => 'node/' . $this->node->nid . '/documents',
        'total' => $this->manager->getDocumentCount(),
      );
    }
    if ($discussions_count = $this->manager->getDiscussionCount() > 0) {
      if ($this->manager->isEnabled('discussions')) {
        $items[] = array(
          'label' => t('Discussions'),
          'path' => 'node/' . $this->node->nid . '/discussions',
          'total' => $discussions_count,
        );
      }
    }
    if ($events_count = $this->manager->getEventCount() > 0) {
      if ($this->manager->isEnabled('events')) {
        $items[] = array(
          'label' => t('Events'),
          'path' => 'node/' . $this->node->nid . '/events',
          'total' => $events_count,
        );
      }
    }

    if ($strategic_advisory = $this->manager->getStrategicAdvisory()) {
      $items[] = array(
        'label' => t('Strategic Advisory Group'),
        'path' => 'node/' . $strategic_advisory->nid,
      );
    }

    $secondary = array();
    if ($responses = $this->getRelatedResponses()) {
      $secondary['responses'] = partial('navigation_options', array(
        'navigation_type_id' => 'related-operations',
        'title' => t('Related operations'),
        'nodes' => node_load_multiple($responses)
      ));
    }
    if ($hubs = $this->getRelatedHubs()) {
      $secondary['hubs'] = partial('navigation_options', array(
        'navigation_type_id' => 'hubs',
        'title' => t('Hubs'),
        'nodes' => node_load_multiple($hubs)
      ));
    }
    if ($working_groups = $this->getRelatedWorkingGroups()) {
      $secondary['working_groups'] = partial('navigation_options', array(
        'navigation_type_id' => 'working-groups',
        'title' => t('Working groups'),
        'nodes' => node_load_multiple($working_groups)
      ));
    }
    // Combine libraries, pages and other required entities under the same listing.
    $page_ids = array_merge($this->manager->getPages(), $this->manager->getLibraries());
    $pages = shelter_base_sort_nids_by_weight($page_ids);
    if ($pages) {
      $secondary['pages'] = partial('navigation_options', array(
        'navigation_type_id' => 'pages',
        'title' => t('Pages'),
        'nodes' => node_load_multiple($pages)
      ));
    }
    $useful_links = $this->manager->getUsefulLinks();
    if ($useful_links) {
      $secondary['useful_links'] = partial('navigation_options', array(
        'navigation_type_id' => 'useful-links',
        'title' => t('Useful links'),
        'links' => $useful_links
      ));
    }

    return array(
      '#theme' => 'cluster_nav_dashboard',
      '#items' => $items,
      '#secondary' => $secondary,
    );
  }

  /**
   * Provide menu to add related content.
   *
   * @see cluster_context.module.
   * @return render array of links.
   */
  public function getEditorMenu() {
    if (!function_exists('cluster_context_links')) {
      return FALSE;
    }
    $links = cluster_context_links($this->node);
    if (!$links) {
      return FALSE;
    }

    return array(
      '#theme' => 'links',
      '#links' => $links,
      '#attributes' => array('class' => 'editor-menu'),
    );
  }

  /**
   * Generates contextual navigation (breadcrumb-like) for groups.
   * Delegates theme implementation to cluster_nav module.
   * @return
   *  Render array of contextual navigation elements.
   */
  public function getContextualNavigation() {
    $wrapper = entity_metadata_wrapper('node', $this->node);
    $output = array(
      '#theme' => 'cluster_nav_contextual',
    );

    // The group parent region.
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
        if ($this->getRedirectParent() != $region->nid) {
          $output['#regions'][] = array(
            'title' => $region->title,
            'path' => 'node/' . $region->nid,
          );
        }
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
   * Returns a list of entities as a render array using the given view mode and theme wrapper.
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
  protected function getList($ids, $view_mode = 'teaser', $theme_wrapper = NULL, $entity_type = 'node') {
    if (!$ids) {
      return FALSE;
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

  /**
   * Gets the node ID from the "redirect parent" (geographic region with the
   * field_response_auto_redirect field set to the current response).
   * Only works if the current page is a response.
   * @return
   *  nid, FALSE if none exist.
   */
  public function getRedirectParent() {
    $query = new EntityFieldQuery();
    $res = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'geographic_region')
      ->fieldCondition('field_response_auto_redirect', 'target_id', $this->node->nid)
      ->propertyCondition('status', NODE_PUBLISHED)
      ->execute();

    if (!isset($res['node'])) {
      return FALSE;
    }

    return key($res['node']);
  }

}

/**
 * Provide renderable content for full page view mode.
 */
class GroupFullDisplayProvider extends GroupDisplayProvider {

  function __construct($node, $view_mode) {
    parent::__construct($node, $view_mode);
  }

  /**
   * Get the contact members for the group.
   * @return
   *  Themed list of contact members or FALSE if none exist.
   */
  public function getContactMembers() {
    if ($contact_members_ids = $this->manager->getContactMembers()) {
      return partial('contact_members', array('nodes' => node_load_multiple($contact_members_ids)));
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
        '#docs' => cluster_docs_prepare_card_data($nids),
      );
    }
    return FALSE;
  }

  /**
   * Get a list of recent documents for the current group.
   * Delegate theming completely to cluster_docs.
   * @return
   *  Render array of recent documents.
   */
  public function getRecentDocuments() {
    if ($nids = $this->manager->getRecentDocuments(5, FALSE)) {
      return theme('cluster_og_recent_documents', array(
        'docs' => cluster_docs_prepare_row_data($nids),
        'all_documents_link' => '/search-documents',
      ));
      // Changed to match the frontpage recent documents.
      /*return array(
        '#theme' => 'cluster_og_recent_documents',
        '#docs' => cluster_docs_prepare_row_data($nids),
        '#all_documents_link' => array(
          '#theme' => 'cluster_docs_all_docs_link',
          '#path' => 'node/' . $this->node->nid . '/documents',
        ),
      );*/
    }
    return FALSE;
  }

  /**
   * Provide recent discussion nodes for the group.
   * @return render array of discussions.
   */
  public function getRecentDiscussions() {
    if ($nodes = $this->manager->getRecentDiscussions()) {
      $content = $this->getList($nodes, 'teaser', 'cluster_og_recent_discussions');
      $content['#all_discussions_link'] = 'node/' . $this->node->nid . '/discussions';
      return $content;
    }
    return FALSE;
  }

  /**
   * Provide the next upcoming event for the group, if any.
   * @return render array of discussions.
   */
  public function getUpcomingEvents($max = 3) {
    if ($nids = $this->manager->getUpcomingEvents($max)) {
      $events = array();
      foreach ($nids as $nid) {
        $events[] = cluster_events_format_upcoming($nid);
      }
      return array(
        '#theme' => 'cluster_og_upcoming_events',
        '#all_events_link' => url('node/' . $this->node->nid . '/events'),
        '#events' => $events
      );
    }

    return array(
      '#theme' => 'cluster_og_no_upcoming_event',
      '#all_events_link' => url('node/' . $this->node->nid . '/events'),
    );
  }

  /**
   * Not shown for this display.
   */
  public function getContextualNavigation() {
    return FALSE;
  }

}

// Defensive default for view modes which are not managed.
class GroupNotImplementedDisplayProvider {
  public function __call($name, $arguments) {
    return FALSE;
  }
}
