<div class="search-summary" v-if="results && hits > 1">
  <span class="summary">Showing {{ resultsFrom }}&ndash;{{ resultsTo }} of {{ hits }} documents.</span>
  <ul class="pagination" v-if="pages > 1">
    <li>Pages:</li>
    <li v-for="p in paginationPages">
      <a v-if="p != '-' && p != page" href="#" @click.prevent="search(true, p)">{{ p+1 }}</a>
      <span v-if="p != '-' && p == page">{{ p+1 }}</span>
      <span v-if="p == '-'">&hellip;</span>
    </li>
  </ul>
  <ul class="search-display">
    <li>
      <a :href="display == 'preview' ? null : '#'" @click.prevent="display = 'preview'" title="Document previews">
        <i class="fas fa-th-large"></i>
      </a>
    </li>
    <li>
      <a :href="display == 'list' ? null : '#'" @click.prevent="display = 'list'" title="Table view">
        <i class="fas fa-th-list"></i>
      </a>
    </li>
  </ul>
</div>

<table v-if="display == 'list' && results" class="document-table">
  <thead>
  <tr>
    <th>Document title</th>
    <th>Size</th>
    <th>Date</th>
  </tr>
  </thead>
  <tbody>
  <tr v-for="document, i in results" :class="['document-row', i % 2 == 0 ? 'odd' : 'even']">
    <td class="information-title">
      <a :href="document.url" v-html="document.title"></a>
      <a v-if="includeDescendants == 1" :href="'/node/' + document.group_nids[0]" class="group" v-html="document.group"></a>
      <div v-if="document.tags" class="tags">
        <div class="item-list">
          <h3>Tags</h3>
          <ul>
            <li v-for="tag in document.tags">{{ tag.value }}</li>
          </ul>
        </div>
      </div>
    </td>
    <td class="information-file">
      <a :href="document.direct_url" target="_blank">
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

<section v-if="display == 'preview' && results" class="document-preview-list">
  <article class="document-preview" v-for="document in results">
    <a class="thumbnail" :href="document.direct_url" target="_blank">
      <div class="file-info">
        <div v-if="document['field_file:file:size']">[ {{ document['field_file:file:size']|file_size }} ]</div>
        <div v-if="document.file_extension" class="file-extension">{{ document.file_extension }}</div>
        <i class="fas fa-download"></i>
      </div>
      <img v-if="document.thumb" :src="document.thumb">
    </a>
    <a :href="document.url">
      <h4 :title="document.title|strip_tags" v-html="
      (
        document.featured && document.key
        ? '<span title=\'Featured and key document\'>★</span> '
        : (
          document.featured
          ? '<span title=\'Featured\'>★</span> '
          : (
            document.key
            ? '<span title=\'Key document\'>★</span> '
            : ''
          )
        )
      ) + document.title">
      </h4>
    </a>
    <a :href="'/node/' + document.group_nids[0]"
       class="group"
       v-if="includeDescendants == 1"
       v-html="document.group">
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
      <li v-for="tag in document.tags" :title="tag.field + ': ' + tag.value">{{ tag.value }}</li>
    </ul>
  </article>
</section>

<div class="no-results" v-if="!searching && !results">
  <a v-if="hasFacetFiltersSelected" href="#" @click.prevent="clearSelectedFacets()">
    No documents found. Try removing the selected filters.
  </a>
  <a v-if="!hasFacetFiltersSelected && query && includeDescendants == 0"
     href="#" @click.prevent="includeDescendants = '1'">
    No documents found matching "<strong>{{ query }}</strong>". Try including subgroups.
  </a>
  <span v-if="!hasFacetFiltersSelected && query && includeDescendants == 1">
    No documents found matching "<strong>{{ query }}</strong>".
  </span>
  <a v-if="!hasFacetFiltersSelected && !query && includeDescendants == 0"
     href="#" @click.prevent="includeDescendants = '1'">
    No documents found. Try including subgroups.
  </a>
  <span v-if="!hasFacetFiltersSelected && !query && includeDescendants == 1">
    No documents found.
  </span>
</div>
