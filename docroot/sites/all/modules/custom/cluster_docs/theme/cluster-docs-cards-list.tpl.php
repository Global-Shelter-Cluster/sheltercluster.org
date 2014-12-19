<?php

/**
 * @file
 *  Template file for a set of documents themed as cards.
 * variables:
 *  $heading
 *    The heading for the list of cards being displayed.
 *  $docs
 *    Array of document nodes prepared for this template.
 *    @see cluster_docs_prepare_card_data().
 *  Each document has the following elements:
 *  array('title', 'link', 'is_link', 'is_file', 'description', 'filesize', 'file_extension', 'source',); 
 */

?>
<?php if ($heading): ?>
  <h4><?php print $heading; ?></h4>
<?php endif; ?>

<ul class="document-cards clearfix">
  <?php foreach($docs as $delta => $doc): ?>
    <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>

    <li class="document-card <?php print $zebra; ?>">
      <div class="image-card">
        <?php if ($doc['is_link']): ?>
          <?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?>
        <?php elseif($doc['is_file']): ?>
          <?php //print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'Icon for a file')); ?>
        <?php endif; ?>
      </div>

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