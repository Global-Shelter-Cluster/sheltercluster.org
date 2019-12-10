<?php

/**
 * @file
 * Contains code for the configuration ui for cluster_locale.
 */

/**
 * Configuration form for mobile locale settings.
 */
function cluster_locale_config_form($form, $form_state) {
  $form = array();
  $languages = array();
  foreach (language_list() as $language) {
    $languages[$language->language] = $language->name;
  }

  $form['cluster_locale_website_enabled_languages'] = array(
    '#title' => 'Enabled website languages.',
    '#type' => 'select',
    '#options' => $languages,
    '#multiple' => TRUE,
    '#default_value' => variable_get('cluster_locale_website_enabled_languages'),
  );

  $form['cluster_locale_mobile_enabled_languages'] = array(
    '#title' => 'Enabled mobile languages.',
    '#type' => 'select',
    '#options' => $languages,
    '#multiple' => TRUE,
    '#default_value' => variable_get('cluster_locale_mobile_enabled_languages'),
  );

  return system_settings_form($form);
}
