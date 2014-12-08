<?php

/**
 *  Implements hook_form_FORM_ID_alter().
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
 *  Implements hook_menu_alter().
 */
function cluster_docs_menu_alter(&$items) {
  foreach (array('group_basic_tags', 'group_advanced_tags') as $group) {
    $path = 'admin/structure/types/manage/document/groups/'.$group.'/delete';
    $items[$path]['access callback'] = FALSE;
  }
}
