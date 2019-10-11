<?php
/**
 * @file
 * cluster_user.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_user_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|user|user|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Administrators only',
    'weight' => '51',
    'children' => array(
      0 => 'og_user_node1',
      1 => 'field_account_origin',
      2 => 'field_push_token',
      3 => 'googleanalytics',
      4 => 'redirect',
      5 => 'wysiwyg',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Administrators only',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-admin',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_admin|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_groups|user|user|form';
  $field_group->group_name = 'group_groups';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Groups',
    'weight' => '49',
    'children' => array(),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Groups',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-groups',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_groups|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notif_email|user|user|form';
  $field_group->group_name = 'group_notif_email';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_notifications';
  $field_group->data = array(
    'label' => 'Email notifications',
    'weight' => '44',
    'children' => array(
      0 => 'field_notif_email_daily',
      1 => 'field_notif_email_weekly',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email notifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-notif-email field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_notif_email|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notif_push|user|user|form';
  $field_group->group_name = 'group_notif_push';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_notifications';
  $field_group->data = array(
    'label' => 'Push notifications',
    'weight' => '43',
    'children' => array(
      0 => 'field_notif_push_daily',
      1 => 'field_notif_push_upcevents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Push notifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-notif-push field-group-fieldset',
        'description' => 'Only applicable if logged into the Shelter Cluster mobile app.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_notif_push|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notifications|user|user|form';
  $field_group->group_name = 'group_notifications';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Notifications',
    'weight' => '50',
    'children' => array(
      0 => 'group_notif_email',
      1 => 'group_notif_push',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Notifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-notifications',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_notifications|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preferences|user|user|form';
  $field_group->group_name = 'group_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '47',
    'children' => array(
      0 => 'timezone',
      1 => 'locale',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-preferences',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_preferences|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile|user|user|form';
  $field_group->group_name = 'group_profile';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'Profile',
    'weight' => '46',
    'children' => array(
      0 => 'field_organisation_name',
      1 => 'field_phone_number',
      2 => 'field_role_or_title',
      3 => 'field_full_name',
      4 => 'picture',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Profile',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-profile',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_profile|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tabs|user|user|form';
  $field_group->group_name = 'group_tabs';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '2',
    'children' => array(
      0 => 'group_admin',
      1 => 'group_groups',
      2 => 'group_notifications',
      3 => 'group_preferences',
      4 => 'group_profile',
      5 => 'group_user',
    ),
    'format_type' => 'accordion',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'effect' => 'none',
        'classes' => '',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tabs|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_user|user|user|form';
  $field_group->group_name = 'group_user';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_tabs';
  $field_group->data = array(
    'label' => 'User and security',
    'weight' => '48',
    'children' => array(
      0 => 'account',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'User and security',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'section-user',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_user|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Administrators only');
  t('Email notifications');
  t('Groups');
  t('Notifications');
  t('Preferences');
  t('Profile');
  t('Push notifications');
  t('Tabs');
  t('User and security');

  return $field_groups;
}
