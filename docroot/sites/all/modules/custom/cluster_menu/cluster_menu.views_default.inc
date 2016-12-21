<?php
/**
 * @file
 * cluster_menu.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cluster_menu_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'mega_menu';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Mega Menu';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = 'nav-item';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '30';

  /* Display: Africa */
  $handler = $view->new_display('block', 'Africa', 'block_1');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '30';

  /* Display: Americas */
  $handler = $view->new_display('block', 'Americas', 'block_2');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '62';

  /* Display: Asia Pacific */
  $handler = $view->new_display('block', 'Asia Pacific', 'block_3');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '74';

  /* Display: Europe */
  $handler = $view->new_display('block', 'Europe', 'block_4');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '114';

  /* Display: MENA */
  $handler = $view->new_display('block', 'MENA', 'block_5');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '117';

  /* Display: Pacific */
  $handler = $view->new_display('block', 'Pacific', 'block_6');
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    'geographic_region' => 'geographic_region',
  );
  /* Filter criterion: Content: Region (field_parent_region) */
  $handler->display->display_options['filters']['field_parent_region_target_id']['id'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['table'] = 'field_data_field_parent_region';
  $handler->display->display_options['filters']['field_parent_region_target_id']['field'] = 'field_parent_region_target_id';
  $handler->display->display_options['filters']['field_parent_region_target_id']['value']['value'] = '97';
  $translatables['mega_menu'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Africa'),
    t('Americas'),
    t('Asia Pacific'),
    t('Europe'),
    t('MENA'),
    t('Pacific'),
  );
  $export['mega_menu'] = $view;

  return $export;
}
