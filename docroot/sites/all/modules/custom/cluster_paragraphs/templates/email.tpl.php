<?php

foreach ($content as $item) {
  if (isset($item['title'])) { ?>
    <h2 style="
      border-bottom: 2px solid #575757;
      text-transform: uppercase;
      color: #575757;
      font-size: 16px;
      padding: 0 0 3px 0;
      margin: 40px 0 20px;
    ">
      <?php print check_plain($item['title']); ?>
    </h2>
  <?php
  }

  $filename = __DIR__ . '/type-' . $item['type'] . '.tpl.php';
  if (file_exists($filename))
    /** @noinspection PhpIncludeInspection */
    include $filename;
  else
    watchdog('cluster_paragraphs', 'Unknown type: @type', ['@type' => $item['type']], WATCHDOG_ERROR);
}
