<?php

namespace Drupal\cluster_upload\Controller;

class DragDropUploadController {

  public function __construct() {

  }

  /**
   * @return Render array.
   */
  public function build() {
    return [
      '#type' => 'markup',
      '#markup' => 'FNORD',
      '#attached' => [
        'js' => [
          'type' => 'file',
          'data' => drupal_get_path('module', 'cluster_upload') . '/js/drag_drop_upload.js',
        ],
      ],
    ];
  }

}
