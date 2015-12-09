<?php
/**
 * @file
 * Homepage partial.
 */
?>

<div class="page-margin clearfix">

  <div class="side-column clearfix">
    <?php if($hot_responses): ?>
      <?php print render($hot_responses); ?>
    <?php endif; ?>

    <section id="secondary-nav" class="clearfix">
      <h3><?php print t('Home'); ?></h3>
      <?php print $homepage_menu; ?>
    </section>

    <?php print partial('twitter_timeline', array('widget_id' => '569895346130534400')); ?>

  </div>

  <div class="main-column clearfix">
    <?php if($upcoming_events): ?>
      <?php print render($upcoming_events); ?>
    <?php endif; ?>
    <div class="wysiwyg">
      <?php print render($page['content']); ?>
    </div>
  </div>

</div>
