<?php

class ClusterAPI_Type_Document extends ClusterAPI_Type {

  protected static $type = 'document';
  protected static $related_def = [];

  /**
   * Example:
   *
   * {
   *   ?: "",
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'document')
      return NULL;

    $ret = [];

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

        //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:

        //Fall-through
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'title' => $node->title,
        ];
    }

    return $ret;
  }
}
