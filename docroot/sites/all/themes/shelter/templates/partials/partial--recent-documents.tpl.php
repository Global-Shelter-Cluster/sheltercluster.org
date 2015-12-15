<section id="shelter-documents">
  <div id="box-documents">
    <div>Recent Documents</div>
    <table class="document-table">
      <thead>
        <th></th>
        <th>Document title</th>
        <th>Size</th>
        <th>Date</th>
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

          <td class="information-title">
            <?php print $doc['link']; ?>
            <?php print $doc['description']; ?>
            <?php print $doc['group']; ?>
          </td>

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
    <div class="all-documents">
      <?php print $all_documents_link; ?>
    </div>
  </div>
</section>