<?php

/**
 * Prepare the form and add the toggle button.
 *
 * @see toggle_optional_fields_form_node_form_alter()
 */
function _toggle_optional_fields_prepare_form(&$form, &$form_state) {
  if (!isset($form_state['storage']['hide_optional_fields'])) {
    $form_state['storage']['hide_optional_fields'] = variable_get('toggle_optional_fields_hide_by_default', TRUE);
  }

  $hidden = $form_state['storage']['hide_optional_fields'];

  $form['toggle_optional_fields'] = array(
    '#type' => 'submit',
    '#value' => t('!action optional fields', array('!action' => $hidden ? 'Show' : 'Hide')),
    '#submit' => array('toggle_optional_fields_submit'),
    '#limit_validation_errors' => array(),
    '#weight' => -100,
  );
}

/**
 * Perform alterations on the node edit form.
 *
 * @see toggle_optional_fields_form_form_alter()
 */
function _toggle_optional_fields_alter_form(&$form, $form_state) {
  $type = $form['#entity_type'];
  $bundle = $form['#bundle'];

  array_map(function($element_name) use (&$form, $type, $bundle) {
    // Only affect fields.
    if (!toggle_optional_fields_element_is_field($element_name)) {
      return;
    }

    $element = &$form[$element_name];

    // Find any optional fields that need to be displayed.
    $overridden_fields = array();
    drupal_alter('toggle_optional_fields_overridden_fields', $overridden_fields);

    if (!empty($overridden_fields[$type][$bundle]) && in_array($element_name, $overridden_fields[$type][$bundle])) {
      return TRUE;
    }

    // If the field is not required, disallow access to hide it.
    if (isset($element[LANGUAGE_NONE][0]['#required'])) {
      return $element['#access'] = !empty($element[LANGUAGE_NONE][0]['#required']);
    }

    if (isset($element[LANGUAGE_NONE]['#required'])) {
      return $element['#access'] = !empty($element[LANGUAGE_NONE]['#required']);
    }
  }, element_children($form));
}

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
  if ($element_name == 'body') {
    return TRUE;
  }

  return substr($element_name, 0, 6) == 'field_';
}
