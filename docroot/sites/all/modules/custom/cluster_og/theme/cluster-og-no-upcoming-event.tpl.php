<?php
/**
 * Template file for the "no upcoming event" block.
 */
?>

<section id="shelter-calendar">
  <div id="box-calendar">
    <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
    <div id="date-calendar">No upcoming event</div>
    <div class="information-card">
      <a class="event" href="<?php print $all_events_link; ?>">See past events</a>
    </div>
  </div>
  <a class="see-all" href="<?php print $all_events_link; ?>">All calendar events</a>
</section>
