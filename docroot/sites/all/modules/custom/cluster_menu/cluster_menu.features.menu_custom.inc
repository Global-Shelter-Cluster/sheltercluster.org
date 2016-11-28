<?php
/**
 * @file
 * cluster_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function cluster_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-mega-menu.
  $menus['menu-mega-menu'] = array(
    'menu_name' => 'menu-mega-menu',
    'title' => 'Mega Menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Mega Menu');


  return $menus;
}
