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

  public function getDrupalEmail() {
    if (!$this->userHasDrupalAccount()) {
      return NULL;
    }
    return $this->hidUser->drupalUser->mail;
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

  public function getDrupalUserField($field_name) {
    if (!$this->userHasDrupalAccount()) {
      return NULL;
    }
    $user = $this->hidUser->drupalUser;
    if (!$user->{$field_name}) {
      return;
    }
    $field = $user->{$field_name};
    $potentially_localized_field = array_pop($field);
    return $potentially_localized_field[0]['value'];
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
   * @TODO
   */
  public function getAddress() {

  }

  /**
   * Provide link to drupal user profile if it exists, link to user creation otherwise.
   */
  public function userLink() {
    $uid = $this->getDrupalUid();

    // Existing Drupal user.
    if ($this->userHasDrupalAccount()) {
      $link_options = [
        'attributes' => [
          'class' => ['update-hid-user'],
          'data-humid' => $this->getHumanitarianId(),
        ],
      ];

      // List of links.
      return [
        '#theme' => 'item_list',
        '#items' => [
          l(t('User id: @uid', ['@uid' => $uid]), 'user/' . $uid),
          l(t('Update Drupal values from Humanitarian ID'), '#', $link_options),
        ],
      ];
    }

    // No drupal user.
    $link_options = [
      'attributes' => [
        'class' => ['create-new-hid-user'],
        'data-humid' => $this->getHumanitarianId(),
      ]
    ];
    return l(t('Create New Drupal User'), '#', $link_options);
  }

  public function userSynchLink() {
    return '@TODO';
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
    $user = user_load_by_mail($this->hidUser->email);
    // Track the user in the cluster_hid table.
    if ($user) {
      db_merge('cluster_hid')
        ->key(['uid' => $user->uid])
        ->fields([
            'uid' => $user->uid,
            'hum_id' => $this->getHumanitarianId(),
        ])
        ->execute();
    }
    return $user;
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

    $this->populateCommonFieldsForCreateOrUpdate($new_user);

    $user = user_save($new_user);
    return $user->uid;
  }

  public function updateHidUserData() {
    if (!$this->userHasDrupalAccount()) {
      throw new \Exception('Cannot update, no Drupal user.');
    }
    $user = $this->hidUser->drupalUser;
    $this->populateCommonFieldsForCreateOrUpdate($user);
    $user = user_save($user);
    return $user->uid;
  }

  private function populateCommonFieldsForCreateOrUpdate($user) {
    $user->name_field['en'][0]['value'] = $this->getFullName();
    $organization_name = $this->getOrganizationName();
    if ($organization_name) {
      $user->field_organisation_name['en'][0]['value'] = $organization_name;
    }

    $phone_number = $this->getPhoneNumber();
    if ($phone_number) {
      $user->field_phone_number[LANGUAGE_NONE][0]['value'] = $phone_number;
    }

    $role_or_title = $this->getRoleOrTitle();
    if ($role_or_title) {
      $user->field_role_or_title[LANGUAGE_NONE][0]['value'] = $role_or_title;
    }
  }

  public static function create($hid_user) {
    return new static($hid_user);
  }

  /**
   * Test if a given user id is matched to a humanitarian id.
   */
  public static function drupalUserHasHumanitarianId($uid) {
    $hum_id = db_select('cluster_hid', 'c')
      ->fields('c', ['hum_id'])
      ->condition('uid', $uid)
      ->execute()
      ->fetchField();
    return $hum_id;
  }

}
