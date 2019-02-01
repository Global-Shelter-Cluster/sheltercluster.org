<?php

/**
 * @file
 * Webform module current_location component.
 */

/**
 * Implements _webform_defaults_component().
 */
function _webform_defaults_geolocation() {
  return array(
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'required' => 0,
    'extra' => array(
      'width' => '',
      'maxlength' => '',
      'minlength' => '',
      'field_prefix' => '',
      'field_suffix' => '',
      'disabled' => 0,
      'unique' => 0,
      'title_display' => 0,
      'description' => '',
      'description_above' => FALSE,
      'placeholder' => '',
      'attributes' => array(),
      'private' => FALSE,
      'analysis' => FALSE,
    ),
  );
}

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_geolocation() {
  return array(
    'webform_display_geolocation' => array(
      'render element' => 'element',
      'file' => 'geolocation.inc',
      'path' => drupal_get_path('module', 'cluster_geo') . '/webform_component',
    ),
  );
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_geolocation($component) {
  return [
    '#markup' => t('This component does not provide extra options.'),
  ];
}

/**
 * Implements _webform_render_component().
 */
function _webform_render_geolocation($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;
  $element = [
    '#title' => $component['name'],
    '#type' => 'fieldset',
    '#weight' => $component['weight'],
    '#required' => $component['required'],
    '#description' => t('The coordinates will be automatically populated when you allow the browser to access your location.'),
    'lon' => [
      '#type' => 'textfield',
      '#title' => 'Longitude',
      '#default_value' => isset($value['lon']) ? check_plain($value['lon']) : '','#description' => $filter ? webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
      '#attributes' => ['id' => 'webform-cluster_geo-longitude'],
      '#theme_wrappers' => array('webform_element'),
      '#required' => $component['required'],
    ],
    'lat' => [
      '#type' => 'textfield',
      '#title' => 'Latitude',
      '#default_value' => isset($value['lat']) ? check_plain($value['lat']) : '',
      '#description' => $filter ? webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
      '#attributes' => ['id' => 'webform-cluster_geo-latitude'],
      '#theme_wrappers' => array('webform_element'),
      '#required' => $component['required'],
    ],
    'modal_map' => [
      '#theme' => 'cluster_geo_modal',
      '#attached' => [
        'css' => [
          'type' => 'file',
          'data' => drupal_get_path('module', 'cluster_geo') . '/css/map_modal.css',
        ],
        'js' => [
          'type' => 'file',
          'data' => drupal_get_path('module', 'cluster_geo') . '/js/map_modal.js',
        ],
      ]
    ],
  ];

  // Add auto detect location.
  $element['#attached']['js'][] = [
    'type' => 'file',
    'data' => drupal_get_path('module', 'cluster_geo') . '/js/geolocation.js',
  ];

  $element['#attached']['css'][] = [
    'type' => 'file',
    'data' => drupal_get_path('module', 'cluster_geo') . '/leaflet/leaflet.css',
  ];
  $element['#attached']['js'][] = [
    'type' => 'file',
    'data' => drupal_get_path('module', 'cluster_geo') . '/leaflet/leaflet.js',
  ];

  if ($component['required']) {
    $element['#attributes']['required'] = 'required';
  }

  return $element;
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_geolocation($component, $value, $format = 'html', $submission = array()) {
  return [
    '#title' => 'Location',
    '#weight' => $component['weight'],
    '#theme' => 'webform_display_geolocation',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#format' => $format,
    '#value' => $value,
    '#translatable' => array('title', 'field_prefix', 'field_suffix'),
  ];
}

/**
 * Format the output of data for this component.
 */
function theme_webform_display_geolocation($variables) {
  return _cluster_geo_format_coordinates($variables['element']['#value']);
}

/**
 * Implements _webform_analysis_component().
 */
function _webform_analysis_geolocation($component, $sids = array(), $single = FALSE, $join = NULL) {
 // @TODO
}

/**
 * Implements _webform_table_component().
 */
function _webform_table_geolocation($component, $value) {
  return _cluster_geo_format_coordinates($value);
}

/**
 * Implements _webform_action_set_component().
 */
function _webform_action_set_geolocation($component, &$element, &$form_state, $value) {
  $element['#value'] = $value;
  form_set_value($element, $value, $form_state);
}

/**
 * Implements _webform_csv_headers_component().
 */
function _webform_csv_headers_geolocation($component, $export_options) {
  // @TODO
  return [];
}

/**
 * Implements _webform_csv_data_component().
 */
function _webform_csv_data_geolocation($component, $export_options, $value) {
  return _cluster_geo_format_coordinates($value);
}

function _cluster_geo_format_coordinates($value) {
  if (!empty($value['lat']) && !empty($value['lon'])) {
    return check_plain('Lat: '. $value['lat'] . ' Lon: ' .  $value['lon']);
  }
  return '';
}
