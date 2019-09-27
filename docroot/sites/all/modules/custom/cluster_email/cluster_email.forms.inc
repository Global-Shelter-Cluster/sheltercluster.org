<?php

function cluster_email_settings_form() {
  return system_settings_form([
    'cluster_email_whitelist' => [
      '#type' => 'textarea',
      '#title' => 'Email address whitelist',
      '#default_value' => variable_get('cluster_email_whitelist', NULL),
      '#description' => t('Only send emails to these addresses on this environment (one email address per line). If empty, there is no restriction.'),
    ],
  ]);
}
