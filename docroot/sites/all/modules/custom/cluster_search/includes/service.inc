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
              $fields_to_transliterate = [
                'attachments_field_file',
              ];
              foreach ($fields_to_transliterate as $field) {
                if ($key === $field && is_string($property_value)) {
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
                )*$%xs', $property_value))
                    $property_value = iconv('CP1252', 'UTF-8', $property_value);
                  $property_value = transliteration_get($property_value);
                }
                $item_to_index[$key] = is_string($property_value)
                  ? substr($property_value, 0, 5000) // Truncate at around 5kb (Algolia has a 10kb limit for docs)
                  : $property_value;
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
      // Add the properly formatted items to the batch.
      $items_to_index[] = $item_to_index;
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

}
