<?php foreach ($docs as $doc): ?>
  <?php if ($doc['is_image']): ?>
    <li class="image-document">
  <?php else: ?>
    <li>
  <?php endif; ?>
    <div class="clearfix">
      <?php if ($doc['is_image']): ?>
        <?php print theme('image', array('path' => $doc['image_uri'])); ?>
      <?php elseif ($doc['has_preview']): ?>
        <?php print theme('image', array('path' => $doc['preview_uri'])); ?>
      <?php endif; ?>
    </div>
    <div class="document-information">
      <h2><?php print $doc['title']; ?></h2>
      <?php print $doc['description']; ?>
    </div>
  </li>
  <?php break; // Just one for now... ?>
<?php endforeach; ?>