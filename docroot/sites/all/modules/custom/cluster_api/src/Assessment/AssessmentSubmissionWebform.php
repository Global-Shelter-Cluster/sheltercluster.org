<?php

namespace Drupal\cluster_api\Assessment;

use Drupal\cluster_api\Assessment\AssessmentSubmissionInterface;

class AssessmentSubmissionWebform implements AssessmentSubmissionInterface {

  private $user;
  private $node;
  private $webform;
  private $submission;

  /**
   * @return array;
   * @throws \Exception
   */
  public function saveSubmission($user, $form_id, $submission) {
    $this->user = $user;

    $this->node = node_load($form_id);

    // If the user is follower of at least one group in which this form is posted, allow.
    $user_is_follower = FALSE;
    if (!isset($this->node->og_group_ref)) {
      return ['success' => FALSE, 'message' => t('Form not in a group')];
    }
    foreach ($this->node->og_group_ref[LANGUAGE_NONE] as $group_id) {
      $roles = og_get_user_roles('node', $group_id['target_id'], $this->user->uid);
      if (in_array('follower', $roles)) {
        $user_is_follower = TRUE;
        break;
      }
    }

    // 2019-04-11: We're removing this requirement (as per SA-70)
//    if (!$user_is_follower) {
//      return ['success' => FALSE, 'message' => t('User is not group follower')];
//    }

    if (!$this->node) {
      return ['success' => FALSE, 'message' => t('Bad form id')];
    }
    if (empty($this->node->webform)) {
      return ['success' => FALSE, 'message' => t('Not a form')];
    }
    $this->webform = $this->node->webform;
    return $this->mapSubmissionToComponents($submission);
  }

  private function mapSubmissionToComponents($submission) {
    $result = ['success' => TRUE, 'message' => t('Form submission successful')];
    $all_form_keys = [];
    $webform_data = [];

    // For each webform component, get the submitted value.
    foreach ($this->webform['components'] as $cid => $component) {
      $form_key = $component['form_key'];
      $all_form_keys[] = $form_key;

      // Test if required values are present.
      if ($component['required'] && empty($submission[$form_key])) {
        return ['success' => FALSE, 'message' => t('@field is required', ['@field' => $component['name']])];
      }

      switch ($component['type']) {
        case 'file':
          if (!$submission[$form_key])
            break;

          $fid = _cluster_api_receive_file($submission[$form_key], 'public://webform/' . date('Y-m'), $form_key);
          $webform_data[$cid] = [$fid];

          break;

        // Submissions are nested too deeply in select.
        case 'select':
          $webform_data[$cid] = [$submission[$form_key]][0];
          break;

        case 'geolocation':
          $webform_data[$cid] = $submission[$form_key];
          break;

        default:
          $webform_data[$cid] = [$submission[$form_key]];
      }
    }

    // Test if submission includes values that are not supported by the webform.
    $unsuported_keys = array_diff(array_keys($submission), $all_form_keys);
    if ($unsuported_keys) {
      return ['success' => FALSE, 'message' => t('Form submission contains inputs that are not defined in the form')];
    }

    module_load_include('inc', 'webform', 'includes/webform.submissions');
//    $webform_data = _webform_client_form_submit_flatten($this->node, $webform_data);
    $webform_data = webform_submission_data($this->node, $webform_data);

    $webform_submission = (object)array(
      'nid' => $this->node->nid,
      'uid' => $this->user->uid,
      'submitted' => REQUEST_TIME,
      'remote_addr' => ip_address(),
      'is_draft' => FALSE,
      'data' => $webform_data,
    );


    webform_submission_insert($this->node, $webform_submission);
    return $result;
  }

}
