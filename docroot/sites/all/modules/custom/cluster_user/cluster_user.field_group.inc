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
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notifications',
    'weight' => '14',
    'children' => array(
      0 => 'group_notif_push',
      1 => 'group_notif_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Notifications',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-notifications field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_notifications|user|user|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Email notifications');
  t('Notifications');
  t('Push notifications');

  return $field_groups;
}
