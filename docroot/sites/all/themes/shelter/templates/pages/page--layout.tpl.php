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

    <div class="page-margin clearfix">

      <a id="logo-shelter-cluster" href="http://sheltercluster.org">
        <?php print _svg('logo-global-shelter-cluster', array('id'=>'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
      </a>

      <ul id="profile-menu-items">
        <li class="profile-item"><a href="#">Login</a></li>
        <li class="profile-item"><a href="#">Create an account</a></li>
      </ul>

      <form class="search" action="http://www.google.com/search" method="get">
        <input class="text-field" type="search" placeholder="Search documents" name="q">
        <input class="submit" type="submit" value="Search">
      </form>

    </div>

    <nav id="nav-shelter" class="clearfix">
      <div class="page-margin">
        <a href="#" id="button-menu-dropdown">Menu</a>
        <ul class="nav-items">
          <li class="nav-item"><a href="#">Home</a></li>
          <li class="nav-item"><a href="#">Current Operations <span class="total">(10)</span></a></li>
          <li class="nav-item"><a href="#">Documents <span class="total">(8200)</span></a></li>
          <li class="nav-item"><a href="#">Geographic Aggregators</a></li>
          <li class="nav-item"><a href="#">Communities of Practice <span class="total">(6)</span></a></li>
          <li class="nav-item"><a href="#">References <span class="total">(34)</span></a></li>
          <li class="sub-nav">
            <ul>
              <li class="nav-item"><a href="#">Manage your profile</a></li>
              <li class="nav-item"><a href="#">Disconnect</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </nav>

    <section id="secondary-nav">
      <div class="page-margin clearfix">
        <ul class="nav-items clearfix">
          <li class="nav-item"><a href="#" class="active">Dashboard</a></li>
          <li class="nav-item"><a href="#">Documents <span class="total">(8200)</span></a></li>
          <li class="nav-item"><a href="#">Discussions</a></li>
          <li class="nav-item"><a href="#">Agenda</a></li>
          <li class="nav-item"><a href="#">Strategic Advisory</a></li>
        </ul>
        <a href="#secondary-nav" class="collapse-menu">
          <?php print _svg('icons/collapse-down', array('alt' => 'Icon for collapsing the menu')); ?>
          more
        </a>
        <ul class="nav-items collapsable hide-this">
          <li class="nav-group clearfix">
            <h3>Hubs</h3>
            <ul class="nav-items">
              <li class="nav-item">
                <a href="#">
                  <?php print _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')); ?>
                  Manilla Hub
                </a>
              </li>
              <li class="nav-item">
                <a href="#">
                  <?php print _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')); ?>
                  Cebu Hub
                </a>
              </li>
              <li class="nav-item">
                <a href="#">
                  <?php print _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')); ?>
                  Guiuian Hub
                </a>
              </li>
              <li class="nav-item">
                <a href="#">
                  <?php print _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')); ?>
                  Roxas Hub
                </a>
              </li>
              <li class="nav-item">
                <a href="#">
                  <?php print _svg('icons/grid-three-up', array('alt' => 'Icon for Hubs')); ?>
                  Ormoc Hub
                </a>
              </li>
            </ul>
          </li><li class="nav-group clearfix">
            <h3>Pages</h3>
            <ul class="nav-items">
              <li class="nav-item"><a href="#">Something</a></li>
              <li class="nav-item"><a href="#">More</a></li>
            </ul>
          </li><li class="nav-group clearfix">
            <h3>More Stuff</h3>
            <ul class="nav-items">
              <li class="nav-item"><a href="#">Something</a></li>
              <li class="nav-item"><a href="#">More</a></li>
              <li class="nav-item"><a href="#">And then Some</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </section>

  </header>

  <div id="content">

    <div class="page-margin clearfix">
      <?php if ($messages) { print $messages; } ?>
    </div>

    <div id="content-header">
      <div class="page-margin clearfix">

        <div class="main-column">
          <section id="operation-information">
            <h1>Typhoon Haiyan</h1>
            <img class="operation-image" src="http://placehold.it/290x150"/>
            <p>Quis enim aut eum diligat quem metuat, aut eum a quo se metui putet? Coluntur tamen simulatione dumtaxat ad tempus. Quod si forte, ut fit plerumque, ceciderunt, tum intellegitur quam fuerint inopes amicorum. Quod Tarquinium dixisse ferunt, tum exsulantem se intellexisse quos fidos amicos habuisset, quos infidos, cum iam neutris gratiam referre posset.</p>
            <p>Orientis vero limes in longum protentus et rectum ab Euphratis fluminis ripis ad usque supercilia porrigitur Nili, laeva Saracenis conterminans gentibus, dextra pelagi fragoribus patens, quam plagam Nicator Seleucus occupatam auxit magnum in modum, cum post Alexandri Macedonis obitum successorio iure teneret regna Persidis, efficaciae inpetrabilis rex, ut indicat cognomentum.</p>
            <p>Tantum autem cuique tribuendum, primum quantum ipse efficere possis, deinde etiam quantum ille quem diligas atque adiuves, sustinere. Non enim neque tu possis, quamvis excellas, omnes tuos ad honores amplissimos perducere, ut Scipio P. Rupilium potuit consulem efficere, fratrem eius L. non potuit. Quod si etiam possis quidvis deferre ad alterum, videndum est tamen, quid ille possit sustinere.</p>
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
            <h4>Join this Operation Group and</h4>
            <fieldset id="checkboxgroup">
              <label><input type="checkbox" selected="selected"/> Receive notifications</label>
              <label><input type="checkbox" selected="selected"/> Register to this group the mailing list</label>
              <label><input type="checkbox"/> Register to the "Global Response" mailinglist</label>
            </fieldset>
            <div id="button-join-group"><a class="button" href="#">Join</a></div>
          </section>
        </div>
      </div>
    </div>

    <div class="page-margin clearfix">
      <div class="main-column">

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

        <section id="key-information">
          <h3>Key Information</h3>
          <h4>Coordination information</h4>
          <ul class="document-cards clearfix">
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'File icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
          </ul>

          <h4>Cluster Guidance</h4>
          <ul class="document-cards clearfix">
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
          </ul>

          <h4>Other Sources of Information</h4>
          <ul class="document-cards clearfix">
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/book', array('class'=>'document-icon', 'alt' => 'Document icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
          </ul>

          <h4>Recent Documents</h4>
          <ul class="document-cards clearfix">
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'File icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card even">
              <div class="image-card"><?php print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'File icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
            <li class="document-card odd">
              <div class="image-card"><?php print _svg('icons/file', array('class'=>'file-icon', 'alt' => 'File icon')); ?></div>
              <div class="information-card">
                <a href="#">id lobortis leo maximus tristique</a>
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
              </div>
              <div class="information-file">
                <span class="size-type">[ 250k ] docx</span>
                <span class="source">Aenean pulvinar</span>
              </div>
            </li>
          </ul>

        </section>

        <div id="content-rendered">
          <?php print render($page['content']); ?>
        </div>

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

  <footer>
    <div class="page-margin">
      <form class="search" action="http://www.google.com/search" method="get">
        <input class="text-field" type="search" placeholder="Search documents" name="q">
        <input class="submit" type="submit" value="Search">
      </form>
    </div>

    <div class="page-margin">
      <section id="active-clusters-list">
        <h3>With 24 <a href='#'>active shelter clusters</a> and cluster like mechanism</h3>
        <ul class="clusters">
          <li class="cluster"><a href="#">Myanmar Rakhine and Kachin Emergency Response</a></li>
          <li class="cluster"><a href="#">Philippines Bohol Earthquake</a></li>
          <li class="cluster"><a href="#">Solomon Islands Floods 2014</a></li>
        </ul>
        <a class="complete-list" href="#">[...] more</a>

      </section><section id="regions-list">
        <h3>Shelter Cluster is present in over <a href="#">34 countries</a></h3>
        <ul class="regions">
          <li class="region"><a href="#" class="region-name">Africa</a>
            <ul class="countries">
              <li class="country"><a href="#">Central African Republic</a></li>
              <li class="country"><a href="#">Chad</a></li>
            </ul>
          </li><li class="region"><a href="#" class="region-name" >Americas</a>
            <ul class="countries">
              <li class="country"><a href="#">Colombia</a></li>
              <li class="country"><a href="#">Haiti</a></li>
            </ul>
          </li><li class="region"><a href="#" class="region-name">MENA</a>
            <ul class="countries">
              <li class="country"><a href="#">Iraq</a></li>
              <li class="country"><a href="#">Palestine</a></li>
              <li class="country"><a href="#">Yemen</a></li>
            </ul>
          </li>
        </ul>
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
