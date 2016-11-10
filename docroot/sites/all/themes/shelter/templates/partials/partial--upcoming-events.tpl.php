<section id="shelter-calendar" class="upcoming-events">
  <div id="box-calendar">
    <div id="date-calendar">
      <?php print $title ?>
    </div>

    <?php foreach ($events as $key => $event): ?>
      <div class="event-card<?php print ($key === 0) ? ' is-first' : ''; ?>">
        <div class="event-title">
          <?php print $event['link']; ?>
        </div>

        <div class="response is-small">
          <?php print $event['response']; ?>
        </div>

        <?php if ($event['location']): ?>
          <div class="information-item event-location is-small">
            <span class="label">
              <?php print t('Location: '); ?>
            </span>

            <span>
              <?php print render($event['location']); ?>
            </span>
          </div>
        <?php endif; ?>

        <div class="information-item event-date is-small">
          <span><?php print render($event['date']); ?></span>
        </div>
  
        <div class="ical">
          <?php print $event['ical']; ?>
        </div><!-- /.ical -->
      </div>
    <?php endforeach; ?>

    <div class="all-events">
      <?php print $all_events_link; ?>
    </div><!-- /.all-events -->
  </div>
</section>
