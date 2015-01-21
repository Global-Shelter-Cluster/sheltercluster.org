<?php

/**
 * Implements hook_menu_alter().
 * Replaces the regular node add pages with a custom one.
 * @see cluster_context_build_form().
 */
function cluster_context_menu_alter(&$items) {
  foreach (node_type_get_types() as $type) {
    $type_url_str = str_replace('_', '-', $type->type);
    $items['node/add/' . $type_url_str]['page callback'] = 'cluster_context_build_form';
  }
}

/**
 * Determines whether the user is using context.
 * @param array|null $form_state Optional.
 * @return bool
 */
function _cluster_context_is_being_used(&$form_state = NULL) {
  foreach (array('group', 'region', 'response') as $key) {
    if (_cluster_context_get_nid_param($key, $form_state)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Restricts access to the node/add/% pages based on the custom
 * "create nodes without cluster context" permission.
 * @param $op
 * @param $node
 * @return bool
 */
function cluster_context_node_add_access($op, $node) {
  return _cluster_context_is_being_used() || user_access('create nodes without cluster context')
    ? node_access($op, $node)
    : FALSE;
}

/**
 * Page callback for node/add/%, replaces the normal one.
 * Necessary to create multiple default values for entity reference fields,
 * when necessary.
 * @param $type
 *  Content type.
 * @return array
 *  Drupal form array.
 */
function cluster_context_build_form($type) {
  global $user;

  if (!_cluster_context_is_being_used() && !user_access('create nodes without cluster context')) {
    return drupal_access_denied();
  }

  $form_id = $type . '_node_form';
  $form_state = array();
  $form_state['build_info']['args'][] = (object) array(
    'uid' => $user->uid,
    'name' => (isset($user->name) ? $user->name : ''),
    'type' => $type,
    'language' => LANGUAGE_NONE
  );

  $form = drupal_build_form($form_id, $form_state);
  if (isset($form_state['cluster_context_prepopulate'])) {
    return $form;
  }

  if ($type === 'response' && isset($_GET['response']) && isset($form['field_associated_regions'])) {
    $response = node_load(intval($_GET['response']));
    if ($response && $response->type === 'response') {
      $response_wrapper = entity_metadata_wrapper('node', $response);
      $regions = $response_wrapper->field_associated_regions->value();
      if (count($regions) > 1) {
        // Creating a child response, and the parent response has more than one associated region.
        $form_state['field']['field_associated_regions'][LANGUAGE_NONE]['items_count'] = count($regions);
        $form_state['cluster_context_prepopulate'] = TRUE;
        drupal_static_reset('drupal_html_id');
        return drupal_rebuild_form($form_id, $form_state, $form);
      }
    }
  }

  return $form;
}

function cluster_context_redirect_home($form, &$form_state) {
  if ($form_state['nid']) {
    // The node was created successfully.
    $form_state['redirect'] = '<front>';
  }
}

/**
 * Implements hook_form_alter().
 * Prepopulates fields based on query string params.
 * For example, "?response=4" will prepopulate "field_parent_response" with the
 * response with nid == 4, if any.
 */
function cluster_context_form_alter(&$form, &$form_state, $form_id) {
  if (!preg_match('/^(.+)_node_form$/', $form_id, $matches)) {
    return;
  }
  $type = $matches[1];

  // If any of the possible query string keys is present, simplify the form.
  if (_cluster_context_is_being_used($form_state)) {
    _cluster_context_simplify_form($form);
  }

  if ($type === 'document' && !_cluster_context_is_being_used($form_state)) {
    array_push($form['actions']['submit']['#submit'], 'cluster_context_redirect_home');
  }

  _cluster_context_prepopulate($form, $form_state, 'og_group_ref', 'group');
  _cluster_context_prepopulate($form, $form_state, 'field_parent_region', 'region', 'geographic_region');
  _cluster_context_prepopulate($form, $form_state, 'field_associated_regions', 'region', 'geographic_region');
  _cluster_context_prepopulate($form, $form_state, 'field_parent_response', 'response', 'response');

  if ($type === 'response' && isset($_GET['response'])) {
    // Creating a child response, pre-populate associated regions too,
    // but don't disable the field.
    $response = node_load(intval($_GET['response']));
    if ($response && $response->type == 'response') {
      $response_wrapper = entity_metadata_wrapper('node', $response);
      $regions = $response_wrapper->field_associated_regions->value();
      _cluster_context_prepopulate($form, $form_state, 'field_associated_regions', $regions, 'geographic_region', FALSE);
    }
  }
}

function _cluster_context_simplify_form(&$form) {
  $to_hide = array(
    'comment_settings' => TRUE,       // "Comment settings" tab.
    'author' => TRUE,                 // "Authoring information" tab.
    'options' => TRUE,                // "Publishing options" tab.
    'revision_information' => TRUE,   // "Revision information" tab.
    'menu' => TRUE,                   // "Menu settings" tab.
    'path' => TRUE,                   // "URL path settings" tab.
    'language' => TRUE,               // "Language" field.
    'group_register' => FALSE,        // "Group register" field.
    'group_access' => FALSE,          // "Group visibility" field.
    'og_roles_permissions' => TRUE,   // "Group roles and permissions" field.
    'og_group_ref' => array(          // "Other groups" field.
      LANGUAGE_NONE => array(
        0 => array(
          'admin' => TRUE,
        ),
      ),
    ),
  );

  _cluster_context_hide($to_hide, $form);

  // Set node language to current language.
  if (isset($form['language'])) {
    global $language;
    $form['language']['#default_value'] = $language->language;
  }

  // Attach a CSS to hide things like the text format tips.
  $form['#attached']['css'][] = drupal_get_path('module', 'cluster_context').'/simplify.css';
}

/**
 * Recursive function to hide form elements.
 * @param array|bool $item
 *  If TRUE, hides the element received using '#access'. If FALSE, uses CSS.
 *  If an array, recursively calls on each array item.
 * @param $element
 *  Render array, it can be a form or a specific element.
 */
function _cluster_context_hide($item, &$element) {
  if ($item === TRUE) {
    // Hide using #access.
    $element['#access'] = FALSE;
    return;
  }
  elseif ($item === FALSE) {
    // Add a class to hide with CSS (less elegant but necessary in some cases).
    $element['#attributes']['class'][] = 'cluster_context_hide';
    return;
  }

  foreach ($item as $key => $child) {
    if (isset($element[$key])) {
      _cluster_context_hide($child, $element[$key]);
    }
  }
}

/**
 * Sets a form's default value for entity reference fields (only works with nodes),
 * or the special "og_group_ref" field.
 * @param $form
 *  Drupal form.
 * @param $form_state
 *  Drupal form state.
 * @param $field
 *  Field name. If the form doesn't have this field, do nothing. "og_group_ref"
 *  is a special case.
 * @param $nodes
 *  If a string, get a single nid from the query string. Otherwise, this can be
 *  a single node object or an array.
 * @param null $bundle
 *  If specified, filter nodes by content type.
 * @param bool $disable
 *  If TRUE, disables the field in the form.
 */
function _cluster_context_prepopulate(&$form, &$form_state, $field, $nodes, $bundle = NULL, $disable = TRUE) {
  if (!isset($form[$field])) {
    return;
  }

  // Prepare $nodes array.
  if (is_string($nodes)) {
    // From nid in $_GET parameter.
    $param = _cluster_context_get_nid_param($nodes, $form_state);
    if (!$param) {
      return;
    }
    $nodes = array(node_load($param));
  }
  elseif (is_object($nodes)) {
    // Received a single node object.
    $nodes = array($nodes);
  }

  // Filter nodes and prepare final list to be set in the form.
  $filtered_nodes = array();
  if ($bundle) {
    // Check each node's bundle.
    foreach ($nodes as $node) {
      if ($node->type === $bundle) {
        $filtered_nodes[] = $node;
      }
    }
  }
  elseif ($field === 'og_group_ref') {
    // Check that each node is a group and that the current user is a member.
    foreach ($nodes as $node) {
      if (og_is_group('node', $node) && og_is_member('node', $node->nid)) {
        $filtered_nodes[] = $node;
      }
    }
  }
  else {
    // No special check.
    $filtered_nodes = $nodes;
  }
  if (!$filtered_nodes) {
    return;
  }

  foreach ($filtered_nodes as $delta => $node) {
    if ($field === 'og_group_ref') {
      // Special case.
      $form[$field][LANGUAGE_NONE][$delta]['default']['#default_value'] = $node->nid;
    }
    else {
      // Entity reference field.
      $form[$field][LANGUAGE_NONE][$delta]['target_id']['#default_value'] = "$node->title ($node->nid)";
    }
  }

  if ($disable) {
    $form[$field]['#disabled'] = TRUE;
  }
}

/**
 * Loads the given parameter from the query string, and stores it in the given
 * form state array. If the value is already stored, retrieves it from $form_state.
 * This is useful for subsequent AJAX calls, which do not contain the query string
 * parameters.
 * Assumes the value is a node ID, converts the value to an integer.
 * @param $name
 *  String, name of the argument to be read.
 * @param array $form_state
 * @return int|null
 */
function _cluster_context_get_nid_param($name, &$form_state = NULL) {
  if ($form_state && isset($form_state['cluster_context_params']) && isset($form_state['cluster_context_params'][$name])) {
    // Value was found in $form_state. Return it immediately.
    return $form_state['cluster_context_params'][$name];
  }
  if (isset($_GET[$name])) {
    if ($form_state) {
      // Store the value in $form_state. Next time this is called, the value
      // is read directly from here.
      $form_state['cluster_context_params'][$name] = intval($_GET[$name]);
    }
    return intval($_GET[$name]);
  }
}
