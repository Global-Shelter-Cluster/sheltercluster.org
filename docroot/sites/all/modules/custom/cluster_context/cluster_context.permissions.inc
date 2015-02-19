<?php

/**
 * Implements hook_permission().
 */
function cluster_context_permission() {
  return array(
    'create nodes without cluster context' =>  array(
      'title' => t('Create nodes without Cluster context'),
      'description' => t('Ability to access the raw node creation pages.'),
    ),
    'select text formats on context aware forms' => array(
      'title' => t('Select text formats on context aware forms.'),
      'description' => t('Users with this permission will be able to select different text formats.'),
    ),
  );
}
