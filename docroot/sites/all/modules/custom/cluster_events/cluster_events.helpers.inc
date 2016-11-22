<?php

/**
 * Whether to limit the All Events page only to upcoming events.
 *
 * @return bool
 */
function _cluster_events_all_events_only_upcoming_events() {
  $parameters = drupal_get_query_parameters();

  return !isset($parameters['all']);
}
