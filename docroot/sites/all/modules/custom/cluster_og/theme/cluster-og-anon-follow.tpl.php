<?php
/**
 * @var string $follow_path
 * @var string $group_type
 * @var array $form
 */
?>
<section id="anon-follow">
  <div>
    <?php print t('Subscribe to <strong>notifications</strong> about this @type by creating an account or logging in (recommended).', [
      '@type' => $group_type,
    ]); ?>
  </div>
  <a href="<?php print url($follow_path); ?>" class="follow">
    <?php print t('Sign up or log in'); ?>
  </a>
  <?php print render($form); ?>
</section>
