<?php

namespace Drupal\cluster_api\Oauth;

use Drupal\cluster_api\Oauth\GrantManagerBase;

class PasswordGrantManager extends GrantManagerBase {

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
    $data = [
      'grant_type' => 'password',
      'username' => $credentials['username'],
      'password' => $credentials['password'],
      'client_id' => $credentials['client_id'],
      'scope' => $credentials['scope'],
    ];

    // Make request to oauth2 server.
    $response = $this->oauthHttpRequest($data);
    return $response;
  }

  public function validateCredentials($credentials) {
    if (!isset($credentials['type'])) {
      return FALSE;
    }
    if ($credentials['type'] != 'password') {
      return FALSE;
    }

    return isset($credentials['username']) &&
      isset($credentials['password']) &&
      isset($credentials['client_id']) &&
      isset($credentials['scope']);
  }

}
