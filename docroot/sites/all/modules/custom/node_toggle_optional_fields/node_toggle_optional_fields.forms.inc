<?php


/**
 * Custom submit handler for the node form.
 *
 * @see node_toggle_optional_fields_form_node_form_alter()
 */
function node_toggle_optional_fields_submit($form, &$form_state) {
  $form_state['storage']['hide_optional_fields'] = empty($form_state['storage']['hide_optional_fields']);

  $form_state['rebuild'] = TRUE;
}

/**
 * Prepare the form and add the toggle button.
 *
 * @see node_toggle_optional_fields_form_node_form_alter()
 */
function _node_toggle_optional_fields_prepare_form(&$form, &$form_state) {
  if (!isset($form_state['storage']['hide_optional_fields'])) {
    $form_state['storage']['hide_optional_fields'] = variable_get('node_toggle_optional_fields_hide_by_default', TRUE);
  }

  $hidden = $form_state['storage']['hide_optional_fields'];

  $form['toggle_optional_fields'] = array(
    '#type' => 'submit',
    '#value' => t('!action optional fields', array('!action' => $hidden ? 'Show' : 'Hide')),
    '#submit' => array('node_toggle_optional_fields_submit'),
    '#limit_validation_errors' => array(),
    '#weight' => -100,
  );
}

/**
 * Perform alterations on the node edit form.
 *
 * @see node_toggle_optional_fields_form_node_form_alter()
 */
function _node_toggle_optional_fields_alter_form(&$form, $form_state) {
  array_map(function($element_name) use (&$form) {
    // Only affect fields.
    if (substr($element_name, 0, 6) !== 'field_') {
      return;
    }

    // If the field is not required, disallow access to hide it.
    if (empty($form[$element_name][LANGUAGE_NONE][0]['#required'])) {
      $form[$element_name]['#access'] = FALSE;
    }
  }, element_children($form));
}
