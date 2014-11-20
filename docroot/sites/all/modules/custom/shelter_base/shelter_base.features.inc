<?php
/**
 * @file
 * shelter_base.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function shelter_base_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
