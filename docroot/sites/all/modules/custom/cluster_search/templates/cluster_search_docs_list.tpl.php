<section class="document-preview-list">

  <article class="document-preview" v-for="document in results">
    <a class="thumbnail" :href="document['field_file:file:url']" target="_blank">
      <div class="file-info">
        <div>[ {{ document['field_file:file:size']|file_size }} ]</div>
        <div v-if="document['field_file:file:url']"
              class="file-extension"
        >{{ document['field_file:file:url']|file_extension }}</div>
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

</section>
