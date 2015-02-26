<?php
/**
 * @file
 * Template file for hot responses list.
 */
?>

<section id="active-responses" class="clearfix">
  <h1><?php print t('Hot Responses'); ?></h1>
  <ul id="hot-responses">
    <?php foreach($responses as $id => $response): ?>
      <li>
        <?php print $response['link']; ?>
        <?php print _svg('icons/' . $response['type']->icon_name, array('class' => $response['type']->icon_class, 'alt' => $respone['type']->name . ' icon')); ?>
      </li>
    <?php endforeach; ?>
  </ul>
  <ul id="legend">
    <?php foreach($icons as $icon): ?>
      <li><?php print _svg('icons/' . $icon->icon_name, array('class' => $icon->icon_class, 'alt' => $icon->name . ' icon')); ?>
        <span><?php print $icon->name?></span>
      </li>
    <?php endforeach; ?>
  </ul>
</section>
