<section class="facets" v-cloak>
  <label class="facet">
    <h4>Search events</h4>
    <input type="search" v-model="search">
  </label>
  <?php if ($include_mode): ?>
  <div class="facet">
    <div class="item-list">
      <ul>
        <li class="leaf"><label><input type="radio" value="upcoming" v-model="mode"> Upcoming</label></li>
        <li class="leaf"><label><input type="radio" value="all" v-model="mode"> All events</label></li>
      </ul>
    </div>
  </div>
  <?php endif; ?>
</section>
