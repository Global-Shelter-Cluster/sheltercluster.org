<li class="coordination-item">
  <div class="avatar">
    <?php if (isset($user_profile['user_picture'])): ?>
      <?php print render($user_profile['user_picture']); ?>
    <?php endif; ?>
  </div>
  <div class="information">
    <?php print render($user_profile['name']); ?>
    <span class="job-title">National Coordinator</span>
    <a class="telephone" href="tel:+09084011218">0908 401 1218</a>
    <?php print render($user_profile['email']); ?></a>
  </div>
</li>
