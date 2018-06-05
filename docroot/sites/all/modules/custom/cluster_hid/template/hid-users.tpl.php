<table>
  <tr>
    <th width="20%"> </th>
    <th width="40%">Humanitarian id</th>
    <th width="40%">Drupal</th>
  </tr>
  <?php foreach($users as $user): ?>
    <tr>
      <td>ID</td>
      <td><?php print $user->getHumanitarianId(); ?></td>
      <td><?php print render($user->userLink()); ?></td>
    </tr>
    <tr>
      <td>Name</td>
      <td><?php print $user->getFullName(); ?></td>
      <td><?php print $user->getDrupalUserField('name_field'); ?></td>
    </tr>
    <tr>
      <td>Email</td>
      <td><?php print $user->getEmail(); ?></td>
      <td><?php print $user->getDrupalEmail(); ?></td>
    </tr>
    <tr>
      <td>Organization</td>
      <td><?php print $user->getOrganizationName(); ?></td>
      <td><?php print $user->getDrupalUserField('field_organisation_name'); ?></td>
    </tr>
    <tr>
      <td>Role or Title</td>
      <td><?php print $user->getRoleOrTitle(); ?></td>
      <td><?php print $user->getDrupalUserField('field_role_or_title'); ?></td>
    </tr>
    <tr>
      <td>Phone Number</td>
      <td><?php print $user->getPhoneNumber(); ?></td>
      <td><?php print $user->getDrupalUserField('field_phone_number'); ?></td>
    </tr>
    <tr>
      <td>Address</td>
      <td><?php print $user->getAddress(); ?></td>
      <td></td>
    </tr>
    <tr>
      <td>Picture</td>
      <td><?php print render($user->getPictureTag()); ?></td>
      <td><?php print render($user->getDrupalUserPicture()); ?></td>
    </tr>
  <?php endforeach; ?>
</table>
