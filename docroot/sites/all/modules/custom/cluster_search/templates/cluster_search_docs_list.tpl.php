<section class="document-list">

  <a v-for="document in results" :href="document.url" :title="document.title|strip_tags">
    <h4 v-html="document.title"></h4>
    <small v-if="includeDescendants == 1" v-html="document.group"></small>
    <img v-if="document.thumb" :src="document.thumb">
    <div v-if="!document.thumb">

    </div>
    <small>
      {{ document.date }}
      <template v-if="document.featured">&middot; Featured</template>
      <template v-if="document.key">&middot; Key document</template>
    </small>
  </a>

</section>
