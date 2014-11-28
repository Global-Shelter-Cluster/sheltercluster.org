<?php

/**
 * A small helper to simplify outputing image tags to be used with svg-inject.js
 */
function _svg($filename, $attributes = array() ) {
  $assets_path = drupal_get_path('theme', 'shelter') . '/assets';
  return '<img class="svg" src="'. $assets_path . '/svg/' . $filename .'.svg" data-src="' . $assets_path . '/svg/' . $filename .'.svg" data-replacement="' . $assets_path . 'svg/replacement/' . $filename .'.png" '.drupal_attributes($attributes).' />';
}
