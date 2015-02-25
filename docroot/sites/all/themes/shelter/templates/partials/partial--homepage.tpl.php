<?php
/**
 * @file
 * Homepage partial.
 */
?>

<div class="page-margin">
  <div class="video">
    <div class="video-container">
      <iframe src="http://www.youtube.com/embed/nzGuN0Cpzks?controls=0&loop=1" frameborder="0" width="460" height="315"></iframe>
    </div>
  </div>
  <?php if($hot_responses): ?>
    <?php print render($hot_responses); ?>
  <?php endif; ?>
</div>

<div class="page-margin">
  <?php print render($page['content']); ?>
</div>

<div class="page-margin">
  <?php print partial('twitter_timeline', array('widget_id' => '569895346130534400')); ?>

  <?php if($upcoming_events): ?>
    <?php print render($upcoming_events); ?>
  <?php endif; ?>
</div>
