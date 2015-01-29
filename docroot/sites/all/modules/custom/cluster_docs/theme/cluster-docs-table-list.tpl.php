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
  <h4>
    <?php print $heading; ?>
    <?php if ($reset_link): ?>
    <small><?php print $reset_link; ?></small>
    <?php endif; ?>
  </h4>
<?php endif; ?>

<table class="document-table">
  <thead>
    <th></th>
    <th><?php print t('Document title') ?></th>
    <th><?php print t('Size') ?></th>
    <th><?php print t('Publication date') ?></th>
  </thead>
  <tbody>
  <?php foreach($docs as $delta => $doc): ?>
    <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>

    <tr class="document-row <?php print $zebra; ?>">
      <td class="image-card">
        <?php if ($doc['is_link']): ?>
          <?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?>
        <?php elseif($doc['is_file']): ?>
          <?php //print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'Icon for a file')); ?>
        <?php endif; ?>
      </td>

      <td class="information-card">
        <?php print $doc['link']; ?>
        <?php //print $doc['description']; ?>
      </td>

      <td class="information-file">
        <?php if ($doc['filesize'] && $doc['file_extension']): ?>
          <span class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></span>
        <?php endif; ?>
      </td>

      <td>
        <?php if ($doc['publication_date']): ?>
          <span class="publication-date"><?php print $doc['publication_date']; ?></span>
        <?php endif; ?>
      </td>
    </tr>

  <?php endforeach; ?>
  </tbody>
</table>

<?php if ($all_documents_link): ?>
  <?php print render($all_documents_link); ?>
<?php endif; ?>