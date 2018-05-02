<?php
/**
 * @file
 * cluster_events.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_events_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_contact|node|event|form';
  $field_group->group_name = 'group_event_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_field_group';
  $field_group->data = array(
    'label' => 'Contact',
    'weight' => '12',
    'children' => array(
      0 => 'field_event_contact',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_contact|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_content_details|node|event|form';
  $field_group->group_name = 'group_event_content_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_field_group';
  $field_group->data = array(
    'label' => 'Event content details',
    'weight' => '9',
    'children' => array(
      0 => 'body',
      1 => 'field_event_files',
      2 => 'title_field',
      3 => 'field_sorting_weight',
      4 => 'date_repeat_entity_clone_state',
      5 => 'date_repeat_entity_master_uuid',
      6 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-content-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_content_details|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_date_group|node|event|form';
  $field_group->group_name = 'group_event_date_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_field_group';
  $field_group->data = array(
    'label' => 'Event date',
    'weight' => '10',
    'children' => array(
      0 => 'field_recurring_event_date2',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-date-group field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_date_group|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_field_group|node|event|form';
  $field_group->group_name = 'group_event_field_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Event field groups',
    'weight' => '0',
    'children' => array(
      0 => 'group_event_contact',
      1 => 'group_event_content_details',
      2 => 'group_event_date_group',
      3 => 'group_event_group_audience',
      4 => 'group_event_location',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-event-field-group field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_event_field_group|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_group_audience|node|event|form';
  $field_group->group_name = 'group_event_group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_field_group';
  $field_group->data = array(
    'label' => 'Event group audience',
    'weight' => '11',
    'children' => array(
      0 => 'og_group_ref',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-group-audience field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_group_audience|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_event_location|node|event|form';
  $field_group->group_name = 'group_event_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_event_field_group';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '8',
    'children' => array(
      0 => 'field_coordinates',
      1 => 'field_postal_address',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-event-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_event_location|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact');
  t('Event content details');
  t('Event date');
  t('Event field groups');
  t('Event group audience');
  t('Location');

  return $field_groups;
}
