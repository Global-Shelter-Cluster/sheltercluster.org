<section id="shelter-calendar" class="upcoming-events preview-block" v-cloak v-if="results">
  <h4><?php print $title ?></h4>

  <div class="list event-preview-list">
    <article
      :class="['event-preview', event.event_date > nowTS ? '' : 'event-preview--past']"
      v-for="event in results">
      <a class="thumbnail" :href="event.url">
        <img v-if="event.event_map_image" :src="event.event_map_image"
             :key="event.event_map_image">
      </a>
      <a v-if="event.can_edit" class="operation-icon"
         :href="'/node/' + event.nid + '/edit'" title="Edit this event">
        <i class="fas fa-edit"></i>
      </a>
      <a v-if="event.can_delete" class="operation-icon"
         :href="'/node/' + event.nid + '/delete'" title="Delete this event">
        <i class="fas fa-trash-alt"></i>
      </a>
      <a :href="event.url">
        <h4 :title="event.title|strip_tags">
          <span v-html="event.title"></span>
        </h4>
      </a>
      <a :href="'/node/' + event.group_nids[0]" class="group"
         v-if="showGroup && groupNid != event.group_nids[0]"
         v-html="event.group">
      </a>

      <div
        v-if="event.date || event.field_language || event.field_event_source"
        class="event-date">
        <i class="far fa-calendar-alt" :title="event.event_date > nowTS ? 'Upcoming event' : 'Past event'"></i>
        {{ event.date }}
        <div class="ical" v-if="event.event_date > nowTS">
          <a :href="'/node/' + event.nid + '/field_recurring_event_date2/ical/addtocal.ics'">
            iCal
          </a>
        </div>
      </div>

      <div v-if="event.event_location_html" v-html="event.event_location_html"
           class="event-location"></div>
    </article>
  </div>

  <div class="footer">
    <?php print $all_events_link; ?>
    <?php if ($global_events_link) print ' &nbsp; '.render($global_events_link); ?>
  </div>
</section>
