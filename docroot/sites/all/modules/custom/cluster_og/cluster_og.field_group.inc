<?php
/**
 * @file
 * cluster_og.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cluster_og_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|community_of_practice|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_of_practice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '37',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|community_of_practice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|geographic_region|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'geographic_region';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '35',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|geographic_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|hub|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '37',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|response|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'response';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '37',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|response|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|strategic_advisory|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategic_advisory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '37',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|strategic_advisory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_discussions|node|working_group|form';
  $field_group->group_name = 'group_discussions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'working_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Discussions',
    'weight' => '15',
    'children' => array(
      0 => 'field_email_address_identifier',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Discussions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-discussions field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_discussions|node|working_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|community_of_practice|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'community_of_practice';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '10',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|community_of_practice|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|geographic_region|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'geographic_region';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '14',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|geographic_region|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|hub|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'hub';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '13',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|hub|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|response|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'response';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '26',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|response|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|strategic_advisory|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'strategic_advisory';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '20',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|strategic_advisory|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_email_subs|node|working_group|form';
  $field_group->group_name = 'group_email_subs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'working_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Email subscriptions',
    'weight' => '14',
    'children' => array(
      0 => 'field_enable_email_subscriptions',
      1 => 'field_subscribers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Email subscriptions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-email-subs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_email_subs|node|working_group|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Discussions');
  t('Email subscriptions');

  return $field_groups;
}
