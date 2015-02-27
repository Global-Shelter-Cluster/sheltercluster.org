<footer>
  <div class="page-margin inside-footer">

    <?php print render($search_form_bottom); ?>

    <section id="active-clusters-list">
      <h3><?php print t('Hot responses'); ?></h3>
      <?php print render($page['footer']['hot_responses']); ?>
      <h3 class="general-information"><?php print t('General Information'); ?></h3>
      <?php print render($page['footer']['general_information']); ?>
    </section>

    <section id="regions-list">
      <h3><?php print t('Shelter information is available on the following countries:'); ?></a></h3>
      <?php print render($page['footer']['menu_regions']); ?>
    </section>

  </div>
</footer>
