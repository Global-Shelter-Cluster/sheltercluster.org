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
  );
}
