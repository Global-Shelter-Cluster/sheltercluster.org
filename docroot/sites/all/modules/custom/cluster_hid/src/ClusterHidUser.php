<?php

namespace Drupal\cluster_hid;

/**
 * Maps a hid API user object to a Drupal user.
 */
class ClusterHidUser {

  private $hid_user;

  public function __construct($hid_user) {
    $this->hid_user = $hid_user;
  }

  public function userAlreadyExistsWithSameEmail() {

  }

  public function userAlreadyRegisterWithHybridAuth() {

  }

  public function createNewDrupalUser() {

  }

  public function updateHidUserData() {

  }

}