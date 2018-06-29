<?php

$data = array(
      'grant_type' => 'password',
      'username' => 'admin',
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

$res = drupal_http_request('http://localhost:32778');

$res = drupal_http_request('https://sheltercluster.lndo.site:444/oauth2/token', $options);
$res = drupal_http_request('http://192.168.0.101:32778/oauth2/token', $options);
dpm($res);
$data = json_decode($res->data);

$tok = oauth2_server_token_load($data->access_token);
dpm($tok);


// request body
{
  "objects": [{
    "type": "global",
    "id": 1
  }],
  "credentials": {
    "type": "password",
    "username": "Camilo",
    "password": "test",
    "client_id": "shelter-client",
    "scope": "response"
  }
}
