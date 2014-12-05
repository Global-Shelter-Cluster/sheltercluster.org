<?php
/**
 * @file
 * cluster_og.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function cluster_og_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-regions.
  $menus['menu-regions'] = array(
    'menu_name' => 'menu-regions',
    'title' => 'Regions',
    'description' => 'Menu that gets automatically populated from Geographic region content.',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Menu that gets automatically populated from Geographic region content.');
  t('Regions');


  return $menus;
}
