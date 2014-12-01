<div id="page">

  <header>

    <div class="page-margin">
      <div id="bandwidth-selector">
        <?php print _svg('icons/signal', array('id'=>'bandwidth-selector-icon', 'alt' => 'Bandwidth indication icon')); ?>
        <a href="">Low</a>
        <a href="">High</a>
      </div>
      <div id="language-selector">
        <ul class="languages">
          <li class="language"><a href="">en</a></li>
          <li class="language"><a href="">fr</a></li>
          <li class="language"><a href="">es</a></li>
          <li class="language"><a href="">ar</a></li>
        </ul>
      </div>
      <a id="button-menu-dropdown">Menu</a>

      <ul id="profile-items">
        <li class="profile-item"><a href="">Login</a></li>
        <li class="profile-item"><a href="">Create an account</a></li>
      </ul>

    </div>

    <nav id="nav-shelter">
      <div class="page-margin">
        <ul id="nav-items">
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

    <div class="page-margin">
      <a id="logo-shelter-cluster" href="http://sheltercluster.org">
        <?php print _svg('logo-global-shelter-cluster', array('id'=>'shelter-cluster', 'alt' => 'Global Shelter Cluster - ShelterCluster.org - Coordinating Humanitarian Shelter')); ?>
      </a>
      <form class="search" action="http://www.google.com/search" method="get">
        <input class="text-field" type="search" placeholder="Search documents" name="q">
        <input class="submit" type="submit" value="Search">
      </form>
    </div>

    <div class="page-margin clearfix">
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
        <h2>Join this Operation Group and</h2>
        <fieldset id="checkboxgroup">
          <label><input type="checkbox">  Receive notifications;</label>
          <label><input type="checkbox">  Register to this group the mailing list;</label>
          <label><input type="checkbox"> Register to the "Global Response" mailinglist</label>
        </fieldset>
        <a id="button-join-group" class="button" href="">Join</a>
      </section>
    </div>

  </header>

  <div id="content">
    <div class="page-margin">
      <?php print $messages; ?>
      <?php print render($page['content']); ?>
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
