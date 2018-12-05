<?php

namespace Drupal\cluster_api\Assessment;

interface AssessmentSubmissionInterface {

  public function saveSubmission($user, $form_id, $submission_data);

}
