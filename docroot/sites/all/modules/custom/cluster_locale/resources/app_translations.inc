<?php

use \Drupal\cluster_api\Oauth\Authorization;

/**
 * Example:
 *
 * jQuery.ajax({
 *   type: "GET",
 *   url: "http://local.sheltercluster.org/api-v1/app-translations/pt-br.json",
 *   dataType: "json",
 *   contentType: "application/json",
 *   success: console.log,
 * });
 *
 * @param $requests
 *
 * @return array
 */
function _cluster_locale_translations_retrieve($language_code) {
  watchdog('cluster_local', $language_code);
  $enabled_languages = variable_get('cluster_locale_mobile_enabled_languages', array());

  if (!isset($enabled_languages[$language_code])) {
    services_error('Language is not enabled', 404);
  }
  
  $query = db_select('locales_source', 's');
  $query->join('locales_target', 't', 't.lid = s.lid');
  $query->condition('s.textgroup', 'cluster_app')
    ->condition('t.language', $language_code)
    ->fields('s', array('source'))
    ->fields('t', array('translation'));

  return $query->execute()->fetchAllKeyed(0);
}
