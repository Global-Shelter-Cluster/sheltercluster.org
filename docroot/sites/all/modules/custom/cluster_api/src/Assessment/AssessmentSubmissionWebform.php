<?php

namespace Drupal\cluster_api\Assessment;

use Drupal\cluster_api\Assessment\AssessmentSubmissionInterface;

class AssessmentSubmissionWebform implements AssessmentSubmissionInterface {

  private $user;
  private $node;
  private $webform;
  private $submission;

  /**
   * @return boolean indicating submission success;
   */
  public function saveSubmission($user, $form_id, $submission) {
    // @TODO test user permission to post on that webform.
    $this->user = $user;

    $this->node = node_load($form_id);
    if (!$this->node) {
      return ['success' => FALSE, 'message' => 'Bad form id'];
    }
    if (empty($this->node->webform)) {
      return ['success' => FALSE, 'message' => 'Not a form'];
    }
    $this->webform = $this->node->webform;
    return $this->mapSubmissionToComponents($submission);
  }

  private function mapSubmissionToComponents($submission) {
    $result = ['success' => TRUE, 'message' => 'Form submission successful'];
    $all_form_keys = [];
    $webform_data = [];

    // For each webform component, get the submitted value.
    foreach ($this->webform['components'] as $cid => $component) {
      $form_key = $component['form_key'];
      $all_form_keys[] = $form_key;

      // Test if required values are present.
      if ($component['required'] && empty($submission[$form_key])) {
        return ['success' => FALSE, 'message' => 'Missing required component ' . $form_key];
      }
      $webform_data[$cid] = [$submission[$form_key]];
    }

    // Test if submission includes values that are not supported by the webform.
    $unsuported_keys = array_diff(array_keys($submission), $all_form_keys);
    if ($unsuported_keys) {
      return ['success' => FALSE, 'message' => 'Unsuported form component: ' . implode($unsuported_keys, ', ')];
    }

    $webform_submission = (object) array(
      'nid' => $this->node->nid,
      'uid' => $this->user->uid,
      'submitted' => REQUEST_TIME,
      'remote_addr' => ip_address(),
      'is_draft' => FALSE,
      'data' => $webform_data,
    );

    module_load_include('inc', 'webform', 'includes/webform.submissions');
    webform_submission_insert($this->node, $webform_submission);
    return $result;
  }

}
