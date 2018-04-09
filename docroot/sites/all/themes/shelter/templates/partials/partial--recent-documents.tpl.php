<section id="shelter-documents" class="recent-documents preview-block" v-cloak v-if="results">
  <h4>{{ title }}</h4>

  <div class="list document-preview-list">
    <article
      :class="['document-preview', document.class]"
      v-for="document in results">
      <a class="thumbnail" :href="document.direct_url" target="_blank">
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
            !keyDocs && document.featured && document.key
            ? '<span title=\'Featured and key document\'>★</span>&nbsp;'
            : (
              !keyDocs && document.featured
              ? '<span title=\'Featured\'>★</span>&nbsp;'
              : (
                !keyDocs && document.key
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
  </div>

  <div class="footer">
    <?php print $all_documents_link; ?>
    <?php if (isset($key_documents_link)) print ' &nbsp; '.$key_documents_link; ?>
  </div>
</section>
