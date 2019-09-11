<?php

/**
 * Implements hook_views_data_alter().
 */
function cluster_factsheets_views_data_alter(&$data) {
  $data['node']['latest_published_factsheets'] = array(
    'title' => t('Latest published factsheets'),
    'help' => t('Selects only the latest published factsheets for each group.'),
    'filter' => array(
      'field' => 'status',
      'handler' => 'cluster_factsheets_views_latest_published_factsheets',
      'label' => t('Latest published factsheetss'),
    ),
  );
}
