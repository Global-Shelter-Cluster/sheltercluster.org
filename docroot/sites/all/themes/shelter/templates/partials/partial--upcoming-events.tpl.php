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

        <?php if($event['location']): ?>
          <div class="information-item event-location">
            <span class="label">
              <?php print t('Location: '); ?>
              <span class="map-link"><?php print $event['map_link']; ?></span>
            </span>
            <span>
              <?php print render($event['location']); ?>
            </span>
          </div>
        <?php endif; ?>

        <?php if($event['contact']): ?>
          <div class="information-item event-contact">
            <span class="label"><?php print t('Contact: '); ?></span>
            <span><?php print $event['contact']; ?></span>
          </div>
        <?php endif; ?>

      </div>
    <?php endforeach; ?>

    <div class="all-events">
      <?php print $all_events_link; ?>
    </div>

  </div>
</section>
