<div class="featured-document-slider">
  <ul>
    <?php foreach ($docs as $doc): ?>
      <?php if ($doc['is_image'] || $doc['has_preview']): ?>
        <li class="image-document">
      <?php else: ?>
        <li>
      <?php endif; ?>
        <div class="document-information clearfix">
          <div class="image-container">
            <?php if ($doc['is_image']): ?>
              <?php print theme('image', array('path' => $doc['image_uri'])); ?>
            <?php elseif ($doc['has_preview']): ?>
              <?php print theme('image', array('path' => $doc['preview_uri'])); ?>
            <?php else: ?>
              <img src="<?php print '/' . drupal_get_path('theme', 'shelter') . '/assets/images/featured-document-texture.jpg'; ?>" />
            <?php endif; ?>
          </div>
          <div class="information-container">
            <div class="document-title">
              <?php if ($doc['is_image']): ?>
                <h2><?php print $doc['title']; ?></h2>
              <?php elseif ($doc['has_preview']): ?>
                <h2><?php print l($doc['title'], $doc['link_url'], array('attributes' => array('target' => '_blank'))); ?></h2>
              <?php else: ?>
                <h2><?php print l($doc['title'], $doc['link_url'], array('attributes' => array('target' => '_blank'))); ?></h2>
              <?php endif; ?>
              <?php if ($doc['filesize'] && $doc['file_extension']): ?>
                <div class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></div>
              <?php endif; ?>
            </div>
            <?php print $doc['description']; ?>
          </div>

        </div>
      </li>
    <?php endforeach; ?>
  </ul>
  <a href="#" class="jcarousel-control-prev">&lsaquo;</a>
  <a href="#" class="jcarousel-control-next">&rsaquo;</a>
  <p class="jcarousel-pagination"></p>
</div>
