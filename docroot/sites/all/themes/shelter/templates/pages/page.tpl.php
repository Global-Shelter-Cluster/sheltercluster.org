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
          <ul class="languages">
            <li class="language"><a href="" class="active">en</a></li>
            <li class="language"><a href="">fr</a></li>
            <li class="language"><a href="">es</a></li>
            <li class="language"><a href="">ar</a></li>
          </ul>
        </div>
        <div id="bandwidth-selector">
          <?php print _svg('icons/signal', array('id' => 'bandwidth-selector-icon', 'alt' => 'Bandwidth indication icon')); ?>
          <a href="" class="active">Low bandwidth environment</a>
          <span>/</span>
          <a href="">Switch to high</a>
        </div>
      </div>
    </section>

    <section id="site-branding" class="clearfix">
      <div class="page-margin clearfix">

        <a id="logo-shelter-cluster" href="http://sheltercluster.org">
          <?php print _svg('logo-global-shelter-cluster', array('id' => 'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
        </a>

        <div id="user-login-container" class="clearfix">
          <?php if (isset($user_login)): ?>
            <?php print render($user_login); ?>
          <?php endif; ?>
        </div>
        <div id="user-profile-container" class="clearfix">
          <?php print render($user_menu); ?>
        </div>

        <?php print render($search_form); ?>

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
    <?php if($hot_responses): ?>
      <div class="page-margin">
        <?php print render($hot_responses); ?>
      </div>
    <?php endif; ?>

    <?php if (!$is_front): ?>
      <section id="operation-title" class="page-margin">
        <?php if (isset($contextual_navigation)): ?>
          <?php print render($contextual_navigation); ?>
        <?php endif; ?>
        <h1><?php print $title; ?></h1>
      </section>
    <?php endif; ?>

    <?php if ($local_tasks): ?>
      <div class="tabs">
        <?php print render($local_tasks); ?>
      </div>
    <?php endif; ?>

    <?php if ($dashboard_menu): ?>
    <section id="secondary-nav">
      <div class="page-margin clearfix">
        <?php print render($dashboard_menu); ?>
      </div>
    </section>
    <?php endif; ?>
  </header>

  <div class="page-margin clearfix">
    <?php print render($page['content']); ?>
  </div>

  <footer>

    <div class="page-margin inside-footer">

      <?php print render($search_form_bottom); ?>

      <section id="active-clusters-list">
        <h3>Hot responses</h3>
        <?php print render($page['footer']['hot_responses']); ?>
      </section>

      <section id="regions-list">
        <h3>Shelter Cluster is present in many countries</a></h3>
        <?php print render($page['footer']['menu_regions']); ?>
      </section>

      <section id="general-information">
        <h3>General Information</h3>
          <?php print render($page['footer']['general_information']); ?>
      </section>

    </div>
  </footer>

</div>
