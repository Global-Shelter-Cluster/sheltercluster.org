<h3 data-collapsible="navigation-option-<?php print $navigation_type_id; ?>"
    <?php if (isset($collapsed) && $collapsed): ?>data-force-collapsible-default="collapsed"<?php endif; ?>
><?php print $title; ?></h3>
<div id="navigation-option-<?php print $navigation_type_id; ?>">
  <ul class="nav-secondary-items">
    <?php foreach ((isset($nodes) ? $nodes : array()) as $node): ?>
      <li class="nav-secondary-item clearfix">
        <?php print l($node->title, 'node/' . $node->nid); ?>
          <?php if (isset($children) && isset($children[$node->nid])): ?>
            <ul class="nav-secondary-items">
              <?php foreach ($children[$node->nid] as $child_node): ?>
                <li class="nav-secondary-child-item clearfix"><?php print l($child_node->title, 'node/' . $child_node->nid); ?></li>
              <?php endforeach; ?>
            </ul>
          <?php endif;?>
      </li>
    <?php endforeach; ?>

    <?php foreach ((isset($links) ? $links : array()) as $link): ?>
      <li class="nav-secondary-item clearfix">
        <?php print l($link->title, $link->url, array('attributes' => array('target' => '_blank'))); ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
