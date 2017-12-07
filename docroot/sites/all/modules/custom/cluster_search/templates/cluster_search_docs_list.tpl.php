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
</div>

<section class="document-preview-list">

  <article class="document-preview" v-for="document in results">
    <a class="thumbnail" :href="document.direct_url" target="_blank">
      <div class="file-info">
        <div v-if="document['field_file:file:size']">[ {{ document['field_file:file:size']|file_size }} ]</div>
        <div v-if="document.file_extension" class="file-extension">{{ document.file_extension }}</div>
        <div class="document-link">
          Download
        </div>
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
</section>
