<?php

namespace Drupal\cluster_api;

abstract class GrantManagerBase implements GrantManagerInterface {

  public function __construct() {
    // Get server endpoint based on environement parameter.
    // admin/config/shelter/cluser-api
    $this->server_endpoint = variable_get('cluster_api_oauth2_server', 'https://sheltercluster.org');
  }

  /**
   * Request access token from oauth2_server over http.
   */
  protected function oauthHttpRequest($data) {
    $options = array(
      'method' => 'POST',
      'data' => http_build_query($data),
      'headers' => array(
        'Content-Type' => 'application/x-www-form-urlencoded',
      ),
    );
    // Make request to oauth2 server.
    $path = $this->server_endpoint . '/oauth2/token';
    $oauth_response = drupal_http_request($path, $options);

    // Failed request.
    if (isset($oauth_response->error) || $oauth_response->code != 200) {;
      $response = [
        'code' => isset($oauth_response->code) ? $oauth_response->code : NULL,
        'response_error' => isset($oauth_response->error) ? $oauth_response->error : NULL,
        'status_message' => isset($oauth_response->status_message) ? $oauth_response->status_message : NULL,
      ];

      // oauth2_server denies authorization.
      if (isset($oauth_response->data)) {
        $data = json_decode($oauth_response->data, TRUE);
        // Example:
        // {"error":"invalid_grant","error_description":"Invalid username and password combination"}
        $response = array_merge($response, $data);
      }

      return $response;
    }

    // Successfull response from oauth2 server, return the access token.
    // {"access_token":"65...","expires_in":"3600","token_type":"Bearer","scope":"response","refresh_token":"e7..."}
    $response = json_decode($oauth_response->data, TRUE);
    $response['code'] = $oauth_response->code;

    return $response;
  }

}
