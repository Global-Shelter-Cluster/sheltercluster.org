<?php

namespace Drupal\cluster_upload\Controller;
use \DateTime;
use \stdClass;

class UploadDocumentController {

  /**
   * @param $gid:
   *  Group node id which is audience of document.
   * @return json response with the document node id.
   */
  public function handleRequest($gid) {
    if ( 0 < $_FILES['file']['error'] ) {
      echo 'Error: ' . $_FILES['file']['error'] . '<br>';
    }
    else {
      $file_temp = file_get_contents($_FILES['file']['tmp_name']);
      $file = $this->saveFile();
      $document = $this->createDocumentNode($file, $gid);
      header('Content-Type: application/json');
      echo json_encode(['document_nid' => $document->nid]);
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
    $initial_date = new DateTime();
    $file->display = 1;
    $node = new stdClass();
    $node->status = 0;
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
    return $node;
  }

}
