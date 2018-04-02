<section class="factsheet-preview-list">
  <?php foreach ($items as $item): ?>
    <article class="preview-block factsheet-preview">
      <a href="<?php print $item['link']; ?>" class="thumbnail">
        <img src="<?php print $item['map']; ?>">
        <img src="<?php print $item['image']; ?>">
      </a>
      <a href="<?php print $item['link']; ?>">
        <h4><?php print date('j M Y', $item['date']); ?></h4>
      </a>

      <div class="summary">
        <?php print $item['summary']; ?>
      </div>
      <ul class="indicators">
        <?php foreach ($item['indicators'] as $indicator => $value): ?>
        <li>
          <strong><?php print $value; ?></strong>
          <?php print $indicator; ?>
        </li>
        <?php endforeach; ?>
      </ul>
    </article>
  <?php endforeach; ?>
</section>
