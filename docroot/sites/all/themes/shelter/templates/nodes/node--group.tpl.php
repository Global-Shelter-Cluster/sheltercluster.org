<?php
/**
 * @file
 * Base group node template.
 */
?>

<section id="content" class="clearfix">

  <div class="side-column">

    <?php if ($content['editor_menu']): ?>
      <section id="add-content" class="clearfix">
        <h3 data-collapsible="add-content-container" data-collapsible-default="collapsed">Add content</h3>
        <div id="add-content-container">
          <?php print render($content['editor_menu']); ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if ($content['local_tasks']): ?>
      <section id="admin-links" class="clearfix">
        <h3 data-collapsible="admin-links-container" data-collapsible-default="collapsed">Group Administration</h3>
        <div id="admin-links-container">
          <?php print render($content['local_tasks']); ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if ($content['dashboard_menu']): ?>
      <section id="secondary-nav">
        <?php print render($content['dashboard_menu']); ?>
      </section>
    <?php endif; ?>

  </div>

  <div class="main-column">

    <?php if ($content['featured_documents']): ?>
      <h3 data-collapsible="featured-documents">Featured Documents</h3>
      <section id="featured-documents">
        <?php print render($content['featured_documents']); ?>
      </section>
    <?php endif; ?>

    <?php if ($content['join_links']): ?>
      <?php print render($content['join_links']); ?>
    <?php endif; ?>

    <?php if (!empty($content['body'])): ?>
      <h3 data-collapsible="operation-overview">
        <?php print _svg('icons/overview', array('id' => 'overview-icon', 'alt' => t('An icon representing'))); ?>
        Overview
      </h3>
      <section id="operation-overview" class="slide-container clearfix">
        <?php if (isset($group_image)): ?>
          <?php print $group_image; ?>
        <?php endif; ?>
        <?php print render($content['body']); ?>
      </section>
    <?php endif; ?>

    <?php if ($content['key_documents']['docs']): ?>
      <h3 data-collapsible="key-information">
        <?php print _svg('icons/key-information', array('id' => 'key-information-icon', 'alt' => t('An icon representing a key with the letter "I" in it.'))); ?>
        Key Information
      </h3>
      <section id="key-information">
        <?php print render($content['key_documents']); ?>
      </section>
    <?php endif; ?>

  </div>

</section>


<section id="mid-content" class="clearfix">

  <div class="main-column">

    <?php if ($content['recent_documents']): ?>
      <h3 data-collapsible="recent-documents">Recent Documents</h3>
      <section id="recent-documents">
        <?php print render($content['recent_documents']); ?>
      </section>
    <?php endif; ?>

  </div>

  <div class="side-column">

    <?php if (!isset($content['upcoming_event'])): ?>
      <section id="shelter-calendar">
        <div id="box-calendar">
          <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
          <div id="date-calendar">No upcoming event</div>
          <div class="information-card">
            <a class="event" href="#">See past events</a>
          </div>
        </div>
        <a class="see-all" href="#">All calendar events</a>
      </section>
    <?php endif; ?>

    <?php if ($content['recent_discussions']): ?>
      <?php print render($content['recent_discussions']); ?>
    <?php endif; ?>

  </div>

</section>


<section id="lower-content" class="clearfix">

  <div id="shelter-coordination-team">
    <?php print render($content['contact_members']); ?>
  </div>

</section>

<section id="left-over-content" class="clearfix">

  <div class="main-column">
    <?php //print render($content); ?>
  </div>

</section>
