<?php
/**
 * @file
 * Homepage partial.
 */
?>

<?php if($hot_responses): ?>
  <div class="page-margin">
    <?php print render($hot_responses); ?>
  </div>
<?php endif; ?>

<div class="page-margin">
  <?php print partial('tableau_desktop'); ?>
  <?php print partial('tableau_tablet'); ?>
  <?php print partial('tableau_mobile'); ?>
</div>
