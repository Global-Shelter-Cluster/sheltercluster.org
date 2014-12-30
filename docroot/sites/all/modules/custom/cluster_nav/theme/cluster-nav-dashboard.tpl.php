<ul class="nav-items clearfix">
  <?php foreach ($items as $item): ?>
  <li class="nav-item">
    <?php print $item; ?>
  </li>
  <?php endforeach; ?>
</ul>

<?php if ($secondary): ?>
  <h3 data-collapsible="dashboard-menu-secondary-elements" data-collapsible-default="collapsed">Other navigation options</h3>
  <section id="dashboard-menu-secondary-elements">
  <ul class="nav-items">
    <?php foreach ($secondary as $group): ?>
    <li class="nav-group clearfix">
      <?php print render($group); ?>
    </li>
    <?php endforeach; ?>
  </ul>

<?php endif; ?>