<?php
/**
 * @file
 * cluster_docs_import.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cluster_docs_import_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'document_export';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Document export';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'import documents feeds';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Preview (field_preview:fid) */
  $handler->display->display_options['relationships']['field_preview_fid']['id'] = 'field_preview_fid';
  $handler->display->display_options['relationships']['field_preview_fid']['table'] = 'field_data_field_preview';
  $handler->display->display_options['relationships']['field_preview_fid']['field'] = 'field_preview_fid';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  /* Field: Content: File */
  $handler->display->display_options['fields']['field_file']['id'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['table'] = 'field_data_field_file';
  $handler->display->display_options['fields']['field_file']['field'] = 'field_file';
  $handler->display->display_options['fields']['field_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_file']['type'] = 'file_url_plain';
  /* Field: Field: Link */
  $handler->display->display_options['fields']['field_link']['id'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['table'] = 'field_data_field_link';
  $handler->display->display_options['fields']['field_link']['field'] = 'field_link';
  $handler->display->display_options['fields']['field_link']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_link']['type'] = 'link_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Document Language */
  $handler->display->display_options['fields']['field_language']['id'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['table'] = 'field_data_field_language';
  $handler->display->display_options['fields']['field_language']['field'] = 'field_language';
  $handler->display->display_options['fields']['field_language']['settings'] = array(
    'format' => array(
      'iso' => 'iso',
      'name' => 0,
      'name_native' => 0,
    ),
  );
  /* Field: Content: Report / Meeting date */
  $handler->display->display_options['fields']['field_report_meeting_date']['id'] = 'field_report_meeting_date';
  $handler->display->display_options['fields']['field_report_meeting_date']['table'] = 'field_data_field_report_meeting_date';
  $handler->display->display_options['fields']['field_report_meeting_date']['field'] = 'field_report_meeting_date';
  $handler->display->display_options['fields']['field_report_meeting_date']['settings'] = array(
    'format_type' => 'sortable_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_document_source']['id'] = 'field_document_source';
  $handler->display->display_options['fields']['field_document_source']['table'] = 'field_data_field_document_source';
  $handler->display->display_options['fields']['field_document_source']['field'] = 'field_document_source';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_preview_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'Preview';
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: Content: Document Type */
  $handler->display->display_options['fields']['field_document_type']['id'] = 'field_document_type';
  $handler->display->display_options['fields']['field_document_type']['table'] = 'field_data_field_document_type';
  $handler->display->display_options['fields']['field_document_type']['field'] = 'field_document_type';
  /* Field: Content: Coordination Management */
  $handler->display->display_options['fields']['field_coordination_management']['id'] = 'field_coordination_management';
  $handler->display->display_options['fields']['field_coordination_management']['table'] = 'field_data_field_coordination_management';
  $handler->display->display_options['fields']['field_coordination_management']['field'] = 'field_coordination_management';
  /* Field: Content: Information Management */
  $handler->display->display_options['fields']['field_information_management']['id'] = 'field_information_management';
  $handler->display->display_options['fields']['field_information_management']['table'] = 'field_data_field_information_management';
  $handler->display->display_options['fields']['field_information_management']['field'] = 'field_information_management';
  /* Field: Content: Technical Support and Design */
  $handler->display->display_options['fields']['field_technical_support_design']['id'] = 'field_technical_support_design';
  $handler->display->display_options['fields']['field_technical_support_design']['table'] = 'field_data_field_technical_support_design';
  $handler->display->display_options['fields']['field_technical_support_design']['field'] = 'field_technical_support_design';
  /* Field: Content: Assessment, Monitoring and Evaluation */
  $handler->display->display_options['fields']['field_assess_monitor_eval']['id'] = 'field_assess_monitor_eval';
  $handler->display->display_options['fields']['field_assess_monitor_eval']['table'] = 'field_data_field_assess_monitor_eval';
  $handler->display->display_options['fields']['field_assess_monitor_eval']['field'] = 'field_assess_monitor_eval';
  /* Field: Content: Inter-Cluster */
  $handler->display->display_options['fields']['field_inter_cluster']['id'] = 'field_inter_cluster';
  $handler->display->display_options['fields']['field_inter_cluster']['table'] = 'field_data_field_inter_cluster';
  $handler->display->display_options['fields']['field_inter_cluster']['field'] = 'field_inter_cluster';
  /* Field: Content: Cross-Cutting Issues */
  $handler->display->display_options['fields']['field_cross_cutting_issues']['id'] = 'field_cross_cutting_issues';
  $handler->display->display_options['fields']['field_cross_cutting_issues']['table'] = 'field_data_field_cross_cutting_issues';
  $handler->display->display_options['fields']['field_cross_cutting_issues']['field'] = 'field_cross_cutting_issues';
  /* Field: Content: Response Phase */
  $handler->display->display_options['fields']['field_response_phase']['id'] = 'field_response_phase';
  $handler->display->display_options['fields']['field_response_phase']['table'] = 'field_data_field_response_phase';
  $handler->display->display_options['fields']['field_response_phase']['field'] = 'field_response_phase';
  /* Field: Content: Intervention Materials */
  $handler->display->display_options['fields']['field_intervention_materials']['id'] = 'field_intervention_materials';
  $handler->display->display_options['fields']['field_intervention_materials']['table'] = 'field_data_field_intervention_materials';
  $handler->display->display_options['fields']['field_intervention_materials']['field'] = 'field_intervention_materials';
  /* Field: Content: Intervention Programming */
  $handler->display->display_options['fields']['field_intervention_programming']['id'] = 'field_intervention_programming';
  $handler->display->display_options['fields']['field_intervention_programming']['table'] = 'field_data_field_intervention_programming';
  $handler->display->display_options['fields']['field_intervention_programming']['field'] = 'field_intervention_programming';
  /* Field: Content: Settlement Type */
  $handler->display->display_options['fields']['field_settlement_type']['id'] = 'field_settlement_type';
  $handler->display->display_options['fields']['field_settlement_type']['table'] = 'field_data_field_settlement_type';
  $handler->display->display_options['fields']['field_settlement_type']['field'] = 'field_settlement_type';
  /* Field: Content: Non Food Items */
  $handler->display->display_options['fields']['field_non_food_items']['id'] = 'field_non_food_items';
  $handler->display->display_options['fields']['field_non_food_items']['table'] = 'field_data_field_non_food_items';
  $handler->display->display_options['fields']['field_non_food_items']['field'] = 'field_non_food_items';
  /* Field: Content: Issues */
  $handler->display->display_options['fields']['field_issues']['id'] = 'field_issues';
  $handler->display->display_options['fields']['field_issues']['table'] = 'field_data_field_issues';
  $handler->display->display_options['fields']['field_issues']['field'] = 'field_issues';
  /* Field: Content: Toolkit */
  $handler->display->display_options['fields']['field_toolkit']['id'] = 'field_toolkit';
  $handler->display->display_options['fields']['field_toolkit']['table'] = 'field_data_field_toolkit';
  $handler->display->display_options['fields']['field_toolkit']['field'] = 'field_toolkit';
  /* Field: Content: Meeting Management */
  $handler->display->display_options['fields']['field_meeting_management']['id'] = 'field_meeting_management';
  $handler->display->display_options['fields']['field_meeting_management']['table'] = 'field_data_field_meeting_management';
  $handler->display->display_options['fields']['field_meeting_management']['field'] = 'field_meeting_management';
  /* Field: Content: Other Keywords */
  $handler->display->display_options['fields']['field_other_keywords']['id'] = 'field_other_keywords';
  $handler->display->display_options['fields']['field_other_keywords']['table'] = 'field_data_field_other_keywords';
  $handler->display->display_options['fields']['field_other_keywords']['field'] = 'field_other_keywords';
  /* Field: Content: Key Document */
  $handler->display->display_options['fields']['field_key_document']['id'] = 'field_key_document';
  $handler->display->display_options['fields']['field_key_document']['table'] = 'field_data_field_key_document';
  $handler->display->display_options['fields']['field_key_document']['field'] = 'field_key_document';
  $handler->display->display_options['fields']['field_key_document']['type'] = 'list_key';
  /* Field: Content: Featured document */
  $handler->display->display_options['fields']['field_featured']['id'] = 'field_featured';
  $handler->display->display_options['fields']['field_featured']['table'] = 'field_data_field_featured';
  $handler->display->display_options['fields']['field_featured']['field'] = 'field_featured';
  $handler->display->display_options['fields']['field_featured']['type'] = 'list_key';
  /* Field: Content: Expire featured setting */
  $handler->display->display_options['fields']['field_featured_date']['id'] = 'field_featured_date';
  $handler->display->display_options['fields']['field_featured_date']['table'] = 'field_data_field_featured_date';
  $handler->display->display_options['fields']['field_featured_date']['field'] = 'field_featured_date';
  $handler->display->display_options['fields']['field_featured_date']['settings'] = array(
    'format_type' => 'sortable_date',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Sorting weight */
  $handler->display->display_options['fields']['field_sorting_weight']['id'] = 'field_sorting_weight';
  $handler->display->display_options['fields']['field_sorting_weight']['table'] = 'field_data_field_sorting_weight';
  $handler->display->display_options['fields']['field_sorting_weight']['field'] = 'field_sorting_weight';
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_limit'] = '1';
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Document status */
  $handler->display->display_options['fields']['field_document_status']['id'] = 'field_document_status';
  $handler->display->display_options['fields']['field_document_status']['table'] = 'field_data_field_document_status';
  $handler->display->display_options['fields']['field_document_status']['field'] = 'field_document_status';
  /* Sort criterion: Content: Nid */
  $handler->display->display_options['sorts']['nid']['id'] = 'nid';
  $handler->display->display_options['sorts']['nid']['table'] = 'node';
  $handler->display->display_options['sorts']['nid']['field'] = 'nid';
  /* Contextual filter: Content: Author uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'node';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'document' => 'document',
  );

  /* Display: By user */
  $handler = $view->new_display('views_data_export', 'By user', 'by_user');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'export/user/%/documents.csv';
  $translatables['document_export'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('image from field_preview'),
    t('Path'),
    t('File'),
    t('Link'),
    t('Title'),
    t('Document Language'),
    t('Report / Meeting date'),
    t('Source'),
    t('Body'),
    t('Preview'),
    t('Document Type'),
    t('Coordination Management'),
    t('Information Management'),
    t('Technical Support and Design'),
    t('Assessment, Monitoring and Evaluation'),
    t('Inter-Cluster'),
    t('Cross-Cutting Issues'),
    t('Response Phase'),
    t('Intervention Materials'),
    t('Intervention Programming'),
    t('Settlement Type'),
    t('Non Food Items'),
    t('Issues'),
    t('Toolkit'),
    t('Meeting Management'),
    t('Other Keywords'),
    t('Key Document'),
    t('Featured document'),
    t('Expire featured setting'),
    t('Sorting weight'),
    t('Groups audience'),
    t('Document status'),
    t('All'),
    t('By user'),
  );
  $export['document_export'] = $view;

  return $export;
}
