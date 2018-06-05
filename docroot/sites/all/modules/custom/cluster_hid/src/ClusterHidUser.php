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

  public function getPicture() {
    if (isset($this->hidUser->picture)) {
      return $this->hidUser->picture;
    }
    return FALSE;
  }

  public function getPictureTag() {
    $url = $this->getPicture();
    if (!$url) {
      return FALSE;
    }
    return [
      '#theme' => 'image',
      '#path' => $url,
    ];
  }

  public function getDrupalUserPicture() {
    if (!$this->userHasDrupalAccount()) {
      return NULL;
    }

    return [
      '#theme' => 'user_picture',
      '#account' => $this->hidUser->drupalUser,
    ];
  }

  /**
   * @TODO
   */
  public function getAddress() {}

  /**
   * Provides markup to let a user account be updated, if possible.
   */
  public function getUpdateLink() {
    // Make sure the email address in Drupal and Humanitarian id are matching.
    $drupalAccount = $this->getDrupalAccount();
    $output = [
      '#prefix' => '<div>',
      '#suffix' => '</div>',
    ];

    if (!$drupalAccount) {
      $text = t('The drupal account email address does not match the Humanitarian id email address - no synch possible.');
      $output['#markup'] = $text;
    }
    else {
      $output['#markup'] = l(t('Synch profile with Humanitarian.id'), 'update-profile-from-hid-id/' . $drupalAccount->uid);
    }
    return $output;
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
      $this->trackUser($user->uid);
    }
    return $user;
  }

  /**
   * Update the cluster_hid table with the user information.
   */
  private function trackUser($uid) {
    db_merge('cluster_hid')
      ->key(['uid' => $uid])
      ->fields([
        'uid' => $uid,
        'hum_id' => $this->getHumanitarianId(),
        'data' => serialize($this->hidUser),
      ])
      ->execute();
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
      throw new \Exception('Cannot update, no Drupal user for email ' . $this->getEmail());
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
      $user->field_role_or_title['en'][0]['value'] = $role_or_title;
    }

    $picture_file = $this->savePicture();
    if ($picture_file) {
      $user->picture = $picture_file;
    }
  }

  /**
   * Saves the picture from Humanitarian id to Drupal file system and returns file object.
   */
  private function savePicture() {
    $image_path = $this->getPicture();
    if (!$image_path) {
      return FALSE;
    }
    $file = system_retrieve_file($image_path, 'public://pictures', TRUE, FILE_EXISTS_REPLACE);
    return $file;
  }

  public static function create($hid_user) {
    return new static($hid_user);
  }

  /**
   * Test if a given Drupal user id is matched to a known humanitarian id.
   */
  public static function drupalUserHasHumanitarianId($uid) {
    // Test the cluster_hid database.
    $hum_id = db_select('cluster_hid', 'c')
      ->fields('c', ['hum_id'])
      ->condition('uid', $uid)
      ->execute()
      ->fetchField();

    // Test the hybrid auth database.
    if (!$hum_id && module_exists('hybridauth')) {
      $hum_id = db_select('hybridauth_identity', 'hi')
        ->fields('hi', ['provider_identifier'])
        ->condition('uid', $uid)
        ->condition('provider', 'HumanitarianId')
        ->execute()
        ->fetchField();
    }
    return $hum_id;
  }

}
