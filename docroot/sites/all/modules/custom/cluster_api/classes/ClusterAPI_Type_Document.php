<?php

class ClusterAPI_Type_Document extends ClusterAPI_Type {

  protected static $type = 'document';
  protected static $related_def = [
    'publisher' => [
      'type' => 'user',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  /**
   * Example:
   *
   * {
   *   changed: "2016-05-02T08:22:29+00:00", // ISO 8601
   *   title: "Humanitarian Guidance note: CASH TRANSFER PROGRAMMING",
   *   publisher: 300, // user id
   *   groups: [8616], // group(s) the document belongs to
   *   date: "2016-04-01",
   *   // TODO: taxonomy
   *   file: "http://path/to/file.pdf",
   *   link: "http://external/link", // the object has either "file" or "link"
   *   source: "DFID",
   *   language: "English",
   *   featured: true,
   *   key: false,
   *   preview: "http://path/to/thumbnail.jpg",
   *   description: "<p>document description</p>",
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'document')
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);

    if (!$node->field_file && !$node->field_link)
      // Document has neither a file nor a link, so it's useless.
      return NULL;

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

        //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        if ($node->field_file)
          $ret['file'] = self::getFileValue('field_file', $wrapper);
        else
          $ret['link'] = $wrapper->field_link->value(); // TODO: check if this works

      //Fall-through
      case ClusterAPI_Object::MODE_STUB:
        $ret += [
          'changed' => self::getDateValue($node->changed),
          'title' => $node->title,
          'publisher' => $node->uid,
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
          'date' => self::getDateValue('field_report_meeting_date', $wrapper, 'Y-m-d'),
          'preview' => self::getFileValue('field_preview', $wrapper, 'medium'),
        ];
    }

    return $ret;
  }
}
