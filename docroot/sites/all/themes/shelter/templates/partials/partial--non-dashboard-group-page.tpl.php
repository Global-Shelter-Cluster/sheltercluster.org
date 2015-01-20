<section id="content" class="clearfix">

  <div class="side-column">
    <?php print render($editor_menu); ?>
    <?php print render($dashboard_menu); ?>
  </div>

  <div class="main-column">
    <?php print render($page['content']); ?>
  </div>

</section>