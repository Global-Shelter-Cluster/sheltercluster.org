<?php

/**
 * Determines if the element name is a field.
 *
 * @param string $element_name
 *   The name of the element.
 *
 * @return bool
 *   TRUE if is a field, or FALSE.
 */
function toggle_optional_fields_element_is_field($element_name) {
  if (in_array($element_name, array('body', 'language'))) {
    return TRUE;
  }

  return substr($element_name, 0, 6) == 'field_';
}
