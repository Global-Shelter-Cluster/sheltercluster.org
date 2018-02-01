<?php

/**
 * @file
 * Contains SearchApiAlgoliaService.
 */

module_load_include('inc', 'search_api_algolia', 'includes/service');

/**
 * SearchApiClusterAlgoliaService class.
 */
class SearchApiClusterAlgoliaService extends SearchApiAlgoliaService {
  /**
   * Connect to the Algolia service.
   *
   * Uses the application ID et API key provided in the UI.
   */
  protected function connect($index) {
    // @todo Make the absence of lib more visible (error message on the status
    // report page for instance, and during the install process).
    if (($library = libraries_load('algolia')) && !empty($library['loaded'])) {
      $algolia_client = new \AlgoliaSearch\Client($this->getApplicationID(), $this->getApiKey());
      $this->setAlgoliaIndex($algolia_client->initIndex(variable_get('cluster_search_algolia_prefix', 'dev') . $index->name));
    }
    else {
      throw new SearchApiException(t('Algolia library could not be found or did not load properly.'));
    }
  }

  public function indexItems(SearchApiIndex $index, array $items) {
    $items_to_index = array();
    $items_indexed = array();

    // Retrieving the entity key ('nid' for nodes, 'uid' for users, etc...).
    $entity_key = entity_get_info($index->item_type)['entity keys']['id'];

    // Connect to the Algolia service.
    $this->connect($index);

    // Iterate over all the items ready for indexing.
    foreach ($items as $item) {
      $item_to_index = array();
      // And then iterate over all the properties of these items.
      foreach ($item as $key => $property) {
        // Do not index the property if its value is not set.
        if (isset($property['value'])) {
          // Do not process the entity id at that stage. Its value is indexed
          // separately as it requires a special property name (ObjectID) in
          // order to be indexed by Algolia.
          if ($key != $entity_key) {
            // If the property type is defined as a list and entity_type is set,
            // we are facing a multivalued entity (checking list<integeger> is
            // not enough as this could be used by a standard select, with no
            // reference).
            // @todo Handle multivalued fields which are not entity reference.
            if (preg_match('/^list<[^>]+>/', $property['type']) && isset($property['entity_type'])) {
              $entity_type = $property['entity_type'];
              foreach ($property['value'] as $property_list_value) {
                $loaded_entity = entity_load_single($entity_type, $property_list_value);
                if ($loaded_entity) {
                  $wrapper = entity_metadata_wrapper($entity_type, $loaded_entity);
                  $item_to_index[$key][] = $wrapper->label();
                }
              }
            }
            // The property only bears a single value.
            else {
              // If entity_type is defined, it means we are facing an entity
              // reference. We then use an entity wrapper to output it.
              if (isset($property['entity_type'])) {
                $entity_type = $property['entity_type'];
                $loaded_entity = entity_load_single($entity_type, $property['value']);
                if ($loaded_entity) {
                  $wrapper = entity_metadata_wrapper($entity_type, $loaded_entity);
                  $property_value = $wrapper->label();
                }
              }
              // Simple property value (no entity to dereference).
              else {
                if ($property['type'] == 'integer') {
                  // We need to transtype the content of integer fields (as they
                  // are stored as string) so that Algolia sees them as
                  // integers.
                  // @todo MAYBE: if more types need to be recognized, make
                  // something more scalable here.
                  $property_value = (int) $property['value'];
                }
                else {
                  $property_value = $property['value'];
                }
              }

              $processed = FALSE;

              $fields_to_transliterate = [
                'attachments_field_file',
                'body:value',
              ];
              foreach ($fields_to_transliterate as $field) {
                if ($key !== $field || is_string($property_value))
                  continue;

                // Truncate at around 4kb (Algolia has a 10kb limit for docs),
                // and transliterate to get rid of UTF issues (this is fine
                // because these fields are never shown to the user).
                $property_value = substr(
                  transliteration_get(substr($property_value, 0, 4000)),
                  0,
                  4000
                );

                try {
                  \AlgoliaSearch\Json::encode($property_value);
                  $item_to_index[$key] = $property_value;
                } catch (\AlgoliaSearch\AlgoliaException $e) {
                  // Ensure UTF8 encoding (otherwise Algolia throws an error)
                  // Code from https://stackoverflow.com/a/1523574/368864
                  if (!preg_match('%^(?:
                      [\x09\x0A\x0D\x20-\x7E]            # ASCII
                    | [\xC2-\xDF][\x80-\xBF]             # non-overlong 2-byte
                    | \xE0[\xA0-\xBF][\x80-\xBF]         # excluding overlongs
                    | [\xE1-\xEC\xEE\xEF][\x80-\xBF]{2}  # straight 3-byte
                    | \xED[\x80-\x9F][\x80-\xBF]         # excluding surrogates
                    | \xF0[\x90-\xBF][\x80-\xBF]{2}      # planes 1-3
                    | [\xF1-\xF3][\x80-\xBF]{3}          # planes 4-15
                    | \xF4[\x80-\x8F][\x80-\xBF]{2}      # plane 16
                  )*$%xs', $property_value)) {
                    $property_value = iconv('CP1252', 'UTF-8', $property_value);
                    try {
                      \AlgoliaSearch\Json::encode($property_value);
                      $item_to_index[$key] = $property_value;
                    } catch (\AlgoliaSearch\AlgoliaException $e) {
                      // Don't include it in the index
                      watchdog('cluster_search', 'Skipped field %field in node %nid due to encoding', ['%field' => $key, '%nid' => $item[$entity_key]['value']]);
                    }
                  }
                }

                $processed = TRUE;
              }

              $group_nids_fields = [
                'og_group_ref:nid',
                'field_associated_regions:nid',
                'field_parent_response:nid',
                'field_parent_region:nid',
              ];
              if (in_array($key, $group_nids_fields)) {
                $key = 'group_nids';

                if (!array_key_exists($key, $item_to_index))
                  $item_to_index[$key] = [];

                foreach ((array) $property_value as $value)
                  $item_to_index[$key][] = intval($value);

                $processed = TRUE;
              }

              if ($key == 'field_language' && is_string($property_value) && $property_value) {
                $lang = i18n_language_load($property_value);
                if ($lang)
                  $property_value = $lang->name;
                else
                  $processed = TRUE; // Skip it
              }

              if (in_array($key, ['created', 'field_report_meeting_date']))
                $property_value = intval($property_value);

              if ($key === 'field_preview:file:fid') {
                $file = file_load($property_value);
                if ($file) {
                  $a=$file->uri;
                  $item_to_index['field_preview:file:url'] = image_style_url('document_preview', $file->uri);
                }
                $processed = TRUE;
              }

              if (!$processed) {
                try {
                  $property_value = is_string($property_value)
                    ? substr($property_value, 0, 4000) // Truncate at 4kb (Algolia has a 10kb limit for docs)
                    : $property_value;

                  \AlgoliaSearch\Json::encode($property_value);
                  $item_to_index[$key] = $property_value;
                } catch (\AlgoliaSearch\AlgoliaException $e) {
                  // Don't include it in the index
                  watchdog('cluster_search', 'Skipped field %field in node %nid due to encoding', [
                    '%field' => $key,
                    '%nid' => $item[$entity_key]['value']
                  ]);
                }
              }
            }
          }
          else {
            // Match the entity key to the objectID primary key required by
            // Algolia.
            $item_to_index['objectID'] = $item[$entity_key]['value'];
          }
        }
      }
      try {
        \AlgoliaSearch\Json::encode($item_to_index);

        if (array_key_exists('created', $item_to_index)) {
          $item_to_index['document_date'] = array_key_exists('field_report_meeting_date', $item_to_index) && $item_to_index['field_report_meeting_date']
            ? $item_to_index['field_report_meeting_date']
            : $item_to_index['created'];
        }

        // Add the properly formatted items to the batch.
        $items_to_index[] = $item_to_index;
      } catch (\AlgoliaSearch\AlgoliaException $e) {
        // Don't include it in the index
        watchdog('cluster_search', 'Skipped node %nid due to encoding', ['%nid' => $item_to_index['objectID']]);
      }
    }

    try {
      // Once a batch is ready, send them over to Algolia.
      $items_indexed = $this->getAlgoliaIndex()->saveObjects($items_to_index);
    }
    catch (Exception $e) {
      watchdog(
        'cluster_search',
        'See '  . __FUNCTION__ . '() ' .  $e->getTraceAsString(),
        NULL,
        WATCHDOG_ERROR
      );
      throw new SearchApiException($e->getMessage());
    }

    // Returns an array of properly indexed objectIDs for Search API's
    // statistics. Depending on the type of entity being indexed, this can be
    // an array of 'nids', 'uids', 'tids', etc...
    return $items_indexed['objectIDs'];
  }

  /**
   * Implements search.
   */
  public function search(SearchApiQueryInterface $query) {
    $this->connect($query->getIndex());

    /** @var \AlgoliaSearch\Index $index */
    $index = $this->getAlgoliaIndex();

    $args = [];

    $query_options = $query->getOptions();
    if (isset($query_options['offset']) || isset($query_options['limit'])) {
      $offset = isset($query_options['offset']) ? $query_options['offset'] : 0;
      $limit = isset($query_options['limit']) ? $query_options['limit'] : 1000000;
      if ($offset % $limit !== 0)
        throw new Exception('Cannot convert offset/limit into page/hitsPerPage');
      $args['page'] = $offset / $limit;
      $args['hitsPerPage'] = $limit;
    }

    $args['attributesToRetrieve'] = implode(',', $query_options['attributesToRetrieve']);

    if (isset($query_options['algoliaMethod']) && $query_options['algoliaMethod'] === 'browse') {
      $result = $index->browseFrom('', $args);
    } else
      $result = $index->search('*', $args);

    array_walk($result['hits'], function(&$hit) {
      $hit['id'] = intval($hit['objectID']);
      unset($hit['objectID']);
    });

    $result = [
      'result count' => $result['nbHits'],
      'results' => $result['hits'],
    ];
    return $result;
  }

}
