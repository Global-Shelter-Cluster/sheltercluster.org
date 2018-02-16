<table>
  <tr>
    <th>Given Name</th>
    <th>Last Name</th>
    <th>Email</th>
    <th>Organization</th>
  </tr>
  <?php foreach($users as $user): ?>
    <tr>
      <td><?php print $user->given_name; ?></td>
      <td><?php print $user->family_name; ?></td>
      <td><?php print $user->email; ?></td>
      <td><?php print $user->organization->name; ?></td>
    </tr>
  <?php endforeach; ?>
</table>