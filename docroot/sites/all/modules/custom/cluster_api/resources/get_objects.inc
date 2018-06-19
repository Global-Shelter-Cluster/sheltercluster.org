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
function _cluster_api_get_objects($requests) {
  global $user;

  $user = user_load(733); // 733: Camilo, 74: Shirin, 70: Neil, 531: Bo

  $object = new ClusterAPI_Object($user);
  return serialize($requests);//$object->getObjects($requests);
}
