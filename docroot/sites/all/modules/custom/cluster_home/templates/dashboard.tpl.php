<section class="home-dashboard">
  <div class="header">
    <h4><?php print t('Currently active Shelter Clusters <small>(or cluster-like mechanisms)</small>'); ?></h4>
    <p><?php print t('A summary of coordination mechanisms in place, more detailed information can be found on the response pages.'); ?></p>
  </div>
  <div class="row-figures clearfix">
    <div class="active-clusters">
      <p><?php print t('Active clusters'); ?></p>
      <span class="big-figure"><?php print $count_all_active; ?></span>
    </div>
    <div class="people-supported">
      <p><?php print t('People supported'); ?></p>
      <span
        class="big-figure"><?php print cluster_factsheets_number($people_supported); ?></span>
    </div>
    <div class="partners">
      <p><?php print t('Cluster partners'); ?></p>
      <span
        class="big-figure"><?php print $partners; ?></span>
    </div>
  </div>
  <div class="row-pies clearfix">
    <div class="by-region">
      <p><?php print t('By region'); ?></p>
      <?php print render($by_region); ?>
    </div>
    <div class="by-disaster-type">
      <p><?php print t('By type of crisis'); ?></p>
      <?php print render($by_disaster_type); ?>
    </div>
  </div>
  <div class="row-bars clearfix">
    <div class="by-country-shelter">
      <p><?php print t('People supported with shelter'); ?></p>
      <?php print render($by_country_shelter); ?>
    </div>
    <div class="by-country-nfi">
      <p><?php print t('People supported with NFI'); ?></p>
      <?php print render($by_country_nfi); ?>
    </div>
    <div class="by-country-funding">
      <p><?php print t('Funding received'); ?></p>
      <?php print render($by_country_funding); ?>
    </div>
  </div>
  <div class="footer">
    <small>
      <?php print t('The above data has been made available to the Global Shelter Cluster through factsheets.'); ?>
      <br/>
      <?php print t('Achievements from all cluster partners (not just the lead agency) and any form of shelter and/or NFI assistance are counted (except distribution of single items).'); ?>
    </small>
  </div>
</section>
