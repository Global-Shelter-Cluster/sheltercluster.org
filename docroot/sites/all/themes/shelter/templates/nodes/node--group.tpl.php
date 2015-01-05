<?php
/**
 * @file
 * Base group node template.
 */
?>

<div id="content">

  <div class="main-column">

    <section id="featured-documents">
      <?php print render($content['featured_documents']); ?>
    </section>

    <h3 data-collapsible="operation-information">
      <?php print _svg('icons/overview', array('id' => 'overview-icon', 'alt' => t('An icon representing'))); ?>
      Overview
    </h3>
    <section id="operation-information" class="slide-container clearfix">
      <?php if (isset($group_image)): ?>
        <?php print $group_image; ?>
      <?php endif; ?>
      <?php print render($content['body']); ?>
    </section>

    <?php if ($content['key_documents']['docs']): ?>
      <h3 data-collapsible="key-information">
        <?php print _svg('icons/key-information', array('id' => 'key-information-icon', 'alt' => t('An icon representing a key with the letter "I" in it.'))); ?>
        Key Information
      </h3>
      <section id="key-information">
        <?php print render($content['key_documents']); ?>
      </section>
    <?php endif; ?>

    <?php if ($content['recent_documents']): ?>
      <h3 data-collapsible="recent-documents">Recent Documents</h3>
      <section id="recent-documents">
        <?php print render($content['recent_documents']); ?>
      </section>
    <?php endif; ?>

  </div>

  <div class="side-column">

    <?php if ($content['editor_menu']): ?>
      <section id="add-content" class="clearfix">
        <h3 data-collapsible="add-content-container">Add content</h3>
        <div id="add-content-container">
          <?php print render($content['editor_menu']); ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if ($content['local_tasks']): ?>
      <section id="admin-links" class="clearfix">
        <h3 data-collapsible="admin-links-container">Group Administration</h3>
        <div id="admin-links-container">
          <?php print render($content['local_tasks']); ?>
        </div>
      </section>
    <?php endif; ?>

    <h3 id="title-join-group" data-collapsible="join-group">Join This Group</h3>
    <section id="join-group" class="clearfix">
      <p>Register and join this group</p>
      <div id="button-join-group"><a href="#">Join</a></div>
    </section>

    <?php if (!isset($content['upcoming_event'])): ?>
      <h3 data-collapsible="shelter-calendar">Calendar</h3>
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
      <section id="shelter-discussions">
        <?php print _svg('icons/discussion', array('id' => 'discussion-icon', 'alt' => t('An icon representing discussions.'))); ?>
        <h3>Discussions</h3>
        <ul id="discussions-items">
          <li class="discussions-item">
            <div class="replies">24 replies</div>
            <div class="information">
              <a href="#" class="topic">Where can I find lumber?</a>
              <span class="date">2014/10/03 by <a class="author" href="#">Jane Wikionsons</a></span>
            </div>
          </li>
          <li class="discussions-item">
            <div class="replies">no replies <span class="new">New</span></div>
            <div class="information">
              <a href="#" class="topic">Are any special requirements for protection needed when entering the</a>
              <span class="date">2014/10/15 by <a class="author" href="#">John Tremblay</a></span>
            </div>
          </li>
        </ul>
        <a class="see-all" href="#">All other discussions</a>
      </section>
    <?php endif; ?>

    <section id="shelter-coordination-team">
      <?php print render($content['contact_members']); ?>
    </section>

  </div>

  <div class="main-column">
    <?php //print render($content); ?>
  </div>

</div>
