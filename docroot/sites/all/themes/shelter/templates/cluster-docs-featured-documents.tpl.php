<ul>
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
        <?php else: ?>
          <img src="http://placehold.it/1000x700/698595" />
        <?php endif; ?>
      </div>
      <div class="document-information">
        <?php if ($doc['is_image']): ?>
          <h2><?php print $doc['title']; ?></h2>
        <?php elseif ($doc['has_preview']): ?>
          <h2><?php print $doc['title']; ?></h2>
        <?php else: ?>
          <h2><?php print l( _svg('icons/file', array('class'=>'document-external', 'alt' => 'Icon for an external resource')) . ' ' . $doc['title'], $doc['link_url'], array('html' => TRUE, 'attributes' => array('target' => '_blank'))); ?></h2>
        <?php endif; ?>
        <?php print $doc['description']; ?>
      </div>
    </li>
    <?php break; // Just one for now... ?>
  <?php endforeach; ?>
</ul>