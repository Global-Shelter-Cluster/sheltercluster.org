<?php
/**
 * @file
 * Base page template.
 */
?>

<div id="page">

  <header>

    <section id="site-options-bar" class="clearfix">
      <div class="page-margin">
        <div id="language-selector" class="clearfix">
          &nbsp; <?php /* print $language_switcher; */ ?>
        </div>
        <?php /* print partial('bandwidth_selector'); */ ?>
      </div>
    </section>

    <section id="site-branding" class="clearfix">
      <div class="page-margin clearfix">

        <a id="logo-shelter-cluster" href="<?php print $base_url; ?>">
          <?php print _svg('logo-global-shelter-cluster', [
            'id' => 'shelter-cluster',
            'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter',
          ]); ?>
        </a>

        <?php if (isset($user_login) && FALSE): /* Do not use login block for now */ ?>
          <?php print partial('compact_user_login', ['user_login' => $user_login]); ?>
        <?php endif; ?>

        <?php if ($variables['login_link']): ?>
          <div id="user-profile-container" class="clearfix">
            <span id="login-link"><?php print $variables['login_link']; ?></span>
          </div>
        <?php endif; ?>
      </div>
    </section>

    <div class="page-margin">
      <div id="nav-master">
        <nav id="nav-shelter" class="clearfix"
             data-search-group-nids="<?php if (isset($search_group_nids))
               print $search_group_nids ?>">
          <a href="#" id="button-menu-dropdown">Menu</a>
          <input type="checkbox" id="mobile_menu_toggle">
          <label for="mobile_menu_toggle">
            <span class="sr-only">Toggle Mobile Menu</span>
            <span class="hamburger-icon"></span>
          </label>
          <div class="list-container">
            <?php
            $menu_tree = menu_tree_all_data('menu-mega-menu');
            $menu_output = menu_tree_output($menu_tree);
            drupal_alter('cluster_mega_menu', $menu_output);
            print render($menu_output);
            ?>
          </div>
        </nav>
      </div>
    </div>

    <div class="page-margin clearfix">
      <?php if ($messages): ?>
        <?php print $messages; ?>
      <?php endif; ?>
      <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
      <?php endif; ?>
    </div>

    <?php if (!$is_front): ?>
      <section id="operation-title" class="page-margin">
        <?php if (isset($contextual_navigation)): ?>
          <?php print render($contextual_navigation); ?>
        <?php endif; ?>
        <h1><?php print $title; ?></h1>
      </section>
    <?php endif; ?>

  </header>

  <?php if ($is_front): ?>

    <?php print partial('homepage', [
      'page' => $page,
      'hot_responses' => $hot_responses,
      'upcoming_events' => $upcoming_events,
      'recent_documents' => $recent_documents,
    ]); ?>

  <?php elseif ($global_events_page): ?>
    <?php print partial('homepage', [
      'page' => $page,
      'hot_responses' => $hot_responses,
      'upcoming_events' => FALSE,
      'recent_documents' => FALSE,
      'extra' => $extra,
    ]); ?>

  <?php elseif ($is_regions_and_countries): ?>
    <?php print partial('regions', ['page' => $page]); ?>

  <?php elseif ($is_user_profile_pages): ?>

    <div class="page-margin clearfix">
      <?php print partial('user_profile_pages', [
        'page' => $page,
        'local_tasks' => $local_tasks,
      ]);
      ?>
    </div>

  <?php elseif ($dashboard_menu || $is_search_documents): ?>

    <div class="page-margin clearfix">
      <?php print partial('non_dashboard_group_page', [
        'page' => $page,
        'editor_menu' => $editor_menu,
        'dashboard_menu' => $dashboard_menu,
        'extra' => $extra,
      ]);
      ?>
    </div>

  <?php else: ?>

    <div class="page-margin clearfix">
      <?php print render($page['content']); ?>
    </div>

  <?php endif; ?>

  <?php print partial('footer', ['page' => $page]); ?>

</div>
