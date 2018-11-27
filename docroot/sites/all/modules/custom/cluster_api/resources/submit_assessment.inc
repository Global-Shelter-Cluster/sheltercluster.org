<?php

use Drupal\cluster_api\Oauth\Authorization;

// @file services module resource

/**
 * Handle submission of an assessment form.
 *
 * @param $form_service
 *  Service used to handle form submission. Supports 'webform'.
 * @param $form_id
 *  Identifier for the form for which the data is submitted.
 * @param $submissions_data
 *  Submitted values to store into the service.
 */
function _cluster_api_submit_assessment($form_service, $form_id, $submission) {
  $auth = new Authorization();
  $auth_response = $auth->authorize($submission);

  // Authorization failed.
  if (!$auth->isAuthorized()) {
    return $auth_response;
  }

  $user = $auth_response['user'];
  $response['authorization'] = $auth_response['authorization'];

  $response['fnord'] = 'FNORD';
  return $response;
}
