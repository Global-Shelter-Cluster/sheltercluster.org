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
          <?php print _svg('logo-global-shelter-cluster', array('id' => 'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
        </a>

        <?php if (isset($user_login) && FALSE): /* Do not use login block for now */ ?>
          <?php print partial('compact_user_login', array('user_login' => $user_login)); ?>
        <?php endif; ?>

        <div id="user-profile-container" class="clearfix">
          <?php print render($user_menu); ?>
        </div>

        <?php if ($global_docs_search_page_link): ?>
          <div class="search-documents-link-wrapper">
            <?php print render($global_docs_search_page_link); ?>
          </div>
        <?php endif; ?>

      </div>
    </section>

    <div class="page-margin clearfix">
      <?php if ($messages): ?>
        <?php print $messages; ?>
      <?php endif; ?>
    </div>

    <div class="page-margin">
      <div id="nav-master">
        <nav id="nav-shelter" class="clearfix">
          <a href="#" id="button-menu-dropdown">Menu</a>
          <div class="list-container">
            <?php print render($main_nav); ?>
          </div>
        </nav>
      </div>
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
    <?php print partial('homepage', array('page' => $page, 'hot_responses' => $hot_responses, 'upcoming_events' => $upcoming_events)); ?>

  <?php elseif ($global_events_page): ?>
    <?php print partial('homepage', array('page' => $page, 'hot_responses' => $hot_responses, 'upcoming_events' => FALSE)); ?>

  <?php elseif ($is_regions_and_countries): ?>
    <?php print partial('regions', array('page' => $page)); ?>

  <?php elseif ($is_user_profile_pages): ?>

    <div class="page-margin clearfix">
      <?php print partial('user_profile_pages', array(
        'page' => $page,
        'local_tasks' => $local_tasks));
      ?>
    </div>

  <?php elseif ($dashboard_menu || $is_search_documents): ?>

    <div class="page-margin clearfix">
      <?php print partial('non_dashboard_group_page', array(
        'page' => $page,
        'editor_menu' => $editor_menu,
        'dashboard_menu' => $dashboard_menu,
        'extra' => $extra));
      ?>
    </div>

  <?php else: ?>

    <div class="page-margin clearfix">
      <?php print render($page['content']); ?>
    </div>

  <?php endif; ?>

  <?php print partial('footer', array('page' => $page, 'search_form_bottom' => $search_form_bottom, 'search_documents_link' => $global_docs_search_page_link)); ?>

</div>
