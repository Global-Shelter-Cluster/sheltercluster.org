<?php

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
function _cluster_api_submit_assessment($form_service, $form_id, $submission_data) {
  return json_encode($form_service);
}
