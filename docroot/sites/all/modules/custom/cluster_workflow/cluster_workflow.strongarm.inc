<?php
/**
 * @file
 * cluster_workflow.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cluster_workflow_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_discussion';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_discussion'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_document';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_document'] = $strongarm;

  return $export;
}
