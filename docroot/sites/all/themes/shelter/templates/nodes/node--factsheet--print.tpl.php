<?php
$r_field_date = render($content['field_date']);
$r_field_photo_credit = render($content['field_photo_credit']);
$r_body = render($content['body']);
$r_field_coverage_against_targets = render($content['field_coverage_against_targets']);
$r_field_need_analysis = render($content['field_need_analysis']);
$r_field_fs_response = render($content['field_fs_response']);
$r_field_gaps_challenges = render($content['field_gaps_challenges']);
$r_field_map = render($content['field_map']);
hide($content['field_image']);
$r_sidebar = render($content);
$is_sidebar_empty = (trim($r_sidebar) === '');
?>
<article class="node--factsheet <?php if (!$is_sidebar_empty) echo 'has-sidebar'; ?>">

  <table class="area-header">
    <tr>
      <td class="area-logo">
        <img src="<?php
        print url('sites/all/themes/shelter/assets/images/printpdf/logo global shelter cluster.png');
        ?>"/>
      </td>
      <td class="area-group">
        <?php
        if (isset($og_group_ref) && isset($og_group_ref['und'][0]['target_id'])) {
          $group = node_load($og_group_ref['und'][0]['target_id']);
          if ($group)
            print check_plain($group->title);
        }
        ?>
      </td>
      <td class="area-date">
        <?php print strip_tags($r_field_date); ?>
      </td>
    </tr>
  </table>

  <table class="area-subheader">
    <tr>
    <td class="area-photo"
        style="
          background-image: url(<?php print $cluster_factsheets['print_main_image_url']; ?>);
          background-image-resize: 4; /* MPDF-specific rule, 4 means 'resize-to-fit w (keep aspect ratio)' */
          ">
      <?php print $r_field_photo_credit; ?>
    </td>
    <td class="separator"></td>
    <td class="area-map">
      <?php print $r_field_map; ?>
    </td>
    </tr>
  </table>

  <?php if (!$is_sidebar_empty): ?>
    <div class="area-aside">
      <?php if ($cluster_factsheets['indicators']): ?>
        <div>
          <h3><?php print t('Key figures'); ?></h3>
          <div class="factsheet-chart-indicators">
            <?php foreach ($cluster_factsheets['indicators'] as $indicator): ?>
              <?php
              switch ($indicator['type']) {
                case 'number':
                  ?>
                  <div>
                    <strong><?php print check_plain($indicator['value']); ?></strong>
                    <label><?php print check_plain(t($indicator['label'])); ?></label>
                  </div>
                  <?php
                  break;

                case 'chart':
                  ?><h4><?php print check_plain(t($indicator['title'])); ?></h4><?php

                  if ($indicator['smallImage']) { ?>
                    <table class="chart--small-image">
                      <tr>
                        <td width="40%">
                          <img <?php print drupal_attributes(['src' => $indicator['chart']]); ?>/>
                        </td>
                        <?php if ($indicator['description']) print '<td><div>' . t($indicator['description']) . '</div></td>'; ?>
                      </tr>
                    </table>
                  <?php } else { ?>
                    <div class="chart">
                      <?php if ($indicator['description']) print '<div>' . t($indicator['description']) . '</div>'; ?>
                      <img <?php print drupal_attributes(['src' => $indicator['chart']]); ?>/>
                    </div>
                  <?php }
                  break;
              }
              ?>
            <?php endforeach; ?>
          </div>
        </div>
      <?php endif; ?>
      <?php
      print $r_sidebar;
      ?>
    </div>
  <?php endif; ?>

  <div class="area-highlights">
    <?php print $r_body; ?>
  </div>
  <div class="area-details">
    <?php if ($cluster_factsheets['indicators_people_totals']): ?>
      <table class="factsheet-chart-indicators">
        <tr>
          <?php foreach ($cluster_factsheets['indicators_people_totals'] as $indicator): ?>
          <td>
            <?php
            switch ($indicator['type']) {
              case 'number':
                ?>
                <div>
                  <strong><?php print check_plain($indicator['value']); ?></strong>
                  <label><?php print check_plain(t($indicator['label'])); ?></label>
                </div>
                <?php
                break;

              case 'chart':
                if ($indicator['smallImage']) { ?>
                  <table class="chart--small-image">
                    <tr>
                      <td width="30%">
                        <strong><?php print check_plain(t($indicator['title'])); ?></strong>
                        <br/>
                        <img <?php print drupal_attributes(['src' => $indicator['chart']]); ?>/>
                      </td>
                      <?php if ($indicator['description']) print '<td><div>' . t($indicator['description']) . '</div></td>'; ?>
                    </tr>
                  </table>
                <?php } else { ?>
                  <div class="chart">
                    <?php if ($indicator['description']) print '<div>' . t($indicator['description']) . '</div>'; ?>
                    <img <?php print drupal_attributes(['src' => $indicator['chart']]); ?>/>
                  </div>
                <?php }
                break;
            }
            ?>
          </td>
          <?php endforeach; ?>
        </tr>
      </table>
    <?php endif; ?>

    <?php if ($cluster_factsheets['cat']): ?>
      <h3><?php print t('Coverage against targets'); ?></h3>
      <div class="chart">
        <?php if ($cluster_factsheets['cat']['description']) print '<div>' . t($cluster_factsheets['cat']['description']) . '</div>'; ?>
        <img <?php print drupal_attributes(['src' => $cluster_factsheets['cat']['chart']]); ?>/>
      </div>
    <?php endif; ?>

    <?php print $r_field_need_analysis; ?>
    <?php print $r_field_fs_response; ?>
    <?php print $r_field_gaps_challenges; ?>
  </div>
</article>
