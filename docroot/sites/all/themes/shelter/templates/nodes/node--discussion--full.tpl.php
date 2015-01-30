<?php

/**
 * @file
 * Shelter Cluster - Discussion node template.
 */

  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  hide($content['og_group_ref']);
?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <h2><?php print $title; ?></h2>
    <?php print render($content); ?>
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>

</div>
