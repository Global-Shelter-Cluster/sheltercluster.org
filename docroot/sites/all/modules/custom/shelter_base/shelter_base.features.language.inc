<?php
/**
 * @file
 * shelter_base.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function shelter_base_locale_default_languages() {
  $languages = array();

  // Exported language: ar.
  $languages['ar'] = array(
    'language' => 'ar',
    'name' => 'Arabic',
    'native' => 'العربية',
    'direction' => 1,
    'enabled' => 1,
    'plurals' => 6,
    'formula' => '(($n==0)?(0):(($n==1)?(1):(($n==2)?(2):(((($n%100)>=3)&&(($n%100)<=10))?(3):(((($n%100)>=11)&&(($n%100)<=99))?(4):5)))))',
    'domain' => '',
    'prefix' => 'ar',
    'weight' => 0,
  );
  // Exported language: bn.
  $languages['bn'] = array(
    'language' => 'bn',
    'name' => 'Bengali',
    'native' => 'Bengali',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'bn',
    'weight' => 0,
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => 0,
  );
  // Exported language: es.
  $languages['es'] = array(
    'language' => 'es',
    'name' => 'Spanish',
    'native' => 'Español',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'es',
    'weight' => 0,
  );
  // Exported language: fr.
  $languages['fr'] = array(
    'language' => 'fr',
    'name' => 'French',
    'native' => 'Français',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'fr',
    'weight' => 0,
  );
  // Exported language: id.
  $languages['id'] = array(
    'language' => 'id',
    'name' => 'Bahasa Indonesian',
    'native' => 'Bahasa Indonesia',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'id',
    'weight' => 0,
  );
  // Exported language: ms.
  $languages['ms'] = array(
    'language' => 'ms',
    'name' => 'Malay',
    'native' => 'Bahasa Melayu',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'ms',
    'weight' => 0,
  );
  // Exported language: my.
  $languages['my'] = array(
    'language' => 'my',
    'name' => 'Burmese',
    'native' => 'Burmese',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'my',
    'weight' => 0,
  );
  // Exported language: pt.
  $languages['pt'] = array(
    'language' => 'pt',
    'name' => 'Portuguese',
    'native' => 'Portuguese',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'pt',
    'weight' => 0,
  );
  return $languages;
}
