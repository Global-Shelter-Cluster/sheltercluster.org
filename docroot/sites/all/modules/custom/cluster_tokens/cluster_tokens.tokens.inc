<?php

/**
 * Implements hook_token_info().
 */
function cluster_tokens_token_info() {
  $info = array();
  $node = &$info['tokens']['node'];

  $node['cluster-response-title'] = array(
    'name' => t('Cluster response'),
    'description' => 'sdf',
  );

  return $info;
}

/**
 * Implements hook_tokens().
 */
function cluster_tokens_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'node' && !empty($data['node'])) {
    $node = $data['node'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'cluster-response-title':
          if (!in_array($node->type, array('document', 'discussion', 'event'))) {
            return;
          }

          try {
            module_load_include('inc', 'pathauto');

            /** @var EntityDrupalWrapper $wrapper */
            $wrapper = entity_metadata_wrapper('node', $node);

            if (empty($wrapper->get('og_group_ref')->value())) {
              return;
            }

            $groups = $wrapper->get('og_group_ref')->value();
            $label = reset($groups)->title;

            $replacements[$original] = pathauto_cleanstring($label);
          }
          catch (Exception $exception) {
            watchdog_exception('cluster_tokens', $exception);
          }
          break;
      }
    }
  }

  return $replacements;
}
