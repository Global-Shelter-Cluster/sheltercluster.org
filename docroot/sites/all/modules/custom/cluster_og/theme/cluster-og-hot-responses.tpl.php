<?php
/**
 * Template file for hot responses list.
 */
?>

<section id="active-responses" class="clearfix">
  <h1><?php print t('Active Responses'); ?></h1>
  <ul id="major-responses">
    <?php foreach($responses as $response): ?>
      <li>
        <?php print $reponse['link']; ?>
        <?php print _svg('icons/' . $response['type']->icon_name, array('class' => $response['type']->icon_class, 'alt' => $respone['type']->name . ' icon')); ?>
      </li>
    <?php endforeach; ?>
  </ul>
  <ul id="legend">
    <?php foreach($icons as $icon): ?>
      <li><?php print _svg('icons/' . $icon->icon_name, array('class'=> $icon->icon_class, 'alt' => $icon->name . ' icon')); ?><?php print $icon->name?></li>
    <?php endforeach; ?>
  </ul>
</section>