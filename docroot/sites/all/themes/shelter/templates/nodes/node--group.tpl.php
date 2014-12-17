<div id="content">

  <div id="content-header">
    <div class="page-margin clearfix">

      <div class="main-column">

        <section id="operation-information">
          <?php if (isset($group_image)): ?>
            <?php print $group_image; ?>
          <?php endif; ?>
          <?php print render($content['body']); ?>
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
      </div>

      <div class="side-column">

        <section id="shelter-calendar">
          <div id="calendar-box">
            <div id="calendar-date">
              <?php print _svg('icons/pin', array('id'=>'calendar-pin', 'alt' => 'Pin icon')); ?>Nov. 24th 2014
            </div>
            <div id="calendar-event">
              <span class="upcoming" href="#">Upcoming event to the <a href="#">agenda</a>:</span>
              <a class="event" href="#">Shelter Technical Meeting 2014</a></div>
          </div>
          <a class="see-all" href="#">All calendar events</a>
        </section>

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
          <?php print render($content['contact_members']); ?>
        </section>

      </div>

      <div class="main-column">
        <?php print render($content); ?>
      </div>

    </div>
  </div>

</div>
