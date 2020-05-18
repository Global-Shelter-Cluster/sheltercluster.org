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
//    $this->getAvailableTranslations();
  }

  /**
   * Magic callback.
   * Provides a default return value of FALSE for all methods that are not implemented in a specific view mode
   * subclass.
   */
  public function __call($name, $arguments) {
    return FALSE;
  }

  public function getGroup() {
    return $this->node;
  }

  /**
   * Gets a list of nids to be used in searches for this group (this group's nid
   * and all of its descendants).
   */
  public function getSearchGroupNids() {
    $relatedHubs = $this->getRelatedHubs();
    $relatedResponses = $this->getRelatedResponses();
    $relatedWorkingGroups = $this->getRelatedWorkingGroups();
    $descendantIds = $this->manager->getDescendantIds(TRUE);

    return array_values(array_filter(array_unique(array_map('intval', array_merge(
      (array) $relatedHubs,
      (array) $relatedResponses,
      (array) $relatedWorkingGroups,
      (array) $descendantIds
    )))));
  }

  /**
   * Returns an array of human-readable types (in plural), for the subgroups (not
   * all descendants) of this group.
   */
  public function getSubgroupTypes() {
    $ret = [];
    if ($this->node->type === 'geographic_region') {
      if ($this->manager->queryChildren([$this->node->nid], 'field_parent_region', 'geographic_region'))
        $ret[] = $this->getGroupTypeLabel('geographic_region', TRUE);
    }
    if ($this->getRelatedHubs())
      $ret[] = $this->getGroupTypeLabel('hub', TRUE);
    if ($this->getRelatedResponses())
      $ret[] = $this->getGroupTypeLabel('response', TRUE);
    if ($this->getRelatedWorkingGroups())
      $ret[] = $this->getGroupTypeLabel('working_group', TRUE);
    return $ret;
  }

  public function getGroupTypeLabel($type = NULL, $plural = FALSE) {
    if (is_null($type))
      $type2 = $this->node->type;
    else
      $type2 = $type;

    switch ($type2) {
      case 'geographic_region':
        if (is_null($type)) {
          $wrapper = entity_metadata_wrapper('node', $this->node);
          if (strtolower(trim($wrapper->field_geographic_region_type->value()->name)) === 'country')
            return $plural ? t('countries') : t('country');
        }
        return $plural ? t('regions') : t('region');
      case 'hub':
        return $plural ? t('hubs') : t('hub');
      case 'response':
        return $plural ? t('responses') : t('response');
      case 'working_group':
        return $plural ? t('working groups') : t('working group');
      default:
        return $plural ? t('groups') : t('group');
    }
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

  protected function followButton() {
    global $user;
    $followed_groups = ClusterAPI_Type_User::getFollowedGroups($user);
    $following = user_is_logged_in() && in_array($this->node->nid, $followed_groups);

    if (!$following && count($followed_groups) >= MAX_FOLLOWED_GROUPS)
      return [
        'label' => t('Cannot follow this @type (you\'re already following too many groups)', ['@type' => $this->getGroupTypeLabel()]),
        'path' => 'user/'.$user->uid.'/edit',
        'options' => array(
          'html' => TRUE,
          'attributes' => [
            'class' => 'cant-follow',
          ],
        ),
      ];

    if (!$following) {
      $group_wrapper = entity_metadata_wrapper('node', $this->node);
      $email_subscriptions_enabled = $group_wrapper->field_enable_email_subscriptions->value();
      if (!$email_subscriptions_enabled || user_is_logged_in()) {
        return [
          'label' => t('Follow this @type', ['@type' => $this->getGroupTypeLabel()]),
          'path' => 'node/' . $this->node->nid . '/follow',
          'options' => [
            'html' => TRUE,
            'attributes' => [
              'class' => 'follow',
            ],
          ],
        ];
      }
      else {
        return [
          'link' => [
            '#theme' => 'cluster_og_anon_follow',
            '#group_type' => $this->getGroupTypeLabel(),
            '#follow_path' => 'node/' . $this->node->nid . '/follow',
            '#form' => drupal_get_form('cluster_og_anon_email_subscribe_form'),
          ],
        ];
      }
    }
    else
      return [
        'label' => t('Un-follow this @type', ['@type' => $this->getGroupTypeLabel()]),
        'path' => 'node/' . $this->node->nid . '/un-follow',
        'options' => array(
          'html' => TRUE,
          'attributes' => [
            'class' => 'un-follow',
          ],
        ),
      ];
  }

  /**
   * Generate the dashboard links for a group node.
   * Delegates theme implementation to cluster_nav module.
   * @param $currently_visible_node_id
   *   The node which is currently being viewed, rather that the group context.
   * @return
   *  Render array of dashboard links.
   */
  public function getDashboardMenu($currently_visible_node_id = NULL) {
    $items = array();

    $items[] = $this->followButton();

    $items['dashboard'] = array(
      'label' => t('Dashboard'),
      'path' => 'node/' . $this->node->nid,
      'options' => array(
        'html' => TRUE,
      ),
    );

    if (cluster_docs_is_group_documents_page() || $this->manager->isEnabled('documents')) {
      $items['documents'] = array(
        'label' => t('Documents'),
        'path' => 'node/' . $this->node->nid . '/documents',
        'total' => $this->manager->getDocumentCount(),
        'options' => array(
          'html' => TRUE,
        ),
      );
    }

    $discussions_count = $this->manager->getDiscussionCount();
    if ($discussions_count > 0) {
      if ($this->manager->isEnabled('discussions')) {
        $items['discussions'] = array(
          'label' => t('Discussions'),
          'path' => 'node/' . $this->node->nid . '/discussions',
          'total' => $discussions_count,
          'options' => array(
            'html' => TRUE,
          ),
        );
      }
    }

    $events_count = $this->manager->getEventCount();
    if (cluster_events_is_group_events_page() || ($this->manager->isEnabled('events') && $events_count > 0)) {
      $items['events'] = [
        'label' => t('Events'),
        'path' => 'node/' . $this->node->nid . '/events',
        'total' => $events_count,
        'options' => [
          'html' => TRUE,
        ],
      ];
    }

    if ($strategic_advisory = $this->manager->getStrategicAdvisory()) {
      $items['sag'] = array(
        'label' => t('Strategic Advisory Group'),
        'path' => 'node/' . $strategic_advisory->nid,
        'options' => array(
          'html' => TRUE,
        ),
      );
    }

    $factsheets_count = $this->manager->getFactsheetsCount();
    if (cluster_factsheets_is_group_factsheets_page() || ($this->manager->isEnabled('factsheets') && $factsheets_count > 0)) {
      $items['factsheets'] = [
        'label' => t('Factsheets'),
        'path' => 'node/' . $this->node->nid . '/factsheets',
        'total' => $factsheets_count,
        'options' => [
          'html' => TRUE,
        ],
      ];
    }

    if (module_exists('cluster_assessment')) {
      $forms_count = cluster_assessment_total_count($this->node->nid);
      if (cluster_assessment_is_group_forms_page() || ($forms_count > 0)) {
        $is_resources_group = variable_get('cluster_og_resources_id') == $this->node->nid;
        $items['assessment_forms'] = [
          'label' => $is_resources_group ? t('Data collection templates') : t('Data collection'),
          'path' => 'node/' . $this->node->nid . '/data-collection',
          'total' => $forms_count,
          'options' => [
            'html' => TRUE,
          ],
        ];
      }
    }

    $news_count = $this->manager->getNewsCount();
    if (cluster_news_is_group_news_page() || ($news_count && $this->manager->isEnabled('news'))) {
      $items['news'] = array(
        'label' => t('News'),
        'path' => 'node/' . $this->node->nid . '/news',
        'total' => $news_count,
        'options' => array(
          'html' => TRUE,
        ),
      );
    }

    $followers_count = $this->manager->getFollowersCount();
    if (cluster_og_is_group_followers_page() || ($followers_count && cluster_og_followers_access($this->node->nid))) {
      $items['followers'] = array(
        'label' => t('Followers'),
        'path' => 'node/' . $this->node->nid . '/followers',
        'total' => $followers_count,
        'options' => array(
          'html' => TRUE,
        ),
      );
    }

    drupal_alter('cluster_og_dashboard_menu', $items);

    $secondary = array();

    $force_collapse = cluster_docs_is_group_documents_page() || cluster_events_is_group_events_page();

    if ($responses = $this->getRelatedResponses()) {
      $variables = [
        'navigation_type_id' => 'related-operations',
        'title' => t('Related operations'),
        'collapsed' => $force_collapse,
        'nodes' => node_load_multiple($responses)
      ];

      if ($this->node->type === 'geographic_region') {
        $hierarchy = $this->manager->getResponseRegionHierarchy();
        if ($hierarchy) {
          $missing = [];
          foreach (array_keys($variables['nodes']) as $nid) {
            $found = FALSE;
            foreach ($hierarchy as $parent_id => $response_ids) {
              if (in_array($nid, $response_ids)) {
                $found = TRUE;
                break;
              }
            }
            if (!$found)
              $missing[] = $nid;
          }

          if ($missing)
            $hierarchy = [($this->node->nid) => $missing] + $hierarchy;

          array_walk($hierarchy, function(&$ids) {
            $ids = node_load_multiple($ids);
          });

          $variables['children'] = $hierarchy;
          $variables['nodes'] = node_load_multiple(array_keys($hierarchy));
          $variables['navigation_type_id'] .= '-hierarchical';
        }
      }

      $secondary['responses'] = partial('navigation_options', $variables);
    }

    if ($hubs = $this->getRelatedHubs()) {
      $secondary['hubs'] = partial('navigation_options', array(
        'navigation_type_id' => 'hubs',
        'title' => t('Hubs'),
        'collapsed' => $force_collapse,
        'nodes' => node_load_multiple($hubs)
      ));
    }

    if ($working_groups = $this->getRelatedWorkingGroups()) {
      $secondary['working_groups'] = partial('navigation_options', array(
        'navigation_type_id' => 'working-groups',
        'title' => t('Working groups'),
        'collapsed' => $force_collapse,
        'nodes' => node_load_multiple($working_groups)
      ));
    }

    // Combine libraries, pages and other required entities under the same listing.
    $page_ids = array_merge($this->manager->getPages(), $this->manager->getLibraries(), $this->manager->getPhotoGalleries());
    $pages = shelter_base_sort_nids_by_weight($page_ids);
    if ($pages) {
      $all_child_pages = $this->getAllChildPagesIds($pages);
      $secondary['pages'] = partial('navigation_options', array(
        'navigation_type_id' => 'pages',
        'title' => t('Pages'),
        'collapsed' => $force_collapse,
        'nodes' => node_load_multiple($pages),
        'children' => $all_child_pages,
      ));
    }

    // $child_page_ids = $this->getChildrenPagesIds($currently_visible_node_id);
    // if ($child_page_ids) {
    //   $secondary['child_pages'] = partial('navigation_options', array(
    //     'navigation_type_id' => 'child_pages',
    //     'title' => t('Child Pages'),
    //     'collapsed' => $force_collapse,
    //     'nodes' => node_load_multiple($child_page_ids)
    //   ));
    // }

    // $parent_page = $this->getParentPageId($currently_visible_node_id);
    // if ($parent_page) {
    //   $secondary['parent_page'] = partial('navigation_options', array(
    //     'navigation_type_id' => 'parent_page',
    //     'title' => t('Parent Page'),
    //     'collapsed' => $force_collapse,
    //     'nodes' => [node_load($parent_page)],
    //   ));
    // }

    $communities_of_practice = $this->manager->getCommunitiesOfPractice();
    if ($communities_of_practice) {
      $secondary['communities_of_practice'] = partial('navigation_options',
        array(
          'navigation_type_id' => 'communities-of-practice',
          'title' => t('Communities of practice'),
          'collapsed' => $force_collapse,
          'nodes' => node_load_multiple($communities_of_practice),
        ));
    }

    $useful_links = $this->manager->getUsefulLinks();
    if ($useful_links) {
      $secondary['useful_links'] = partial('navigation_options', array(
        'navigation_type_id' => 'useful-links',
        'title' => t('Useful links'),
        'collapsed' => $force_collapse,
        'links' => $useful_links
      ));
    }

//    $translations = $this->getAvailableTranslations();
//    if ($translations) {
//      $secondary['translations'] = partial('navigation_options', array(
//        'navigation_type_id' => 'translations',
//        'title' => t('Translations'),
//        'collapsed' => $force_collapse,
//        'links' => $translations,
//      ));
//    }

    return array(
      '#theme' => 'cluster_nav_dashboard',
      '#items' => $items,
      '#secondary' => $secondary,
    );
  }

  private function getChildrenPagesIds($id) {
    $child_page_ids = $this->manager->getChildrenPages($id);
    return shelter_base_sort_nids_by_weight($child_page_ids);
  }

  /**
   * Given a list of ids, return a keyed array with child page nodes.
   */
  public function getAllChildPagesIds($ids) {
    $children = [];
    foreach ($ids as $id) {
      $child_ids = $this->getChildrenPagesIds($id);
      if ($child_ids) {
        $children[$id] = node_load_multiple($child_ids);
      }
    }
    return $children;
  }

  private function getParentPageId($currently_visible_node_id) {
    return $this->manager->getParentPage($currently_visible_node_id);
  }

  /**
   * Prepare parent or children links.
   */
  public function getRelatedPagesLinks($currently_visible_node_id) {
    $parent_id = $this->getParentPageId($currently_visible_node_id);
    $links = [];
    if ($parent_id) {
      $list_title = t('Parent page');
      $node = node_load($parent_id);
      $links[] = l($node->title, 'node/' . $node->nid);
    }

    $children_ids = $this->getChildrenPagesIds($currently_visible_node_id);
    if ($children_ids) {
      $list_title = t('Children pages');
      $nodes = node_load_multiple($children_ids);
      foreach ($nodes as $node) {
        $links[] = l($node->title, 'node/' . $node->nid);
      }
    }
    if (!$links) {
      return FALSE;
    }

    return [
      '#type' => 'container',
      '#attributes' => [
        'class' => ['related-page-navigation'],
      ],
      'list' => [
        '#theme' => 'item_list',
        '#items' => $links,
        '#title' => $list_title,
      ],
    ];
  }

  /**
   * Provide menu to add related content.
   *
   * @see cluster_context.module.
   * @return render array of links.
   */
  public function getEditorMenu() {
    $node = $this->node;

    if (!user_is_logged_in()) {
      // Logged out.
      return FALSE;
    }

    global $user;

    if (!og_is_member('node', $node->nid, 'user', $user)) {
      // Current user does not belong to the group.
      return FALSE;
    }

    $manager = GroupContentManager::getInstance($node);

    $ret = []; // Array of render arrays for each section in the menu

    $this->generateEditorMenuSectionIndividual($ret, [
      [
        'enabled' => $manager->isEnabled('documents') && node_access('create', 'document'),
        'icon' => 'fas fa-file-alt',
        'title' => t('Document'),
        'href' => 'node/add/document',
        'query' => [
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ],
      ],
      [
        'enabled' => $manager->isEnabled('events') && node_access('create', 'event'),
        'icon' => 'fas fa-calendar-alt',
        'title' => t('Event'),
        'href' => 'node/add/event',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
      [
        'enabled' => node_access('create', 'page'),
        'icon' => 'fas fa-file',
        'title' => t('Page'),
        'href' => 'node/add/page',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
      [
        'enabled' => node_access('create', 'factsheet') && og_user_access('node', $node->nid, 'create factsheet content'),
        'icon' => 'fas fa-chart-bar',
        'title' => t('Factsheet'),
        'href' => 'node/' . $node->nid . '/add-factsheet',
        'query' => array(
          'group' => $node->nid,
        ),
      ],
      [
        'enabled' => $manager->isEnabled('discussions') && node_access('create', 'discussion'),
        'icon' => 'fas fa-comment',
        'title' => t('Discussion'),
        'href' => 'node/add/discussion',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
      [
        'enabled' => node_access('create', 'contact'),
        'icon' => 'fas fa-user',
        'title' => t('Team member'),
        'href' => 'node/add/contact',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
    ]);

    $this->generateEditorMenuSectionIndividual($ret, [
      [
        'enabled' => node_access('create', 'alert') && og_user_access('node', $node->nid, 'create alert content'),
        'icon' => 'fas fa-bullhorn',
        'title' => t('Alert'),
        'href' => 'node/add/alert',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
      [
        'enabled' => node_access('create', 'news') && og_user_access('node', $node->nid, 'create news content'),
        'icon' => 'fas fa-newspaper',
        'title' => t('News'),
        'href' => 'node/add/news',
        'query' => array(
          'group' => $node->nid,
          'destination' => 'node/' . $node->nid
        ),
      ],
    ]);

    $this->generateEditorMenuSectionGrouped($ret, [
      [
        'icon' => 'fas fa-list-ul',
        'links' => [
          [
            'enabled' => $manager->isEnabled('documents') && node_access('create', 'library'),
            'title' => t('Library'),
            'href' => 'node/add/library',
            'query' => array(
              'group' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $manager->isEnabled('documents') && node_access('create', 'arbitrary_library'),
            'title' => t('Arbitrary library'),
            'href' => 'node/add/arbitrary-library',
            'query' => array(
              'group' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => node_access('create', 'photo_gallery'),
            'title' => t('Photo gallery'),
            'href' => 'node/add/photo-gallery',
            'query' => array(
              'group' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
        ],
      ],
      [
        'icon' => 'fas fa-edit',
        'links' => [
          [
            'enabled' => node_access('create', 'webform'),
            'title' => t('Form'),
            'href' => 'node/add/webform',
            'query' => array(
              'group' => $node->nid,
            ),
          ],
          [
            'enabled' => node_access('create', 'kobo_form'),
            'title' => t('Kobo form'),
            'href' => 'node/add/kobo-form',
            'query' => array(
              'group' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
        ],
      ],
    ]);

    $this->generateEditorMenuSectionGrouped($ret, [
      [
        'icon' => 'fas fa-users',
        'links' => [
          // For responses
          [
            'enabled' => $node->type === 'response' && node_access('create', 'response'),
            'title' => t('Child response'),
            'href' => 'node/add/response',
            'query' => array(
              'response' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'response' && (node_access('create', 'hub') || og_user_access('node', $node->nid, 'manage_child_hub')),
            'title' => t('Hub'),
            'href' => 'node/add/hub',
            'query' => array(
              'response' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'response' && (node_access('create', 'working_group') || og_user_access('node', $node->nid, 'manage_child_working_group')),
            'title' => t('Working group'),
            'href' => 'node/add/working-group',
            'query' => array(
              'response' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'response' && !$manager->getStrategicAdvisory() && (node_access('create', 'strategic-advisory') || og_user_access('node', $node->nid, 'manage_child_sag')),
            'title' => t('Strategic advisory group'),
            'href' => 'node/add/strategic-advisory',
            'query' => array(
              'response' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],

          // For geographic regions
          [
            'enabled' => $node->type === 'geographic_region' && node_access('create', 'geographic-region'),
            'title' => t('Child region'),
            'href' => 'node/add/geographic-region',
            'query' => array(
              'region' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'geographic_region' && node_access('create', 'response'),
            'title' => t('Response'),
            'href' => 'node/add/response',
            'query' => array(
              'region' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'geographic_region' && (node_access('create', 'working_group') || og_user_access('node', $node->nid, 'manage_child_working_group')),
            'title' => t('Working group'),
            'href' => 'node/add/working-group',
            'query' => array(
              'response' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
          [
            'enabled' => $node->type === 'geographic_region' && !$manager->getStrategicAdvisory() && (node_access('create', 'strategic-advisory') || og_user_access('node', $node->nid, 'manage_child_sag')),
            'title' => t('Strategic advisory group'),
            'href' => 'node/add/strategic-advisory',
            'query' => array(
              'region' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],

          // General
          [
            'enabled' => node_access('create', 'community_of_practice'),
            'title' => t('Community of practice'),
            'href' => 'node/add/community-of-practice',
            'query' => array(
              'group' => $node->nid,
              'destination' => 'node/' . $node->nid
            ),
          ],
        ],
      ],
    ]);

    return $ret ?: FALSE;
  }

  private function generateEditorMenuSectionGrouped(&$sections, $data) {
    foreach ($data as &$group)
      $group['links'] = array_filter($group['links'], function($link) {
        return $link['enabled'];
      });

    $data = array_filter($data, function($group) {
      return count($group['links']) > 0;
    });

    if (!count($data))
      return;

    $items = array_map(function($group) {
      $item = [
        [
          '#theme'      => 'html_tag',
          '#tag'        => 'i',
          '#attributes' => ['class' => $group['icon'] . ' fa-fw'],
          '#value'      => '',
        ],
        [
          '#theme' => 'item_list',
          '#type'  => 'ul',
          '#items' => array_map([$this, 'generateEditorMenuLink'], $group['links']),
        ]
      ];

      return render($item);
    }, $data);

    $sections[] = [
      '#theme'      => 'item_list',
      '#type'       => 'ul',
      '#attributes' => array('class' => 'editor-menu-grouped'),
      '#items'      => $items,
    ];
  }

  private function generateEditorMenuSectionIndividual(&$sections, $data) {
    $data = array_filter($data, function($link) {
      return $link['enabled'];
    });

    if (!count($data))
      return;

    $items = array_map([$this, 'generateEditorMenuLink'], $data);

    $sections[] = [
      '#theme'      => 'item_list',
      '#type'       => 'ul',
      '#attributes' => array('class' => 'editor-menu-individual'),
      '#items'      => $items,
    ];
  }

  private function generateEditorMenuLink($link) {
    $text = check_plain($link['title']);

    if (isset($link['icon']))
      $text = theme_html_tag([
          'element'       => [
            '#tag'        => 'i',
            '#attributes' => ['class' => $link['icon']],
            '#value'      => '',
          ],
        ]) . $text;

    return l($text, $link['href'], [
      'html'  => TRUE,
      'query' => isset($link['query']) ? $link['query'] : NULL,
    ]);
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

  public function getAvailableTranslations() {
    if (!isset($this->node->translations) && !isset($this->node->translations->data)) {
     return NULL;
    }
    global $language;
    $all_languages = language_list();
    // Get available translations for all other languages than current language.
    $current_lang = $language->language;
    $existing_translations = array_keys($this->node->translations->data);
    $available_translations = array_diff($existing_translations, [$current_lang]);

    $links = array();
    foreach ($available_translations as $translation) {
      $new_link = new stdClass;
      $new_link->title = $all_languages[$translation]->native;
      $new_link->url = drupal_get_path_alias('node/' . $this->node->nid, $translation);
      $new_link->options = [
        'attributes' => ['target' => '_self'],
        'language' => $all_languages[$translation]];
      $links[] = $new_link;
    }

    return $links;
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
    return theme('cluster_og_recent_documents', array(
      'all_documents_link' => url('node/' . $this->node->nid . '/documents'),
      'has_key_documents' => $this->manager->hasKeyDocuments(),
    ));
  }

  /**
   * Provide recent discussion nodes for the group.
   * @return render array of discussions.
   */
  public function getRecentDiscussions() {
    if ($nodes = $this->manager->getRecentDiscussions()) {
      $content = $this->getList($nodes, 'teaser', 'cluster_og_recent_discussions');
      $content['#all_discussions_link'] = url('node/' . $this->node->nid . '/discussions');
      return $content;
    }
    return FALSE;
  }

  /**
   * Provide the next upcoming event for the group, if any.
   * @return render array of discussions.
   */
  public function getUpcomingEvents($max = 3) {
    return [
      '#theme' => 'cluster_og_upcoming_events',
      '#all_events_link' => url('node/' . $this->node->nid . '/events'),
    ];
  }

  /**
   * Not shown for this display.
   */
  public function getContextualNavigation() {
    return FALSE;
  }

  /**
   * Get the most recent factsheet, displayed in its abbreviated mode, to be
   * shown below the body field on the dashboard page.
   */
  public function getFactsheet() {
    $nids = $this->manager->getFactsheets(1);
    if (!count($nids))
      return NULL;

    $fs = node_load($nids[0]);
    if (!$fs)
      return NULL;

    return node_view($fs, 'factsheet_summary');
  }

}

// Defensive default for view modes which are not managed.
class GroupNotImplementedDisplayProvider {
  public function __call($name, $arguments) {
    return FALSE;
  }
}
