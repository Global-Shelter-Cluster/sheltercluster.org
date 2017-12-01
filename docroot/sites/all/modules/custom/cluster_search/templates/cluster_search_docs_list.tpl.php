<section class="document-preview-list">

  <article class="document-preview" v-for="document in results">
    <a v-if="document.thumb" :href="document.url">
      <img class="thumbnail" :src="document.thumb">
<!--      <div v-if="!document.thumb">-->
<!--        ?-->
<!--      </div>-->
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

    <div v-if="document.date" class="document-date">
      {{ document.date }}
      <span v-if="document.field_document_source" :title="'Source: ' + document.field_document_source">
        <span v-if="document.date">&middot;</span>
        Source: {{ document.field_document_source }}
      </span>
    </div>

    <div class="file-info">
      <span>[ {{ document['field_file:file:size']|file_size }} ]</span>
      <span v-if="document['field_file:file:url']"
            class="file-extension"
      >{{ document['field_file:file:url']|file_extension }}</span>
      <span class="document-link">
        <a :href="document['field_file:file:url']" target="_blank">Download</a>
      </span>
    </div>
  </article>

</section>
