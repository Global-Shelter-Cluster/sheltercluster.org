<section id="content" class="clearfix">

  <div class="side-column">

    <?php if ($local_tasks): ?>
      <section id="user-profile-links" class="clearfix">
        <h3>Navigation</h3>
        <div id="user-profile-links-container">
          <?php print render($local_tasks); ?>
        </div>
      </section>
    <?php endif; ?>

  </div>

  <div class="main-column">
    <?php print render($page['content']); ?>
  </div>

</section>
