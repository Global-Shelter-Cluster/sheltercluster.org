<section id="secondary-nav">
  <div class="page-margin clearfix">
    <ul class="nav-items clearfix">
      <li class="nav-item"><a href="" class="active">Dashboard</a></li>
      <li class="nav-item"><a href="">Documents <span class="total">(8200)</span></a></li>
      <li class="nav-item"><a href="">Discussions</a></li>
      <li class="nav-item"><a href="">Agenda</a></li>
      <li class="nav-item"><a href="">Strategic Advisory</a></li>
    </ul>

    <ul class="nav-items">
      <?php if (isset($content['related_hubs'])): ?>
        <li class="nav-group clearfix">
          <?php print render($content['related_hubs']); ?>
        </li>
      <?php endif; ?>
      <?php if (isset($content['related_responses'])): ?>
        <li class="nav-group clearfix">
          <?php print render($content['related_responses']); ?>
        </li>
      <?php endif; ?>
    </ul>

    <a href="#secondary-nav" class="collapse-menu">
      <?php print _svg('icons/collapse-down', array('alt' => 'Icon for collapsing the menu')); ?>
      more
    </a>

    <ul class="nav-items collapsable hide-this">
        <li class="nav-group clearfix">
          TEST
        </li>
    </ul>

  </div>
</section>

<div id="content">

  <div id="content-header">
    <div class="page-margin clearfix">

      <div class="main-column">

        <?php $contextual_navigation = node_view($node, 'contextual_navigation') ?>
        <?php print render($contextual_navigation); ?>

        <section id="operation-information">
          <h1><?php print $title; ?></h1>
          <p>Operation started November 8th, 2013, and is on going.</p>
          <ul id="meta-data">
            <li class="data-item"><span>Type:</span> Windstorm</li>
            <li class="data-item"><span>Damage Location:</span> Rural, Peri-Urban, Urban</li>
            <li class="data-item"><span>Degree of Displacement:</span> Hight</li>
            <li class="data-item"><span>Emergency Lead Agency</span> IFRC</li>
          </ul>
        </section>
        <?php print render($content); ?>
      </div>

      <div class="side-column">
        <section id="operation-group">
          <h3>Join this Operation Group and</h3>
          <fieldset id="checkboxgroup">
            <label><input type="checkbox" selected="selected"/> Receive notifications</label>
            <label><input type="checkbox" selected="selected"/> Register to this group the mailing list</label>
            <label><input type="checkbox"/> Register to the "Global Response" mailinglist</label>
          </fieldset>
          <div id="button-join-group"><a class="button" href="">Join</a></div>
        </section>
      </div>

    </div>
  </div>

  <div>
    <div class="page-margin clearfix">
      <div class="main-column">

        <section id="featured-documents">
          <ul>
            <li>
               <img src="/sites/all/themes/shelter/assets/images/fake/feature-document.jpg" alt="" />
                <div class="document-information">
                  <h2>Featured Document Title 1</h2>
                  <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
                </div>
            </li>
            <li>
              <img src="sites/all/themes/shelter/assets/images/fake/feature-document.jpg" alt="" />
              <div class="document-information">
                <h2>Featured Document Title 2</h2>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
            </li>
          </ul>
        </section>

      </div>
    </div>
  </div>

</div>
