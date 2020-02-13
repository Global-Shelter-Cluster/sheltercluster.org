<section class="home-dashboard">
  <div class="header">
    <h2><?php print t('Currently active Shelter Clusters <small>(or cluster-like mechanisms)</small>'); ?></h2>
    <p><?php print t('A summary of coordination mechanisms in place, more detailed information can be found on the response pages.'); ?></p>
  </div>
  <div class="active-clusters">
    <h4><?php print t('Active clusters'); ?></h4>
    <span class="big-figure"><?php print $count_all_active; ?></span>
  </div>
  <div class="people-supported">
    <h4><?php print t('People supported'); ?></h4>
    <span
      class="big-figure"><?php print cluster_factsheets_number($people_supported); ?></span>
  </div>
  <div class="partners">
    <h4><?php print t('Cluster partners'); ?></h4>
    <span
      class="big-figure"><?php print $partners; ?></span>
  </div>
  <div class="by-region">
    <h4><?php print t('By region'); ?></h4>
    <?php print render($by_region); ?>
  </div>
  <div class="by-disaster-type">
    <h4><?php print t('By type of crisis'); ?></h4>
    <?php print render($by_disaster_type); ?>
  </div>
  <div class="by-country-shelter">
    <h4><?php print t('People supported with shelter'); ?></h4>
    <?php print render($by_country_shelter); ?>
  </div>
  <div class="by-country-nfi">
    <h4><?php print t('People supported with NFI'); ?></h4>
    <?php print render($by_country_nfi); ?>
  </div>
  <div class="by-country-funding">
    <h4><?php print t('Funding received'); ?></h4>
    <?php print render($by_country_funding); ?>
  </div>
</section>
