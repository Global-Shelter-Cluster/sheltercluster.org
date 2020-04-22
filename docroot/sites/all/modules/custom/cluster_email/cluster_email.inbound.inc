<?php

/**
 * Example $mandrill_event:
 *
 * {
 *   "ts": 1368214102,
 *   "event": "inbound",
 *   "msg": {
 *     "dkim": {
 *       "signed": true,
 *       "valid": true
 *     },
 *     "email": "dev-test@inbound.sheltercluster.org",
 *     "from_email": "example.sender@mandrillapp.com",
 *     "headers": {
 *       "Content-Type": "multipart/alternative;+boundary=\"_av-7r7zDhHxVEAo2yMWasfuFw\"",
 *       "Date": "Fri,+10+May+2013+19:28:20++0000",
 *       "Dkim-Signature": [
 *         "v=1;+a=rsa-sha1;+c=relaxed/relaxed;+s=mandrill;+d=mail115.us4.mandrillapp.com;+h=From:Sender:Subject:List-Unsubscribe:To:Message-Id:Date:MIME-Version:Content-Type;+i=example.sender@mail115.us4.mandrillapp.com;+bh=d60x72jf42gLILD7IiqBL0OBb40=;+b=iJd7eBugdIjzqW84UZ2xynlg1SojANJR6xfz0JDD44h78EpbqJiYVcMIfRG7mkrn741Bd5YaMR6p+9j41OA9A5am+8BE1Ng2kLRGwou5hRInn+xXBAQm2NUt5FkoXSpvm4gC4gQSOxPbQcuzlLha9JqxJ+8ZZ89/20txUrRq9cYxk=",
 *         "v=1;+a=rsa-sha256;+c=relaxed/relaxed;+d=c.mandrillapp.com;+i=@c.mandrillapp.com;+q=dns/txt;+s=mandrill;+t=1368214100;+h=From+:+Sender+:+Subject+:+List-Unsubscribe+:+To+:+Message-Id+:+Date+:+MIME-Version+:+Content-Type+:+From+:+Subject+:+Date+:+X-Mandrill-User+:+List-Unsubscribe;+bh=y5Vz+RDcKZmWzRc9s0xUJR6k4APvBNktBqy1EhSWM8o=;+b=PLAUIuw8zk8kG5tPkmcnSanElxt6I5lp5t32nSvzVQE7R8u0AmIEjeIDZEt31+Q9PWt+nY+sHHRsXUQ9SZpndT9Bk++/SmyA2ntU/2AKuqDpPkMZiTqxmGF80Wz4JJgx2aCEB1LeLVmFFwB+5Nr/LBSlsBlRcjT9QiWw0/iRvCn74="
 *       ],
 *       "Domainkey-Signature": "a=rsa-sha1;+c=nofws;+q=dns;+s=mandrill;+d=mail115.us4.mandrillapp.com;+b=X6qudHd4oOJvVQZcoAEUCJgB875SwzEO5UKf6NvpfqyCVjdaO79WdDulLlfNVELeuoK2m6alt2yw+5Qhp4TW5NegyFf6Ogr/Hy0Lt411r/0lRf0nyaVkqMM/9g13B6D9CS092v70wshX8+qdyxK8fADw8+kEelbCK2cEl0AGIeAeo=;",
 *       "From": "<example.sender@mandrillapp.com>",
 *       "List-Unsubscribe": "<mailto:unsubscribe-md_999.aaaaaaaa.v1-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@mailin1.us2.mcsv.net?subject=unsub>",
 *       "Message-Id": "<999.20130510192820.aaaaaaaaaaaaaa.aaaaaaaa@mail115.us4.mandrillapp.com>",
 *       "Mime-Version": "1.0",
 *       "Received": [
 *         "from+mail115.us4.mandrillapp.com+(mail115.us4.mandrillapp.com+[205.201.136.115])+by+mail.example.com+(Postfix)+with+ESMTP+id+AAAAAAAAAAA+for+<dev-test@inbound.sheltercluster.org>;+Fri,+10+May+2013+19:28:21++0000+(UTC)",
 *         "from+localhost+(127.0.0.1)+by+mail115.us4.mandrillapp.com+id+hhl55a14i282+for+<dev-test@inbound.sheltercluster.org>;+Fri,+10+May+2013+19:28:20++0000+(envelope-from+<bounce-md_999.aaaaaaaa.v1-aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa@mail115.us4.mandrillapp.com>)"
 *       ],
 *       "Sender": "<example.sender@mail115.us4.mandrillapp.com>",
 *       "Subject": "This+is+an+example+webhook+message",
 *       "To": "<dev-test@inbound.sheltercluster.org>",
 *       "X-Report-Abuse": "Please+forward+a+copy+of+this+message,+including+all+headers,+to+abuse@mandrill.com"
 *     },
 *     "raw_msg": "Received:+from+mail115.us4.mandrillapp.com+(mail115.us4.mandrillapp.com+[205.201.136.115])\n\tby+mail.example.com+(Postfix)+with+ESMTP...",
 *     "sender": null,
 *     "spam_report": {
 *       "matched_rules": [
 *         {
 *           "description": "RBL:+ISIPP+IADB+lists+as+vouched-for+sender",
 *           "name": "RCVD_IN_IADB_VOUCHED",
 *           "score": -2.2
 *         },
 *         {
 *           "description": "BODY:+HTML:+images+with+0-400+bytes+of+words",
 *           "name": "HTML_IMAGE_ONLY_04",
 *           "score": 0.3
 *         },
 *         ...
 *       ],
 *       "score": -2.6
 *     },
 *     "spf": {
 *       "detail": "sender+SPF+authorized",
 *       "result": "pass"
 *     },
 *     "subject": "This+is+an+example+webhook+message",
 *     "tags": [],
 *     "template": null,
 *     "text": "This+is+an+example+inbound+message.\n",
 *     "text_flowed": false,
 *     "html": "<p>This+is+an+example+inbound+message.</p><img+src=\"http://mandrillapp.com/track/open.php?u=999&id=aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa&tags=_all,_sendexample.sender@mandrillapp.com\"+height=\"1\"+width=\"1\">\n",
 *     "to": [
 *       [
 *         "dev-test@inbound.sheltercluster.org",
 *         null
 *       ]
 *     ]
 *   }
 * }
 */

function cluster_email_inbound() {
  if (!isset($_POST['mandrill_events'])) {
    drupal_exit();
  }
  $mandrill_events = json_decode($_POST['mandrill_events'], TRUE);
  if (!is_array($mandrill_events) || count($mandrill_events) === 0) {
    drupal_exit();
  }

  $is_prod = shelter_base_is_prod();
  $env = shelter_base_get_env();
  // Emails should look like "stage-testpage-9175@inbound.sheltercluster.org",
  // or "testpage-9175@inbound.sheltercluster.org" for production.
  $env_prefix = $is_prod ? '' : preg_quote($env . '-');

  foreach ($mandrill_events as $mandrill_event) {
    if ($mandrill_event['event'] !== 'inbound') {
      watchdog('cluster_email_inbound', 'Unrecognized event: @event. Message: @msg', [
        '@event' => $mandrill_event['event'],
        '@msg' => print_r($mandrill_event, TRUE),
      ], WATCHDOG_WARNING);
      continue;
    }

    if (preg_match('/^' . $env_prefix . '([^@]+)@/', $mandrill_event['msg']['email'], $matches) === FALSE) {
      watchdog('cluster_email_inbound', 'Could not parse email: @msg', ['@msg' => print_r($mandrill_event, TRUE)], WATCHDOG_WARNING);
      continue;
    }

    $spam_score = isset($mandrill_event['msg']['spam_report'])
      ? $mandrill_event['msg']['spam_report']['score']
      : NULL;
    $spf = isset($mandrill_events['msg']['spf'])
      ? $mandrill_events['msg']['spf']
      : NULL;
    $dkim = isset($mandrill_events['msg']['dkim'])
      ? $mandrill_events['msg']['dkim']
      : NULL;

    $user = user_load_by_mail($mandrill_event['msg']['from_email']);

    $text = isset($mandrill_event['msg']['text'])
      ? trim(_cluster_email_character_conversion($mandrill_event['msg']['text']))
      : NULL;

    $html = NULL;
    if (isset($mandrill_event['msg']['html']) && trim(strip_tags($mandrill_event['msg']['html'])) !== '') {
      $html = trim(_cluster_email_character_conversion($mandrill_event['msg']['html']));
    }

    if (!$text && !$html) {
      watchdog('cluster_email_inbound', 'Received email without text or HTML body: @msg', ['@msg' => print_r($mandrill_event, TRUE)], WATCHDOG_WARNING);
      continue;
    }

    $message = array_filter([
      'ts' => $mandrill_event['ts'],
      'uid' => $user ? $user->uid : NULL,
      'from_email' => $mandrill_event['msg']['from_email'],
      'from_name' => isset($mandrill_event['msg']['from_name']) ? _cluster_email_character_conversion($mandrill_event['msg']['from_name']) : NULL,
      'subject' => $mandrill_event['msg']['subject'] ? _cluster_email_character_conversion($mandrill_event['msg']['subject']) : '',
      'html' => $html,
      'text' => $text,
      'spam_score' => $spam_score,
      'spf' => $spf,
      'dkim' => $dkim,
    ]);

    $name = $matches[1];

    watchdog('cluster_email_inbound', 'Processing inbound email (@name): @msg', [
      '@name' => $name,
      '@msg' => json_encode($message),
    ], WATCHDOG_DEBUG);

    module_invoke_all('cluster_email_inbound_handle', $name, $message);
  }

  drupal_exit();
}

/**
 * Gets rid of utf-8 characters that can't be translated into latin-1 (the encoding we use on the DB).
 *
 * @param string $string
 * @return string
 */
function _cluster_email_character_conversion($string) {
  // See https://www.php.net/manual/en/function.iconv.php#108643
  ini_set('mbstring.substitute_character', 'none');
  return mb_convert_encoding($string, 'LATIN1', 'UTF-8');
}

/**
 * Implements hook_cluster_email_inbound_handle().
 */
function cluster_email_cluster_email_inbound_handle($name, $message) {
  $prefix = 'testpage-';
  if (
    substr($name, 0, strlen($prefix)) !== $prefix
    || preg_match('/^' . preg_quote($prefix) . '(\d+)$/', $name, $matches) === FALSE
  )
    return;

  $gid = $matches[1];
  $group = node_load($gid);
  if (!og_is_group('node', $group)) {
    return;
  }

  if (isset($message['html'])) {
    $body = ['format' => 'filtered_html', 'value' => $message['html']];
  }
  else {
    $body = ['format' => 'plain_text', 'value' => $message['text']];
  }

  $values = [
    'type' => 'page',
    'status' => NODE_NOT_PUBLISHED,
  ];

  if (isset($message['uid'])) {
    $values['uid'] = $message['uid'];
  }

  $node = entity_create('node', $values);
  $wrapper = entity_metadata_wrapper('node', $node);

  $wrapper->title->set('Test page created from inbound email on ' . format_date($message['ts']));
  $wrapper->og_group_ref->set([$group]);

  //  $wrapper->body->set($body); // this sets the lang of the body field to "en", so we do it directly in $node
  $node->body = [LANGUAGE_NONE => [$body]];

  $wrapper->save();
}
