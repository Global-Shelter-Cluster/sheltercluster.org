<?php
/**
 * @file
 * cluster_paragraphs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_paragraphs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function cluster_paragraphs_paragraphs_info() {
  $items = array(
    'images' => array(
      'name' => 'Images',
      'bundle' => 'images',
      'locked' => '1',
    ),
    'links' => array(
      'name' => 'Links',
      'bundle' => 'links',
      'locked' => '1',
    ),
    'publications' => array(
      'name' => 'Publications',
      'bundle' => 'publications',
      'locked' => '1',
    ),
    'short_publications' => array(
      'name' => 'Short publications',
      'bundle' => 'short_publications',
      'locked' => '1',
    ),
    'team_members' => array(
      'name' => 'Team members',
      'bundle' => 'team_members',
      'locked' => '1',
    ),
    'text' => array(
      'name' => 'Text',
      'bundle' => 'text',
      'locked' => '1',
    ),
    'twocol_text_link' => array(
      'name' => 'Two-column table (text, link)',
      'bundle' => 'twocol_text_link',
      'locked' => '1',
    ),
  );
  return $items;
}
