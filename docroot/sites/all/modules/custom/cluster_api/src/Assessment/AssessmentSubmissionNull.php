<?php

namespace Drupal\cluster_api\Assessment;

use Drupal\cluster_api\Assessment\AssessmentSubmissionInterface;

class AssessmentSubmissionNull implements AssessmentSubmissionInterface {

  public function saveSubmission($user, $form_id, $submission_data) {
    return NULL;
  }

}
