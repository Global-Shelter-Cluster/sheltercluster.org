<?php

namespace Drupal\cluster_api\Oauth;

interface GrantManagerInterface {

  /**
   * Authorize with client request provided credentials.
   */
  public function authorizeWithCredentials($credentials);

  public function getAccessToken($credentials);

  public function validateCredentials($credentials);

}
