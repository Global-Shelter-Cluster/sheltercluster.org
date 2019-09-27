<?php

class ClusterMailSystem extends MandrillMailSystem {
  public function mail(array $message) {
    $whitelist = variable_get('cluster_email_whitelist', NULL);
    if (empty($whitelist))
      return parent::mail($message);

    $whitelist = explode("\n", $whitelist);
    $whitelist = array_map('trim', $whitelist);
    $whitelist = array_map('strtolower', $whitelist);
    $whitelist = array_filter($whitelist);

    $recipients = explode(',', $message['to']);
    $recipients = array_map('trim', $recipients);
    $recipients = array_filter($recipients, function($recipient) use ($whitelist) {
      foreach ($whitelist as $address) {
        if (strtolower($recipient) === $address)
          return TRUE;

        return strpos(strtolower($recipient), '<'.$address.'>') !== FALSE;
      }
    });

    if (count($recipients) === 0)
      return;

    $message['to'] = implode(',', $recipients);

    return parent::mail($message);
  }
}
