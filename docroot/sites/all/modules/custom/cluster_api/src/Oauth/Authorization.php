<?php

namespace Drupal\cluster_api\Oauth;

class Authorization {

  /**
   * Attempt to get a Drupal user object either from login credentials or bearer token.
   *
   * @param $requests
   * Request access token in the abscence of bearer token.
   * // password grant
   * {
   *   "credentials": {
   *     "type": "password",
   *     "username": "jmlavarennestage",
   *     "password": "123",
   *     "client_id": "shelter-client",
   *     "scope": "response"
   *   }
   * }
   *
   * // refresh_token grant.
   * {
   *   "credentials": {
   *     "type": "refresh_token",
   *     "refresh_token": "73654fn0rdfcc28785bd7fn0rd9ac2b2f74fn0rd",
   *     "client_id": "shelter-client",
   *     "scope": "response"
   *   }
   * }
   * @return ['user' => $drupal_user, 'authorization' => OAUTH_RESPONSE_INFO]
   */
  public function authorize($requests) {
    $response = ['user' => FALSE];
    $bearer_token = $this->getBearerToken();
    $return_access_token_in_response = TRUE;

    // Try to identify token bearer.
    if ($bearer_token) {
      $oauth_response = $this->authorizeTokenBearer($bearer_token);
      $return_access_token_in_response = FALSE;
    }

    // Try to idenfy user with specified grant.
    else {
      $oauth_response = $this->authorizeWithCredentials($requests);
      $bearer_token = isset($oauth_response['access_token']) ? $oauth_response['access_token'] : NULL;
    }

    $response['authorization'] = $oauth_response;

    // Authorization failed.
    if (!$oauth_response['code'] == '200') {
      return $response;
    }

    if (isset($oauth_response['expires_in'])) {
      $response['authorization']['expires_at'] = time() + $oauth_response['expires_in'];
    }

    // Access token was successfuly generated or validated.
    $token_data =  oauth2_server_token_load($bearer_token);
    $response['user'] = user_load($token_data->uid);

    return $response;
  }

  /**
   * Get bearer token for request Authorization header.
   */
  private function getBearerToken() {
    $headers = array_change_key_case(getallheaders());
    if (!array_key_exists('authorization', $headers)) {
      return FALSE;
    }

    $authorization_header = $headers['authorization'];
    watchdog('cluster_api_headers', json_encode(getallheaders()));
    if (substr($authorization_header, 0, 7) !== 'Bearer ') {
      return FALSE;
    }

    $token = trim(substr($authorization_header, 7));
    return $token;
  }

  /**
   * Validate bearer token and provide response.
   */
  private function authorizeTokenBearer($token, $client_id = NULL, $scope = NULL) {
    $token_data = oauth2_server_token_load($token);

    // The token is not recognized.
    if (!$token_data) {
      return [
        'code' => '401',
        'response_error' => 'Unauthorized',
        'status_message' => 'Unauthorized',
        'error_description' => 'Token not recognized',
      ];
    }

    //  Access token bearer.
    if ($token_data->type == 'access' && $token_data->expires > time()) {
      return [
        'code' => '200',
        'status_message' => 'ok',
      ];
    }

    return [
      'code' => '403',
      'status_message' => 'Forbidden',
      'error_description' => 'No valid access token',
    ];
  }

  /**
   * Authorize with password grant or refresh_token grant.
   */
  private function authorizeWithCredentials($requests) {
    if (
      !isset($requests['credentials']) &&
      !isset($requests['credentials']['type']) &&
      ($requests['credentials']['type'] != 'password' || $requests['credentials']['type'] != 'refresh_token')
    ) {
      //watchdog('cluster_api_credentials', json_encode($requests));
      $grant_type = $requests['credentials']['type'];
      $error_descriptor = $grant_type . ' is not a valid grant type';
      if (!$grant_type) {
        $error_descriptor = 'Grant type not provided';
      }
      return [
        'code' => '400',
        'response_error' => 'Bad request',
        'status_message' => 'Bad request',
        'error_description' => $error_descriptor,
      ];
    }

    switch ($requests['credentials']['type']) {
      case 'password':
        $grant_manager = new PasswordGrantManager();
        break;
      case 'refresh_token':
        $grant_manager = new RefreshTokenGrantManager();
        break;
    }

    return $grant_manager->authorizeWithCredentials($requests['credentials']);
  }

}
