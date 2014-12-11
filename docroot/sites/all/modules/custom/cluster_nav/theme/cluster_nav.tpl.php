<ul class="nav-items clearfix">
  <?php foreach ($items as $item): ?>
  <li class="nav-item">
    <?php
    $text = t($item['label']);

    if (isset($item['total'])) {
      $text .= ' <span class="total">(' . $item['total'] . ')</span>';
    }

    print l($text, $item['path'], array('html' => TRUE));
    ?>
  </li>
  <?php endforeach; ?>
</ul>

<?php if (isset($secondary)): ?>
  <a href="#secondary-nav" class="collapse-menu">
    <?php print _svg('icons/collapse-down', array('alt' => 'Icon for collapsing the menu')); ?>
    more
  </a>

  <ul class="nav-items collapsable hide-this">
    <?php foreach ($secondary as $group): ?>
    <li class="nav-group clearfix">
      <?php print render($group); ?>
    </li>
    <?php endforeach; ?>
  </ul>

<?php endif; ?>