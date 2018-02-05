<?php

namespace Cluster;

use AlgoliaSearch\Client;
use Documer\Documer;
use Documer\Storage\Memory;

class Classifier {
  const QUERY_RESULTS_PER_PAGE = 200;
  const LIMIT_TERMS_INITIAL = 10; // How many terms to load from the classifier
  const LIMIT_TERMS_FINAL = 3; // How many terms to show to the user (advanced tags get preference, etc.)
  const LIMIT_PERCENTAGE = 0; // If zero, doesn't limit by percentage
  const LIMIT_CHARS = 1000; // If title+body has less than this, we'll use the file content

  /** @var array */
  private $config;

  /** @var \Documer\Documer */
  private $documer;

  /** @var \Cluster\DrupalDBStorage */
  private $storage;

  /** @var \SearchApiIndex */
  private $index;

  /**
   * Key is field name in Algolia, value is a function that receives a node object and returns the string for that field.
   * @var array
   */
  private $text_fields = [];

  /**
   * @var array
   *
   * E.g. [
   *   'field_document_type' => [
   *     'Coordination management' => 123,
   *     'Technical support and design' => 124,
   *     ...
   *   ],
   *   ...
   * ]
   */
  private $term_mapping = NULL;

  public function __construct($config = []) {
    $this->config = $config;
    $this->storage = new DrupalDBStorage();
    $this->documer = new Documer($this->storage);
    $this->index = search_api_index_load($config['search_api_index']);

    $this->text_fields = [
      'title' => function($node) {
        return $node->title;
      },
      'body:value' => function($node) {
        return strip_tags($node->body[LANGUAGE_NONE][0]['value']);
      },
      'attachments_field_file' => function($node) {
        //TODO: implement
        return '';
      },
    ];
  }

  private function initTermMapping() {
    if (!is_null($this->term_mapping))
      return;

    $taxonomy_field_vocabulary_mapping = [];
    foreach (cluster_docs_taxonomies(FALSE) as $field) {
      $field_info = field_info_field($field);
      if (isset($field_info['settings']['allowed_values'][0]['vocabulary'])) {
        $vocabulary = taxonomy_vocabulary_machine_name_load($field_info['settings']['allowed_values'][0]['vocabulary']);
        $taxonomy_field_vocabulary_mapping[$field] = $vocabulary->vid;
      }
    }

    $this->term_mapping = [];

    foreach ($taxonomy_field_vocabulary_mapping as $field => $vid) {
      $this->term_mapping[$field] = [];
      foreach (taxonomy_get_tree($vid) as $term) {
        $this->term_mapping[$field][$term->name] = $term->tid;
      }
    }
  }

  private function loadResults($page, &$found_results) {
    $this->initTermMapping();

    $query = $this->index->query();
    $query->setOption('algoliaMethod', 'browse');
    $query->setOption('attributesToRetrieve', array_merge(array_keys($this->text_fields), cluster_docs_taxonomies(FALSE)));
    $query->range($page * self::QUERY_RESULTS_PER_PAGE, self::QUERY_RESULTS_PER_PAGE);

    $result = $query->execute();
    $final_results = [];
    $found_results = FALSE;
    foreach ($result['results'] as $hit) {
      $found_results = TRUE;
      $final_results[] = $this->processHit($hit);
    }

    return array_filter($final_results);
  }

  public function getAllDocumentCount() {
    $this->initTermMapping();

    $query = $this->index->query();
    $query->setOption('algoliaMethod', 'browse');
    $query->range(0, 1);

    $result = $query->execute();
    return $result['result count'];
  }

  private function processHit($hit) {
    $ret = ['text' => '', 'tids' => []];

    foreach (array_keys($this->text_fields) as $field) {
      if (isset($hit[$field]))
        $ret['text'] .= ' ' . $hit[$field];
    }

    if (!trim($ret['text']))
      return NULL;

    foreach ($this->term_mapping as $field => $map) {
      if (!isset($hit[$field]))
        continue;
      foreach ($hit[$field] as $term_name)
        if (isset($map[$term_name]))
          $ret['tids'][] = $map[$term_name];
    }

    if (!$ret['tids'])
      return NULL;

    return $ret;
  }

  /**
   * @return bool TRUE if results were found for this page, FALSE if none were found
   */
  public function train($page = 0) {
    $found_results = FALSE;
    foreach ($this->loadResults($page, $found_results) as $result) {
      foreach ($result['tids'] as $tid)
        $this->documer->train($tid, ucwords($result['text']));
    }
    return $found_results;
  }

  public function trainSingleNode($node) {
    $wrapper = entity_metadata_wrapper('node', $node);
    $tids = [];
    foreach (cluster_docs_taxonomies(FALSE) as $field) {
      foreach ($wrapper->$field as $t) {
        $tids[] = $t->value()->tid;
      }
    }

    if (!$tids)
      return;

    $text = $this->extractTextFromNode($node);

    foreach ($tids as $tid)
      $this->documer->train($tid, ucwords($text));
  }

  public function clear() {
    $this->storage->clearAllData();
  }

  /**
   * @param string $text
   * @param array $exclude_tids
   *
   * @return array of term ids
   */
  public function getTerms($text, $exclude_tids = []) {
    $exclude_tids = (array) $exclude_tids;
    $ret = $this->documer->guess(ucwords($text));

    $ret = array_filter($ret, function($percentage, $tid) use ($exclude_tids) {
      if (in_array($tid, $exclude_tids))
        return FALSE;
      return $percentage > self::LIMIT_PERCENTAGE;
    }, ARRAY_FILTER_USE_BOTH);

    arsort($ret); // Sort by ranking (highest first)

    $initial_tids = array_keys(array_slice($ret, 0, self::LIMIT_TERMS_INITIAL, TRUE));

    return $this->refineTids($initial_tids);
  }

  /**
   * @param array $tids
   * @return array, e.g. ['field_document_type' => [4, 21], 'field_xyz' => [$xyz_tid_1, ...]]
   */
  public function groupTidsByField($tids) {
    $ret = [];
    $this->initTermMapping();
    foreach ($tids as $tid) {
      foreach ($this->term_mapping as $field => $field_tids) {
        if (in_array($tid, $field_tids)) {
          if (!isset($ret[$field]))
            $ret[$field] = [];
          $ret[$field][] = $tid;
          continue;
        }
      }
    }
    return $ret;
  }

  public function extractTextFromNode($node) {
    $text = '';

    foreach ($this->text_fields as $fn) {
      $text .= ' ' . $fn($node);
      if (drupal_strlen($text) > self::LIMIT_CHARS) {
        $text = text_summary($text, NULL, self::LIMIT_CHARS);
        break;
      }
    }

    return $text;
  }

  public function getTermsForNode($node, $exclude_tids = []) {
    return $this->getTerms($this->extractTextFromNode($node), $exclude_tids);
  }

  /**
   * Limits the number of tids by self::LIMIT_TERMS_FINAL, trying to get the
   * most granular terms (advanced tags first, then basic tags, then document
   * type)
   *
   * @param array $tids
   * @return array
   */
  private function refineTids($tids) {
    $groups = cluster_docs_taxonomy_groups();
    $grouped_fields = [];
    $cluster_docs_taxonomies = cluster_docs_taxonomies(FALSE);
    foreach ($groups as $group_count) {
      $grouped_fields[] = array_splice($cluster_docs_taxonomies, 0, $group_count);
    }

    // First group is advanced tags, second is basic tags, third is doc type and language fields
    $grouped_fields = array_reverse($grouped_fields);

    $this->initTermMapping();
    $ret = [];

    foreach ($grouped_fields as $fields_in_current_group) {
      foreach ($tids as $tid) {
        foreach ($fields_in_current_group as $field) {
          if (!isset($this->term_mapping[$field]))
            continue;

          if (in_array($tid, $this->term_mapping[$field])) {
            $ret[] = $tid;
            if (count($ret) == self::LIMIT_TERMS_FINAL)
              return $ret;

            continue 2; // Move on to the next term id
          }
        }
      }
    }

    return $ret;
  }

  public function getStorageStats() {
    return $this->storage->getStats();
  }
}
