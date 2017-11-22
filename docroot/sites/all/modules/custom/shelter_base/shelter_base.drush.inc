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

  $items['execute-update-hook'] = array(
    'description' => dt('Execute specific update hook'),
    'bootstrap' => 'DRUSH_BOOTSTRAP_DRUPAL_FULL',
    'aliases' => array('exu'),
    'arguments' => array(
      'module' => 'The module which implements the update hook to run.',
      'number' => 'The N value of the update hook to execute, or "X"',
    ),
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

/**
 * Executes a specific update hook without updating the schema_version value in the systems table.
 *
 * Useful to test update hooks while developping.
 * @example drush exu shelter_base 7010
 */
function drush_shelter_base_execute_update_hook($module = NULL, $number = NULL) {
  if (is_null($module) || is_null($number)) {
    drupal_set_message('Usage: drush cex MODULE_NAME HOOK_NUMBER');
    return;
  }
  if (!module_exists($module)) {
    drupal_set_message('No such module: ' . $module);
    return;
  }
  if (!is_numeric($number) && $number != "X") {
    drupal_set_message('Second argument must be hook number or "X"');
    return;
  }
  if (!module_load_install($module)) {
    drupal_set_message('No install file named ' . $module . '.install');
    return;
  }

  $hook_function = $module . '_update_' . $number;
  if (!function_exists($hook_function)) {
    drupal_set_message('No such function: ' . $hook_function);
    return;
  }

  $hook_function();
  drupal_set_message('Ran ' . $hook_function);
}