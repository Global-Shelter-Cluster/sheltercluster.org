<a href="<?php print url('<front>', ['absolute' => TRUE]); ?>">
  <img
    style="width: 200px"
    src="<?php print check_url($logo); ?>"
  />
</a>

<?php

$items = [];

if ($data['cluster_factsheets'])
  $items[] = format_plural(
    count($data['cluster_factsheets']),
    'New factsheet',
    '@count new factsheets'
  );

if ($data['cluster_docs'])
  $items[] = format_plural(
    count($data['cluster_docs']),
    '1 new document',
    '@count new documents'
  );

if ($data['cluster_og'])
  $items[] = format_plural(
    count($data['cluster_og']),
    '1 new page',
    '@count new pages'
  );

if ($items): ?>

<p style="display: none;">
  <?php print implode(check_plain(' · '), $items).'.'; ?>
</p>

<?php endif;
