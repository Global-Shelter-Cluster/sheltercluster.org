<?php

class ClusterAPI_Type_Page extends ClusterAPI_Type {

  protected static $type = 'page';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'documents' => [
      'type' => 'document',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
  ];

  /**
   * Example:
   *
   * {
   *   _mode: OBJECT_MODE_PUBLIC,
   *   _persist: true,
   *   type: "arbitrary_library",
   *   id: 12345,
   *   title: "Some docs",
   *   body: "<p>hello</p>",
   *   url: "https://www.sheltercluster.org/response/ecuador-earthquake-2016/library/some-docs",
   *   documents: [30, 45, 123, 693],
   * }
   *
   * @param int $id
   * @param string $mode
   *
   * @return array|null
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if (!$node || !in_array($node->type, ['basic_page', 'library', 'arbitrary_library', 'photo_gallery']))
      // This id is not for a page node
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PUBLIC:
        switch ($node->type) {
          case 'library':
            $ret['is_global_library'] = (bool)$wrapper->field_is_global_library->value();
            // TODO: "search filters"
            break;
          case 'arbitrary_library':
            $ret['documents'] = self::getReferenceIds('node', $node, 'field_arbitrary_document_ref', TRUE);
            break;
          case 'photo_gallery':
            $ret['sections'] = [];

            foreach ($wrapper->field_sections as $section) {
              $s = [
                'title' => $section->field_section_title->value(),
                'description' => $section->field_section_description->value(),
                'photos' => [],
              ];

              foreach ($section->field_photos as $photo) {
                $s['photos'][] = array_filter([
                  'url_thumbnail' => self::getFileValue2('field_photo', $photo, 'photo_gallery_thumbnail'),
                  'url_medium' => self::getFileValue2('field_photo', $photo, 'photo_gallery_medium'),
                  'url_full' => self::getFileValue2('field_photo', $photo, 'photo_gallery_full'),
                  'url_original' => self::getFileValue2('field_photo', $photo),
                  'author' => $photo->field_author->value(),
                  'taken' => self::getDateValue('field_taken', $photo, 'Y-m-d'),
                  'caption' => $photo->field_caption->value(),
                ]);
              }

              $ret['sections'][] = array_filter($s);
            }
            break;
        }

        $ret += [
          'url' => url('node/' . $id, ['absolute' => TRUE]),
          'body' => $wrapper->body->value()['safe_value'],
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
        ];

      //Fall-through
      default:
        $ret += [
          'type' => $node->type,
          'title' => $node->title,
        ];
    }

    return $ret;
  }
}
