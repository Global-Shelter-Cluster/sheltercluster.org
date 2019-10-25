<table cellpadding="0" cellspacing="0" border="0" style="
  min-width: 70%;
  border-collapse: collapse;
">
  <?php if ($item['headers']): ?>
  <thead style="
    background-color: #7F1416;
    color: white;
  ">
  <tr>
    <?php foreach ($item['headers'] as $header): ?>
    <th style="padding: 7px 5px; text-align: left;">
      <?php print check_plain($header); ?>
    </th>
    <?php endforeach; ?>
  </tr>
  </thead>
  <?php endif; ?>
  <?php if ($item['rows']): ?>
  <tbody style="
  ">
  <?php foreach ($item['rows'] as $row): ?>
  <tr>
    <?php foreach ($row as $cell): ?>
    <td style="padding: 5px; border: 1px solid #d7d7d7;">
      <?php
      $title = isset($cell['title']) ? $cell['title'] : $cell['url'];
      if (isset($cell['url']))
        print l($title, $cell['url']);
      else
        print check_plain($title);
      ?>
    </td>
    <?php endforeach; ?>
  </tr>
  <?php endforeach; ?>
  </tbody>
  <?php endif; ?>
</table>
