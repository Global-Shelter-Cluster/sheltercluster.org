<?php
/**
 * @file
 * cluster_og.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function cluster_og_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'followers';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'og_membership';
  $view->human_name = 'Followers';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '30';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: OG membership: User from OG membership */
  $handler->display->display_options['relationships']['og_membership_related_user']['id'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_membership_related_user']['field'] = 'og_membership_related_user';
  $handler->display->display_options['relationships']['og_membership_related_user']['label'] = 'user';
  $handler->display->display_options['relationships']['og_membership_related_user']['required'] = TRUE;
  /* Relationship: OG membership: OG Roles from membership */
  $handler->display->display_options['relationships']['og_users_roles']['id'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['table'] = 'og_membership';
  $handler->display->display_options['relationships']['og_users_roles']['field'] = 'og_users_roles';
  $handler->display->display_options['relationships']['og_users_roles']['label'] = 'roles';
  $handler->display->display_options['relationships']['og_users_roles']['required'] = TRUE;
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'contact_avatar';
  /* Field: Field: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_type'] = 'strong';
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['empty'] = '[name_field]';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Field: Organization name */
  $handler->display->display_options['fields']['field_organisation_name']['id'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['table'] = 'field_data_field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['field'] = 'field_organisation_name';
  $handler->display->display_options['fields']['field_organisation_name']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['field_organisation_name']['label'] = '';
  $handler->display->display_options['fields']['field_organisation_name']['element_label_colon'] = FALSE;
  /* Field: Field: Role or title */
  $handler->display->display_options['fields']['field_role_or_title']['id'] = 'field_role_or_title';
  $handler->display->display_options['fields']['field_role_or_title']['table'] = 'field_data_field_role_or_title';
  $handler->display->display_options['fields']['field_role_or_title']['field'] = 'field_role_or_title';
  $handler->display->display_options['fields']['field_role_or_title']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['field_role_or_title']['label'] = '';
  $handler->display->display_options['fields']['field_role_or_title']['element_type'] = 'em';
  $handler->display->display_options['fields']['field_role_or_title']['element_label_colon'] = FALSE;
  /* Field: Field: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['field_phone_number']['label'] = '';
  $handler->display->display_options['fields']['field_phone_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone_number']['delta_offset'] = '0';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Name (name_field) */
  $handler->display->display_options['sorts']['name_field_value']['id'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['table'] = 'field_data_name_field';
  $handler->display->display_options['sorts']['name_field_value']['field'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['relationship'] = 'og_membership_related_user';
  /* Sort criterion: User: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'users';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'og_membership_related_user';
  /* Contextual filter: OG membership: Group ID */
  $handler->display->display_options['arguments']['gid']['id'] = 'gid';
  $handler->display->display_options['arguments']['gid']['table'] = 'og_membership';
  $handler->display->display_options['arguments']['gid']['field'] = 'gid';
  $handler->display->display_options['arguments']['gid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['gid']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['gid']['default_argument_options']['index'] = '1';
  $handler->display->display_options['arguments']['gid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['gid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['gid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: OG user roles: Role Name */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'og_role';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'og_users_roles';
  $handler->display->display_options['filters']['name']['value'] = array(
    'follower' => 'follower',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'og_membership_related_user';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $translatables['followers'] = array(
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
    t('user'),
    t('roles'),
    t('[name_field]'),
    t('All'),
  );
  $export['followers'] = $view;

  return $export;
}
