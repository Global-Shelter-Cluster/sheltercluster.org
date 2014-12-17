<div id="content">

  <div id="content-header">
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

        <h3 data-collapse="operation-information">Overview</h3>
        <section id="operation-information">
          <?php if (isset($group_image)): ?>
            <?php print $group_image; ?>
          <?php endif; ?>
          <?php print render($content['body']); ?>
        </section>

        <h3 data-collapse="key-information">Key Information</h3>
        <section id="key-information">
        <?php print render($content['key_documents']); ?>
        </section>

        <h3 data-collapse="recent-documents">Recent Documents</h3>
        <section id="recent-documents">
          <?php print render($content['recent_documents']); ?>
        </section>

      </div>

      <div class="side-column">

        <h3 data-collapse="operation-group">Join This Group</h3>
        <section id="join-group" class="clearfix">
          <p>Register and join this group</p>
          <div id="button-join-group"><a href="#">Join</a></div>
        </section>

        <h3 data-collapse="shelter-calendar">Calendar</h3>
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
        <?php dpm($content); ?>
      </div>

    </div>
  </div>

</div>
