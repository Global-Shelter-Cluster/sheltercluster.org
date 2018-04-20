<?php

namespace Drupal\cluster_hid;

/**
 * Maps a hid API user object to a Drupal user.
 */
class ClusterHidUser {

  private $hidUser;

  public function __construct($hid_user) {
    $this->hidUser = $hid_user;
    $this->hidUser->drupalUser = $this->getDrupalAccount();
  }

  public function getUser() {
    return $this->hidUser;
  }

  public function getHumanitarianId() {
    return $this->hidUser->user_id;
  }

  public function getEmail() {
    return $this->hidUser->email;
  }

  public function getGivenName() {
    return $this->hidUser->given_name;
  }

  public function getFamilyName() {
    return $this->hidUser->family_name;
  }

  public function getFullName() {
    return $this->getFamilyName() . ', ' . $this->getGivenName();
  }

  public function getOrganizationName() {
    return $this->hidUser->organization->name;
  }

  public function getPhoneNumber() {
    return array_pop($this->hidUser->phone_numbers)->number;
  }

  /**
   * @TODO consider using addressfield.
   */
  public function getAddress() {

  }

  /**
   * Provide link to drupal user profile if it exists, link to user creation otherwise.
   */
  public function userLink() {
    $uid = $this->getDrupalUid();
    if ($this->userHasDrupalAccount()) {
      return l('User id: ' . $uid, 'user/' . $uid);
    }
    $link_options = [
      'attributes' => [
        'class' => ['create-new-hid-user'],
        'data-humid' => $this->getHumanitarianId(),
      ]
    ];
    return l(t('Create New Drupal User'), '#', $link_options);
    return l(t('Create New Drupal User'), 'create-new-user-from-hid-id/' . $this->getHumanitarianId(), $link_options);
  }

  public function getDrupalUid() {
    if ($this->userHasDrupalAccount()) {
      return $this->hidUser->drupalUser->uid;
    }
    return FALSE;
  }

  public function userHasDrupalAccount() {
    return (bool) $this->hidUser->drupalUser;
  }

  /**
   * Test if a user with the same email address already exists.
   * @return user or false.
   */
  private function getDrupalAccount() {
    return user_load_by_mail($this->hidUser->email);
  }

  public function createNewDrupalUser() {
    if ($this->userHasDrupalAccount()) {
      throw new \Exception('Tried to create a new account for existing user in cluster_hid.');
    }
    $new_user = new \stdClass();
    $new_user->is_new = TRUE; // duh
    $new_user->name = $this->getEmail();
    $new_user->pass = base64_encode(random_bytes(10));
    $new_user->mail = $this->getEmail();
    $new_user->status = 1;
    $new_user->init = $this->getEmail();
    $new_user->name_field['en'][0]['value'] = $this->getFullName();
    $new_user->field_organisation_name['en'][0]['value'] = $this->getOrganizationName();
    $new_user->field_phone_number[LANGUAGE_NONE][0]['value'] = $this->getPhoneNumber();

    $user = user_save($new_user);
    return $user->uid;
  }

  public function updateHidUserData() {

  }

  public static function create($hid_user) {
    return new static($hid_user);
  }

}
