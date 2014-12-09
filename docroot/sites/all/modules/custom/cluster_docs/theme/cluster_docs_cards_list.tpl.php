<?php

/**
 * @file
 *  Template file for a set of documents themed as cards.
 * variables:
 *  $heading
 *    The heading for the list of cards being displayed.
 *  $docs
 *    Array of document nodes prepared for this template.
 *  Each document has the following properties: 
 *
 */

?>
<?php if ($heading): ?>
  <h4><?php print $heading; ?></h4>
<?php endif; ?>
<ul class="document-cards clearfix">
  <?php foreach($docs as $delta => $doc): ?>
    <?php $zebra = ($delta % 2) ? 'odd' : 'even'; ?> 
    <li class="document-card <?php print $zebra; ?>">
      <div class="image-card"><?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?></div>
      <div class="information-card">
        <?php print $doc['link']; ?>
        <?php print $doc['description']; ?>
      </div>
      <div class="information-file">
        <?php if ($doc['filesize'] && $doc['file_extension']): ?>
          <span class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></span>
        <?php endif; ?>
        <?php if ($doc['source']): ?>
          <span class="source"><?php print $doc['source']; ?></span>
        <?php endif; ?>
      </div>
    </li>
  <?php endforeach; ?>
</ul>