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

        <?php if (isset($contextual_navigation)): ?>
          <?php print $contextual_navigation; ?>
        <?php endif; ?>

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

        <?php print render($content); ?>

      </div>

      <div class="side-column">
        <section id="shelter-discussions">
          <h3>Discussions</h3>
          <ul id="discussions-items">
            <li class="discussions-item">
              <div class="replies">24 replies</div>
              <div class="information">
                <a href="#" class="topic">Where can I find lumber?</a>
                <span class="date">2014/10/03 by <a class="author" href="#">Jane Wikionsons</a></span>
              </div>
            </li>
            <li class="discussions-item">
              <div class="replies">no replies <span class="new">New</span></div>
              <div class="information">
                <a href="#" class="topic">Are any special requirements for protection needed when entering the</a>
                <span class="date">2014/10/15 by <a class="author" href="#">John Tremblay</a></span>
              </div>
            </li>
          </ul>
          <a class="see-all" href="#">All other discussions</a>
        </section>

        <section id="shelter-coordination-team">
          <h3>Coordination Team</h3>
          <h4>National Team</h4>
          <ul id="coordination-items" class="clearfix">
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Victoria Stodard (IFRC)</span>
                <span class="job-title">National Coordinator</span>
                <a class="telephone" href="tel:+09084011218">0908 401 1218</a>
                <a class="email" href="mailto:coord.phil@sheltercluster.org">coord.phil@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Tom York (CRS)</span>
                <span class="job-title">National Information Management</span>
                <a class="telephone" href="tel:+09084011218">0908 555 1790</a>
                <a class="email" href="mailto:tom.york@sheltercluster.org">tom.york@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Gian Gimang (IFRC)</span>
                <span class="job-title">Assistant Techhical Coordination</span>
                <a class="telephone" href="tel:+09084011218">0966 666 1256</a>
                <a class="email" href="mailto:gian.gimang@sheltercluster.org">gian.gimang@sheltercluster.org</a>
              </div>
            </li>
          </ul>

          <h4>Region VIII</h4>
          <ul id="coordination-items" class="clearfix">
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Victoria Stodard (IFRC)</span>
                <span class="job-title">National Coordinator</span>
                <a class="telephone" href="tel:+09084011218">0908 401 1218</a>
                <a class="email" href="mailto:coord.phil@sheltercluster.org">coord.phil@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Tom York (CRS)</span>
                <span class="job-title">National Information Management</span>
                <a class="telephone" href="tel:+09084011218">0908 555 1790</a>
                <a class="email" href="mailto:tom.york@sheltercluster.org">tom.york@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Gian Gimang (IFRC)</span>
                <span class="job-title">Assistant Techhical Coordination</span>
                <a class="telephone" href="tel:+09084011218">0966 666 1256</a>
                <a class="email" href="mailto:gian.gimang@sheltercluster.org">gian.gimang@sheltercluster.org</a>
              </div>
            </li>
          </ul>

          <h4>Guiuan Sub-Hub</h4>
          <ul id="coordination-items" class="clearfix">
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Victoria Stodard (IFRC)</span>
                <span class="job-title">National Coordinator</span>
                <a class="telephone" href="tel:+09084011218">0908 401 1218</a>
                <a class="email" href="mailto:coord.phil@sheltercluster.org">coord.phil@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Tom York (CRS)</span>
                <span class="job-title">National Information Management</span>
                <a class="telephone" href="tel:+09084011218">0908 555 1790</a>
                <a class="email" href="mailto:tom.york@sheltercluster.org">tom.york@sheltercluster.org</a>
              </div>
            </li>
            <li class="coordination-item">
              <div class="avatar">
                <?php print _svg('icons/person', array('id'=>'person-avatar', 'alt' => 'Avatar person icon')); ?>
              </div>
              <div class="information">
                <span class="name">Gian Gimang (IFRC)</span>
                <span class="job-title">Assistant Techhical Coordination</span>
                <a class="telephone" href="tel:+09084011218">0966 666 1256</a>
                <a class="email" href="mailto:gian.gimang@sheltercluster.org">gian.gimang@sheltercluster.org</a>
              </div>
            </li>
          </ul>
        </section>

      </div>
    </div>
  </div>

</div>
