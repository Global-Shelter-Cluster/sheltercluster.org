<article class="factsheet-full">
  <header class="date">
    <?php print render($content['field_date']); ?>
  </header>
  <div class="photo"
       style="background-image: url(<?php print $cluster_factsheets['main_image_url']; ?>);">
    <?php print render($content['field_photo_credit']); ?>
  </div>
  <main class="highlights">
    <?php print render($content['body']); ?>
  </main>
  <div class="details">
    <?php print render($content['field_need_analysis']); ?>
    <?php print render($content['field_fs_response']); ?>
    <?php print render($content['field_gaps_challenges']); ?>
    <?php print render($content['field_coverage_against_targets']); ?>
  </div>
  <div class="map">
    <?php print render($content['field_map']); ?>
  </div>
  <aside class="aside">
    <?php
    hide($content['field_image']);
    print render($content);
    ?>
    <div>
      <h3><?php print t('Key figures'); ?></h3>
      <div class="factsheet-chart-indicators">
        <?php foreach ($cluster_factsheets['indicators'] as $indicator): ?>
          <?php print render($indicator); ?>
        <?php endforeach; ?>
      </div>
    </div>
  </aside>
</article>
