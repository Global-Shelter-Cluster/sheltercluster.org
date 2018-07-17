<?php

function cluster_api_settings() {
  $form = [
    'cluster_api_oauth2_server' => [
      '#type' => 'textfield',
      '#title' => 'URL of oauth2 server',
      '#default_value' => variable_get('cluster_api_oauth2_server', 'https://sheltercluster.org'),
    ],
  ];
  return system_settings_form($form);
}
