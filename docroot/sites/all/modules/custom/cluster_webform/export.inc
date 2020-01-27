<?php
/**
 * @file
 * These functions export a webform's fields as a simple JSON structure, in order to be exported through the API.
 * module_load_include('inc', 'webform', 'export');
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

  $targeted_conditional_components = _cluster_webform_get_condition_target_components($node->webform['conditionals'], $node->webform['components']);
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

    // Add conditionals for this item.
    if (array_key_exists($cid, $targeted_conditional_components)) {
      $item['conditional'] = $targeted_conditional_components[$cid];
    };

    $current_page['fields'][] = $item;

  }

  $store_page();
  return $ret;
}

/**
 * Format the conditional webform rules and actions for export.
 */
function _cluster_webform_get_condition_target_components($conditionals, $form_components) {
  $export = [];
  foreach($conditionals as $rule_group_id => $rule_group) {
    $component_rules = [];
    foreach ($rule_group['rules'] as $rules) {
      $optional = [];
      if ($rules['operator'] !== 'equal') {
        $optional['operator'] = $rules['operator'];
      }
      $component_rules[] = array_merge(
        $optional, [
        'field' => $form_components[$rules['source']]['form_key'],
        'value' => $rules['value'],
      ]);
    }

    foreach ($rule_group['actions'] as $action) {
      $optional = [];
      if ($rule_group['andor'] == 'or') {
        $optional['or'] = TRUE;
      }
      $export[$action['target']] = array_merge(
        $optional, [
        'rules' => $component_rules,
      ]);
    }
  }
  return $export;
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
          $item[$key] = $component['extra'][$key] ? TRUE : FALSE;
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

        case 'current_coordinates':
          if ($component['extra'][$key])
            $item[$key] = TRUE;
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

function cluster_webform_export_excel($node) {
  if ($node->type !== 'webform') {
    return MENU_NOT_FOUND;
  }

  $xls = new PhpOffice\PhpSpreadsheet\Spreadsheet();
  $xls->setActiveSheetIndex(0);

  $survey = $xls->getActiveSheet();
  $survey->setTitle('survey');
  $choices = $xls->createSheet();
  $choices->setTitle('choices');
  $settings = $xls->createSheet();
  $settings->setTitle('settings');

  $survey_cols = [
    'type' => 'A',
    'name' => 'B',
    'label' => 'C',
    'hint' => 'D',
    'default' => 'E',
    'required' => 'F',
    'appearance' => 'G',
    'constraint' => 'H',
    'calculation' => 'I',
  ];
  $choices_cols = [
    'list_name' => 'A',
    'name' => 'B',
    'label' => 'C',
  ];
  $settings_cols = [
    'version' => 'A',
  ];

  foreach ($survey_cols as $k => $v)
    $survey->setCellValue($v.'1', $k);
  foreach ($choices_cols as $k => $v)
    $choices->setCellValue($v.'1', $k);
  foreach ($settings_cols as $k => $v)
    $settings->setCellValue($v.'1', $k);

  $survey_row = 2;
  $choices_row = 2;
  $settings_row = 2;

  $write_row = function($data, &$sheet, &$cols, &$row) {
    foreach ($data as $k => $v) {
      $sheet->setCellValue($cols[$k].$row, $v);
    }
    $row++;
  };
  $write_row_survey = function($data) use ($write_row, $survey, $survey_cols, &$survey_row) {
    $write_row($data, $survey, $survey_cols, $survey_row);
  };
  $write_row_choices = function($data) use ($write_row, $choices, $choices_cols, &$choices_row) {
    $write_row($data, $choices, $choices_cols, $choices_row);
  };
  $write_row_settings = function($data) use ($write_row, $settings, $settings_cols, &$settings_row) {
    $write_row($data, $settings, $settings_cols, $settings_row);
  };

  $uuid = function($size) {
    $chars = array_merge(
      range(ord('A'), ord('Z')),
      range(ord('a'), ord('z')),
      range(ord('0'), ord('9'))
    );
    $keys = array_rand($chars, $size);
    shuffle($keys);
    return join('', array_map(function($key) use ($chars) {return chr($chars[$key]);}, $keys));
  };

  $write_row_survey(['type' => 'start', 'name' => 'start']);
  $write_row_survey(['type' => 'end', 'name' => 'end']);

  $is_first_page = TRUE;
  $label_counter = 0; // for "markup" components
  foreach (cluster_webform_export($node) as $page_idx => $page) {
    if ($is_first_page)
      $is_first_page = FALSE;
    else {
      $write_row_survey(['type' => '', 'name' => 'break'.$page_idx, 'label' => $page['title']]);
    }

    foreach ((array) $page['fields'] as $field) {
      $row = [
        'required' => isset($field['required']) && $field['required'] ? 'true' : 'false',
      ];
      foreach (['name' => 'key', 'label' => 'name', 'hint' => 'description', 'default' => 'default'] as $property_excel => $property_field) {
        if (isset($field[$property_field]))
          $row[$property_excel] = $field[$property_field];
      }

      switch ($field['type']) {
        case 'textfield':
          $row += ['type' => 'text'];
          break;
        case 'textarea':
          $row += ['type' => 'text', 'appearance' => 'multiline'];
          break;
        case 'date':
          $row += ['type' => 'date'];
          break;
        case 'time':
          $row += ['type' => 'time'];
          break;
        case 'geolocation':
          $row += ['type' => 'geopoint'];
          break;
        case 'file':
          if (isset($field['file_type']) && $field['file_type'] === 'image')
            $row += ['type' => 'image'];
          else
            continue; // skip this field
          break;
        case 'markup':
          $row += ['type' => 'note', 'name' => 'label'.(++$label_counter), 'label' => trim(strip_tags($field['value']))];
          break;
        case 'number':
          $type = isset($field['integer']) && $field['integer'] ? 'integer' : 'decimal';
          $row += ['type' => $type];

          $constraints = [];
          if (isset($field['min']))
            $constraints[] = '. >= '.$field['min'];
          if (isset($field['max']))
            $constraints[] = '. <= '.$field['max'];
          if ($constraints)
            $row['constraint'] = implode(' and ', $constraints);

          break;
        case 'select':
          $type = isset($field['multiple']) && $field['multiple'] ? 'select_multiple' : 'select_one';
          $id = $uuid(7);
          $row['type'] = $type.' '.$id;

          foreach ((array) $field['options'] as $name => $label)
            $write_row_choices(['list_name' => $id, 'name' => $name, 'label' => $label]);

          break;
      }
      $write_row_survey($row);
    }
  }

  $version = $uuid(22);
  $write_row_settings(['version' => $version]);

  $objWriter = PhpOffice\PhpSpreadsheet\IOFactory::createWriter($xls, 'Xlsx');
  $uri = drupal_tempnam('temporary://', 'webform-export') . '.xlsx';
  $objWriter->save(drupal_realpath($uri));
  $filename = _cluster_webform_sanitize_filename($node->title.'.xlsx');
  file_transfer($uri, [
    'Content-Disposition' => 'attachment; filename="'. str_replace('"', '', $filename) .'"',
    'Content-Type' => 'application/vnd.openxmlformats-officedocument.spreadsheetml.sheet',
  ]);
}

function _cluster_webform_sanitize_filename($filename) {
  $filename = preg_replace('/[\x00-\x1F]/u', '_', $filename);
  if (substr(PHP_OS, 0, 3) == 'WIN') {
    // These characters are not allowed in Windows filenames
    $filename = str_replace(array(':', '*', '?', '"', '<', '>', '|'), '_', $filename);
  }
  return $filename;
}
