<?php

/**
 * Most of this code is adapted from
 * https://github.com/Alymosul/exponent-server-sdk-php
 */

class ClusterAPI_Expo {

  const BATCH_SIZE = 100;

  /**
   * The Expo Api Url that will receive the requests
   */
  const EXPO_API_URL = 'https://exp.host/--/api/v2/push/send';
  /**
   * cURL handler
   *
   * @var null|resource
   */
  private $ch = NULL; // Curl handler

  /**
   * Send a notification via the Expo Push Notifications Api.
   *
   * @param array $tokens
   * @param array $data
   * @param bool $debug
   *
   * @throws \Exception
   *
   * @return array|bool
   */
  public function notify($tokens, array $data) {
    $currentBatch = 0;

    while (TRUE) {
      $currentBatchTokens = array_slice($tokens, $currentBatch * self::BATCH_SIZE, self::BATCH_SIZE);
      if (count($currentBatchTokens) === 0)
        break;
      $currentBatch++;

      $postData = [];
      foreach ($currentBatchTokens as $token) {
        $postData[] = $data + ['to' => $token];
      }

      $ch = $this->prepareCurl();

      curl_setopt($ch, CURLOPT_POSTFIELDS, json_encode($postData));

      $response = $this->executeCurl($ch);

      $sleptAlready = FALSE;
      $loggedTooBigAlready = FALSE;

      foreach ($response as $key => $item) {
        if ($item['status'] !== 'ok') {
          $token = $currentBatchTokens[$key];
          switch (isset($item['details']) && isset($item['details']['error']) ? $item['details']['error'] : NULL) {
            case 'DeviceNotRegistered':
              // Remove this push token from our database
              $removed_count = _cluster_api_clear_push_token($token);
              if ($removed_count)
                watchdog('expo', 'Removed token @token from @count users.', ['@token' => $token, '@count' => $removed_count]);
              break;

            case 'MessageRateExceeded':
              // We're supposed to retry these notifications, and implement exponential backoff, but for now we just
              // sleep for a while before continuing, and discard the lost notifications.
              // Eventually, we might want to do something smarter.
              // See https://docs.expo.io/versions/latest/guides/push-notifications/

              if (!$sleptAlready) {
                watchdog('expo', 'MessageRateExceeded response on token @token (and possibly others): @body', ['@token' => $token, '@body' => print_r($item, TRUE)], WATCHDOG_WARNING);
                sleep(5);
                $sleptAlready = TRUE;
              }
              break;

            case 'MessageTooBig':
              if (!$loggedTooBigAlready) {
                watchdog('expo', 'MessageTooBig response on token @token (and possibly others): @body. Notification data was: @notification', ['@token' => $token, '@body' => print_r($item, TRUE), '@notification' => print_r($data, TRUE)], WATCHDOG_WARNING);
                $loggedTooBigAlready = TRUE;
              }
              break;

            case 'InvalidCredentials':
            default:
              watchdog('expo', 'Non-ok response on token @token: @body', ['@token' => $token, '@body' => print_r($item, TRUE)], WATCHDOG_WARNING);
          }
        }
      }
    }
  }

  /**
   * Sets the request url and headers
   *
   * @throws Exception
   *
   * @return null|resource
   */
  private function prepareCurl() {
    // Create or reuse existing cURL handle
    $this->ch = isset($this->ch) ? $this->ch : curl_init();

    // Throw exception if the cURL handle failed
    if (!$this->ch) {
      throw new Exception('Could not initialise cURL!');
    }

    $ch = $this->ch;

    // Set cURL opts
    curl_setopt($ch, CURLOPT_URL, self::EXPO_API_URL);
    curl_setopt($ch, CURLOPT_HTTPHEADER, [
      'accept: application/json',
      'content-type: application/json',
    ]);
    curl_setopt($ch, CURLOPT_POST, 1);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, TRUE);

    return $ch;
  }

  /**
   * Executes cURL and captures the response
   *
   * @param $ch
   *
   * @return array
   */
  private function executeCurl($ch) {
    $response = [
      'body' => curl_exec($ch),
      'status_code' => curl_getinfo($ch, CURLINFO_HTTP_CODE),
    ];

    if ($response['status_code'] != 200) {
      watchdog('expo', 'Non-200 response from @url: @response', ['@url' => self::EXPO_API_URL, '@response' => print_r($response, TRUE)], WATCHDOG_ERROR);
    }

    $data = json_decode($response['body'], TRUE)['data'];

    return is_array($data) ? $data : [];
  }
}
