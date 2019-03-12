<?php

/**
 * Example:
 *
 * jQuery.ajax({
 *   type: "GET",
 *   url: "http://local.sheltercluster.org/api-v1/app-languages",
 *   dataType: "json",
 *   contentType: "application/json",
 *   success: console.log,
 * });
 *
 * @param $requests
 *
 * @return array
 */
function _cluster_locale_languages_index() {
  $enabled_languages = variable_get('cluster_locale_mobile_enabled_languages');
  if (count($enabled_languages)) {
    $languages = db_select('languages', 'l')
      ->fields('l', array('language', 'name', 'native', 'formula', 'direction'))
      ->orderBy('weight')
      ->condition('language', $enabled_languages, 'IN')
      ->execute()
      ->fetchAllAssoc('language');
    return $languages;
  }

  return [];
}
