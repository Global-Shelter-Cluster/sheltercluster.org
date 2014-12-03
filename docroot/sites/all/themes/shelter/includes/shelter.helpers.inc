<?php

/**
 * A small helper to simplify outputing image tags to be used with svg-inject.js
 */
function _svg($filename, $attributes = array() ) {
  $assets_path = base_path() . drupal_get_path('theme', 'shelter') . '/assets';
  if ( isset($attributes['class'])) {
    if (gettype($attributes['class']) == 'string') {
      $attributes['class'] = array($attributes['class']);
    }
    $attributes['class'] = array_merge( $attributes['class'], array('svg'));
  } else {
    $attributes['class'] = array('svg');
  }
  $resolution = '4x';
  return '<img src="'. $assets_path . '/svg/' . $filename .'.svg" data-src="' . $assets_path . '/svg/' . $filename .'.svg" data-replacement="' . $assets_path . 'svg/replacement/' . $filename .'-' . $resolution . '.png" '.drupal_attributes($attributes).' />';
}
