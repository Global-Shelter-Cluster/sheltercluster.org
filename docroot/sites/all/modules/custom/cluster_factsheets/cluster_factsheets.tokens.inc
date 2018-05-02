<?php

/**
 * Implements hook_token_info().
 */
function cluster_factsheets_token_info() {
  $info = [];
  $node = &$info['tokens']['node'];

  $node['cluster-factsheet-date'] = [
    'name' => t('Factsheet date'),
    'description' => 'Y-m format',
  ];

  return $info;
}

/**
 * Implements hook_tokens().
 */
function cluster_factsheets_tokens($type, $tokens, array $data = [], array $options = []) {
  $replacements = [];

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'cluster-factsheet-date':
          if ($node->type !== 'factsheet')
            return;

          try {
            module_load_include('inc', 'pathauto');

            $items = field_get_items('node', $node, 'field_date');
            if (!$items)
              return;
            $item = $items[0];

            $date = new DateObject($item['value'], $item['timezone_db'], date_type_format($item['date_type']));
            if (empty($date))
              return;
            // TODO: is this necessary? (code copied from date.tokens.inc)
//            if (!empty($date) && $item['timezone_db'] != $item['timezone']) {
//              date_timezone_set($date, timezone_open($item['timezone']));
//            }

            $formatted = date_format_date($date, 'custom', 'Y-m');
            $replacements[$original] = pathauto_cleanstring($formatted);
          } catch (Exception $exception) {
            watchdog_exception('cluster_factsheets', $exception);
          }
          break;
      }
    }
  }

  return $replacements;
}
