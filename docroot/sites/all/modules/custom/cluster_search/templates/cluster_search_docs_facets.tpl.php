<section class="facets" v-cloak>
  <label class="facet">
    <h4>Search</h4>
    <input type="search" v-model="query">
  </label>
  <div class="facet" v-if="descendantNids.length > 1">
    <h4>Groups</h4>
    <div class="item-list">
      <ul>
        <li class="leaf">
          <label><input type="radio" value="0" v-model="includeDescendants"> Only this group</label>
        </li>
        <li class="leaf">
          <label><input type="radio" value="1" v-model="includeDescendants"> Include subgroups</label>
        </li>
      </ul>
    </div>
  </div>
  <div class="facet" v-for="(facet, facetField) in facetsDisplay" :data-facet="facetField">
    <h4>{{ facet.title }}</h4>
    <div class="item-list">
      <ul>
        <li class="leaf" v-for="(facetCount, facetValue) in facet.values">
          <label>
            <input type="checkbox" :checked="isFacetActive(facetField, facetValue)" @change="changeFacetFilter($event, facetField, facetValue)">
            {{ facetValue }} ({{ facetCount }})
          </label>
        </li>
      </ul>
    </div>
  </div>
</section>
