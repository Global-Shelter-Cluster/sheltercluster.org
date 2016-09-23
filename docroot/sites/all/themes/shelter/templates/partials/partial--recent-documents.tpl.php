<section id="shelter-documents">
  <table class="document-table">
    <thead>
      <th>Recent Documents</th>
    </thead>
    <tbody>
    <?php foreach($docs as $delta => $doc): ?>
      <?php $zebra = (($delta + 1) % 2) ? 'odd' : 'even'; ?>
      <tr class="document-row <?php print $zebra; ?>">
        <td class="information-title">

          <div>
            <?php print $doc['link']; ?>
            <?php print $doc['description']; ?>
            <?php print $doc['group']; ?>
          </div>

          <?php if ($doc['filesize'] && $doc['file_extension']): ?>
            <span class="size-type">[ <?php print $doc['filesize']; ?>M ] <?php print $doc['file_extension']; ?></span>
          <?php endif; ?>
          <?php if ($doc['date']): ?>
            <span class="recent-document-date"><?php print $doc['date']; ?></span>
          <?php endif; ?>
        </td>
      </tr>

    <?php endforeach; ?>
    </tbody>
  </table>
  <div class="all-documents">
    <?php print $all_documents_link; ?>
  </div>
</section>
