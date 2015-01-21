<ul class="nav-items clearfix">
  <?php foreach ($items as $item): ?>
  <li class="nav-item">
    <?php print $item; ?>
  </li>
  <?php endforeach; ?>
</ul>

<?php if ($secondary): ?>
  <ul class="nav-items">
    <?php foreach ($secondary as $group): ?>
    <li class="nav-group clearfix">
      <?php print render($group); ?>
    </li>
    <?php endforeach; ?>
  </ul>
<?php endif; ?>
