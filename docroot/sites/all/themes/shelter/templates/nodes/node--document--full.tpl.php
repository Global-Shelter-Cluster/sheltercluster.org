<?php

/**
 * @file
 * Shelter Cluster - Document node template.
 */

  // We hide the comments and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  hide($content['og_group_ref']);

  // Hiding content fields
  hide($content['body']);
  hide($content['field_report_meeting_date']);
  hide($content['field_preview']);
  hide($content['field_file']);
  hide($content['field_link']);
  hide($content['field_featured']);
  hide($content['field_language']);
  hide($content['field_response']);
  hide($content['field_document_type']);
  hide($content['field_document_source']);

  $author = user_load($node->uid);

  // Preview image field
  if ($preview_images = field_get_items('node', $node, 'field_preview')) {
    $preview_image_uri = $preview_images[0]['uri'];
    $style          = 'document_preview';
    $derivative_uri = image_style_path($style, $preview_image_uri);
    $success        = file_exists($derivative_uri) || image_style_create_derivative(image_style_load($style), $preview_image_uri, $derivative_uri);
    $new_image_url  = file_create_url($derivative_uri);
  }

  // Render field value function
  function fieldValue($field_name, $node) {
    $field = field_get_items('node', $node, $field_name);
    $view = field_view_value('node', $node, $field_name, $field[0]);
    return $view;
  }

  $tag_groups = array('field_coordination_management',
                      'field_information_management',
                      'field_technical_support_design',
                      'field_assess_monitor_eval',
                      'field_inter_cluster',
                      'field_cross_cutting_issues',
                      'field_response_phase',
                      'field_intervention_materials',
                      'field_intervention_programming',
                      'field_settlement_type',
                      'field_non_food_items',
                      'field_issues',
                      'field_toolkit',
                      'field_meeting_management');

  if (render($content['field_file'])) {
    $file_field = field_get_items('node', $node, 'field_file');
    $file_field_name = $file_field[0]["filename"];
    $document_url = file_create_url($file_field[0]["uri"]);
    $document_link_title = "Download " . $file_field_name;
    $document_button_text = "Download";
  } else {
    $file_link = field_get_items('node', $node, 'field_link');
    $document_url = render($file_link[0]['url']);
    $document_url_parts = parse_url($document_url);
    $document_link_title = "View document on " . $document_url_parts['host'];
    $document_button_text = "Open document";
  }

?>

<div id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <div class="content"<?php print $content_attributes; ?>>
    
    <div class="doc-details">
      <div class="doc-publisher">
        <div class="doc-attr-label">Publisher </div>
        <div class="doc-attr-value">
          <a href="/users/<?php print $author->name; ?>" title="View publisher">
            <?php print $author->name; ?>
          </a>
        </div>
      </div>
      <div class="doc-date">
        <div class="doc-attr-label">Date </div>
        <div class="doc-attr-value">
          <strong><?php $value = fieldValue('field_report_meeting_date', $node); print render($value); ?></strong>
        </div>
      </div>

      <div class="doc-type">
        <div class="doc-attr-label">Type </div>
        <div class="doc-attr-value">
          <?php $value = fieldValue('field_document_type', $node); print render($value); ?>
        </div>
      </div>

      <?php if (render($content['field_file'])): ?>
        <div class="doc-filename">
          <div class="doc-attr-label">Filename </div>
          <div class="doc-attr-value">
            <a href="<?php print $document_url;?>" title="<?php print $document_link_title;?>">
              <?php print $file_field_name; ?>
            </a>
          </div>
        </div>
      <?php else: ?>
        <div class="doc-host-website">
          <div class="doc-attr-label">Website </div>
          <div class="doc-attr-value">
            <a href="<?php print $document_url; ?>" title="Open <?php print $document_url; ?>">
              <?php print $document_url_parts['host'] ?>
            </a>
          </div>
        </div>
      <?php endif; ?>

      <div class="doc-source">
        <div class="doc-attr-label">Source </div>
        <div class="doc-attr-value">
          <strong><?php $value = fieldValue('field_document_source', $node); print render($value); ?></strong>
        </div>
      </div>
      <?php if (render($content['og_group_ref'])):?>
        <div class="doc-group">
          <div class="doc-attr-label">Group </div>
          <div class="doc-attr-value">
            <?php print render($content['og_group_ref']); ?>
          </div>
        </div>
      <?php endif; ?>
      <div class="doc-language">
        <div class="doc-attr-label">Language </div>
        <div class="doc-attr-value">
          <strong><?php print locale_language_name($node->language); ?></strong>
        </div>
      </div>
      
      <div class="doc-tags">
        <div class="doc-attr-label">Tags </div>
        <div class="doc-attr-value"><?php
          foreach ($tag_groups as $tag_group) {
            if (array_key_exists($tag_group, $content)) {
              $value = fieldValue($tag_group, $node);
              print render($value);
            }
          }
        ?></div>
      </div>
    </div>
    
    <div class="doc-download">
      <a href="<?php print $document_url; ?>"
           title="<?php print $document_link_title; ?>"
           target="_blank">
        <div class="doc-preview">
          <?php if ($preview_images): ?>
            <img src="<?php print $new_image_url ?>" />
          <?php endif; ?>
        </div>
      </a>
      <div class="doc-button">
        <a href="<?php print $document_url; ?>"
           title="<?php print $document_link_title; ?>"
           target="_blank" class="button"><?php print $document_button_text; ?></a>
      </div>
    </div>

    <div class="doc-description">
      <?php print render($content['body']); ?>
    </div>
  </div>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>

</div>
