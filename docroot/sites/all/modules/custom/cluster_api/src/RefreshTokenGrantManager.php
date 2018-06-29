<?php

namespace Drupal\cluster_api;

use Drupal\cluster_api\GrantManagerBase;

class RefreshTokenGrantManager extends GrantManagerBase {

  public function authorizeWithCredentials($credentials) {
    if (!$this->validateCredentials($credentials)) {
      return [
        'code' => '401',
        'response_error' => 'Unauthorized',
        'status_message' => 'Unauthorized',
        'error_description' => 'Client did not provided adequate credentials',
      ];
    }

    $oauth_response = $this->getAccessToken($credentials);
    return $oauth_response;
  }

  public function getAccessToken($credentials) {
    $data = array(
      'grant_type' => 'refresh_token',
      'refresh_token' => $credentials['refresh_token'],
      'client_id' => $credentials['client_id'],
      'scope' => $credentials['scope'],
    );

    // Make request to oauth2 server.
    $response = $this->oauthHttpRequest($data);

    return $response;
  }

  public function validateCredentials($credentials) {
    if (!isset($credentials['type'])) {
      return FALSE;
    }
    if ($credentials['type'] != 'refresh_token') {
      return FALSE;
    }

    return isset($credentials['refresh_token']) &&
      isset($credentials['client_id']) &&
      isset($credentials['scope']);
  }

}
