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

  foreach ($node->webform['components'] as $cid => $component) {
    $type = $component['type'];
    $item = NULL;

    switch ($type) {
      case 'pagebreak':
        $store_page();
        $current_page['title'] = $component['name'];
        continue 2;

      case 'markup':
      case 'textfield':
        $item = call_user_func('_cluster_webform_export_' . $type, $component);
        if (!$item)
          continue 2;
        $item['type'] = $type;
    }

    if ($item)
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

function _cluster_webform_export_textfield($component) {
  $item = [
    'key' => $component['form_key'],
    'name' => $component['name'],
  ];

  if ($component['required'] == 1)
    $item['required'] = TRUE;

  if ($component['value'])
    $item['default'] = $component['value'];

  if ($component['extra']['description'])
    $item['description'] = $component['extra']['description'];

  return $item;
}
