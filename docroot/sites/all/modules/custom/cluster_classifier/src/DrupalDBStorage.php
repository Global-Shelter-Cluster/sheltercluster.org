<?php

namespace Cluster;

use Documer\Storage\Adapter;

class DrupalDBStorage implements Adapter {

  public function getDistinctLabels() {
    return db_select('cluster_classifier_labels', 'l')
      ->fields('l')
      ->distinct()
      ->execute()
      ->fetchCol();
  }

  public function getWordCount($word) {
    return intval(db_select('cluster_classifier_words')
      ->condition('word', $word)
      ->countQuery()
      ->execute()
      ->fetchField());
  }

  public function getWordProbabilityWithLabel($word, $label) {
    return intval(db_select('cluster_classifier_words')
      ->condition('word', $word)
      ->condition('tid', $label)
      ->countQuery()
      ->execute()
      ->fetchField());
  }

  public function getInverseWordProbabilityWithLabel($word, $label) {
    return intval(db_select('cluster_classifier_words')
      ->condition('word', $word)
      ->condition('tid', $label, '<>')
      ->countQuery()
      ->execute()
      ->fetchField());
  }

  public function insertLabel($label) {
    db_insert('cluster_classifier_labels')
      ->fields(['tid' => $label])
      ->execute();
  }

  public function insertWord($word, $label) {
    db_insert('cluster_classifier_words')
      ->fields(['word' => $word, 'tid' => $label])
      ->execute();
  }

  public function clearAllData() {
    db_delete('cluster_classifier_words')->execute();
    db_delete('cluster_classifier_labels')->execute();
  }

  public function getStats() {
    return [
      'words' => intval(db_select('cluster_classifier_words')
        ->countQuery()
        ->execute()
        ->fetchField()),
      'labels' => intval(db_select('cluster_classifier_labels')
        ->countQuery()
        ->execute()
        ->fetchField()),
    ];
  }
}
