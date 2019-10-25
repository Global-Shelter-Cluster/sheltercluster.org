<div class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="content"<?php print $content_attributes; ?>>
    <?php
    hide($content['field_twocol_headers']);
    hide($content['field_twocol_text_link']);
    print render($content);
    ?>

    <table>
      <?php
      $has_headers = trim($content['field_twocol_headers'][0]['#item']['first'])
        || trim($content['field_twocol_headers'][0]['#item']['second']);

      if ($has_headers):
        ?>
        <thead>
        <tr>
          <th><?php print check_plain($content['field_twocol_headers'][0]['#item']['first']); ?></th>
          <th><?php print check_plain($content['field_twocol_headers'][0]['#item']['second']); ?></th>
        </tr>
        </thead>
      <?php endif; ?>
      <?php
      $children = element_children($content['field_twocol_text_link']);
      if (count($children)):
        ?>
        <tbody>
        <?php
        foreach ($children as $key):
          $item = current($content['field_twocol_text_link'][$key]['entity']['field_collection_item'])
          ?>
          <tr>
            <td><?php print render($item['field_cell_text']); ?></td>
            <td><?php print render($item['field_cell_link']); ?></td>
          </tr>
        <?php endforeach; ?>
        </tbody>
      <?php endif; ?>
    </table>

  </div>
</div>

