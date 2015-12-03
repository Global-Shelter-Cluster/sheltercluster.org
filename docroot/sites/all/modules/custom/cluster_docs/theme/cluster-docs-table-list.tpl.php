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
    <?php

    $headers = array(
      'title' => 'Document title',
      'size' => 'Size',
      'date' => 'Date',
    );

    foreach ($headers as $column => $header):
    ?>
      <th>
        <?php
        if (array_key_exists($column, $sort_link_params)) {
          print l($header, current_path(), array('query' => $sort_link_params[$column]));
        }
        else {
          print t($header);
        }
        ?>

        <?php
        // Arrows to indicate sort direction
        if ($sort_column == $column) {
          if ($sort_direction == 'DESC'):
            ?>&#9660;<?php
          else:
            ?>&#9650;<?php
          endif;
        }
        ?>
      </th>
    <?php endforeach ?>
  </thead>
  <tbody>
  <?php if ($docs) foreach($docs as $delta => $doc): ?>
    <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>

    <tr class="document-row <?php print $zebra; ?>">
      <td class="image-card">
        <?php if ($doc['is_link']): ?>
          <?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?>
        <?php elseif($doc['is_file']): ?>
          <?php //print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'Icon for a file')); ?>
        <?php endif; ?>
        <?php print $doc['edit_link']; ?>
      </td>

      <td class="information-title">
        <?php print $doc['link']; ?>
        <?php print $doc['description']; ?>
        <?php print $doc['group']; ?>
      </td>

      <?php if (arg(0) == 'search-documents'): ?>
        <td class="group-name">&nbsp;</td>
      <?php endif; ?>

      <td class="information-file">
        <?php if ($doc['filesize'] && $doc['file_extension']): ?>
          <span class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></span>
        <?php endif; ?>
      </td>

      <td class="publication-date">
        <?php if ($doc['date']): ?>
          <span><?php print $doc['date']; ?></span>
        <?php endif; ?>
      </td>
    </tr>

  <?php endforeach; ?>
  </tbody>
</table>

<?php if ($all_documents_link): ?>
  <?php print render($all_documents_link); ?>
<?php endif; ?>
