<?php

/**
 * @file
 * Default theme implementation to present all user profile data.
 */

?>
<div class="profile"<?php print $attributes; ?>>
  <div class="profile-header clearfix">
    <div class="avatar">
      <?php print render($user_profile['user_picture']); ?>
    </div>
    <?php print render($user_profile['name']); ?>
    <?php print render($user_profile['email']); ?>
  </div>

  <div class="history">
    <?php print render($user_profile['summary']); ?>
  </div>
  <?php print render($user_profile); ?>
</div>
