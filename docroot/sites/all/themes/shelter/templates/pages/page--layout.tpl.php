<div id="page">

  <header>

    <section id="site-options-bar" class="clearfix">
      <div class="page-margin">
        <div id="language-selector" class="clearfix">
          <ul class="languages">
            <li class="language"><a href="" class="active">en</a></li>
            <li class="language"><a href="">fr</a></li>
            <li class="language"><a href="">es</a></li>
            <li class="language"><a href="">ar</a></li>
          </ul>
        </div>
        <div id="bandwidth-selector">
          <?php print _svg('icons/signal', array('id'=>'bandwidth-selector-icon', 'alt' => 'Bandwidth indication icon')); ?>
          <a href="" class="active">Low bandwidth environment</a>
          <span>/</span>
          <a href="">Swicth to high</a>
        </div>
      </div>
    </section>

    <div class="page-margin clearfix">

      <a id="logo-shelter-cluster" href="http://sheltercluster.org">
        <?php print _svg('logo-global-shelter-cluster', array('id'=>'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
      </a>

      <ul id="profile-menu-items">
        <li class="profile-item"><a href="">Login</a></li>
        <li class="profile-item"><a href="">Create an account</a></li>
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
          <li class="nav-item"><a href="">Home</a></li>
          <li class="nav-item"><a href="">Current Operations <span class="total">(10)</span></a></li>
          <li class="nav-item"><a href="">Documents <span class="total">(8200)</span></a></li>
          <li class="nav-item"><a href="">Geographic Aggregators</a></li>
          <li class="nav-item"><a href="">Communities of Practice <span class="total">(6)</span></a></li>
          <li class="nav-item"><a href="">References <span class="total">(34)</span></a></li>
          <li class="sub-nav">
            <ul>
              <li class="nav-item"><a href="">Manage your profile</a></li>
              <li class="nav-item"><a href="">Disconnect</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </nav>

    <section id="secondary-nav">
      <div class="page-margin clearfix">
        <ul class="nav-items">
          <li class="nav-item"><a href="" class="active">Dashboard</a></li>
          <li class="nav-item"><a href="">Documents <span class="total">(8200)</span></a></li>
          <li class="nav-item"><a href="">Discussions</a></li>
          <li class="nav-item"><a href="">Agenda</a></li>
          <li class="nav-item"><a href="">Strategic Advisory</a></li>
          <li class="nav-group clearfix">
            <h3>Hubs</h3>
            <ul class="nav-items">
              <li class="nav-item"><a href="">Manilla Hub</a></li>
              <li class="nav-item"><a href="">Cebu Hub</a></li>
              <li class="nav-item"><a href="">Guiuian Hub</a></li>
              <li class="nav-item"><a href="">Roxas Hub</a></li>
              <li class="nav-item"><a href="">Ormoc Hub</a></li>
            </ul>
          </li>
          <li class="nav-group clearfix">
            <h3>Pages</h3>
            <ul class="nav-items">
              <li class="nav-item"><a href="">Something</a></li>
              <li class="nav-item"><a href="">More</a></li>
            </ul>
          </li>
        </ul>
      </div>
    </section>

  </header>

  <div id="content">

    <div class="page-margin clearfix">

      <?php if ($messages) { print $messages; } ?>

      <div id="content-header">

        <section id="operation-information">
          <h1>Typhoon Haiyan</h1>
          <p>Operation started November 8th, 2013, and is on going.</p>
          <ul id="meta-data">
            <li class="data-item"><span>Type:</span> Windstorm</li>
            <li class="data-item"><span>Damage Location:</span> Rural, Peri-Urban, Urban</li>
            <li class="data-item"><span>Degree of Displacement:</span> Hight</li>
            <li class="data-item"><span>Emergency Lead Agency</span> IFRC</li>
          </ul>
        </section>

        <section id="operation-group">
          <h3>Join this Operation Group and</h3>
          <fieldset id="checkboxgroup">
            <label><input type="checkbox"/> Receive notifications</label>
            <label><input type="checkbox"/> Register to this group the mailing list</label>
            <label><input type="checkbox"/> Register to the "Global Response" mailinglist</label>
          </fieldset>
          <div id="button-join-group"><a class="button" href="">Join</a></div>
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

      <div id="content-rendered">
        <?php print render($page['content']); ?>
      </div>

    </div>
  </div>

  <footer>
    <div class="page-margin clearfix">
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
