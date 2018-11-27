<?php

namespace Drupal\cluster_api\Assessment;

interface AssessmentSubmissionInterface {

  public function saveSubmission($id, $data);

}
