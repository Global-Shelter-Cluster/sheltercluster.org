<?php
/**
 * @file
 * Homepage partial.
 */
?>

<div id="content" class="page-margin clearfix home-main">

  <div class="side-column clearfix">
    <?php if ($extra): ?>
      <?php print render($extra); ?>
    <?php endif; ?>

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
    <div class="clearfix">
      
      <?php print render($page['homepage']); ?>
      
      <?php if($upcoming_events): ?>
        <?php print render($upcoming_events); ?>
      <?php endif; ?>
      <?php if($recent_documents): ?>
        <?php print render($recent_documents); ?>
      <?php endif; ?>
    </div>
    <div class="wysiwyg">
      <?php print render($page['content']); ?>
    </div>

    <div class="twitter-timeline-main" data-set="twitter-timeline"></div>
  </div>

</div>
