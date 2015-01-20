<h3 data-collapsible="navigation-option-<?php print $navigation_type_id; ?>"><?php print $title; ?></h3>
<div id="navigation-option-<?php print $navigation_type_id; ?>">
  <ul class="nav-items">
    <?php foreach ($nodes as $node): ?>
      <li class="nav-group clearfix"><?php print l($node->title, 'node/' . $node->nid); ?></li>
    <?php endforeach; ?>
  </ul>
</div>
