<?php
/**
 * @file
 * shelter_base.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function shelter_base_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-general-information.
  $menus['menu-general-information'] = array(
    'menu_name' => 'menu-general-information',
    'title' => 'General Information',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('General Information');


  return $menus;
}
