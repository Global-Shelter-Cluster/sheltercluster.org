<?php
/**
 * Template file for the "no upcoming events" block.
 */
?>

<section id="shelter-calendar">
  <div id="box-calendar">
    <?php print _svg('icons/pin', array('id' => 'calendar-pin-icon', 'alt' => t('An icon representing a calendar with a pin on it.'))); ?>
    <div id="date-calendar"><?php print t('No upcoming events') ?></div>
    <div class="information-card">
      <a class="event" href="<?php print $all_events_link; ?>"><?php print t('See past events'); ?></a>
    </div>
  </div>
  <a class="see-all" href="<?php print $all_events_link; ?>"><?php print t('All calendar events'); ?></a>
</section>
