<div class="search-summary" v-if="results && hits >= 1" v-cloak>
  <span v-if="hits > 1" class="summary">Showing {{ resultsFrom }}&ndash;{{ resultsTo }} of {{ hits }} events.</span>
  <ul class="pagination" v-if="pages > 1">
    <li>Pages:</li>
    <li v-for="p in paginationPages">
      <a v-if="p != '-' && p != page" href="#" @click.prevent="doSearch(p)">{{ p+1 }}</a>
      <span v-if="p != '-' && p == page">{{ p+1 }}</span>
      <span v-if="p == '-'">&hellip;</span>
    </li>
  </ul>
  <span v-if="hits <= 1"></span>
<!--  <ul class="search-display">-->
<!--    <li>-->
<!--      <a :href="display == 'preview' ? null : '#'" @click.prevent="display = 'preview'" title="Event previews">-->
<!--        <i class="fas fa-th-large"></i>-->
<!--      </a>-->
<!--    </li>-->
<!--    <li>-->
<!--      <a :href="display == 'list' ? null : '#'" @click.prevent="display = 'list'" title="Table view">-->
<!--        <i class="fas fa-th-list"></i>-->
<!--      </a>-->
<!--    </li>-->
<!--  </ul>-->
</div>

<!--table v-if="display == 'list' && results" class="event-table" v-cloak>
  <thead>
  <tr>
    <th style="width: 100%;">Event title</th>
    <th>Location</th>
    <th>Date</th>
  </tr>
  </thead>
  <tbody>
  <tr v-for="event, i in results" :class="['event-row', i % 2 == 0 ? 'odd' : 'even']">
    <td class="information-title">
      <a v-if="event.can_edit" class="operation-icon" :href="'/node/' + event.nid + '/edit'" title="Edit this event">
        <i class="fas fa-edit"></i>
      </a>
      <a v-if="event.can_delete" class="operation-icon" :href="'/node/' + event.nid + '/delete'" title="Delete this event">
        <i class="fas fa-trash-alt"></i>
      </a>
      <a :href="event.url" v-html="event.title"></a>
      <a v-if="showGroup && groupNid != event.group_nids[0]" :href="'/node/' + event.group_nids[0]" class="group" v-html="event.group"></a>
      <div v-if="event.tags && event.tags.length" class="tags">
        <div class="item-list">
          <h3>Tags</h3>
          <ul>
            <li v-for="tag in event.tags" @click="selectFacet(tag.field_key, tag.value)">{{ tag.value }}</li>
          </ul>
        </div>
      </div>
    </td>
    <td class="information-file">
      <a :href="event.direct_url" target="_blank">
        <span v-if="event['field_file:file:size']">[ {{ event['field_file:file:size']|file_size }} ]</span>
        <span v-if="event.file_extension">{{ event.file_extension }}</span>
        <span v-if="!event['field_file:file:size'] && !event.file_extension">LINK</span>
      </a>
    </td>
    <td class="publication-date">
      <span>
        {{ event.date }}
      </span>
    </td>
  </tr>
  </tbody>
</table-->

<section v-if="display == 'preview' && results" class="event-preview-list" v-cloak>
  <article class="event-preview" v-for="event in results">
    <a v-if="event.event_map_image" class="thumbnail" :href="event.event_map_link" target="_blank">
      <img v-if="event.event_map_image" :src="event.event_map_image" :key="event.event_map_image">
    </a>
    <a v-if="event.can_edit" class="operation-icon" :href="'/node/' + event.nid + '/edit'" title="Edit this event">
      <i class="fas fa-edit"></i>
    </a>
    <a v-if="event.can_delete" class="operation-icon" :href="'/node/' + event.nid + '/delete'" title="Delete this event">
    </a>
    <a :href="event.url">
      <h4 :title="event.title|strip_tags">
        <i v-if="event.event_date > nowTS" class="far fa-calendar-alt" title="Upcoming"></i>
        <span v-html="event.title"></span>
      </h4>
    </a>
    <a :href="'/node/' + event.group_nids[0]" class="group"
       v-if="showGroup && groupNid != event.group_nids[0]" v-html="event.group">
    </a>

    <div v-if="event.date || event.field_language || event.field_event_source" class="event-date">
      {{ event.date }}
    </div>

    <div v-if="event.event_location_html" v-html="event.event_location_html" class="event-location"></div>
  </article>
</section>

<div class="no-results" v-if="false">
  <span>
    Loading&hellip;
  </span>
</div>

<div class="no-results" v-if="showNoResultsMessage" v-cloak>
  <a v-if="search && mode === 'all' && descendantNids.length > 1"
     href="#" @click.prevent="mode = 'descendants'">
    No events found matching "<strong>{{ search }}</strong>". Try including subgroups.
  </a>
  <span v-else-if="search && (mode === 'descendants' || descendantNids.length <= 1)">
    No events found matching "<strong>{{ search }}</strong>".
  </span>
  <a v-else-if="!search && mode === 'all' && descendantNids.length > 1"
     href="#" @click.prevent="mode = 'descendants'">
    No events found. Try including subgroups.
  </a>
  <a v-else-if="!search && mode === 'upcoming'"
     href="#" @click.prevent="mode = 'all'">
    No events found. Try including past events.
  </a>
  <span v-else>
    No events found.
  </span>
</div>
