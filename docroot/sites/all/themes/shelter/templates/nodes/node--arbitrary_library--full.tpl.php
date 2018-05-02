<?php

/**
 * @file
 * Shelter Cluster - Library node template.
 */

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    <h2><?php print $title; ?><?php if ($edit_link): ?><?php print $edit_link; ?><?php endif; ?></h2>
    <?php if (isset($content['related_nav'])) :?>
      <?php print render($content['related_nav']); ?>
    <?php endif; ?>
    <?php print render($content); ?>
  </div>

</div>
