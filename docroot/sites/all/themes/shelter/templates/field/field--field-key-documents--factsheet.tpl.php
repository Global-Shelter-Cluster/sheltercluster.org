<div>
  <?php if (!$label_hidden): ?>
    <h3><?php print $label ?></h3>
  <?php endif; ?>
  <ul>
    <?php
    foreach ($items as $delta => $item)
      print '<li>' . render($item) . '</li>';
    ?>
  </ul>
</div>
