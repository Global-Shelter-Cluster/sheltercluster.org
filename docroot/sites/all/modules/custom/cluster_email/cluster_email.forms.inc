<?php

function cluster_email_settings_form() {
  $form = [];

  $form['cluster_email_whitelist'] = [
    '#type' => 'textarea',
    '#title' => t('Email address whitelist'),
    '#default_value' => variable_get('cluster_email_whitelist', NULL),
    '#description' => t('Only send emails to these addresses on this environment (one email address per line). If empty, there is no restriction.'),
  ];

  $form['inbound'] = [
    '#type' => 'fieldset',
    '#title' => t('Inbound emails'),
  ];

  $form['inbound']['cluster_email_inbound'] = [
    '#type' => 'checkbox',
    '#title' => t('Enable'),
    '#default_value' => variable_get('cluster_email_inbound', 0),
    '#description' => t('Process inbound emails (e.g. discussions)')
  ];

  $form['inbound']['cluster_email_inbound_anon'] = [
    '#type' => 'checkbox',
    '#title' => t('Accept emails from anonymous users'),
    '#default_value' => variable_get('cluster_email_inbound_anon', 0),
    '#description' => t('Process emails from users not registered in the system.')
  ];

  $form['inbound']['cluster_email_inbound_spam'] = [
    '#type' => 'textfield',
    '#title' => t('Spam score threshold'),
    '#default_value' => variable_get('cluster_email_inbound_spam', CLUSTER_EMAIL_DEFAULT_SPAM_SCORE_THRESHOLD),
    '#description' => t('Normal emails might have a value of around 1.2; spam tests are around 1000. A higher number here will allow more spam.')
  ];

  return system_settings_form($form);
}
