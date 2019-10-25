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
