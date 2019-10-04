<?php
/**
 * @file
 * cluster_assessment.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cluster_assessment_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_cluster_assessment_assessment_pattern';
  $strongarm->value = '';
  $export['pathauto_cluster_assessment_assessment_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_cluster_assessment_pattern';
  $strongarm->value = '[node:content-type]/[node:title]/data-collection';
  $export['pathauto_cluster_assessment_pattern'] = $strongarm;

  return $export;
}
