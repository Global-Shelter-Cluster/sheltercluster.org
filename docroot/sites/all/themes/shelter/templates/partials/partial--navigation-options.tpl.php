<?php

/**
 * Returns an $options array with "archived" class and tooltip for the given node.
 */
$link_options = function($node) {
  $options = [];
  $items = field_get_items('node', $node, 'field_response_status');
  if ($items && $items[0]['value'] === 'archived')
    $options = ['attributes' => ['class' => 'archived', 'title' => t('Archived response')]];
  return $options;
}

?>
<h3 data-collapsible="navigation-option-<?php print $navigation_type_id; ?>"
    <?php if (isset($collapsed) && $collapsed): ?>data-force-collapsible-default="collapsed"<?php endif; ?>
><?php print $title; ?></h3>
<div id="navigation-option-<?php print $navigation_type_id; ?>">
  <ul class="nav-secondary-items">
    <?php foreach ((isset($nodes) ? $nodes : array()) as $node): ?>
      <li class="nav-secondary-item clearfix">
        <?php print l($node->title, 'node/' . $node->nid, $link_options($node)); ?>
          <?php if (!empty($children) && isset($children[$node->nid])): ?>
            <ul class="nav-secondary-items">
              <?php foreach ($children[$node->nid] as $child_node): ?>
                <li class="nav-secondary-child-item clearfix"><?php print l($child_node->title, 'node/' . $child_node->nid, $link_options($child_node)); ?></li>
              <?php endforeach; ?>
            </ul>
          <?php endif;?>
      </li>
    <?php endforeach; ?>

    <?php foreach ((isset($links) ? $links : array()) as $link): ?>
      <li class="nav-secondary-item clearfix">
        <?php
          $options = [
            'attributes' => [
              'target' => '_blank',
            ],
          ];
          if (isset($link->options)) {
            $options = $link->options;
          }
          print l(
            $link->title,
            $link->url,
            $options
          );
        ?>
      </li>
    <?php endforeach; ?>
  </ul>
</div>
