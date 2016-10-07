<?php

namespace Drupal\cluster_content\RestWSFormat;

use RestWSFormatJSON;

class ClusterFormatJSON extends RestWSFormatJSON {

  /**
   * {@inheritdoc}
   */
  public function getResourceReference($resource, $id) {
    $return = parent::getResourceReference($resource, $id);

    if ($resource == 'taxonomy_term') {
      unset($return['resource']);
      unset($return['uuid']);
    }

    return $return;
  }
}
