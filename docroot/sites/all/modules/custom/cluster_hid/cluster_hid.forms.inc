<?php

use Drupal\cluster_hid\ClusterHidHttpClient;

function cluster_hid_settings_form() {
  return system_settings_form([
    'form' => [
      '#type' => 'fieldset',
      '#title' => t('Humanitarian Id'),
      'cluster_hid_jwt' => [
        '#type' => 'textarea',
        '#title' => 'JWT',
        '#default_value' => variable_get('cluster_hid_jwt', NULL),
        '#description' => t('Get your JWT from your Humanitarian Id profile settings.'),
      ],
    ],
  ]);
}

function cluster_hid_search_form($form, &$form_state) {
  $js_path = drupal_get_path('module', 'cluster_hid') . '/js/';
  return [
    'name' => [
      '#type' => 'textfield',
      '#default_value' => isset($form_state['values']['name']) ? $form_state['values']['name'] : '',
      '#title' => t('Search by name'),
      '#size' => 100,
      '#description' => 'Enter parts of the first or last name of the user you are looking for.',
      '#autocomplete_path' => 'hid-search-user-search-autocomplete',
    ],
    '#attached' => [
      'js' => [
        $js_path . 'humanitarianIdSearchUsers.js',
      ],
    ],
    'user-data' => [
      '#type' => 'item',
    ],
  ];
}

function cluster_hid_search_form_submit(&$form, &$form_state) {
  $form_state['rebuild'] = TRUE;
  $http_client = ClusterHidHttpClient::getInstance();
  $name = $form_state['values']['name'];
  $values = $http_client->searchUserByName($name);
}
