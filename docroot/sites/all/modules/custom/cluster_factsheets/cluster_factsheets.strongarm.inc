<?php
/**
 * @file
 * cluster_factsheets.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function cluster_factsheets_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'clone_use_node_type_name';
  $strongarm->value = 1;
  $export['clone_use_node_type_name'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_factsheet';
  $strongarm->value = 0;
  $export['comment_anonymous_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_factsheet';
  $strongarm->value = 0;
  $export['comment_default_mode_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_factsheet';
  $strongarm->value = '50';
  $export['comment_default_per_page_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_factsheet';
  $strongarm->value = '0';
  $export['comment_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_factsheet';
  $strongarm->value = 1;
  $export['comment_form_location_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_factsheet';
  $strongarm->value = '1';
  $export['comment_preview_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_factsheet';
  $strongarm->value = 1;
  $export['comment_subject_field_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__factsheet';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'related_response' => array(
        'custom_settings' => FALSE,
      ),
      'related_hub' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'factsheet_summary' => array(
        'custom_settings' => TRUE,
      ),
      'preview_block' => array(
        'custom_settings' => TRUE,
      ),
      'factsheet_homepage_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'factsheet_preview_block' => array(
        'custom_settings' => TRUE,
      ),
      'print' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'path' => array(
          'weight' => '1',
        ),
        'redirect' => array(
          'weight' => '0',
        ),
        'title' => array(
          'weight' => '33',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_node__factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_factsheet';
  $strongarm->value = '0';
  $export['language_content_type_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_factsheet';
  $strongarm->value = array();
  $export['menu_options_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_factsheet';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_factsheet';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_factsheet';
  $strongarm->value = '1';
  $export['node_preview_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_factsheet';
  $strongarm->value = 1;
  $export['node_submitted_factsheet'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_cluster_factsheets_factsheets_pattern';
  $strongarm->value = '';
  $export['pathauto_cluster_factsheets_factsheets_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_cluster_factsheets_pattern';
  $strongarm->value = '[node:content-type]/[node:title]/factsheets';
  $export['pathauto_cluster_factsheets_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_factsheet_pattern';
  $strongarm->value = '[node:cluster-response-title]/factsheets/[node:cluster-factsheet-date]';
  $export['pathauto_node_factsheet_pattern'] = $strongarm;

  return $export;
}
