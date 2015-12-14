<section id="shelter-documents">
  <div id="box-documents">
    <?php foreach($documents as $document): ?>
      <div class="event-card">
        <div class="event-title">
          <span class="arrow">›</span>
          <?php //print $document['title']; ?>
        </div>
      </div>
    <?php endforeach; ?>

    <div class="all-documents">
      <?php print $all_documents_link; ?>
    </div>
  </div>
</section>
