<?php

namespace Drupal\cluster_upload\Controller;
use \DateTime;
use \stdClass;

class UploadDocumentController {

  /**
   * @param $gid:
   *  Group node id which is audience of document.
   * @return void
   *
   * Prints json response with the document node id.
   */
  public function handleRequest($gid) {
    if ( 0 < $_FILES['file']['error'] ) {
      echo 'Error: ' . $_FILES['file']['error'] . '<br>';
    }
    else {
      $document = NULL;
      // Test allowed file extensions.
      $allowed_extensions = field_info_instance('node', 'field_file', 'document')['settings']['file_extensions'];
      $allowed_extensions_list = explode(' ', $allowed_extensions);
      $file_extension = pathinfo($_FILES['file']['name'], PATHINFO_EXTENSION);

      header('Content-Type: application/json');
      // Extension is not allowed by field instance setting.
      if (!in_array($file_extension, $allowed_extensions_list)) {
        drupal_set_message(t("The document extension is not allowed, must be one of " . $allowed_extensions));
        echo json_encode(['document_nid' => NULL, 'status' => 'error']);
        return;
      }

      $file = $this->saveFile();
      $document = $this->createDocumentNode($file, $gid);
      if (!is_null($document)) {
        echo json_encode(['document_nid' => $document->nid, 'status' => 'ok', 'audience_gid' => $gid]);
      }
      else {
        echo json_encode(['document_nid' => NULL, 'status' => 'error']);
      }
    }
  }

  /**
   * @return instance of Drupal file interface.
   */
  private function saveFile() {
    $file_temp = file_get_contents($_FILES['file']['tmp_name']);
    return file_save_data($file_temp, 'public://' . $_FILES['file']['name']);
  }

  /**
   * Create a document node with the file attached to file_field and og audience for gid.
   *
   * @return $node
   *  Newly created document node.
   */
  private function createDocumentNode($file, $gid) {
    global $user;
    try {
      $initial_date = new DateTime();
      $file->display = 1;
      $node = new stdClass();
      $node->language = LANGUAGE_NONE;
      $node->status = 0;
      $node->uid = $user->uid;
      $node->type = 'document';
      $node->title = $file->filename;
      $node->og_group_ref[LANGUAGE_NONE][0] = [
        'target_id' => $gid,
      ];
      $node->field_language[LANGUAGE_NONE][0] = [
        'value' => 'en',
      ];
      $node->field_report_meeting_date[LANGUAGE_NONE][0] = [
        'value' => $initial_date->format('Y-m-d H:i:s'),
      ];
      $node->field_file[LANGUAGE_NONE][0] = (array) $file;
      node_save($node);
      drupal_set_message(t("Your document has been created. Please complete the document form and choose the appropriate publishing status."));
      return $node;
    }
    catch (\Exception $e) {
      drupal_set_message(t("There was an error during the document creation."));
      return NULL;
    }
  }

}
