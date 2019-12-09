<?php
$r_field_date = render($content['field_date']);
$r_field_photo_credit = render($content['field_photo_credit']);
$r_body = render($content['body']);
$r_field_coverage_against_targets = render($content['field_coverage_against_targets']);
$r_field_need_analysis = render($content['field_need_analysis']);
$r_field_fs_response = render($content['field_fs_response']);
$r_field_gaps_challenges = render($content['field_gaps_challenges']);
$r_field_map = render($content['field_map']);
hide($content['field_image']);
$r_sidebar = render($content);
$is_sidebar_empty = (trim($r_sidebar) === '');
?>
<article class="factsheet-full<?php print ($is_sidebar_empty ? ' factsheet-no-sidebar' : ''); ?>">
  <header class="date">
    <?php
    if ($view_mode === 'full') {
      print l('<i class="far fa-file-pdf"></i> <span>'.check_plain(variable_get('print_pdf_link_text')).'</span>', 'printpdf'.url('node/'.arg(1)), [
        'html' => TRUE,
        'attributes' => ['class' => 'export-link'],
      ]);
    }
    ?>
    <div style="flex: 1;"></div>
    <?php if (!empty($cluster_factsheets['full_factsheet'])) print render($cluster_factsheets['full_factsheet']); ?>
    <?php if (!empty($cluster_factsheets['prev'])) print render($cluster_factsheets['prev']); ?>
    <?php print $r_field_date; ?>
    <?php if (!empty($cluster_factsheets['next'])) print render($cluster_factsheets['next']); ?>
  </header>
  <div class="photo"
       style="background-image: url(<?php print $cluster_factsheets['main_image_url']; ?>);">
    <?php print $r_field_photo_credit; ?>
  </div>
  <main class="highlights">
    <?php print $r_body; ?>
  </main>
  <div class="details">
    <?php print $r_field_coverage_against_targets; ?>
    <?php print $r_field_need_analysis; ?>
    <?php print $r_field_fs_response; ?>
    <?php print $r_field_gaps_challenges; ?>
  </div>
  <div class="map">
    <?php print $r_field_map; ?>
  </div>
  <?php if (!$is_sidebar_empty): ?>
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
      print $r_sidebar;
      ?>
    </aside>
  <?php endif; ?>
</article>
