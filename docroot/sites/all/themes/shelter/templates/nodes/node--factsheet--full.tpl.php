<article class="factsheet-full">
  <header class="date">
    <?php print render($content['field_date']); ?>
  </header>
  <div class="photo" style="background-image: url(<?php print $content['main_image_url']; ?>);">
    <?php print render($content['field_photo_credit']); ?>
  </div>
  <main class="highlights">
    <?php print render($content['body']); ?>
  </main>
  <div class="details">
    <?php print render($content['field_need_analysis']); ?>
    <?php print render($content['field_fs_response']); ?>
    <?php print render($content['field_gaps_challenges']); ?>
  </div>
  <div class="map">
    <?php print render($content['field_map']); ?>
  </div>
  <aside class="aside">
    <ul class="indicators">
      <?php foreach ($content['indicators'] as $indicator => $value): ?>
        <li>
          <strong><?php print $value; ?></strong>
          <?php print $indicator; ?>
        </li>
      <?php endforeach; ?>
    </ul>
  </aside>
</article>
