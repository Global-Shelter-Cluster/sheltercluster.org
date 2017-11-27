<section class="document-preview-list">

  <article class="document-preview" v-for="document in results">
    <a :href="document.url">
      <img class="thumbnail" v-if="document.thumb" :src="document.thumb">
      <div v-if="!document.thumb">
        ?
      </div>
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


    <div v-if="document.field_document_source" class="document-source is-small">
      Source: {{ document.field_document_source }}
    </div>

    <div class="file-info">
      <span v-if="document['field_file:file:url']" class="file-extension is-small">
        [ {{ document['field_file:file:size']|file_size }} ]
        {{ document['field_file:file:url']|file_extension }}
      </span>
      <span class="document-link">
        <a :href="document['field_file:file:url']">Download</a>
      </span>
    </div>

    <div class="document-date is-small">{{ document.date }}</div>

<!--    <div class="info">-->
<!--      {{ document.date }}-->
<!--      <span class="file-extension is-small">{{ 'a.pdf'|file_extension }}</span>-->
<!--      <span class="document-link">-->
<!--        <a href="http://local.sheltercluster.org/haiti-hurricane-matthew-2016/documents/usaid-ofda-report-wind-testing-small-transitional-housing">Download</a>-->
<!--      </span>-->
<!--    </div>-->
  </article>

</section>
