<?php
/**
 * @file
 * cluster_docs.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_docs_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced_tags|node|document|form';
  $field_group->group_name = 'group_advanced_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced tags',
    'weight' => '27',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_advanced_tags|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_tags|node|document|form';
  $field_group->group_name = 'group_basic_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Basic tags',
    'weight' => '6',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_basic_tags|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_metadata|node|document|form';
  $field_group->group_name = 'group_document_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Document details',
    'weight' => '1',
    'children' => array(
      0 => 'group_document_settings',
      1 => 'group_document_source',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'label' => 'Document details',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
      ),
    ),
  );
  $field_groups['group_document_metadata|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_og|node|document|form';
  $field_group->group_name = 'group_document_og';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Group settings',
    'weight' => '8',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-document-og field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_document_og|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_page_content|node|document|form';
  $field_group->group_name = 'group_document_page_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Document page content',
    'weight' => '6',
    'children' => array(
      0 => 'field_preview',
      1 => 'body',
      2 => 'title_field',
      3 => 'field_image',
      4 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_document_page_content|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_settings|node|document|form';
  $field_group->group_name = 'group_document_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '8',
    'children' => array(
      0 => 'field_key_document',
      1 => 'og_group_ref',
      2 => 'field_featured',
      3 => 'field_sorting_weight',
      4 => 'field_featured_date',
      5 => 'field_document_status',
      6 => 'redirect',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-document-settings field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_document_settings|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_source|node|document|form';
  $field_group->group_name = 'group_document_source';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Document',
    'weight' => '5',
    'children' => array(
      0 => 'field_assess_monitor_eval',
      1 => 'field_coordination_management',
      2 => 'field_cross_cutting_issues',
      3 => 'field_document_source',
      4 => 'field_information_management',
      5 => 'field_inter_cluster',
      6 => 'field_intervention_materials',
      7 => 'field_intervention_programming',
      8 => 'field_issues',
      9 => 'field_non_food_items',
      10 => 'field_preview',
      11 => 'field_report_meeting_date',
      12 => 'field_response_phase',
      13 => 'field_settlement_type',
      14 => 'field_technical_support_design',
      15 => 'field_toolkit',
      16 => 'body',
      17 => 'title_field',
      18 => 'field_document_type',
      19 => 'field_other_keywords',
      20 => 'field_meeting_management',
      21 => 'field_image',
      22 => 'field_language',
      23 => 'group_source',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Document',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-document-source field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_document_source|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_type|node|document|form';
  $field_group->group_name = 'group_document_type';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tags';
  $field_group->data = array(
    'label' => 'Document type',
    'weight' => '15',
    'children' => array(
      0 => 'field_coordination_management',
      1 => 'field_information_management',
      2 => 'field_technical_support_design',
      3 => 'field_document_type',
      4 => 'group_basic_tags',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_document_type|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_keywords|node|document|form';
  $field_group->group_name = 'group_keywords';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tags';
  $field_group->data = array(
    'label' => 'Keywords',
    'weight' => '18',
    'children' => array(
      0 => 'field_other_keywords',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_keywords|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_source|node|document|form';
  $field_group->group_name = 'group_source';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_source';
  $field_group->data = array(
    'label' => 'Document source',
    'weight' => '47',
    'children' => array(
      0 => 'field_file',
      1 => 'field_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Document source',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-source field-group-fieldset',
        'description' => 'Choose either an uploaded file or link for your document.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_source|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|document|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '3',
    'children' => array(
      0 => 'group_advanced_tags',
      1 => 'group_document_type',
      2 => 'group_keywords',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tags|node|document|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Advanced tags');
  t('Basic tags');
  t('Document');
  t('Document details');
  t('Document page content');
  t('Document source');
  t('Document type');
  t('Group settings');
  t('Keywords');
  t('Tags');

  return $field_groups;
}
