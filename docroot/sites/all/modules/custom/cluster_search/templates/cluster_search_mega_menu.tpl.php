<li class="expanded last nav-item" id="cluster-search-mega-menu">
  <a href="#" @click.prevent="focus">Search</a>
  <ul class="nav-items menu search-input-row">
    <li class="search-input">
      <input type="search" v-model="query" @focus="focusHandler"
             @blur="blurHandler">
    </li>
    <li class="algolia-logo">
      <img
        src="https://www.algolia.com/static_assets/images/press/downloads/search-by-algolia.png"
        alt="Search by Algolia">
    </li>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && !indexFilter">
    <li v-if="results.documents.length > 0">
      <a href="#" @click.prevent="indexFilter = 'documents'">Documents</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="document in getPage(results.documents, 0, 10)">
          <a :href="document.url" class="search-result-title"
             :title="document.title">
            {{ document.title }}
            <small v-if="document.group" class="search-result-title"
                   :title="document.group">{{ document.group }}
            </small>
            <small>
              {{ document.date }}
              <template v-if="document.featured">&middot; Featured</template>
              <template v-if="document.key">&middot; Key</template>
            </small>
          </a>
        </li>
      </ul>
    </li>
    <li v-if="results.documents.length > 10">
      <div>&nbsp;</div>
      <ul class="nav-items menu">
        <li class="leaf" v-for="document in getPage(results.documents, 1, 10)">
          <a :href="document.url" class="search-result-title"
             :title="document.title">
            {{ document.title }}
            <small v-if="document.group" class="search-result-title"
                   :title="document.group">{{ document.group }}
            </small>
            <small>
              <template v-if="document.date">{{ document.date }}</template>
              <template v-if="document.featured">&middot; Featured</template>
              <template v-if="document.key">&middot; Key</template>
            </small>
          </a>
        </li>
      </ul>
    </li>
    <li v-if="results.events.length > 0">
      <a href="#" @click.prevent="indexFilter = 'events'">Events</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="event in results.events">
          <a :href="event.url" class="search-result-title" :title="event.title">
            {{ event.title }}
            <small v-if="event.group" class="search-result-title"
                   :title="event.group">{{ event.group }}
            </small>
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
        <a href="#" @click.prevent="indexFilter = 'pages'">Pages</a>
        <ul class="nav-items menu">
          <li class="leaf" v-for="page in results.pages">
            <a :href="page.url">
              {{ page.title }}
              <small v-if="page.group" class="search-result-title"
                     :title="page.group">{{ page.group }}
              </small>
              <small>{{ page.type }}</small>
            </a>
          </li>
        </ul>
      </template>
      <br v-if="results.pages.length > 0 && results.groups.length > 0">
      <template v-if="results.groups.length > 0">
        <a href="#" @click.prevent="indexFilter = 'groups'">Groups</a>
        <ul class="nav-items menu">
          <li class="leaf" v-for="group in results.groups">
            <a :href="group.url">
              {{ group.title }}
              <small>{{ group.type }}</small>
            </a>
          </li>
        </ul>
      </template>
    </li>
    <li v-if="results.contacts.length > 0">
      <a href="#" @click.prevent="indexFilter = 'contacts'">Contacts</a>
      <ul class="nav-items menu">
        <li class="leaf" v-for="contact in results.contacts">
          <a :href="contact.url" target="_blank">
            {{ contact.title }}
            <small v-if="contact.group" class="search-result-title"
                   :title="contact.group">{{ contact.group }}
            </small>
            <small v-if="contact.role || contact.org">
              <template v-if="contact.org">
                {{ contact.org}}
                <template v-if="contact.role">
                  &middot; {{ contact.role }}
                </template>
              </template>
              <template v-if="!contact.org && contact.role">
                {{ contact.role }}
              </template>
            </small>
            <small v-if="contact.email">{{ contact.email }}</small>
            <small v-if="contact.phone">{{ contact.phone }}</small>
          </a>
        </li>
      </ul>
    </li>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && indexFilter == 'documents'">
    <template v-for="page in 5">
      <li v-if="results.documents.length > (page-1) * 10">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null">Documents</a>
        <div v-if="page > 1">&nbsp;</div>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="document in getPage(results.documents, page-1, 10)">
            <a :href="document.url" class="search-result-title"
               :title="document.title">
              {{ document.title }}
              <small v-if="document.group" class="search-result-title"
                     :title="document.group">{{ document.group }}
              </small>
              <small>
                {{ document.date }}
                <template v-if="document.featured">&middot; Featured</template>
                <template v-if="document.key">&middot; Key</template>
              </small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && indexFilter == 'events'">
    <template v-for="page in 5">
      <li v-if="results.events.length > (page-1) * 10">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null">Events</a>
        <div v-if="page > 1">&nbsp;</div>
        <ul class="nav-items menu">
          <li class="leaf" v-for="event in getPage(results.events, page-1, 10)">
            <a :href="event.url" class="search-result-title" :title="event.title">
              {{ event.title }}
              <small v-if="event.group" class="search-result-title"
                     :title="event.group">{{ event.group }}
              </small>
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
  <ul class="nav-items menu" v-if="hasResults && indexFilter == 'pages'">
    <template v-for="page in 5">
      <li v-if="results.pages.length > (page-1) * 8">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null">Pages</a>
        <div v-if="page > 1">&nbsp;</div>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="page in getPage(results.pages, page-1, 8)">
            <a :href="page.url">
              {{ page.title }}
              <small v-if="page.group" class="search-result-title"
                     :title="page.group">{{ page.group }}
              </small>
              <small>{{ page.type }}</small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && indexFilter == 'groups'">
    <template v-for="page in 5">
      <li v-if="results.groups.length > (page-1) * 8">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null">Groups</a>
        <div v-if="page > 1">&nbsp;</div>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="group in getPage(results.groups, page-1, 8)">
            <a :href="group.url">
              {{ group.title }}
              <small>{{ group.type }}</small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu" v-if="hasResults && indexFilter == 'contacts'">
    <template v-for="page in 5">
      <li v-if="results.contacts.length > (page-1) * 6">
        <a v-if="page === 1" href="#" @click.prevent="indexFilter = null">Contacts</a>
        <div v-if="page > 1">&nbsp;</div>
        <ul class="nav-items menu">
          <li class="leaf"
              v-for="contact in getPage(results.contacts, page-1, 6)">
            <a :href="contact.url" target="_blank">
              {{ contact.title }}
              <small v-if="contact.group" class="search-result-title"
                     :title="contact.group">{{ contact.group }}
              </small>
              <small v-if="contact.role || contact.org">
                <template v-if="contact.org">
                  {{ contact.org}}
                  <template v-if="contact.role">
                    &middot; {{ contact.role }}
                  </template>
                </template>
                <template v-if="!contact.org && contact.role">
                  {{ contact.role }}
                </template>
              </small>
              <small v-if="contact.email">{{ contact.email }}</small>
              <small v-if="contact.phone">{{ contact.phone }}</small>
            </a>
          </li>
        </ul>
      </li>
    </template>
  </ul>
  <ul class="nav-items menu search-no-results" v-if="showNoResultsMessage">
    <li>
      <div>No results found for "{{ query }}"</div>
      <a v-if="indexFilter" href="#" @click.prevent="indexFilter = null">Search everything</a>
    </li>
  </ul>
</li>
