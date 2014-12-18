<div id="page">

  <header>

    <section id="site-options-bar" class="clearfix">
      <div class="page-margin">
        <div id="language-selector" class="clearfix">
          <ul class="languages">
            <li class="language"><a href="#" class="active">en</a></li>
            <li class="language"><a href="#">fr</a></li>
            <li class="language"><a href="#">es</a></li>
            <li class="language"><a href="#">ar</a></li>
          </ul>
        </div>
        <div id="bandwidth-selector">
          <?php print _svg('icons/signal', array('id'=>'bandwidth-selector-icon', 'alt' => 'Bandwidth indication icon')); ?>
          <a href="#" class="active">Low bandwidth environment</a>
          <span>/</span>
          <a href="#">Swicth to high</a>
        </div>
      </div>
    </section>

    <section id="site-branding" class="clearfix">
      <div class="page-margin clearfix">

        <a id="logo-shelter-cluster" href="http://sheltercluster.org">
          <?php print _svg('logo-global-shelter-cluster', array('id'=>'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
        </a>

        <ul id="profile-menu-items">
          <li class="profile-item"><a href="">Login</a></li>
          <li class="profile-item"><a href="">Create an account</a></li>
        </ul>

        <form class="search" action="http://www.google.com/search" method="get">
          <input class="text-field" type="search" placeholder="Search site" name="q">
          <input class="submit" type="submit" value="Go">
        </form>

      </div>
    </section>
    <div class="page-margin">
      <nav id="nav-shelter" class="clearfix">
        <a href="#" id="button-menu-dropdown">Menu</a>
        <ul class="nav-items">
          <li class="nav-item"><a href="#">Home</a></li>
          <li class="nav-item"><a href="#">Current Operations</a></li>
          <li class="nav-item"><a href="#">Global</a></li>
          <li class="nav-item"><a href="#">Regions & Countries</a></li>
          <li class="nav-item"><a href="#">Communities of Practice</a></li>
          <li class="nav-item"><a href="#">References</a></li>
        </ul>
        <ul class="sub-nav">
          <li class="nav-item"><a href="#">Manage your profile</a></li>
          <li class="nav-item"><a href="#">Disconnect</a></li>
        </ul>
      </nav>
    </div>
  </header>

  <div id="content">

    <div class="page-margin clearfix">
      <?php if ($messages) { print $messages; } ?>
    </div>

    <div id="content-header">
      <div class="page-margin clearfix">
        <div class="main-column">

          <section id="active-responses" class="clearfix">
            <h1>Active Responses</h1>
            <ul id="major-responses">
              <li>
                <a href="#">Typhoon Haian</a>
                <?php print _svg('icons/complex-crisis', array('class'=>'complex-crisis-icon', 'alt' => 'Complex crisis icon')); ?>
              </li>
              <li>
                <a href="#">Fukushima Earthquake</a>
                <?php print _svg('icons/natural-disaster', array('class'=>'natural-disaster-icon', 'alt' => 'Natural disaster icon')); ?>
              </li>
              <li>
                <a href="#">Hurricane Katrina</a>
                <?php print _svg('icons/natural-disaster', array('class'=>'natural-disaster-icon', 'alt' => 'Natural disaster icon')); ?>
                <?php print _svg('icons/complex-crisis', array('class'=>'complex-crisis-icon', 'alt' => 'Complex crisis icon')); ?>
              </li>
            </ul>
            <ul id="legend">
              <li><?php print _svg('icons/conflict', array('class'=>'conflict-icon', 'alt' => 'Conflict icon')); ?> Conflict</li>
              <li><?php print _svg('icons/complex-crisis', array('class'=>'complex-crisis-icon', 'alt' => 'Complex crisis icon')); ?> Complex Crisis</li>
              <li><?php print _svg('icons/natural-disaster', array('class'=>'natural-disaster-icon', 'alt' => 'Natural disaster icon')); ?> Natural Disaster</li>
              <li><?php print _svg('icons/man-made-disaster', array('class'=>'man-made-disaster-icon', 'alt' => 'Man-made disaster icon')); ?> Man-made disaster</li>
            </ul>
          </section>

          <section id="featured-documents">
            <ul>
              <li>
                 <img src="sites/all/themes/shelter/assets/images/fake/feature-document.jpg" alt="" />
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
        <div class="side-column">

          <section id="join-group">
            <h4>Join our mailinglist</h4>
            <fieldset>
              <label>
                <input type="checkbox"/>
                <span>Register to the "Global Response" mailinglist</span>
              </label>
            </fieldset>
            <fieldset>
              <input type="email" name="email" placeholder="Your Email Address" />
            </fieldset>
            <div id="button-join-group"><a href="#">Join</a></div>
          </section>

          <section id="shelter-calendar">
            <div id="calendar-box">
              <div id="calendar-date">
                <?php print _svg('icons/pin', array('id'=>'calendar-pin', 'alt' => 'Pin icon')); ?>Nov. 24th 2014
              </div>
              <div id="calendar-event">
                <span class="upcoming" href="#">Upcoming envent to <a href="#">agenda</a>:</span>
                <a class="event" href="#">Shelter Technical Meeting 2014</a></div>
            </div>
            <a class="see-all" href="#">All calendar events</a>
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

    <div class="page-margin clearfix">
      <div class="main-column">


        <div id="content-rendered">
          <?php print render($page['content']); ?>
        </div>

      </div>

    </div>
  </div>

  <footer>
    <div class="page-margin clearfix">
      <form class="search" action="http://www.google.com/search" method="get">
        <input class="text-field" type="search" placeholder="Search site" name="q">
        <input class="submit" type="submit" value="Go">
      </form>
    </div>

    <div class="page-margin">
      <section id="active-clusters-list">
        <h3>With 24 <a href='#'>active responses</a> and cluster like mechanisms.</h3>
        <ul class="clusters">
          <li class="cluster"><a href="#">Myanmar Rakhine and Kachin Emergency Response</a></li>
          <li class="cluster"><a href="#">Philippines Bohol Earthquake</a></li>
          <li class="cluster"><a href="#">Solomon Islands Floods 2014</a></li>
        </ul>
        <a class="complete-list" href="#">[...] more</a>

      </section><section id="regions-list">
        <h3>Shelter Cluster is present in over <a href="#">34 regions</a>.</h3>
        <?php print render($page['footer']['menu_regions']); ?>
      </section>

      <section id="general-information">
        <h3>General Information</h3>
        <ul class="links">
          <li class="link"><a href="#">About this site</a></li>
          <li class="link"><a href="#">Contact information</a></li>
          <li class="link"><a href="#">Twitter account</a></li>
        </ul><ul class="links">
          <li class="link"><a href="#">Support Team</a></li>
          <li class="link"><a href="#">Partnership</a></li>
        </ul><ul class="links">
          <li class="link"><a href="#">Other</a></li>
          <li class="link"><a href="#">More information</a></li>
          <li class="link"><a href="#">Twitter account</a></li>
        </ul>
      </section>

      <section id="partners-list">
        <ul class="partners clearfix">
          <li class="partner"><a href="#">ECHO</a></li>
          <li class="partner"><a href="#">IFRC</a></li>
          <li class="partner"><a href="#">UNHCR</a></li>
        </ul>
      </section>

    </div>
  </footer>

</div>
