<?php
/**
 * @file
 * cluster_docs_import.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function cluster_docs_import_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'documents';
  $feeds_importer->config = array(
    'name' => 'Documents',
    'description' => 'IMPORTANT: User needs to be a member of each group referenced by the documents being imported',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => FALSE,
        'direct' => FALSE,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          0 => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Path',
            'target' => 'path_alias',
            'pathauto_override' => 1,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'File',
            'target' => 'field_file:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          2 => array(
            'source' => 'Link',
            'target' => 'field_link:url',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'Title',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Document Language',
            'target' => 'field_language',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Report / Meeting date',
            'target' => 'field_report_meeting_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          6 => array(
            'source' => 'Source',
            'target' => 'field_document_source',
            'unique' => FALSE,
            'language' => 'und',
          ),
          7 => array(
            'source' => 'Body',
            'target' => 'body',
            'unique' => FALSE,
            'language' => 'und',
          ),
          8 => array(
            'source' => 'Preview',
            'target' => 'field_preview:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          9 => array(
            'source' => 'Document Type',
            'target' => 'field_document_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          10 => array(
            'source' => 'Coordination Management',
            'target' => 'field_coordination_management',
            'unique' => FALSE,
            'language' => 'und',
          ),
          11 => array(
            'source' => 'Information Management',
            'target' => 'field_information_management',
            'unique' => FALSE,
            'language' => 'und',
          ),
          12 => array(
            'source' => 'Technical Support and Design',
            'target' => 'field_technical_support_design',
            'unique' => FALSE,
            'language' => 'und',
          ),
          13 => array(
            'source' => 'Assessment, Monitoring and Evaluation',
            'target' => 'field_assess_monitor_eval',
            'unique' => FALSE,
            'language' => 'und',
          ),
          14 => array(
            'source' => 'Inter-Cluster',
            'target' => 'field_inter_cluster',
            'unique' => FALSE,
            'language' => 'und',
          ),
          15 => array(
            'source' => 'Cross-Cutting Issues',
            'target' => 'field_cross_cutting_issues',
            'unique' => FALSE,
            'language' => 'und',
          ),
          16 => array(
            'source' => 'Response Phase',
            'target' => 'field_response_phase',
            'unique' => FALSE,
            'language' => 'und',
          ),
          17 => array(
            'source' => 'Intervention Materials',
            'target' => 'field_intervention_materials',
            'unique' => FALSE,
            'language' => 'und',
          ),
          18 => array(
            'source' => 'Intervention Programming',
            'target' => 'field_intervention_programming',
            'unique' => FALSE,
            'language' => 'und',
          ),
          19 => array(
            'source' => 'Settlement Type',
            'target' => 'field_settlement_type',
            'unique' => FALSE,
            'language' => 'und',
          ),
          20 => array(
            'source' => 'Non Food Items',
            'target' => 'field_non_food_items',
            'unique' => FALSE,
            'language' => 'und',
          ),
          21 => array(
            'source' => 'Issues',
            'target' => 'field_issues',
            'unique' => FALSE,
            'language' => 'und',
          ),
          22 => array(
            'source' => 'Toolkit',
            'target' => 'field_toolkit',
            'unique' => FALSE,
            'language' => 'und',
          ),
          23 => array(
            'source' => 'Meeting Management',
            'target' => 'field_meeting_management',
            'unique' => FALSE,
            'language' => 'und',
          ),
          24 => array(
            'source' => 'Other Keywords',
            'target' => 'field_other_keywords',
            'unique' => FALSE,
            'language' => 'und',
          ),
          25 => array(
            'source' => 'Key Document',
            'target' => 'field_key_document',
            'unique' => FALSE,
            'language' => 'und',
          ),
          26 => array(
            'source' => 'Featured document',
            'target' => 'field_featured',
            'unique' => FALSE,
            'language' => 'und',
          ),
          27 => array(
            'source' => 'Expire featured setting',
            'target' => 'field_featured_date:start',
            'unique' => FALSE,
            'language' => 'und',
          ),
          28 => array(
            'source' => 'Sorting weight',
            'target' => 'field_sorting_weight',
            'unique' => FALSE,
            'language' => 'und',
          ),
          29 => array(
            'source' => 'Groups audience',
            'target' => 'og_group_ref:etid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          30 => array(
            'source' => 'Document status',
            'target' => 'field_document_status',
            'unique' => FALSE,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'document',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['documents'] = $feeds_importer;

  return $export;
}
