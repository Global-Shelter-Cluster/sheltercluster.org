<article class="factsheet-full">
  <header class="date">
    <?php if (!empty($cluster_factsheets['full_factsheet'])) print render($cluster_factsheets['full_factsheet']); ?>
    <?php if (!empty($cluster_factsheets['prev'])) print render($cluster_factsheets['prev']); ?>
    <?php print render($content['field_date']); ?>
    <?php if (!empty($cluster_factsheets['next'])) print render($cluster_factsheets['next']); ?>
  </header>
  <div class="photo"
       style="background-image: url(<?php print $cluster_factsheets['main_image_url']; ?>);">
    <?php print render($content['field_photo_credit']); ?>
  </div>
  <main class="highlights">
    <?php print render($content['body']); ?>
  </main>
  <div class="details">
    <?php print render($content['field_coverage_against_targets']); ?>
    <?php print render($content['field_need_analysis']); ?>
    <?php print render($content['field_fs_response']); ?>
    <?php print render($content['field_gaps_challenges']); ?>
  </div>
  <div class="map">
    <?php print render($content['field_map']); ?>
  </div>
  <aside class="aside">
    <?php if ($cluster_factsheets['indicators']): ?>
    <div>
      <h3><?php print t('Key figures'); ?></h3>
      <div class="factsheet-chart-indicators">
        <?php foreach ($cluster_factsheets['indicators'] as $indicator): ?>
          <?php print render($indicator); ?>
        <?php endforeach; ?>
      </div>
    </div>
    <?php endif; ?>
    <?php
    hide($content['field_image']);
    print render($content);
    ?>
  </aside>
</article>
