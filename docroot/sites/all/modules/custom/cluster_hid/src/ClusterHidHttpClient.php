<?php

namespace Drupal\cluster_hid;

use GuzzleHttp\Client;
use GuzzleHttp\Psr7\Response;

class ClusterHidHttpClient {

  protected static $instance = null;

  private $query;

  // https://api.staging.humanitarian.id
  protected $endpoint = 'https://api.humanitarian.id/api/v2/';

  /**
   * @var GuzzleHttp\Client
   */
  private $httpClient;

  protected function __construct() {
    $this->setHttpClient();
  }

  private function setHttpClient() {
    $jwt = variable_get('cluster_hid_jwt', NULL);
    if (is_null($jwt)) {
      throw new \Exception('No valid JWT token for hid API.');
    }
    $this->httpClient = new \GuzzleHttp\Client([
      'headers' => ['authorization' => 'Bearer ' . $jwt],
      'base_uri' => $this->endpoint,
    ]);
  }

  public static function getInstance() {
    if (!isset(static::$instance)) {
      static::$instance = new static();
    }
    return static::$instance;
  }

  public function makeTestRequest() {
    // use Drupal\cluster_hid\ClusterHidHttpClient;
    // $s = ClusterHidHttpClient::getInstance();
    // $s->makeTestRequest();
    // 58e4abca3f0e0d00aeec8806
    // 5a749d5cf94a9509ffc5ebc5
    // 58e4ac763f0e0d00aeec8b36
    try {
      $res = $this->httpClient->request('GET', 'user/58e4abca3f0e0d00aeec8806');
      dpm($res->getStatusCode());
      $contents = $res->getBody()->getContents();
      dpm($contents);
    }
    catch (\Exception $e) {
      dpm($e->getMessage());
    }
  }

  public function getUserById($id) {
    $response = $this->httpGet('user/' . $id);
    return $this->prepareResponseReturnValue($response);
  }

  public function searchUserByName($name) {
    $response = $this->httpGet('user?q=' . $name . '&sort=name&fields=family_name+given_name+email+organization');
    return $this->prepareResponseReturnValue($response);
  }

  public function searchUserByNameForAutocomplete($name) {
    $response = $this->httpGet('user?q=' . $name . '&sort=name&fields=family_name+given_name+email+organization');
    return $this->prepareResponseReturnValue($response);
  }

  /**
   * Validates response and provides json object.
   */
  private function prepareResponseReturnValue($response) {
    if (is_null($response) && !isset($response->getBody)) {
      return;
    }
    $contents = $response->getBody()->getContents();
    return json_decode($contents);
  }

  private function httpGet($query) {
    try {
      return $this->httpClient->get($query);
    }
    catch (\Exception $e) {
      watchdog('cluster_hid', 'HTTP request error @error', ['@error' => $e->getMessage(), WATCHDOG_ERROR]);
    }
  }

}
