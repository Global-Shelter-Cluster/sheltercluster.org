<li class="expanded last nav-item" id="cluster-search-mega-menu">
  <a href="#" @click.prevent="focus"><i class="fa fa-search"></i> Search</a>
  <template>
  <ul class="nav-items menu search-input-row">
    <li class="within-group" v-if="groupNids">
      <label>
        <input type="checkbox" v-model="onlyWithinGroup">
        Search within <em>{{ groupTitle }}</em>
      </label>
    </li>
    <li class="search-input">
      <input type="search" v-model="query" @focus="focusHandler"
             @blur="blurHandler">
    </li>
    <li class="algolia-logo">
      <img
        src="<?php print url('/sites/all/themes/shelter/assets/images/search-by-algolia.png'); ?>"
        alt="Search by Algolia">
    </li>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && !indexFilter">
    <li v-if="results.documents.length > 0">
      <a href="#" @click.prevent="indexFilter = 'documents'" title="Click here to search documents only">Documents</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="document in getPage(results.documents, 0, 10)">
          <a :href="document.url" class="search-result-title"
             :title="document.title|strip_tags">
            <div v-html="document.title"></div>
            <small v-if="document.group" class="search-result-title"
                   :title="document.group|strip_tags" v-html="document.group"></small>
            <small>
              {{ document.date }}
              <template v-if="document.featured">&middot; Featured</template>
              <template v-if="document.key && !document.featured">&middot; Key document</template>
            </small>
          </a>
        </li>
      </ul>
    </li>
    <li v-if="results.documents.length > 10">
      <span class="mobile-hide">&nbsp;</span>
      <ul class="nav-items menu">
        <li class="leaf" v-for="document in getPage(results.documents, 1, 10)">
          <a :href="document.url" class="search-result-title"
             :title="document.title|strip_tags">
            <div v-html="document.title"></div>
            <small v-if="document.group" class="search-result-title"
                   :title="document.group|strip_tags" v-html="document.group"></small>
            <small>
              {{ document.date }}
              <template v-if="document.featured">&middot; Featured</template>
              <template v-if="document.key && !document.featured">&middot; Key document</template>
            </small>
          </a>
        </li>
      </ul>
    </li>
    <li v-if="results.events.length > 0">
      <a href="#" @click.prevent="indexFilter = 'events'" title="Click here to search events only">Events</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="event in results.events">
          <a :href="event.url" class="search-result-title" :title="event.title|strip_tags">
            <div v-html="event.title"></div>
            <small v-if="event.group" class="search-result-title"
                   :title="event.group|strip_tags" v-html="event.group"></small>
            <small>
              {{ event.date }}
              <template v-if="event.location">&middot; {{ event.location }}
              </template>
            </small>
          </a>
        </li>
      </ul>
    </li>
    <li v-if="results.pages.length > 0 || results.groups.length > 0">
      <template v-if="results.pages.length > 0">
        <a href="#" @click.prevent="indexFilter = 'pages'" title="Click here to search pages only">Pages</a>
        <ul class="nav-items menu">
          <li class="leaf" v-for="page in results.pages">
            <a :href="page.url">
              <div v-html="page.title"></div>
              <small v-if="page.group" class="search-result-title"
                     :title="page.group|strip_tags" v-html="page.group"></small>
              <small v-if="page.type">{{ page.type }}</small>
            </a>
          </li>
        </ul>
      </template>
      <br class="mobile-hide" v-if="results.pages.length > 0 && results.groups.length > 0">
      <template v-if="results.groups.length > 0">
        <a href="#" @click.prevent="indexFilter = 'groups'" title="Click here to search groups only">Groups</a>
        <ul class="nav-items menu">
          <li class="leaf" v-for="group in results.groups">
            <a :href="group.url">
              <div v-html="group.title"></div>
              <small>{{ group.type }}</small>
            </a>
          </li>
        </ul>
      </template>
    </li>
    <li v-if="results.contacts.length > 0">
      <a href="#" @click.prevent="indexFilter = 'contacts'" title="Click here to search contacts only">Contacts</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="contact in results.contacts">
          <a :href="contact.url" target="_blank">
            <div v-html="contact.title"></div>
            <small v-if="contact.group" class="search-result-title"
                   :title="contact.group|strip_tags" v-html="contact.group"></small>
            <small v-if="contact.role && contact.org" v-html="contact.org + ' &middot; ' + contact.role"></small>
            <small v-if="contact.role && !contact.org" v-html="contact.role"></small>
            <small v-if="!contact.role && contact.org" v-html="contact.org"></small>
            <small v-if="contact.email" v-html="contact.email"></small>
            <small v-if="contact.phone" v-html="contact.phone"></small>
          </a>
        </li>
      </ul>
    </li>
  </ul>
  <ul class="nav-items menu search-filtered-by-index" v-if="hasResults && indexFilter == 'documents'">
    <template v-for="page in 5">
      <li v-if="results.documents.length > (page-1) * 10">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null" title="Click here to search everything">* Documents</a>
        <span v-if="page > 1">&nbsp;</span>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="document in getPage(results.documents, page-1, 10)">
            <a :href="document.url" class="search-result-title"
               :title="document.title|strip_tags">
              <div v-html="document.title"></div>
              <small v-if="document.group" class="search-result-title"
                     :title="document.group|strip_tags" v-html="document.group"></small>
              <small>
                {{ document.date }}
                <template v-if="document.featured">&middot; Featured</template>
                <template v-if="document.key && !document.featured">&middot; Key document</template>
              </small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-filtered-by-index" v-if="hasResults && indexFilter == 'events'">
    <template v-for="page in 5">
      <li v-if="results.events.length > (page-1) * 10">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null" title="Click here to search everything">* Events</a>
        <span v-if="page > 1">&nbsp;</span>
        <ul class="nav-items menu">
          <li class="leaf" v-for="event in getPage(results.events, page-1, 10)">
            <a :href="event.url" class="search-result-title" :title="event.title|strip_tags">
              <div v-html="event.title"></div>
              <small v-if="event.group" class="search-result-title"
                     :title="event.group|strip_tags" v-html="event.group"></small>
              <small>
                {{ event.date }}
                <template v-if="event.location">&middot; {{ event.location }}
                </template>
              </small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-filtered-by-index" v-if="hasResults && indexFilter == 'pages'">
    <template v-for="page in 5">
      <li v-if="results.pages.length > (page-1) * 8">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null" title="Click here to search everything">* Pages</a>
        <span v-if="page > 1">&nbsp;</span>
        <ul class="nav-items menu">
          <li class="leaf" v-for="page in getPage(results.pages, page-1, 8)">
            <a :href="page.url">
              <div v-html="page.title"></div>
              <small v-if="page.group" class="search-result-title"
                     :title="page.group|strip_tags" v-html="page.group"></small>
              <small v-if="page.type">{{ page.type }}</small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-filtered-by-index" v-if="hasResults && indexFilter == 'groups'">
    <template v-for="page in 5">
      <li v-if="results.groups.length > (page-1) * 8">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null" title="Click here to search everything">* Groups</a>
        <span v-if="page > 1">&nbsp;</span>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="group in getPage(results.groups, page-1, 8)">
            <a :href="group.url">
              <div v-html="group.title"></div>
              <small>{{ group.type }}</small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-filtered-by-index" v-if="hasResults && indexFilter == 'contacts'">
    <template v-for="page in 5">
      <li v-if="results.contacts.length > (page-1) * 6">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null" title="Click here to search everything">* Contacts</a>
        <span v-if="page > 1">&nbsp;</span>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="contact in getPage(results.contacts, page-1, 6)">
            <a :href="contact.url" target="_blank">
              <div v-html="contact.title"></div>
              <small v-if="contact.group" class="search-result-title"
                     :title="contact.group|strip_tags" v-html="contact.group"></small>
              <small v-if="contact.role && contact.org" v-html="contact.org + ' &middot; ' + contact.role"></small>
              <small v-if="contact.role && !contact.org" v-html="contact.role"></small>
              <small v-if="!contact.role && contact.org" v-html="contact.org"></small>
              <small v-if="contact.email" v-html="contact.email"></small>
              <small v-if="contact.phone" v-html="contact.phone"></small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-no-results" v-if="showNoResultsMessage">
    <li>
      <span>No results found for "<strong>{{ query }}</strong>"</span>
      <a v-if="indexFilter" href="#" @click.prevent="indexFilter = null">Search everything</a>
      <a v-if="!indexFilter && groupNids && onlyWithinGroup" href="#" @click.prevent="onlyWithinGroup = false">Search outside this group</a>
    </li>
  </ul>
  </template>
</li>
