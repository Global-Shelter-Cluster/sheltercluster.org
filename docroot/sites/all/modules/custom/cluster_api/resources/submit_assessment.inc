<?php

use Drupal\cluster_api\Assessment\AssessmentSubmissionFactory;
use Drupal\cluster_api\Oauth\Authorization;

// @file services module resource

/**
 * Handle submission of an assessment form.
 *
 * @param $form_service
 *  Service used to handle form submission. Supports 'webform'.
 * @param $form_id
 *  Identifier for the form for which the data is submitted.
 * @param $request
 *  Submitted values to store into the service and Authorization credentials if not bearing token.
 *  Assessment is expected to be an object where the key matches 'form_key'.
 *  {
 *    "assessment": {
 *      "other_value": "fnord",
 *      "test_123": 42
 *    },
 *    "credentials": {...}
 *  }
 */
function _cluster_api_submit_assessment($form_service, $form_id, $request) {
  if (empty($request['assessment'])) {
    return services_error('Assessment form submission unacceptable', 403);
  }

  $auth = new Authorization();
  $auth_response = $auth->authorize($request);

  // Authorization failed.
  if (!$auth->isAuthorized()) {
    return services_error($auth->getErrorMessage(), $auth->getResponseCode());
  }

  $user = $auth->getUser();
  $response['authorization'] = $auth->getAuthorization();

  $assessment_submission = AssessmentSubmissionFactory::createInstance($form_service);
  $result = $assessment_submission->saveSubmission($user, $form_id, $request['assessment']);
  if (!$result['success']) {
    $response['assessment_errors'] = $result['message'];
  }

  return $response;
}
