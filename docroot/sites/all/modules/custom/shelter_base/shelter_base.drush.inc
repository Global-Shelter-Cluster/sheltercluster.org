<?php

/**
 * Implements hook_drush_command().
 */
function shelter_base_drush_command() {
  $items = array();

  $items['shelter-base-modules'] = array(
    'description' => dt('Enable core, contrib and custom modules defined by the shelter_base module.'),
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
  );

  return $items;
}

/**
 * Import articles from a previously recorded operation date.
 */
function drush_shelter_base_modules() {
  module_load_install('shelter_base');
  _shelter_base_modules_enable('core');
  _shelter_base_modules_enable('contrib');
  _shelter_base_modules_enable('custom');
  echo "Modules enabled.\n";
}