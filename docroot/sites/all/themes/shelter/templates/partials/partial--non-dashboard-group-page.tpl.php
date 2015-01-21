<section id="content" class="clearfix">

  <div class="side-column">

    <?php if ($editor_menu): ?>
      <section id="add-content" class="clearfix">
        <h3 data-collapsible="add-content-container" data-collapsible-default="collapsed">Add content</h3>
        <div id="add-content-container">
          <?php print render($editor_menu); ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if ($local_tasks): ?>
      <section id="admin-links" class="clearfix">
        <h3 data-collapsible="admin-links-container" data-collapsible-default="collapsed">Group Administration</h3>
        <div id="admin-links-container">
          <?php print render($local_tasks); ?>
        </div>
      </section>
    <?php endif; ?>

    <?php if ($dashboard_menu): ?>
      <section id="secondary-nav">
        <?php print render($dashboard_menu); ?>
      </section>
    <?php endif; ?>

  </div>

  <div class="main-column">
    <?php print render($page['content']); ?>
  </div>

</section>
