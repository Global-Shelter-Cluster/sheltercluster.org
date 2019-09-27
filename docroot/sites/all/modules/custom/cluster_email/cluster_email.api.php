<?php

function hook_daily_email_notification_objects_alter(&$objects_by_gid) {
  $gid = 100; // a node id for which this is TRUE: og_is_group('node', node_load($gid))

  $document_nid = 200; // a node id for a document that was created within the last 24 hours

  $objects_by_gid[$gid]['cluster_docs'][] = $document_nid;
}

function hook_weekly_email_notification_objects_alter(&$objects_by_gid) {
  $gid = 100; // a node id for which this is TRUE: og_is_group('node', node_load($gid))

  $document_nid = 200; // a node id for a document that was created within the last 7 days

  $objects_by_gid[$gid]['cluster_docs'][] = $document_nid;
}

//function hook_cluster_email_objects_label($ids, $langcode) {
//  return format_plural(count($ids), 'a document', '@count documents', [], ['langcode' => $langcode]);
//}
//
//function hook_cluster_email_object_title($id, $langcode) {
//  $node = node_load($id);
//  return $node->title;
//}
//
//function hook_cluster_email_weight() {
//  return 10;
//}

function hook_cluster_email_render_data($ids, $langcode) {

}
