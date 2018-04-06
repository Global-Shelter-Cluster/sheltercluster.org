<table>
  <tr>
    <th>Name</th>
    <th>Email</th>
    <th>Organization</th>
    <th>Sheltercluster.org User</th>
  </tr>
  <?php foreach($users as $user): ?>
    <tr>
      <td><?php print $user->getFullName(); ?></td>
      <td><?php print $user->getEmail(); ?></td>
      <td><?php print $user->getOrganizationName(); ?></td>
      <td><?php print $user->userLink(); ?></td>
    </tr>
  <?php endforeach; ?>
</table>
