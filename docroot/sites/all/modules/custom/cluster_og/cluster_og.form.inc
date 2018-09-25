<?php

function cluster_og_settings() {
  $form = [
    'cluster_og_global_id' => [
      '#type' => 'textfield',
      '#title' => 'Global group ID',
      '#default_value' => variable_get('cluster_og_global_id', '4290'),
    ],
  ];

  return system_settings_form($form);
}
