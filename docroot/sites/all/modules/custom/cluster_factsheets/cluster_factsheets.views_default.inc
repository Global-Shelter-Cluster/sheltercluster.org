<?php
/**
 * @file
 * cluster_factsheets.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cluster_factsheets_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'factsheets';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Factsheets';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Factsheets';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
    'field_date' => 'field_date',
    'og_group_ref' => 'field_date',
    'status' => 'status',
    'body' => 'body',
  );
  $handler->display->display_options['style_options']['default'] = 'field_date';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '<br>',
      'empty_column' => 0,
    ),
    'og_group_ref' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'body' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No documents found.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_publish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'skip_permission_check' => 0,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = '';
  $handler->display->display_options['fields']['edit_node']['element_label_colon'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = 'Photo';
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['label'] = 'Factsheet';
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = 'Group';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Highlights';
  $handler->display->display_options['fields']['body']['alter']['max_length'] = '400';
  $handler->display->display_options['fields']['body']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '400',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'factsheet' => 'factsheet',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Latest */
  $handler = $view->new_display('page', 'Latest', 'latest');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Latest published factsheets';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'factsheet' => 'factsheet',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Latest published factsheets */
  $handler->display->display_options['filters']['latest_published_factsheets']['id'] = 'latest_published_factsheets';
  $handler->display->display_options['filters']['latest_published_factsheets']['table'] = 'node';
  $handler->display->display_options['filters']['latest_published_factsheets']['field'] = 'latest_published_factsheets';
  $handler->display->display_options['filters']['latest_published_factsheets']['group'] = 1;
  $handler->display->display_options['path'] = 'admin/content/factsheets';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Factsheets';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Fac';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export - Latest */
  $handler = $view->new_display('views_data_export', 'Data export - Latest', 'csv_latest');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = 'Group';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Highlights';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Need analysis */
  $handler->display->display_options['fields']['field_need_analysis']['id'] = 'field_need_analysis';
  $handler->display->display_options['fields']['field_need_analysis']['table'] = 'field_data_field_need_analysis';
  $handler->display->display_options['fields']['field_need_analysis']['field'] = 'field_need_analysis';
  /* Field: Content: Response */
  $handler->display->display_options['fields']['field_fs_response']['id'] = 'field_fs_response';
  $handler->display->display_options['fields']['field_fs_response']['table'] = 'field_data_field_fs_response';
  $handler->display->display_options['fields']['field_fs_response']['field'] = 'field_fs_response';
  /* Field: Content: Gaps / challenges */
  $handler->display->display_options['fields']['field_gaps_challenges']['id'] = 'field_gaps_challenges';
  $handler->display->display_options['fields']['field_gaps_challenges']['table'] = 'field_data_field_gaps_challenges';
  $handler->display->display_options['fields']['field_gaps_challenges']['field'] = 'field_gaps_challenges';
  /* Field: Content: Figures represent: */
  $handler->display->display_options['fields']['field_household_figures']['id'] = 'field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['table'] = 'field_data_field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['field'] = 'field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['label'] = 'Figures represent';
  /* Field: Content: People per household */
  $handler->display->display_options['fields']['field_people_per_household']['id'] = 'field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['table'] = 'field_data_field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['field'] = 'field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Cluster partners */
  $handler->display->display_options['fields']['field_fsi_partners']['id'] = 'field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['table'] = 'field_data_field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['field'] = 'field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: In need */
  $handler->display->display_options['fields']['field_fsi_in_need']['id'] = 'field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['table'] = 'field_data_field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['field'] = 'field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_targeted']['id'] = 'field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['table'] = 'field_data_field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['field'] = 'field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_reached']['id'] = 'field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['table'] = 'field_data_field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['field'] = 'field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['id'] = 'field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['table'] = 'field_data_field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['field'] = 'field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['label'] = 'Targeted (NFI)';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['id'] = 'field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['table'] = 'field_data_field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['field'] = 'field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['label'] = 'Reached (NFI)';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['id'] = 'field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['table'] = 'field_data_field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['field'] = 'field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['label'] = 'Targeted (Shelter)';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['id'] = 'field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['table'] = 'field_data_field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['field'] = 'field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['label'] = 'Reached (Shelter)';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Required */
  $handler->display->display_options['fields']['field_fsi_funding_required']['id'] = 'field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['table'] = 'field_data_field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['field'] = 'field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Funded */
  $handler->display->display_options['fields']['field_fsi_funded']['id'] = 'field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['table'] = 'field_data_field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['field'] = 'field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_funding_source']['id'] = 'field_funding_source';
  $handler->display->display_options['fields']['field_funding_source']['table'] = 'field_data_field_funding_source';
  $handler->display->display_options['fields']['field_funding_source']['field'] = 'field_funding_source';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'factsheet' => 'factsheet',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Latest published factsheets */
  $handler->display->display_options['filters']['latest_published_factsheets']['id'] = 'latest_published_factsheets';
  $handler->display->display_options['filters']['latest_published_factsheets']['table'] = 'node';
  $handler->display->display_options['filters']['latest_published_factsheets']['field'] = 'latest_published_factsheets';
  $handler->display->display_options['path'] = 'data-export/factsheets.csv';
  $handler->display->display_options['displays'] = array(
    'latest' => 'latest',
    'default' => 0,
    'all' => 0,
  );

  /* Display: All */
  $handler = $view->new_display('page', 'All', 'all');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'All factsheets';
  $handler->display->display_options['path'] = 'admin/content/factsheets/all';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'All factsheets';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'a';
  $handler->display->display_options['tab_options']['weight'] = '0';

  /* Display: Data export - All */
  $handler = $view->new_display('views_data_export', 'Data export - All', 'csv_all');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Date */
  $handler->display->display_options['fields']['field_date']['id'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['table'] = 'field_data_field_date';
  $handler->display->display_options['fields']['field_date']['field'] = 'field_date';
  $handler->display->display_options['fields']['field_date']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_date']['alter']['path'] = 'node/[nid]';
  $handler->display->display_options['fields']['field_date']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_repeat_rule' => 'show',
  );
  /* Field: Content: Groups audience */
  $handler->display->display_options['fields']['og_group_ref']['id'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['table'] = 'og_membership';
  $handler->display->display_options['fields']['og_group_ref']['field'] = 'og_group_ref';
  $handler->display->display_options['fields']['og_group_ref']['label'] = 'Group';
  $handler->display->display_options['fields']['og_group_ref']['settings'] = array(
    'bypass_access' => 0,
    'link' => 1,
  );
  $handler->display->display_options['fields']['og_group_ref']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Highlights';
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Need analysis */
  $handler->display->display_options['fields']['field_need_analysis']['id'] = 'field_need_analysis';
  $handler->display->display_options['fields']['field_need_analysis']['table'] = 'field_data_field_need_analysis';
  $handler->display->display_options['fields']['field_need_analysis']['field'] = 'field_need_analysis';
  /* Field: Content: Response */
  $handler->display->display_options['fields']['field_fs_response']['id'] = 'field_fs_response';
  $handler->display->display_options['fields']['field_fs_response']['table'] = 'field_data_field_fs_response';
  $handler->display->display_options['fields']['field_fs_response']['field'] = 'field_fs_response';
  /* Field: Content: Gaps / challenges */
  $handler->display->display_options['fields']['field_gaps_challenges']['id'] = 'field_gaps_challenges';
  $handler->display->display_options['fields']['field_gaps_challenges']['table'] = 'field_data_field_gaps_challenges';
  $handler->display->display_options['fields']['field_gaps_challenges']['field'] = 'field_gaps_challenges';
  /* Field: Content: Figures represent: */
  $handler->display->display_options['fields']['field_household_figures']['id'] = 'field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['table'] = 'field_data_field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['field'] = 'field_household_figures';
  $handler->display->display_options['fields']['field_household_figures']['label'] = 'Figures represent';
  /* Field: Content: People per household */
  $handler->display->display_options['fields']['field_people_per_household']['id'] = 'field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['table'] = 'field_data_field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['field'] = 'field_people_per_household';
  $handler->display->display_options['fields']['field_people_per_household']['settings'] = array(
    'thousand_separator' => '',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Cluster partners */
  $handler->display->display_options['fields']['field_fsi_partners']['id'] = 'field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['table'] = 'field_data_field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['field'] = 'field_fsi_partners';
  $handler->display->display_options['fields']['field_fsi_partners']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: In need */
  $handler->display->display_options['fields']['field_fsi_in_need']['id'] = 'field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['table'] = 'field_data_field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['field'] = 'field_fsi_in_need';
  $handler->display->display_options['fields']['field_fsi_in_need']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_targeted']['id'] = 'field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['table'] = 'field_data_field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['field'] = 'field_fsi_targeted';
  $handler->display->display_options['fields']['field_fsi_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_reached']['id'] = 'field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['table'] = 'field_data_field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['field'] = 'field_fsi_reached';
  $handler->display->display_options['fields']['field_fsi_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['id'] = 'field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['table'] = 'field_data_field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['field'] = 'field_fsi_nfi_targeted';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['label'] = 'Targeted (NFI)';
  $handler->display->display_options['fields']['field_fsi_nfi_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['id'] = 'field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['table'] = 'field_data_field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['field'] = 'field_fsi_nfi_reached';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['label'] = 'Reached (NFI)';
  $handler->display->display_options['fields']['field_fsi_nfi_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Targeted */
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['id'] = 'field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['table'] = 'field_data_field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['field'] = 'field_fsi_shelter_targeted';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['label'] = 'Targeted (Shelter)';
  $handler->display->display_options['fields']['field_fsi_shelter_targeted']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Reached */
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['id'] = 'field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['table'] = 'field_data_field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['field'] = 'field_fsi_shelter_reached';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['label'] = 'Reached (Shelter)';
  $handler->display->display_options['fields']['field_fsi_shelter_reached']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Required */
  $handler->display->display_options['fields']['field_fsi_funding_required']['id'] = 'field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['table'] = 'field_data_field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['field'] = 'field_fsi_funding_required';
  $handler->display->display_options['fields']['field_fsi_funding_required']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Funded */
  $handler->display->display_options['fields']['field_fsi_funded']['id'] = 'field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['table'] = 'field_data_field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['field'] = 'field_fsi_funded';
  $handler->display->display_options['fields']['field_fsi_funded']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Source */
  $handler->display->display_options['fields']['field_funding_source']['id'] = 'field_funding_source';
  $handler->display->display_options['fields']['field_funding_source']['table'] = 'field_data_field_funding_source';
  $handler->display->display_options['fields']['field_funding_source']['field'] = 'field_funding_source';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Date (field_date) */
  $handler->display->display_options['sorts']['field_date_value']['id'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['table'] = 'field_data_field_date';
  $handler->display->display_options['sorts']['field_date_value']['field'] = 'field_date_value';
  $handler->display->display_options['sorts']['field_date_value']['order'] = 'DESC';
  $handler->display->display_options['path'] = 'data-export/factsheets-all.csv';
  $handler->display->display_options['displays'] = array(
    'all' => 'all',
    'default' => 0,
    'latest' => 0,
  );
  $translatables['factsheets'] = array(
    t('Master'),
    t('Factsheets'),
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
    t('No documents found.'),
    t('Content'),
    t('- Choose an operation -'),
    t('Nid'),
    t('Photo'),
    t('Factsheet'),
    t('Group'),
    t('Published'),
    t('Highlights'),
    t('Latest'),
    t('Latest published factsheets'),
    t('Data export - Latest'),
    t('Date'),
    t('Need analysis'),
    t('Response'),
    t('Gaps / challenges'),
    t('Figures represent'),
    t('People per household'),
    t('Cluster partners'),
    t('In need'),
    t('Targeted'),
    t('Reached'),
    t('Targeted (NFI)'),
    t('Reached (NFI)'),
    t('Targeted (Shelter)'),
    t('Reached (Shelter)'),
    t('Required'),
    t('Funded'),
    t('Source'),
    t('All'),
    t('All factsheets'),
    t('Data export - All'),
  );
  $export['factsheets'] = $view;

  return $export;
}
