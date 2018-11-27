<?php
/**
 * @file
 * cluster_api.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function cluster_api_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'mobile';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'api-v1';
  $endpoint->authentication = array();
  $endpoint->server_settings = array();
  $endpoint->resources = array(
    'follow' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'forgot' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'get-objects' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'logout' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'signup' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
    'submit-assessment' => array(
      'operations' => array(
        'create' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 1;
  $export['mobile'] = $endpoint;

  return $export;
}
