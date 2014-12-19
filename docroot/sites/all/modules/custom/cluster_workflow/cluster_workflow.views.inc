<?php

/**
 *  Implements hook_views_query_alter().
 */
function cluster_workflow_views_query_alter(&$view, &$query) {
  if ($view->name != 'workbench_moderation') {
    return;
  }

  // 2014-12-19
  // Remove the "node_access" and "user_access" tags from the query. This causes
  // the query to lose its permission checks, which are broken and not necessary.
  $query->tags = array();
}
