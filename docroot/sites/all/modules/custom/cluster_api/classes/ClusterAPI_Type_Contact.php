<?php

class ClusterAPI_Type_Contact extends ClusterAPI_Type {

  protected static $type = 'contact';
  protected static $related_def = [
    'groups' => [
      'type' => 'group',
      'mode' => ClusterAPI_Object::MODE_STUB,
    ],
    'user' => [
      'type' => 'user',
      'mode' => ClusterAPI_Object::MODE_PUBLIC,
    ],
  ];

  /**
   * Example:
   *
   * {
   *   _mode: OBJECT_MODE_PUBLIC,
   *   _persist: true,
   *   id: 9415,
   *   name: "Leeanne Marshall",
   *   picture: "https://www.sheltercluster.org/.../image.jpg",
   *   org: "International Federation of Red Crosses",
   *   role: "Coordinator",
   *   mail: ["coord1.ecuador@sheltercluster.org"],
   *   phone: ["+1 555 1234 567"],
   *   bio: "<p>html bio text</p>",
   *   groups: [9175, 10318],
   *   user: 123, // TODO
   * }
   *
   */
  protected function generateObject($id, $mode) {
    $node = node_load($id);
    if ($node->type !== 'contact')
      return NULL;

    $ret = [];
    $wrapper = entity_metadata_wrapper('node', $node);

    switch ($mode) {
      case ClusterAPI_Object::MODE_PRIVATE:

      //Fall-through
      case ClusterAPI_Object::MODE_PUBLIC:
        $ret += [
          'groups' => self::getReferenceIds('node', $node, 'og_group_ref', TRUE),
          // TODO: add a user ref field and a "user" value (single int) to $ret
        ];

      //Fall-through
      default:
        $ret += [
          'name' => $node->title,
          'picture' => self::getFileValue('field_image', $wrapper, 'contact_avatar'),
          'org' => $wrapper->field_organisation_name->value(),
          'role' => $wrapper->field_role_or_title->value(),
          'mail' => $wrapper->field_email->value(),
          'phone' => $wrapper->field_phone_number->value(),
          'bio' => $wrapper->body->value()['safe_value'],
        ];
    }

    return $ret;
  }
}
