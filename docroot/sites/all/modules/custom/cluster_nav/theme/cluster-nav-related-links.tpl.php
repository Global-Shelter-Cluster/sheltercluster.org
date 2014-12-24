<?php
/**
 * @file
 *  Template file for related group links.
 */
?>

<?php if ($header): ?>
  <h3><?php print $header; ?></h3>
<?php endif; ?>
<ul class="nav-items">
  <?php foreach ($links as $link): ?>
    <?php print render($link); ?>
  <?php endforeach; ?>
</ul>