<section class="document-preview-list">

  <a class="document-preview" v-for="document in results" :href="document.url">
    <img class="thumbnail" v-if="document.thumb" :src="document.thumb">
    <div v-if="!document.thumb">
      ?
    </div>
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
    ) + document.title"></h4>
    <small v-if="includeDescendants == 1" v-html="document.group"></small>
    <small>
      {{ document.date }}
    </small>
  </a>

</section>
