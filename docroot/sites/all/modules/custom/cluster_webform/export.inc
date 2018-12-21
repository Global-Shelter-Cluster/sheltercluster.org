<?php
/**
 * @file
 * These functions export a webform's fields as a simple JSON structure, in order to be exported through the API.
 */

/**
 * Example:
 *   [
 *     0 => [
 *       'title' => 'Some fields', // empty for the first page, "Start" assumed
 *       'fields' => [
 *         [
 *           'type' => 'textfield',
 *           'key' => 'first_name',
 *           'name' => 'First name',
 *           'required' => TRUE, // optional
 *           'default' => 'type here', // optional
 *           'description' => 'Type your first name here', // optional
 *         ],
 *         [
 *           'type' => 'markup',
 *           'value' => '<p>hello, this is simple some <em>text</em></p>',
 *         ],
 *       ],
 *     ],
 *   ]
 *
 * @param $node
 * @return array
 */
function cluster_webform_export($node) {
  $ret = [];
  $current_page = ['fields' => []];

  // Call this function every time we need to define a new page, and once again at the end.
  $store_page = function () use (&$ret, &$current_page) {
    if ($current_page['fields']) {
      $ret[] = $current_page;
    }
    $current_page = ['fields' => []];
  };

  $supported_components = _cluster_webform_get_supported_components();
  foreach ($node->webform['components'] as $cid => $component) {
    $type = $component['type'];
    if (!in_array($type, $supported_components)) {
      continue;
    }

    $item = NULL;

    if ($type == 'pagebreak') {
      $store_page();
      $current_page['title'] = $component['name'];
      continue;
    }

    if (function_exists('_cluster_webform_export_' . $type)) {
      $item = call_user_func('_cluster_webform_export_' . $type, $component, $type);
    }
    else {
      $item = _cluster_webform_export_component($component, $type);
    }

    if (!$item) {
      continue;
    }
    $item['type'] = $type;
    $current_page['fields'][] = $item;

  }

  $store_page();

  return $ret;
}

function _cluster_webform_export_markup($component) {
  if (!$component['value'])
    return NULL;

  return ['value' => $component['value']];
}

function _cluster_webform_export_component($component, $type) {
  $item = [
    'key' => $component['form_key'],
    'name' => $component['name'],
  ];

  if (!empty($component['description'])) {
    $item['description'] = $component['description'];
  }

  if ($component['required'] == 1) {
    $item['required'] = TRUE;
  }

  if ($component['value']) {
    $item['default'] = $component['value'];
  }

  $supported_elements = _cluster_webform_get_supported_component_elements($type);
  foreach ($supported_elements as $key) {
    if (!empty ($component['extra'][$key])) {
      switch ($key) {
        // Cast to boolean.
        case 'integer':
        case 'multiple':
          $item[$key] = $component['extra'][$key] ? 'true' : 'false';
          break;

        // Cast to int.
        case 'max':
        case 'min':
          $item[$key] = (int) $component['extra'][$key];
          break;

        case 'filtering':
          $item['file_extensions'] = $component['extra'][$key]['types']; // array of extensions, e.g. ['gif', 'jpg', 'jpeg', 'png']

          $item['file_type'] = 'file'; // possible values: "file", "image", possibly others in the future (e.g. "video", "signature/drawing", etc.)

          $image_extensions = ['gif', 'jpg', 'jpeg', 'png'];
          if (
            count(array_intersect($item['file_extensions'], $image_extensions)) > 0 // there are image extensions,
            && count(array_diff($item['file_extensions'], $image_extensions)) === 0 // and _only_ image extensions
          ) {
            $item['file_type'] = 'image';
          }

          break;

        default:
          $item[$key] = $component['extra'][$key];
      }
    }
  }
  return $item;
}

function _cluster_webform_export_select($component, $type) {
  $items = _cluster_webform_export_component($component, $type);

  // It is unfortunate that webforms did not use the key 'options'.
  $options = explode(PHP_EOL, $items['items']);
  unset($items['items']);

  $export = [];
  foreach ($options as $option) {
    if ($option) {
      $exploded = explode('|', $option);
      $export[$exploded[0]] = trim($exploded[1]);
    }
  }
  $items['options'] = $export;

  return $items;
}

function _cluster_webform_export_time($component, $type) {
  $items = _cluster_webform_export_component($component, $type);

  // Format default time to expose hours and minutes.
  if (!empty($items['default'])) {
    $time_values = explode(':', $items['default']);
    if (count($time_values) == 2) {
      $items['hours'] = $time_values[0];
      $items['minutes'] = $time_values[1];
    }
  }

  return $items;
}
