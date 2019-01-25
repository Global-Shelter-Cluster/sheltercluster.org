<?php
/**
 * @file
 * Webform component functionality for the location component.
 */

define('WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_POINT', 'point');
define('WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_GOOGLE_URL', 'google_url');

// TODO: Remaining webform hooks.
// TODO: Max zoom.
// TODO: Bounding box on the map?

/**
 * Implements _webform_theme_component().
 */
function _webform_theme_gpslocation() {
  return array(
    'webform_gpslocation_gpslocation' => array(
      'render element' => 'element',
      'file' => 'components/gpslocation_component.inc',
      'path' => drupal_get_path('module', 'webform_gpslocation'),
    ),
    'webform_gpslocation_display_gpslocation' => array(
      'render element' => 'element',
      'file' => 'components/gpslocation_component.inc',
      'path' => drupal_get_path('module', 'webform_gpslocation'),
    ),
  );
}


/**
 * Implements _webform_defaults_component.
 */
function _webform_defaults_gpslocation() {
  return [
    'name' => '',
    'form_key' => NULL,
    'pid' => 0,
    'weight' => 0,
    'value' => '',
    'required' => 0,
    'extra' => [
      'width' => '',
      'field_prefix' => '',
      'field_suffix' => '',
      'disabled' => 0,
      'title_display' => 0,
      'description' => '',
      'description_above' => FALSE,
      'attributes' => [],
      'private' => FALSE,
      'analysis' => FALSE,
      // Custom settings.
      'restrict_location' => FALSE,
      'restriction_boundary' => '',
      'restriction_error' => '',
      'map_type' => '',
      'map_min_zoom' => '0',
      'map_max_zoom' => '18',
      'map_default_zoom' => '4',
      'map_bounding_box' => '',
      'map_center_lat' => '',
      'map_center_lon' => '',
      'center_is_default' => FALSE,
      'render_location' => WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_POINT,
    ],
  ];
}

/**
 * Implements _webform_edit_component().
 */
function _webform_edit_gpslocation(array $component) {
  $form = array();

  $leaflet_map_type_options = array_map(function ($map) {
      return isset($map['label']) ? $map['label'] : t('Unlabeled map');
  }, leaflet_map_get_info());

  $form['extra']['map_type'] = [
    '#type' => 'select',
    '#options' => $leaflet_map_type_options,
    '#required' => TRUE,
    '#default_value' => $component['extra']['map_type'],
  ];

  // NTH: Perhaps implement as a map?
  $form['extra']['map_center_lat'] = [
    '#type' => 'textfield',
    '#title' => t('Default map center latitude'),
    '#default_value' => $component['extra']['map_center_lat'],
    '#description' => t('Latitude of the co-ordinate that is used as the initial map center.'),
    '#required' => TRUE,
  ];

  $form['extra']['map_center_lon'] = [
    '#type' => 'textfield',
    '#title' => t('Default map center longitude'),
    '#default_value' => $component['extra']['map_center_lon'],
    '#description' => t('Longitude of the co-ordinate that is used as the initial map center.'),
    '#required' => TRUE,
  ];

  $form['extra']['map_default_zoom'] = [
    '#type' => 'textfield',
    '#title' => t('Default zoom level'),
    '#default_value' => $component['extra']['map_default_zoom'],
    '#description' => t('The default zoom level of the map. Combined with the default coordinates, this determines what is shown on the map.'),
    '#required' => TRUE,
  ];

  $form['extra']['map_min_zoom'] = [
    '#type' => 'textfield',
    '#title' => t('Minimum zoom level'),
    '#default_value' => $component['extra']['map_min_zoom'],
    '#description' => t('The minimum zoom level of the map.'),
    '#required' => TRUE,
  ];

  $form['extra']['map_max_zoom'] = [
    '#type' => 'textfield',
    '#title' => t('Maximum zoom level'),
    '#default_value' => $component['extra']['map_max_zoom'],
    '#description' => t('The maximum zoom level of the map. While the map type usually specifies a maximum zoom in the label, be sure to test manually; many map types will not have tilesets for the given maximum zoom, resulting in an empty map.'),
    '#required' => TRUE,
  ];

  $form['extra']['map_bounding_box'] = [
    '#type' => 'textarea',
    '#title' => t('Map bounds'),
    '#default_value' => $component['extra']['map_bounding_box'],
    '#description' => t('Two coordinate pairs describing northwest and southeast of a rectangle that will be used as map boundary. Format Lat,Lon;Lat,Lon'),
    '#required' => FALSE,
  ];

  $form['extra']['restrict_location'] = [
    '#type' => 'radios',
    '#title' => t('Restrict given location'),
    '#options' => [
      0 => t('Do not restrict the input location'),
      1 => t('Restrict the input location to the specified restriction boundary'),
    ],
    '#default_value' => $component['extra']['restrict_location'],
    '#description' => t('Whether to restrict the input location to a location within certain boundaries.'),
    '#required' => TRUE,
  ];

  // NTH: Perhaps implement as drawn on the default location map?
  $form['extra']['restriction_boundary'] = [
    '#type' => 'textarea',
    '#title' => t('Restriction boundaries'),
    '#default_value' => $component['extra']['restriction_boundary'],
    '#description' => t('Coordinates describing one or more polygons. Given locations must reside in one of the polygons to be accepted.'),
    '#required' => FALSE,
  ];

  $form['extra']['restriction_error'] = [
    '#type' => 'textarea',
    '#title' => t('Restriction error message'),
    '#default_value' => $component['extra']['restriction_error'],
    '#description' => t('Error message when the point is not in the given restriction polygons.'),
    '#required' => FALSE,
  ];

  $form['extra']['render_location'] = [
    '#type' => 'radios',
    '#title' => t('Render output as'),
    '#options' => [
      WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_POINT => t('Point (lat, lon)'),
      WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_GOOGLE_URL => t('Google maps url'),
    ],
    '#default_value' => $component['extra']['render_location'],
    '#description' => t('How to output the value of this field when rendered, for example in an e-mail confirmation.'),
    '#required' => TRUE,
  ];

  return $form;
}

/**
 * Implements _webform_render_component.
 */
function _webform_render_gpslocation($component, $value = NULL, $filter = TRUE, $submission = NULL) {
  $node = isset($component['nid']) ? node_load($component['nid']) : NULL;
  $map_bounding_box = [];

  // Parse the bounding box string.
  if ($component['extra']['map_bounding_box']) {
    $coordinate_pairs = explode(';', $component['extra']['map_bounding_box']);
    foreach ($coordinate_pairs as $coordinate_pair) {
      $map_bounding_box[] = explode(',', $coordinate_pair);
    }
  }

  $element = [
    '#type' => 'webform_gpslocation_gpslocation',
    '#title' => $filter ? webform_filter_xss($component['name']) : $component['name'],
    '#title_display' => $component['extra']['title_display'] ? $component['extra']['title_display'] : 'before',
    '#weight' => $component['weight'],
    '#description' => $filter ? webform_filter_descriptions($component['extra']['description'], $node) : $component['extra']['description'],
    '#required' => $component['required'],
    '#process' => ['webform_gpslocation_process_gpslocation'],
    '#theme' => 'webform_gpslocation_gpslocation',
    '#theme_wrappers' => ['webform_element'],
    '#element_validate' => ['webform_gpslocation_validate_gpslocation'],
    '#translatable' => ['title', 'description'],
    '#restrict_location' => $component['extra']['restrict_location'],
    '#restriction_boundary' => $component['extra']['restriction_boundary'],
    '#map_type' => $component['extra']['map_type'],
    '#map_default_zoom' => $component['extra']['map_default_zoom'],
    '#map_default_center' => [
      'lat' => $component['extra']['map_center_lat'],
      'lon' => $component['extra']['map_center_lon'],
    ],
    '#map_max_zoom' => $component['extra']['map_max_zoom'],
    '#map_min_zoom' => $component['extra']['map_min_zoom'],
    '#map_bounding_box' => $map_bounding_box,
    '#restriction_error' => check_plain($component['extra']['restriction_error']),
  ];

  $element['#default_value'] = $value;

  return $element;
}

/**
 * Expand the lv_webform_gpslocation element.
 */
function webform_gpslocation_process_gpslocation($element, $form_state, $form) {
  $form_key = $element['#webform_component']['form_key'];

  $element['lat'] = [
    '#attributes' => ['id' => $form_key . '-lat'],
    '#type' => 'hidden',
    '#default_value' => $element['#default_value']['lat'],
  ];

  $element['lon'] = [
    '#attributes' => ['id' => $form_key . '-lon'],
    '#type' => 'hidden',
    '#default_value' => $element['#default_value']['lon'],
  ];

  $element['zoom'] = [
    '#attributes' => ['id' => $form_key . '-zoom'],
    '#type' => 'hidden',
    '#default_value' => $element['#default_value']['zoom'],
  ];

  $map = leaflet_map_get_info($element['#map_type']);

  // Override default map settings.
  $map['settings']['minZoom'] = $element['#map_min_zoom'];
  $map['settings']['maxZoom'] = $element['#map_max_zoom'];
  $map['settings']['zoom'] = $element['#map_default_zoom'];

  // Zoom around center to avoid unintended drift.
  $map['settings']['scrollWheelZoom'] = 'center';
  $map['settings']['doubleClickZoom'] = 'center';
  $map['settings']['touchZoom'] = 'center';

  if (!empty($element['#map_bounding_box'])) {
    $map['settings']['maxBounds'] = $element['#map_bounding_box'];
  }

  if (!empty($element['#value']) && $element['#value']['lat'] !== '') {
    $map['center'] = [
      'lat' => $element['#value']['lat'],
      'lon' => $element['#value']['lon'],
    ];
    $map['settings']['zoom'] = $element['#value']['zoom'];
  }
  elseif ($element['#default_value']) {
    $map['center'] = [
      'lat' => $element['#default_value']['lat'],
      'lon' => $element['#default_value']['lon'],
    ];
  }
  else {
    $map['center'] = [
      'lat' => $element['#map_default_center']['lat'],
      'lon' => $element['#map_default_center']['lon'],
    ];
  }

  $id = $form_key . '-use-gps';

  $element['use-gps-location-button'] = [
    '#markup' => '<div class="gpslocation-action-button"><a id="' . $id . '"  class="btn btn-primary" href="#">' . t('Use current location') . '</a></div>',
  ];

  $element['map-wrapper'] = [
    '#type' => 'container',
    '#id' => $element['#id'] . '-map-wrapper',
  ];

  $element['map-wrapper']['map'] = leaflet_build_map($map, []);

  $path = drupal_get_path('module', 'webform_gpslocation');

  $settings = [
    [
      'formKey' => $form_key,
      'buttonId' => $id,
      'mapId' => $element['map-wrapper']['map']['#attributes']['id'],
      'mapWrapperId' => $element['#id'] . '-map-wrapper',
      'crossHair' => [
        'iconUrl' => base_path() . $path . '/components/img/crosshair.svg',
        'iconSize' => [61, 61],
        'iconAnchor' => [31, 31],
      ],
      'zoomOnLocation' => $element['#map_max_zoom'],
    ],
  ];

  $element['#attached']['js'][] = array(
    'data' => array('webform_gpslocation' => $settings),
    'type' => 'setting',
  );

  $element['#attached']['js'][] = $path . '/components/js/gpslocation_component.js';
  $element['#attached']['libraries_load'][] = array('leaflet');
  $leaflet_lib = libraries_info('leaflet');
  $leaflet_lib['library path'] = '/sites/all/libraries/leaflet';
  libraries_load_files($leaflet_lib);

  return $element;
}

/**
 * Validate the given location.
 */
function webform_gpslocation_validate_gpslocation($element, &$form_state) {
  $lat = $element['lat']['#value'];
  $lon = $element['lon']['#value'];

  if ($element['#required'] && (empty($lat) || empty($lon))) {
    form_error($element, t('%name must have a valid location.', array('%name' => $element['#title'])));
    return;
  }

  // TODO: Sanity checks.
  if (!empty($element['#restrict_location']) && !empty($lat) && !empty($lon)) {
    $polygons = explode("\n", $element['#restriction_boundary']);
    foreach ($polygons as $polygon) {
      if (webform_gps_location_is_in_polygon($lat, $lon, $polygon)) {
        // If the point is within at least one polygon, the point is accepted.
        return;
      }
    }

    $error = $element['#restriction_error'];
    if ($error === '') {
      $error = t('%name location must be within the given area.', array('%name' => $element['#title']));
    }
    form_error($element, $error);
  }
}

/**
 * Implements _webform_display_component().
 */
function _webform_display_gpslocation($component, $value, $format = 'html', $submission = array()) {
  $default = [
    'lat' => NULL,
    'lon' => NULL,
    'zoom' => NULL,
  ];
  $display = [
    '#title' => $component['name'],
    '#weight' => $component['weight'],
    '#theme' => 'webform_gpslocation_display_gpslocation',
    '#theme_wrappers' => $format == 'html' ? array('webform_element') : array('webform_element_text'),
    '#post_render' => array('webform_element_wrapper'),
    '#field_prefix' => $component['extra']['field_prefix'],
    '#field_suffix' => $component['extra']['field_suffix'],
    '#render_location' => $component['extra']['render_location'],
    '#component' => $component,
    '#format' => $format,
    '#value' => isset($value['lat']) ? $value : $default,
  ];

  return $display;
}


/**
 * Theme the gpslocation form element.
 */
function theme_webform_gpslocation_gpslocation($variables) {
  $element = $variables['element'];
  return drupal_render_children($element);
}

/**
 * Theme the gpslocation display.
 */
function theme_webform_gpslocation_display_gpslocation($variables) {
  $element = $variables['element'];
  $format = $element['#format'];
  $value = $element['#value'];
  $lat = $value['lat'];
  $lon = $value['lon'];

  $link_to_map = $element['#render_location'] === WEBFORM_GPSLOCATION_GPSLOCATION_RENDER_GOOGLE_URL && $lat !== NULL && $lon !== NULL;

  if ($format == 'html') {
    if ($link_to_map) {
      $output = t('Latitude: @lat, Longitude: @lon. Show on <a href="@url">Google maps</a>.', [
        '@lat' => $lat,
        '@lon' => $lon,
        '@url' => url('https://maps.google.com/', [
          'query' => [
            'q' => $lat . ',' . $lon,
            'll' => $lat . ',' . $lon,
            'z' => 14,
          ],
          'absolute' => TRUE,
        ]),
      ]);
    }
    else {
      $output = t('Latitude: @lat, Longitude: @lon.', [
        '@lat' => $lat,
        '@lon' => $lon,
      ]);
    }
  }
  else {
    if ($link_to_map) {
      $output = t('Latitude: !lat, Longitude: !lon. Google maps: !url .', [
        '!lat' => $lat,
        '!lon' => $lon,
        '!url' => url('https://maps.google.com/', [
          'query' => [
            'q' => $lat . ',' . $lon,
            'll' => $lat . ',' . $lon,
            'z' => 14,
          ],
          'absolute' => TRUE,
        ]),
      ]);
    }
    else {
      $output = $value['lat'] . ', ' . $value['lon'];
    }
  }

  return $output;
}

