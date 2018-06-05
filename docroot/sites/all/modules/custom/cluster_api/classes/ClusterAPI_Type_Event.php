<?php

class ClusterAPI_Type_Event extends ClusterAPI_Type {

  protected static $type = 'event';
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
    if ($node->type !== 'event')
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
