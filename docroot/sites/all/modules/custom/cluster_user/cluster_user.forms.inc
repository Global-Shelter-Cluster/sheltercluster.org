<?php

function cluster_user_registration_settings_form() {
  $form = [];

  $form['cluster_user_registration_whitelist'] = [
    '#type' => 'textarea',
    '#title' => t('Email addresses allowed'),
    '#default_value' => variable_get('cluster_user_registration_whitelist', NULL),
    '#description' => t('Individual email addresses that are allowed to register on the site (one email address per line).'),
  ];

  $form['cluster_user_registration_regex_blacklist'] = [
    '#type' => 'textarea',
    '#title' => t('Email addresses blocked'),
    '#default_value' => variable_get('cluster_user_registration_regex_blacklist', NULL),
    '#description' => t('Rules for email addresses to be blocked from user registration (one regular expression per line, e.g. "/@bad_host\.example\.com/i").'),
  ];

  return system_settings_form($form);
}
