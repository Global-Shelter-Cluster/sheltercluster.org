<section id="all-events">

    <div id="date-calendar"><?php print $title ?></div>

    <?php foreach($events as $event): ?>
      <?php if($event['is_future']): ?>
        <div class="event-card future-event-card">
      <?php else: ?>
        <div class="event-card past-event-card">
      <?php endif; ?>
        <div class="event-title">
          <span class="arrow">›</span>
          <?php print $event['link']; ?>
        </div>

        <?php if($event['is_future']): ?>
          <div class="table-wrapper">
            <div class="event-information">
        <?php endif; ?>

        <div class="information-item event-date">
          <span class="label"><?php print t('Event date: '); ?></span>
          <span><?php print render($event['date']); ?></span>
        </div>

        <?php if($event['location']): ?>
          <div class="information-item event-location">
            <span class="label"><?php print t('Location: '); ?></span>
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

        <?php if($event['description']): ?>
          <div class="information-item event-description">
            <span class="label"><?php print t('Description: '); ?></span>
            <span><?php print drupal_render($event['description']); ?></span>
          </div>
        <?php endif; ?>
        
        <?php if($event['is_future']): ?>
            </div>
            <div class="event-map">
              <div>
                <?php print $event['static_map']; ?>
              </div>
            </div>
          </div>
        <?php endif; ?>

      </div>
    <?php endforeach; ?>

</section>
