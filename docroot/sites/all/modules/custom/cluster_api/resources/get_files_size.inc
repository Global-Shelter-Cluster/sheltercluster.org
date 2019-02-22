<?php

/**
 * Example:
 *
 * jQuery.ajax({
 *   type: "POST",
 *   url: "http://local.sheltercluster.org/api-v1/get-files-size",
 *   dataType: "json",
 *   contentType: "application/json",
 *   success: console.log,
 *   data: JSON.stringify([
 *     "http://www.sheltercluster.org/sites/default/files/somefile.pdf",
 *     "http://www.sheltercluster.org/sites/default/files/somefile2.pdf",
 *   ])
 * });
 *
 * @param $requests
 *
 * @return array
 */
function _cluster_api_get_files_size($request) {
  // Add the authorized user id to the requested objects.
  $file_scheme = 'public://';
  $file_wrapper = file_stream_wrapper_get_instance_by_uri($file_scheme);
  $external_url = $file_wrapper->getExternalUrl();

  // Replace the public path to "public://".
  foreach ($request as &$url) {
    $url = str_replace($external_url, $file_scheme, $url);
  }

  // Get file size from file_managed table.
  $query = db_select('file_managed', 'f')
    ->condition('uri', $request, 'IN');
  $query->addExpression('SUM(filesize)', 'total');
  $results = $query->execute()->fetchCol();
  $total = reset($results);

  // If there are no files, $total will be null, return 0 instead.
  return $total ? $total : 0;
}
