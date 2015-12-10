<?php //kpr($variables); ?>
<section id="shelter-calendar">
  <div id="box-calendar">
    <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
    <div id="date-calendar"><?php print $title ?></div>

    <?php foreach($events as $event): ?>
      <div class="event-card">
        <div>
          <?php print $event['link']; ?>
        </div>
        <div class="event-date">
          <span class="label"><?php print t('Event date: '); ?></span>
          <span><?php print $event['date']; ?></span>
        </div>
        <div class="event-location">
          <span class="label"><?php print t('Location: '); ?></span>
          <span><?php print $event['location']; ?></span>
        </div>
        <div class="event-contact">
          <span class="label"><?php print t('Contact: '); ?></span>
          <span><?php print $event['location']; ?></span>
        </div>
      </div>
    <?php endforeach; ?>

    <div class="all-events">
      <?php print $all_events_link; ?>
    </div>
  </div>
</section>
