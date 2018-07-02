<?php

exit();

// Example code on how to use Authorization.php for password grant.
use Drupal\cluster_api\Authorization;

$auth = new Authorization();
$req_s = '{
  "objects": [{
    "type": "global",
    "id": 1
  }],
  "credentials": {
    "type": "password",
    "username": "jmlavarennestage",
    "password": "1231",
    "client_id": "shelter-client",
    "scope": "response"
  }
}';

$requests = json_decode($req_s, TRUE);
$res = $auth->authorize($requests);
dpm($res);

// Example of http request for password grant
 $data = array(
  'grant_type' => 'password',
  'username' => 'jmlavarennestage',
  'password' => '123',
  'client_id' => 'shelter-client',
  'scope' => 'response',
);
$options = array(
  'method' => 'POST',
  'data' => http_build_query($data),
  'headers' => array(
    'Content-Type' => 'application/x-www-form-urlencoded',
  ),
);

$res = drupal_http_request('http://192.168.0.102:32778/oauth2/token', $options);
dpm($res);
$data = json_decode($res->data);

$tok = oauth2_server_token_load($data->access_token);
dpm($tok);
