<?php

function cluster_email_inbound() {
  watchdog('cluster_email_inbound', '0: '.print_r($_POST, TRUE));
  watchdog('cluster_email_inbound', '1: '.print_r($_POST['mandrill_events'], TRUE));
  watchdog('cluster_email_inbound', '2: '.print_r(json_decode($_POST['mandrill_events'], TRUE), TRUE));

  drupal_exit();
}
