<?php

/**
 * A small helper to simplify outputing image tags to be used with svg-inject.js
 */
function _svg($filename, $attributes) {
  $assets_path = drupal_get_path('theme', 'shelter') . '/assets';
  return '<img class="inject-me" data-src="' . $assets_path . '/svg/' . $filename .'.svg" data-replacement="' . $assets_path . '/png/' . $filename .'.png" />';
}
