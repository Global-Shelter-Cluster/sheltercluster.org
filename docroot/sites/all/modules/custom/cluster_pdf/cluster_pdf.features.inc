<?php
/**
 * @file
 * cluster_pdf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_pdf_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
