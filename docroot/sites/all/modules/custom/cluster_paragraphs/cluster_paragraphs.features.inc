<?php
/**
 * @file
 * cluster_paragraphs.features.inc
 */

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
