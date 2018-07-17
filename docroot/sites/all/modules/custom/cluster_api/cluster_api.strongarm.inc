<?php
/**
 * @file
 * cluster_api.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cluster_api_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'cluster_api_oauth2_server';
  $strongarm->value = 'http://192.168.0.105:32776';
  $export['cluster_api_oauth2_server'] = $strongarm;

  return $export;
}
