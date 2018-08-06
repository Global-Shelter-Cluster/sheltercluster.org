<?php

function _cluster_api_forgot($data) {
  watchdog('cluster_api_forgot', json_encode($data));
  $name = $data['value'];

  // The following code was copied from _user_resource_request_new_password().

  $name = trim($name);
  // Try to load by email.
  $users = user_load_multiple(array(), array('mail' => $name, 'status' => '1'));
  $account = reset($users);
  if (!$account) {
    // No success, try to load by name.
    $users = user_load_multiple(array(), array('name' => $name, 'status' => '1'));
    $account = reset($users);
  }
  if (!isset($account->uid)) {
    return services_error(t('Sorry, "@name" is not recognized as a user name or an e-mail address.', array('@name' => $name)), 406);
  }
  // Mail one time login URL and instructions using current language.
  global $language;
  $mail = _user_mail_notify('password_reset', $account, $language);
  if (!empty($mail)) {
    watchdog('user', 'Password reset instructions mailed to %name at %email.', array('%name' => $account->name, '%email' => $account->mail));
    return TRUE;
  }
  else {
    return FALSE;
  }
}
