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
    <section id="secondary-nav">
      <h3><?php print t('Home'); ?></h3>
      <?php print $homepage_menu; ?>
    </section>
  </div>

  <div class="main-column clearfix">
    <div>
      <div class="video-container">
        <iframe src="http://www.youtube.com/embed/nzGuN0Cpzks?controls=0&loop=1&autoplay=0" frameborder="0" width="460" height="315"></iframe>
      </div>
    </div>
    <div class="wysiwyg">
      <?php print render($page['content']); ?>
    </div>
  </div>

</div>

<div class="page-margin clearfix">

  <div class="side-column">
    <?php if($upcoming_events): ?>
      <?php print render($upcoming_events); ?>
    <?php endif; ?>
    <?php print partial('twitter_timeline', array('widget_id' => '569895346130534400')); ?>
  </div>

  <div class="main-column">
    <?php print partial('posters'); ?>
  </div>

</div>
