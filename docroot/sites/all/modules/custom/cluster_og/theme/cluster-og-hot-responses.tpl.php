<?php
/**
 * @file
 * Template file for hot responses list.
 */
?>

<section id="active-responses" class="clearfix">
  <h1><?php print t('Featured Responses'); ?></h1>
  <ul id="hot-responses">
    <?php foreach($responses as $id => $response): ?>
      <li>
        <?php print $response['link']; ?>
        <?php print _svg('icons/' . $response['type']->icon_name, array('class' => $response['type']->icon_class, 'alt' => $respone['type']->name . ' icon')); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</section>
