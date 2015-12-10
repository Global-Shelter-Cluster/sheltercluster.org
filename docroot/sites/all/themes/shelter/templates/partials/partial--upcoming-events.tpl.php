<?php //kpr($variables); ?>
<section id="shelter-calendar">
  <div id="box-calendar">
    <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
    <div id="date-calendar"><?php print $title ?></div>
    <div class="information-card">
      <?php foreach($events as $event): ?>
        <?php print $event['event_link']; ?>
      <?php endforeach; ?>
    </div>
    <?php print $all_events_link; ?>
  </div>
</section>
