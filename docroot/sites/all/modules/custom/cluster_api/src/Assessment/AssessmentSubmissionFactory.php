<?php

namespace Drupal\cluster_api\Assessment;

use Drupal\cluster_api\Assessment\AssessmentSubmissionWebform;

class AssessmentSubmissionFactory {

  public static function createInstance($type) {
    switch ($type) {
      case 'webform':
        return new AssessmentSubmissionWebform();
      default:
        return new AssessmentSubmissionNull();
    }
  }

}
