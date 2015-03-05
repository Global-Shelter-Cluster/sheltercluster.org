<?php
/**
 * @file
 * Template file for hot responses list.
 */
?>

<section id="active-responses" class="clearfix">
  <h1><?php print t('Featured Responses'); ?></h1>
  <ul class="hot-responses">
    <?php foreach($responses as $id => $response): ?>
      <li class="hot-responses-link">
        <?php print $response['link']; ?>
        <?php print _svg('icons/' . $response['type']->icon_name, array('class' => $response['type']->icon_class, 'alt' => $response['type']->name . ' icon')); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</section>
