<footer>
  <div class="page-margin inside-footer">

    <?php print render($search_form_bottom); ?>

    <section id="active-clusters-list">
      <h3>Hot responses</h3>
      <?php print render($page['footer']['hot_responses']); ?>
    </section>

    <section id="regions-list">
      <h3>Shelter Cluster is present in many countries</a></h3>
      <?php print render($page['footer']['menu_regions']); ?>
    </section>

    <section id="general-information">
      <h3>General Information</h3>
        <?php print render($page['footer']['general_information']); ?>
    </section>

  </div>
</footer>