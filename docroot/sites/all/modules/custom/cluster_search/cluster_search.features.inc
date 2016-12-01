<?php
/**
 * @file
 * cluster_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cluster_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_index().
 */
function cluster_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "local",
    "item_type" : "node",
    "options" : {
      "index_directly" : 1,
      "cron_limit" : "50",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_attachments_alter_settings" : {
          "status" : 1,
          "weight" : "0",
          "settings" : {
            "excluded_extensions" : "aif art avi bmp gif ico mov oga ogv png psd ra ram rgb flv",
            "number_indexed" : "0",
            "max_file_size" : "0",
            "excluded_private" : 1
          }
        },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 1,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "attachments_field_event_files" : { "type" : "text" },
        "attachments_field_file" : { "type" : "text" },
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "comment_count" : { "type" : "integer" },
        "created" : { "type" : "date" },
        "field_assess_monitor_eval" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_coordination_management" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_cross_cutting_issues" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_document_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_file:file:size" : { "type" : "integer" },
        "field_information_management" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_inter_cluster" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_intervention_materials" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_intervention_programming" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_issues" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_meeting_management" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_non_food_items" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_report_meeting_date" : { "type" : "date" },
        "field_response_phase" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_settlement_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_technical_support_design" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_toolkit" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "og_group_ref" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "string" },
        "type" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function cluster_search_default_search_api_server() {
  $items = array();
  $items['local'] = entity_import('search_api_server', '{
    "name" : "local",
    "machine_name" : "local",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "3",
      "partial_matches" : 1,
      "indexes" : { "default_node_index" : {
          "type" : {
            "table" : "search_api_db_default_node_index",
            "column" : "type",
            "type" : "string",
            "boost" : "1.0"
          },
          "title" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "5.0"
          },
          "promote" : {
            "table" : "search_api_db_default_node_index",
            "column" : "promote",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "sticky" : {
            "table" : "search_api_db_default_node_index",
            "column" : "sticky",
            "type" : "boolean",
            "boost" : "1.0"
          },
          "created" : {
            "table" : "search_api_db_default_node_index",
            "column" : "created",
            "type" : "date",
            "boost" : "1.0"
          },
          "changed" : {
            "table" : "search_api_db_default_node_index",
            "column" : "changed",
            "type" : "date",
            "boost" : "1.0"
          },
          "author" : {
            "table" : "search_api_db_default_node_index",
            "column" : "author",
            "type" : "integer",
            "boost" : "1.0"
          },
          "comment_count" : {
            "table" : "search_api_db_default_node_index",
            "column" : "comment_count",
            "type" : "integer",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_default_node_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "og_group_ref" : {
            "table" : "search_api_db_default_node_index_og_group_ref",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_assess_monitor_eval" : {
            "table" : "search_api_db_default_node_index_field_assess_monitor_eval",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_coordination_management" : {
            "table" : "search_api_db_default_node_index_field_coordination_management",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_cross_cutting_issues" : {
            "table" : "search_api_db_default_node_index_field_cross_cutting_issues",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_information_management" : {
            "table" : "search_api_db_default_node_index_field_information_management",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_inter_cluster" : {
            "table" : "search_api_db_default_node_index_field_inter_cluster",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_intervention_materials" : {
            "table" : "search_api_db_default_node_index_field_intervention_materials",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_intervention_programming" : {
            "table" : "search_api_db_default_node_index_field_intervention_programmin",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_issues" : {
            "table" : "search_api_db_default_node_index_field_issues",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_non_food_items" : {
            "table" : "search_api_db_default_node_index_field_non_food_items",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_response_phase" : {
            "table" : "search_api_db_default_node_index_field_response_phase",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_settlement_type" : {
            "table" : "search_api_db_default_node_index_field_settlement_type",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_technical_support_design" : {
            "table" : "search_api_db_default_node_index_field_technical_support_desig",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_toolkit" : {
            "table" : "search_api_db_default_node_index_field_toolkit",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_document_type" : {
            "table" : "search_api_db_default_node_index_field_document_type",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_file:file:size" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_file_file_size",
            "type" : "integer",
            "boost" : "1.0"
          },
          "title_field" : {
            "table" : "search_api_db_default_node_index",
            "column" : "title_field",
            "type" : "string",
            "boost" : "1.0"
          },
          "nid" : {
            "table" : "search_api_db_default_node_index",
            "column" : "nid",
            "type" : "integer",
            "boost" : "1.0"
          },
          "field_meeting_management" : {
            "table" : "search_api_db_default_node_index_field_meeting_management",
            "column" : "value",
            "type" : "list\\u003Cinteger\\u003E",
            "boost" : "1.0"
          },
          "field_report_meeting_date" : {
            "table" : "search_api_db_default_node_index",
            "column" : "field_report_meeting_date",
            "type" : "date",
            "boost" : "1.0"
          },
          "attachments_field_file" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "attachments_field_event_files" : {
            "table" : "search_api_db_default_node_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
