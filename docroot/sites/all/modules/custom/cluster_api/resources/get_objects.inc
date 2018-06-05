<?php

/**
 * Example:
 *
 * jQuery.ajax({
 *   type: "POST",
 *   url: "http://local.sheltercluster.org/api-v1/get-objects",
 *   dataType: "json",
 *   contentType: "application/json",
 *   success: console.log,
 *   data: JSON.stringify([
 *     {type: 'user', id: 1},
 *     {type: 'group', id: 2},
 *   ])
 * });
 *
 * @param $requests
 *
 * @return array
 */
function _cluster_api_get_objects_resource($requests) {
  global $user;

  $user = user_load(733); // Camilo

  $object = new ClusterAPI_Object($user);
  return $object->getObjects($requests);
  $a = 1;

  return array_merge([
    ['a' => 3],
    ['b' => 4],
  ], (array) $requests);
}
