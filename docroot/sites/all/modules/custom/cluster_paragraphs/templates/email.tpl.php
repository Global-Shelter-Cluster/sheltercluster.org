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

  switch ($item['type']) {
    case 'text': ?>
      <div>
        <?php print ($item['body']); ?>
      </div>
      <?php
      break;

    case 'images': ?>
      <div>
        <?php
        foreach ($item['images'] as $image) {
          ?>
          <img style="
            max-width: 100%;
            height: auto;
            margin: 10px 10px 0 0;
            display: inline-block;
          "
            src="<?php print check_url($image['url']); ?>"
            title="<?php print check_plain($image['title']); ?>"
            alt="<?php print check_plain($image['alt']); ?>"
          />
          <?php
        }
        ?>
      </div>
      <?php
      break;

    case 'links': ?>
      <ul>
        <?php
        foreach ($item['links'] as $link) {
          ?>
          <li style="
            margin-bottom: 5px;
          ">
            <a
              style="
                text-decoration: none;
                color: black;
              "
              href="<?php print check_url($link['url']); ?>"
            >
              <?php print check_plain($link['title']); ?>
            </a>
          </li>
          <?php
        }
        ?>
      </ul>
      <?php
      break;

    default:
      watchdog('cluster_paragraphs', 'Unknown type: @type', ['@type' => $item['type']], WATCHDOG_ERROR);
  }
}
