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
