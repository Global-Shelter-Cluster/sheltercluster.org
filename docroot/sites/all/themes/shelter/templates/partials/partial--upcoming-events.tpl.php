<?php // dpm($variables); ?>

<section id="shelter-calendar">
  <div id="box-calendar">
    <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
    <div id="date-calendar"><?php print $title ?></div>
    <?php foreach($events as $event): ?>
      <div class="event-card">
        <div class="event-title">
          <span class="arrow">›</span>
          <?php print $event['link']; ?>
        </div>
        <div class="information-item event-date">
          <span class="label"><?php print t('Event date: '); ?></span>
          <span><?php print $event['date']; ?></span>
        </div>
        <div class="information-item event-location">
          <span class="label"><?php print t('Location: '); ?></span>
          <span>
            <?php print render($event['location']); ?>
            &nbsp;[<?php print $event['map_link']; ?>]
          </span>
        </div>
        <div class="information-item event-contact">
          <span class="label"><?php print t('Contact: '); ?></span>
          <span><?php print $event['contact']; ?></span>
        </div>

        <div class="event-map">
          <?php print $event['static_map']; ?>
        </div>
      </div>
    <?php endforeach; ?>

    <div class="all-events">
      <?php print $all_events_link; ?>
    </div>

  </div>
</section>
