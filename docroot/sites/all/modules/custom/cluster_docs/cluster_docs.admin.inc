<?php

/**
 * Implements hook_form_FORM_ID_alter().
 * Removes the "delete" links for the "basic tags" and "advanced tags" field groups.
 */
function cluster_docs_form_field_ui_field_overview_form_alter(&$form, &$form_state, $form_id) {
  foreach (array('group_basic_tags', 'group_advanced_tags') as $group) {
    if (isset($form['fields'][$group])) {
      $form['fields'][$group]['delete']['#access'] = FALSE;
    }
  }
}

/**
 * Implements hook_module_implements_alter().
 * Makes cluster_docs_form_field_ui_field_overview_form_alter() run after all other
 * modules, important in this case because field_group implements this alter, adding
 * the field group rows to the table.
 */
function cluster_docs_module_implements_alter(&$implementations, $hook) {
  if ($hook == 'form_alter' && isset($implementations['cluster_docs'])) {
    $group = $implementations['cluster_docs'];
    unset($implementations['cluster_docs']);
    $implementations['cluster_docs'] = $group;
  }
}

/**
 * Implements hook_menu_alter().
 * Disables the "delete" pages for the "basic tags" and "advanced tags" field groups.
 */
function cluster_docs_menu_alter(&$items) {
  foreach (array('group_basic_tags', 'group_advanced_tags') as $group) {
    $path = 'admin/structure/types/manage/document/groups/'.$group.'/delete';
    $items[$path]['access callback'] = FALSE;
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 * Adds custom validation function to the document node form.
 */
function cluster_docs_form_document_node_form_alter(&$form, &$form_state, $form_id) {
  $form['#validate'][] = 'cluster_docs_validate_link';
}

/**
 * Custom validation function for the Document node form. Forces the link to be external.
 * For example, if the user types "google.com", the link becomes "http://google.com".
 */
function cluster_docs_validate_link($form, &$form_state) {
  $node = (object) $form_state['values'];
  $wrapper = entity_metadata_wrapper('node', $node);
  $link = $wrapper->field_link->value();

  if ($link['url'] && !preg_match('/^https?:\/\//', $link['url'])) {
    $link['url'] = 'http://' . $link['url'];
    form_set_value($form['field_link'], array(LANGUAGE_NONE => array($link)), $form_state);
  }
}
