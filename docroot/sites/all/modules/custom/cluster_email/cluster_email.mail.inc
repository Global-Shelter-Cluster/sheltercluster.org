<?php

class ClusterMailSystem extends MandrillMailSystem {
  public function mail(array $message) {
//    watchdog('cluster_email', 'Sending email: %subject, to %recipients.', [
//      '%subject' => $message['subject'],
//      '%recipients' => $message['to'],
//    ]);

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

    $excluded = [];

    $recipients = explode(',', $message['to']);
    $recipients = array_map('trim', $recipients);
    $recipients = array_filter($recipients, function($recipient) use ($whitelist, &$excluded) {
      foreach ($whitelist as $address) {
        if (strtolower($recipient) === $address)
          return TRUE;

        if (strpos(strtolower($recipient), '<' . $address . '>') !== FALSE)
          return TRUE;
      }

      $excluded[] = $recipient;
    });

    if (count($excluded) > 0)
      watchdog('cluster_email', 'Filtered out email recipients for email: %subject. Excluded: @excluded, included: @included.', [
        '%subject' => $message['subject'],
        '@excluded' => implode(', ', $excluded),
        '@included' => count($recipients) > 0 ? implode(', ', $recipients) : 'none (email will not be sent)',
      ]);

    if (count($recipients) === 0)
      return TRUE;

    $message['to'] = implode(',', $recipients);

    // TODO: make this work (right now it sets this in the "reply-to" field, not in "from")
//    if ($message['from_name'])
//      $message['from'] = $message['from_name'] . ' <'.$message['from'].'>';

    return parent::mail($message);
  }

  public function format(array $message) {
    // Join the body array into one string.
    if (is_array($message['body']))
      $message['body'] = implode("\n\n", $message['body']);

    return $message;
  }
}
