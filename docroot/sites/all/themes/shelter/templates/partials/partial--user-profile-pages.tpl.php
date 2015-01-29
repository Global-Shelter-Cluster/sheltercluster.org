<section id="content" class="clearfix">

  <div class="side-column">

    <?php if ($local_tasks): ?>
      <section id="user-profile-links" class="clearfix">
        <h3>Navigation</h3>
        <div id="user-profile-links-container">
          <ul>
            <?php print render($local_tasks); ?>
          </ul>
        </div>
      </section>
    <?php endif; ?>

  </div>

  <div class="main-column">
    <?php print render($page['content']); ?>
  </div>

</section>
