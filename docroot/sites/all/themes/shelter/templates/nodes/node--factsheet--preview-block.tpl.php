<article class="preview-block factsheet-preview">
  <a href="<?php print url('node/' . $nid); ?>" class="thumbnail">
    <?php print render($content['field_image']); ?>
    <?php print render($content['field_map']); ?>
  </a>
  <a href="<?php print url('node/' . $nid); ?>">
    <h4 title="<?php print t($content['og_group_ref'][0]['#label']); ?>"><?php print render($content['og_group_ref']); ?></h4>
  </a>

  <div class="subtitle">
    <?php print render($content['field_date']); ?>
  </div>
  <div class="summary">
    <?php print render($content['body']); ?>
  </div>
  <ul class="indicators">
    <?php foreach ($cluster_factsheets['indicators'] as $indicator => $value): ?>
      <li>
        <strong><?php print $value; ?></strong>
        <?php print $indicator; ?>
      </li>
    <?php endforeach; ?>
  </ul>
</article>
