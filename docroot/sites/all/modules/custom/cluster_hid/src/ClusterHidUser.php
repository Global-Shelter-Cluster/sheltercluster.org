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
    return $this->hidUser->id;
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

  public function getRoleOrTitle() {
    $first_role = array_pop($this->hidUser->functional_roles);
    $first_title = array_pop($this->hidUser->job_titles);
    if (!empty($first_role)) {
      return $first_role;
    }
    if (!empty($first_title)) {
      return $first_title;
    }
    return FALSE;
  }

  public function getOrganizationName() {
    if (isset($this->hidUser->organization) && isset($this->hidUser->organization->name)) {
      return $this->hidUser->organization->name;
    }
    return FALSE;
  }

  public function getPhoneNumber() {
    $first_number = array_pop($this->hidUser->phone_numbers);
    if (isset($first_number->number)) {
      return $first_number->number;
    }
    return FALSE;
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
    $new_user->is_new = TRUE;
    $new_user->name = $this->getEmail();
    $new_user->pass = crypt(md5(rand(0,100000)+strtotime(time())+$row[0]));
    $new_user->mail = $this->getEmail();
    $new_user->status = 1;
    $new_user->init = $this->getEmail();
    $new_user->name_field['en'][0]['value'] = $this->getFullName();

    $organization_name = $this->getOrganizationName();
    if ($organization_name) {
      $new_user->field_organisation_name['en'][0]['value'] = $organization_name;
    }

    $phone_number = $this->getPhoneNumber();
    if ($phone_number) {
      $new_user->field_phone_number[LANGUAGE_NONE][0]['value'] = $phone_number;
    }

    $role_or_title = $this->getRoleOrTitle();
    if ($role_or_title) {
      $new_user->field_role_or_title[LANGUAGE_NONE][0]['value'] = $role_or_title;
    }

    $user = user_save($new_user);
    return $user->uid;
  }

  public function updateHidUserData() {

  }

  public static function create($hid_user) {
    return new static($hid_user);
  }

}
