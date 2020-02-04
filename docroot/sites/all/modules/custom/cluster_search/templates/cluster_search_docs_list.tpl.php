<div class="cluster-search-docs-list search-summary" v-if="results && hits >= 1" v-cloak>
  <span v-if="hits > 1" class="summary">Showing {{ resultsFrom }}&ndash;{{ resultsTo }} of {{ hits }} documents.</span>
  <ul class="pagination" v-if="pages > 1">
    <li>Pages:</li>
    <li v-for="p in paginationPages">
      <a v-if="p != '-' && p != page" href="#" @click.prevent="doSearch(true, p)">{{ p+1 }}</a>
      <span v-if="p != '-' && p == page">{{ p+1 }}</span>
      <span v-if="p == '-'">&hellip;</span>
    </li>
  </ul>
  <span v-if="hits <= 1"></span>
  <ul class="search-display">
    <li v-if="display != 'preview'" key="preview">
      <a :href="display == 'preview' ? null : '#'" @click.prevent="display = 'preview'" title="Document previews">
        <i class="fas fa-image"></i> high bandwidth
      </a>
    </li>
    <li v-if="display != 'list'" key="list">
      <a :href="display == 'list' ? null : '#'" @click.prevent="display = 'list'" title="Table view">
        <i class="fas fa-list"></i> low bandwidth
      </a>
    </li>
  </ul>
</div>

<table v-if="display == 'list' && results" class="document-table" v-cloak>
  <thead>
  <tr>
    <th style="width: 100%;">Document title</th>
    <th>Size</th>
    <th>Date</th>
  </tr>
  </thead>
  <tbody>
  <tr v-for="document, i in results" :class="['document-row', i % 2 == 0 ? 'odd' : 'even']">
    <td class="information-title">
      <a v-if="document.can_edit" class="operation-icon" :href="'/node/' + document.nid + '/edit'" title="Edit this document">
        <i class="fas fa-edit"></i>
      </a>
      <a v-if="document.can_delete" class="operation-icon" :href="'/node/' + document.nid + '/delete'" title="Delete this document">
        <i class="fas fa-trash-alt"></i>
      </a>
      <a :href="document.url" v-html="document.title"></a>
      <a v-if="groupNid != document.group_nids[0]" :href="'/node/' + document.group_nids[0]" class="group" v-html="document.group"></a>
      <div v-if="document.tags && document.tags.length" class="tags">
        <div class="item-list">
          <h3>Tags</h3>
          <ul>
            <li v-for="tag in document.tags" @click="selectFacet(tag.field_key, tag.value)">{{ tag.value }}</li>
          </ul>
        </div>
      </div>
    </td>
    <td class="information-file">
      <a class="download-doc" :href="document.direct_url" target="_blank" @click="hitEvent('view', document)">
        <span v-if="document['field_file:file:size']">[ {{ document['field_file:file:size']|file_size }} ]</span>
        <span v-if="document.file_extension">{{ document.file_extension }}</span>
        <span v-if="!document['field_file:file:size'] && !document.file_extension">LINK</span>
      </a>
    </td>
    <td class="publication-date">
      <span>
        {{ document.date }}
      </span>
    </td>
  </tr>
  </tbody>
</table>

<section v-if="display == 'preview' && results" class="document-preview-list" v-cloak>
  <article :class="['document-preview', document.class]" v-for="document in results">
    <a class="thumbnail" :href="document.direct_url" target="_blank" @click="hitEvent('view', document)">
      <div class="file-info">
        <div v-if="document['field_file:file:size']">[ {{ document['field_file:file:size']|file_size }} ]</div>
        <div v-if="document.file_extension" class="file-extension">{{ document.file_extension }}</div>
        <i class="fas fa-download"></i>
      </div>
      <img v-if="document.thumb" :src="document.thumb" :key="document.thumb">
    </a>
    <a v-if="document.can_edit" class="operation-icon" :href="'/node/' + document.nid + '/edit'" title="Edit this document">
      <i class="fas fa-edit"></i>
    </a>
    <a v-if="document.can_delete" class="operation-icon" :href="'/node/' + document.nid + '/delete'" title="Delete this document">
      <i class="fas fa-trash-alt"></i>
    </a>
    <a :href="document.url">
      <h4 :title="document.title|strip_tags">
        <div v-if="document.field_document_status" class="document-status">
          {{ document.field_document_status }}
        </div>
        <span v-html="
          (
            document.featured && document.key
            ? '<span title=\'Featured and key document\'>★</span>&nbsp;'
            : (
              document.featured
              ? '<span title=\'Featured\'>★</span>&nbsp;'
              : (
                document.key
                ? '<span title=\'Key document\'>★</span>&nbsp;'
                : ''
              )
            )
          ) + document.title">
        </span>
      </h4>
    </a>
    <a :href="'/node/' + document.group_nids[0]" class="group"
       v-if="groupNid != document.group_nids[0]" v-html="document.group">
    </a>

    <div v-if="document.date || document.field_language || document.field_document_source" class="document-date">
      {{ document.date }}
      <span v-if="document.field_language">
        <span v-if="document.date">&middot;</span>
        {{ document.field_language }}
      </span>
      <span v-if="document.field_document_source"
            :title="'Source: ' + document.field_document_source">
        <span v-if="document.date || document.field_language">&middot;</span>
        {{ document.field_document_source }}
      </span>
    </div>

    <ul v-if="document.tags" class="tags">
      <li v-for="tag in document.tags" :title="tag.field + ': ' + tag.value" @click="selectFacet(tag.field_key, tag.value)">{{ tag.value }}</li>
    </ul>
  </article>
</section>

<div class="no-results" v-if="false">
  <span>
    Loading&hellip;
  </span>
</div>

<div class="no-results" v-if="showNoResultsMessage" v-cloak>
  <a v-if="hasFacetFiltersSelected" href="#" @click.prevent="clearSelectedFacets()">
    No documents found. Try removing the selected filters.
  </a>
  <a v-else-if="search && mode === 'normal' && descendantNids.length > 1"
     href="#" @click.prevent="mode = 'descendants'">
    No documents found matching "<strong>{{ search }}</strong>". Try including subgroups.
  </a>
  <span v-else-if="search && (mode === 'descendants' || descendantNids.length <= 1)">
    No documents found matching "<strong>{{ search }}</strong>".
  </span>
  <a v-else-if="!search && mode === 'normal' && descendantNids.length > 1"
     href="#" @click.prevent="mode = 'descendants'">
    No documents found. Try including subgroups.
  </a>
  <a v-else-if="!search && mode === 'normal' && descendantNids.length > 1"
     href="#" @click.prevent="mode = 'descendants'">
    No documents found. Try including subgroups.
  </a>
  <span v-else>
    No documents found.
  </span>
</div>
