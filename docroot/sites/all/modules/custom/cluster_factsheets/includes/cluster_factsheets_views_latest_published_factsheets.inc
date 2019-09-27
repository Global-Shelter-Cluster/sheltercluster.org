<?php

class cluster_factsheets_views_latest_published_factsheets extends views_handler_filter {
  function admin_summary() { }
  function operator_form(&$form, &$form_state) { }
  function can_expose() { return FALSE; }

  function query() {
    $table = $this->ensure_my_table();
    $placeholder = $this->placeholder();

    $nids = db_query(<<<EOS
      SELECT field_date.entity_id factsheet_nid
      FROM {field_data_field_date} field_date
          INNER JOIN {og_membership} ogm ON ogm.type = 'og_membership_type_default' AND ogm.group_type = 'node' AND ogm.state = 1 AND field_date.entity_id = ogm.etid
      WHERE field_date.entity_type = 'node'
        AND field_date.bundle = 'factsheet'
        AND field_date.deleted = 0
        AND (ogm.gid, field_date.field_date_value) IN (
          SELECT ogm2.gid, MAX(fd2.field_date_value)
          FROM {field_data_field_date} fd2
            INNER JOIN {og_membership} ogm2 on fd2.entity_id = ogm2.etid
          GROUP BY ogm2.gid
        )
      GROUP BY ogm.gid;
EOS
    )->fetchCol();

    $this->query->add_where_expression($this->options['group'], "$table.status = 1 AND $table.nid IN ($placeholder)", array($placeholder => $nids));
  }
}
