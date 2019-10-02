<?php

class ClusterMailSystem extends MandrillMailSystem {
  public function mail(array $message) {
    $is_prod = function_exists('shelter_base_is_prod') ? shelter_base_is_prod() : FALSE;
    $env = function_exists('shelter_base_get_env') ? shelter_base_get_env() : 'unknown';

    if (!$is_prod) {
      // Add environment to subject line (if not prod)
      if (strlen($env) > 10)
        $env = substr($env, 0, 7).'...';

      $message['subject'] = '('.$env.') '.$message['subject'];
    }

    $whitelist = variable_get('cluster_email_whitelist', NULL);
    if (empty($whitelist)) {
      if ($is_prod)
        return parent::mail($message);
      else
        throw new Exception('Only the production environment is allowed to send emails without a whitelist. Go to admin/config/shelter/email to configure one.');
    }

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

  public function format(array $message) {
    // Join the body array into one string.
    if (is_array($message['body']))
      $message['body'] = implode("\n\n", $message['body']);

    return $message;
  }
}
