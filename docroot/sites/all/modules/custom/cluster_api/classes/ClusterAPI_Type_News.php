<?php

class ClusterAPI_Type_News extends ClusterAPI_Type {

  protected static $type = 'news';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'news')
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $ret += [
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
          'content' => cluster_paragraphs_render_email_content($wrapper->field_content->value()),
          'url' => url('node/' . $id, ['absolute' => TRUE]),
        ];

      //Fall-through
      default:
        $ret += [
          'title' => $node->title,
          'date' => self::getDateValue('field_news_date', $wrapper, 'Y-m-d'),
        ];
    }

    return $ret;
  }
}
