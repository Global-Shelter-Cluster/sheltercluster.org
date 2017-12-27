<section id="shelter-documents" class="recent-documents">
  <table class="document-table">
    <thead>
      <th>Recent Documents</th>
    </thead>
    <tbody>
    <?php foreach($docs as $delta => $doc): ?>
      <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>
      <tr class="document-row <?php print $zebra; ?>">
        <td class="information-title">
          <div class="document-title">
            <a href="<?php print $doc['node_url']; ?>">
              <?php print $doc['title']; ?>
            </a>
          </div><!-- /.document-title -->

          <?php if ($doc['group']): ?>
            <div class="document-response is-small">
              <?php print $doc['group']; ?>
            </div>
          <?php endif; ?>

          <div class="document-source is-small">
            <?php print $doc['source']; ?>
          </div>

          <div class="file-info">
            <?php if ($doc['file_extension']): ?>
              <?php print render($doc['file_extension']); ?>
            <?php endif; ?>

            <?php print render($doc['download_link']); ?>
          </div>

          <?php if ($doc['date']): ?>
            <div class="document-date is-small">
              <?php print $doc['date']; ?>
            </div>
          <?php endif; ?>
        </td>
      </tr>

    <?php endforeach; ?>
    </tbody>
  </table>
  <div class="all-documents">
    <?php print $all_documents_link; ?>
    <?php if (isset($key_documents_link)) print ' &nbsp; '.$key_documents_link; ?>
  </div>
</section>
