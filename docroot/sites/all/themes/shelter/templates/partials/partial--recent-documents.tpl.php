<section id="shelter-documents">
  <div id="box-documents">
    <table class="document-table">
      <thead>
        <th>Recent Documents</th>
      </thead>
      <tbody>
      <?php foreach($docs as $delta => $doc): ?>
        <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>
        <tr class="document-row <?php print $zebra; ?>">
          <td>
            <span class="image-card">
              <?php if ($doc['is_link']): ?>
                <?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?>
              <?php elseif($doc['is_file']): ?>
                <?php //print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'Icon for a file')); ?>
              <?php endif; ?>
            </span>

            <span class="information-title">
              <?php print $doc['link']; ?>
              <?php print $doc['description']; ?>
              <?php print $doc['group']; ?>
            </span>

            <span class="information-file">
              <?php if ($doc['filesize'] && $doc['file_extension']): ?>
                <div class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></div>
              <?php endif; ?>
              <?php if ($doc['date']): ?>
                <div><?php print $doc['date']; ?></div>
              <?php endif; ?>
            </span>
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