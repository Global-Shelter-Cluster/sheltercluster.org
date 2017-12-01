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
  $field_group->parent_name = 'group_tags';
  $field_group->data = array(
    'label' => 'Advanced tags',
    'weight' => '17',
    'children' => array(
      0 => 'field_assess_monitor_eval',
      1 => 'field_cross_cutting_issues',
      2 => 'field_inter_cluster',
      3 => 'field_intervention_materials',
      4 => 'field_intervention_programming',
      5 => 'field_issues',
      6 => 'field_non_food_items',
      7 => 'field_response_phase',
      8 => 'field_settlement_type',
      9 => 'field_toolkit',
      10 => 'field_meeting_management',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
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
  $field_group->parent_name = 'group_tags';
  $field_group->data = array(
    'label' => 'Basic tags',
    'weight' => '16',
    'children' => array(
      0 => 'field_coordination_management',
      1 => 'field_information_management',
      2 => 'field_technical_support_design',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
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
    'weight' => '7',
    'children' => array(
      0 => 'group_document_source',
      1 => 'group_document_settings',
      2 => 'group_document_og',
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
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_og|node|document|form';
  $field_group->group_name = 'group_document_og';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Group settings',
    'weight' => '15',
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
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_document_settings|node|document|form';
  $field_group->group_name = 'group_document_settings';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_document_metadata';
  $field_group->data = array(
    'label' => 'Document settings',
    'weight' => '14',
    'children' => array(
      0 => 'field_key_document',
      1 => 'field_featured',
      2 => 'field_sorting_weight',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-document-settings field-group-tab',
        'required_fields' => 1,
      ),
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
    'label' => 'Document source',
    'weight' => '13',
    'children' => array(
      0 => 'field_file',
      1 => 'field_link',
      2 => 'field_document_source',
      3 => 'field_report_meeting_date',
      4 => 'field_language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-document-source field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_document_source|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
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
      0 => 'field_document_type',
    ),
    'format_type' => 'htab',
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
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
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
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-keywords field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_keywords|node|document|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tags|node|document|form';
  $field_group->group_name = 'group_tags';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'document';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tags',
    'weight' => '8',
    'children' => array(
      0 => 'group_advanced_tags',
      1 => 'group_basic_tags',
      2 => 'group_document_type',
      3 => 'group_keywords',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-tags field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tags|node|document|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced tags');
  t('Basic tags');
  t('Document details');
  t('Document settings');
  t('Document source');
  t('Document type');
  t('Group settings');
  t('Keywords');
  t('Tags');

  return $field_groups;
}
