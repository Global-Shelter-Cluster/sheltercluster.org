<div>
  <?php if (!$label_hidden): ?>
    <h3><?php print $label ?></h3>
  <?php endif; ?>
  <?php
  foreach ($items as $delta => $item)
    print render($item);
  ?>
</div>
