<?php

namespace Cluster;

class Content extends \SearchApiAttachmentsAlterSettings {
  public function __construct(\SearchApiIndex $index = NULL, array $options = []) {
  }

  public static function getFileContents($file) {
    $temp = new Content();
    return $temp->getFileContent($file);
  }
}
