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
