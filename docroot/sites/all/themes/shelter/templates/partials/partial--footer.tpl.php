<footer>
  <div class="page-margin inside-footer">
    <section id="active-clusters-list">
      <h3><?php print t('Featured Responses'); ?></h3>
      <?php print render($page['footer']['hot_responses']); ?>
      <h3 class="general-information"><?php print t('General Information'); ?></h3>
      <?php print render($page['footer']['general_information']); ?>
    </section>

    <section id="regions-list">
      <h3><?php print t('Shelter information is available on the following countries:'); ?></h3>
      <?php print render($page['footer']['menu_regions']); ?>
    </section>
  </div>

  <div class="page-margin inside-footer">
    <section id="contributions">

      <h3><?php print t('Download the Shelter Cluster mobile app'); ?></h3>
      <ul class="contributors clearfix appstores">
        <li class="contributor">
          <a href="https://apps.apple.com/app/shelter-cluster/id1415068304" target="_blank">
            <?php print theme('image', array(
              'path' => drupal_get_path('theme', 'shelter') . '/assets/images/app store.png',
              'alt' => t('App Store'),
            )); ?>
          </a>
        </li>
        <li class="contributor">
          <a href="https://play.google.com/store/apps/details?id=org.sheltercluster.shelterapp" target="_blank">
            <?php print theme('image', array(
              'path' => drupal_get_path('theme', 'shelter') . '/assets/images/google play.png',
              'alt' => t('Google Play'),
            )); ?>
          </a>
        </li>
      </ul>

      <h3><?php print t('This website is made possible through the financial and in-kind contributions of:'); ?></h3>
      <ul class="contributors clearfix">
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/red-cross.jpg',
            'alt' => t('Canadian Red Cross'),
          )); ?>
        </li>
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/gov-canada.png',
            'alt' => t('Governement of Canada'),
          )); ?>
        </li>
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/unhcr.png',
            'alt' => t('UNHCR The UN Refugee Agency'),
          )); ?>
        </li>
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/ifrc-scalled.png',
            'alt' => t('International Federation of Red Cross and Red Crescent Societies'),
          )); ?>
        </li>
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/humanitarian-aid.png',
            'alt' => t('Humanitarian Aid and Civil Protection'),
          )); ?>
        </li>
        <li class="contributor">
          <?php print theme('image', array(
            'path' => drupal_get_path('theme', 'shelter') . '/assets/images/usaid.png',
            'alt' => t('Humanitarian Aid and Civil Protection'),
            'attributes' => ['style' => 'width: 200px;'],
          )); ?>
        </li>
      </ul>

    </section>
  </div>
</footer>
