<?php

use PhpOffice\PhpSpreadsheet;
use PhpOffice\PhpSpreadsheet\Cell\Coordinate;

/**
 * @see cluster_webform_export()
 * @param object $node
 * @param array $data
 * @return bool TRUE if successful
 */
function cluster_webform_import($node, $data) {
  if (!$node || !$data || !$node->nid)
    return FALSE;

  $existing_form_keys = []; // keys are "form_key"s, values are TRUE (i.e. you should use array_key_exists() to check if a form_key already exists)
  $max_weight = -1;
  foreach ((array) $node->webform['components'] as $component) {
    if (isset($component['form_key'])) {
      $existing_form_keys[$component['form_key']] = TRUE;
    }
    if (isset($component['weight'])) {
      $max_weight = max($max_weight, intval($component['weight'], 10));
    }
  }

  $prepare_component = function($component) use ($node, &$max_weight) {
    $component['nid'] = $node->nid;
    $component['pid'] = 0;
    $component['weight'] = ++$max_weight;
    return $component;
  };

  $is_first_page = TRUE;
  foreach ($data as $page) {
    if (!$is_first_page) {
      $component = _cluster_webform_import_break(['name' => $page['title']], $existing_form_keys);
      webform_component_insert($prepare_component($component));
    }

    foreach ((array) $page['fields'] as $field) {
      if (!array_key_exists('type', $field)) {
        // Shouldn't happen, but let's skip the field if it does.
        continue;
      }
      $type = $field['type'];

      if (function_exists('_cluster_webform_import_' . $type))
        $component = call_user_func_array('_cluster_webform_import_' . $type, [$field, &$existing_form_keys]);
      else
        $component = _cluster_webform_import_component($field, $existing_form_keys);

      if ($component)
        webform_component_insert($prepare_component($component));
    }

    $is_first_page = FALSE;
  }
}

function _cluster_webform_import_component($field, &$existing_form_keys) {
//  if (isset($field['key'])) $field['key'] .= rand(100000,999999); // TODO: TEMP!!!
  if (isset($field['key']) && array_key_exists($field['key'], $existing_form_keys)) {
    drupal_set_message(t('Field already exists in this form: @key', ['@key' => $field['key']]), 'warning');
    return NULL;
  }

  if (!in_array($field['type'], _cluster_webform_get_supported_components())) {
    drupal_set_message(t('Unknown field type: @type', ['@type' => $field['type']]), 'warning');
    return NULL;
  }

  $component = [
    'type' => $field['type'],
  ];

  // values in root
  foreach ([
    'key' => 'form_key',
    'name' => 'name',
    'default' => 'value',
  ] as $field_key => $component_key) {
    if (isset($field[$field_key])) {
      $component[$component_key] = $field[$field_key];
    }
  }

  // values inside "extra" array
  foreach ([
    'description' => 'description',
    'min' => 'min',
    'max' => 'max',
  ] as $field_key => $component_key) {
    if (isset($field[$field_key])) {
      if (!isset($component['extra'])) $component['extra'] = [];
      $component['extra'][$component_key] = $field[$field_key];
    }
  }

  // booleans in root
  foreach ([
    'required',
  ] as $key) {
    if (isset($field[$key])) {
      $component[$key] = $field[$key] ? 1 : 0;
    }
  }

  // booleans inside "extra" array
  foreach ([
    'integer',
    'multiple',
  ] as $key) {
    if (isset($field[$key])) {
      if (!isset($component['extra'])) $component['extra'] = [];
      $component['extra'][$key] = $field[$key] ? 1 : 0;
    }
  }

  // Options (for selects), if they exist (they go in the "extra" array)
  if (isset($field['options'])) {
    if (!isset($component['extra'])) $component['extra'] = [];

    $component['extra']['items'] = join(PHP_EOL, array_map(function($k, $v) {
      return "$k|$v";
    }, array_keys($field['options']), $field['options']));
  }

  if (!array_key_exists('form_key', $component))
    return NULL;
  $existing_form_keys[$component['form_key']] = TRUE;

  return $component;
}

function _cluster_webform_import_markup($field, &$existing_form_keys) {
  if (!array_key_exists('value', $field))
    return NULL;

  $form_key = 'markup';
  $counter = 0;
  while (array_key_exists($form_key, $existing_form_keys))
    $form_key = 'markup'.(++$counter);

  $existing_form_keys[$form_key] = TRUE;

  return [
    'type' => 'markup',
    'form_key' => $form_key,
    'name' => 'markup',
    'value' => $field['value'],
  ];
}

function _cluster_webform_import_break($field, &$existing_form_keys) {
  $form_key = 'break';
  $counter = 0;
  while (array_key_exists($form_key, $existing_form_keys))
    $form_key = 'break'.(++$counter);

  $existing_form_keys[$form_key] = TRUE;

  return [
    'type' => 'pagebreak',
    'form_key' => $form_key,
    'name' => $field['name'],
  ];
}

/**
 * @see cluster_webform_export()
 * @param object $file
 * @return array|FALSE
 */
function cluster_webform_import_excel($file) {
  $spreadsheet = PhpSpreadsheet\IOFactory::load(drupal_realpath($file->uri));

  $sheet_names = $spreadsheet->getSheetNames();
  if (count(array_intersect($sheet_names, [
      'survey',
      'choices',
      'settings',
    ])) < 3) {
    drupal_set_message('Invalid file format (sheets not found)', 'error');
    return FALSE;
  }
  $sheet_map = array_flip($sheet_names); // ['survey' => 0, 'choices' => 1, 'settings' => 2]

  $survey = $spreadsheet->getSheet($sheet_map['survey']);
  $choices = $spreadsheet->getSheet($sheet_map['choices']);

  $survey_cols = [
    'type' => '',
    'name' => '',
    'label' => '',
    'hint' => '',
    'default' => '',
    'required' => '',
    'appearance' => '',
    'constraint' => '',
    //    'calculation' => '',
  ];
  $choices_cols = [
    'list_name' => '',
    'name' => '',
    'label' => '',
  ];

  $build_cols = function (PhpSpreadsheet\Worksheet\Worksheet $sheet, &$cols) {
    foreach ($cols as $header => &$col) {
      $found = FALSE;

      for ($c = 1; $c <= Coordinate::columnIndexFromString($sheet->getHighestColumn()); $c++) {
        if ($sheet->getCellByColumnAndRow($c, 1)->getValue() === $header) {
          $found = TRUE;
          $col = Coordinate::stringFromColumnIndex($c);
          break;
        }
      }

      if (!$found) {
        return $header;
      } // a.k.a. "this header was not found"
    }

    return TRUE; // a.k.a. "it's all good"
  };
  $err = $build_cols($survey, $survey_cols);
  if ($err !== TRUE) {
    drupal_set_message('Header "' . $err . '" not found in survey sheet', 'error');
    return FALSE;
  }
  $err = $build_cols($choices, $choices_cols);
  if ($err !== TRUE) {
    drupal_set_message('Header "' . $err . '" not found in choices sheet', 'error');
    return FALSE;
  }

  $read_row = function (PhpSpreadsheet\Worksheet\Worksheet $sheet, $cols, $row) {
    $ret = [];
    foreach ($cols as $key => $c) {
      $ret[$key] = $sheet->getCell($c . $row)->getValue();
    }
    return array_filter($ret);
  };

  // Prepare all the "options" ("choices" sheet), keyed by the internal ID
  $options = []; // E.g. ['abc123' => ['red' => 'Red', 'green' => 'Green'], ...]
  for ($r = 2; $r <= $choices->getHighestRow(); $r++) {
    $row = $read_row($choices, $choices_cols, $r);
    if (!isset($row['list_name']) || !isset($row['name']) || !isset($row['label'])) {
      continue;
    }

    if (!isset($options[$row['list_name']])) {
      $options[$row['list_name']] = [];
    }

    $options[$row['list_name']][$row['name']] = $row['label'];
  }

  // Now go through the form elements
  $data = [];
  $currentPage = [];
  for ($r = 2; $r <= $survey->getHighestRow(); $r++) {
    $row = $read_row($survey, $survey_cols, $r);

    if (!isset($row['type'])) {
      if (isset($row['label'])) {
        $data[] = $currentPage;
        $currentPage = ['title' => $row['label']];
      }
      continue;
    }

    $field = [];
    if (isset($row['required']) && strtolower(trim($row['required'])) === 'true')
      $field['required'] = TRUE;
    foreach ([
               'name' => 'key',
               'label' => 'name',
               'hint' => 'description',
               'default' => 'default',
             ] as $property_excel => $property_field) {
      if (isset($row[$property_excel])) {
        $field[$property_field] = $row[$property_excel];
      }
    }

    $type_parts = explode(' ', $row['type']);

    switch ($type_parts[0]) {
      case 'start':
      case 'end':
      case 'calculate':
        // Skip these without errors
        continue 2;

      case 'text':
        $field['type'] = (isset($row['appearance']) && $row['appearance'] === 'multiline')
          ? 'textarea'
          : 'textfield';
        break;
      case 'date':
        $field['type'] = 'date';
        break;
      case 'time':
        $field['type'] = 'time';
        break;
      case 'geopoint':
        $field['type'] = 'geolocation';
        break;
      case 'image':
        $field['type'] = 'file';
        $field['file_type'] = 'image';
        $field['file_extensions'] = ['gif', 'jpg', 'jpeg', 'png'];
        break;
      case 'note':
        if (!isset($row['label']))
          continue 2;
        // Discard everything except the label
        $field = ['type' => 'markup', 'value' => $row['label']];
        break;

      case 'integer':
        $field['integer'] = TRUE;
        // fall-through
      case 'decimal':
        $field['type'] = 'number';
        if (isset($row['constraint'])) {
          foreach (explode(' and ', $row['constraint']) as $constraint) {
            $constraint = trim($constraint);

            if (preg_match('/^\. >= (\d+)$/', $constraint, $matches))
              $field['min'] = intval($matches[1], 10);
            elseif (preg_match('/^\. <= (\d+)$/', $constraint, $matches))
              $field['max'] = intval($matches[1], 10);
            else
              drupal_set_message(t('Constraint not supported for field: @field', ['@field' => isset($field['name']) ? $field['name'] : 'unknown']), 'warning');
          }
        }
        break;

      case 'select_multiple':
        $field['multiple'] = TRUE;
        // fall-through
      case 'select_one':
        $field['type'] = 'select';
        if (count($type_parts) < 2)
          continue 2;
        if (array_key_exists($type_parts[1], $options))
          $field['options'] = $options[$type_parts[1]];
        break;

      default:
        drupal_set_message(t('Unsupported field type: @type', ['@type' => $type_parts[0]]), 'warning');
        continue 2;
    }

    $currentPage['fields'][] = $field;
  }

  if ($currentPage) {
    $data[] = $currentPage;
  }

  return $data;
}
