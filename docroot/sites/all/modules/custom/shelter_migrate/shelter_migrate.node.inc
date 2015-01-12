<?php

/**
 * Generates the form for the document migration pages (one for each group node).
 */
function shelter_migrate_node_form($form, &$form_state) {
  $node = menu_get_object();
  if (!og_is_group('node', $node)) {
    drupal_set_message('Not a group', 'error');
    return;
  }

  $form['alert'] = array(
    '#theme' => 'html_tag',
    '#tag' => 'div',
    '#value' => t('This page contains very dangerous operations, be careful!'),
    '#attributes' => array('class' => 'messages warning'),
  );

  $form['rss_url'] = array(
    '#type' => 'textarea',
    '#title' => t('RSS Url'),
    '#default_value' => _shelter_migrate_node_rss_url($node->nid),
  );

  $form['run'] = array(
    '#type' => 'submit',
    '#name' => 'run',
    '#value' => t('Run document import for this group'),
  );

  return $form;
}

/**
 * Run the document import.
 * @param $form
 * @param $form_state
 */
function shelter_migrate_node_form_submit($form, &$form_state) {
  if (!($url = $form_state['values']['rss_url'])) {
    drupal_set_message('URL not set or incorrect.', 'error');
    return;
  }

  $node = menu_get_object();
  _shelter_migrate_node_rss_url($node->nid, $url);

  require_once 'includes/import_group_documents.inc';
  drupal_set_message(_shelter_migrate_import_group_documents($node->nid, $url));
}

/**
 * Reads/writes the RSS url for the given group nid from/to the database.
 * @param int $nid
 *  Node ID for the group.
 * @param string|null $url
 *  If set, stores the URL in the database. Otherwise, retrieves it.
 * @return string|null
 *  The URL, or NULL if none has been saved for the given nid.
 */
function _shelter_migrate_node_rss_url($nid, $url = NULL) {
  if ($url) {
    db_merge('shelter_migrate_rss')
      ->key(array('nid' => $nid))
      ->fields(array(
        'url' => $url,
      ))
      ->execute();

    return $url;
  }
  else {
    return db_select('shelter_migrate_rss', 'r')
      ->fields('r', array('url'))
      ->condition('r.nid', $nid)
      ->execute()
      ->fetchField();
  }
}
