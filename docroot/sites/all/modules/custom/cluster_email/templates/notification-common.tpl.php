<?php if ($data['cluster_factsheets']): ?>
  <ul style="
    list-style: none;
    margin: 30px 0;
    padding: 0;
  ">
    <?php
    foreach ($data['cluster_factsheets'] as $factsheet):
      ?>
      <li style="
      width: 100%;
      margin: 0;
      padding: 0 0 20px 0;
    ">
        <a
          style="
          text-decoration: none;
          color: black;
        "
          href="<?php print $factsheet['link']; ?>"
        >
          <h4 style="
          text-align: right;
          font-size: 16px;
          color: #7f1416;
          line-height: 21px;
          margin: 0;
        "><?php print t('Factsheet') . check_plain(' · ') . $factsheet['date']; ?></h4>
          <?php if ($factsheet['image']): ?>
            <div style="
              width: 100%;
              height: 120px;
              background-image: url(<?php print $factsheet['image']; ?>);
              background-size: cover;
              background-position: center;
              "></div>
          <?php endif; ?>
          <div style="
          margin-top: 10px;
          font-size: 12px;
        ">
            <?php print $factsheet['highlights']; ?>
          </div>
          <p style="font-size: 12px; color: #575757;"><?php print t('See full factsheet'); ?></p>
        </a>
      </li>
    <?php
    endforeach;
    ?>
  </ul>
<?php endif; ?>

<?php if ($data['cluster_docs']): ?>
  <h3 style="
  ">
    <?php print format_plural(count($data['cluster_docs']), 'New document', 'New documents') ?>
  </h3>
  <ul style="
    list-style: none;
    margin: 30px 0;
    padding: 0;
  ">
    <?php
    $counter = 0;
    foreach ($data['cluster_docs'] as $doc):
      ?>
      <li style="
      display: inline-block;
      vertical-align: top;
      width: 45%;
      margin: 0;
      padding: 0 20px 20px 0;
      min-width: 300px;
      box-sizing: border-box;
    ">
        <a
          style="
          display: flex;
          text-decoration: none;
          color: black;
        "
          href="<?php print $doc['link']; ?>"
        >
          <?php if ($doc['thumbnail']): ?>
            <img
              style="
            float: left;
            width: 100px;
            height: 100px;
            margin-right: 10px;
          "
              width="100"
              height="100"
              src="<?php print $doc['thumbnail']; ?>"
            />
          <?php endif; ?>
          <div>
            <h4 style="
            font-size: 16px;
            font-weight: normal;
            color: #7f1416;
            line-height: 21px;
            text-transform: uppercase;
            margin: 0;
          "><?php print check_plain($doc['title']); ?></h4>
            <p style="
            margin-top: 3px;
            font-size: 12px;
            color: #575757;
          ">
              <?php
              $line = [$doc['date'], $doc['language'], $doc['source']];
              print join(check_plain(' · '), array_filter($line));
              ?>
            </p>
            <?php if ($doc['tags']): ?>
              <p style="
            margin-top: 10px;
            font-size: 12px;
            color: #575757;
          ">
                <?php foreach ($doc['tags'] as $tag): ?>
                  <span style="
              border: 1px solid #575757;
              border-radius: 6px;
              padding: 0 4px;
              margin: 1px;
              display: inline-block;
              max-width: 220px;
              white-space: nowrap;
              overflow: hidden;
              text-overflow: ellipsis;
            "><?php print $tag; ?></span>
                <?php endforeach; ?>
              </p>
            <?php endif; ?>
          </div>
        </a>
      </li>
      <?php
      $counter++;
    endforeach;
    ?>
  </ul>
<?php endif; ?>

<?php if ($data['cluster_og']): ?>
  <h3 style="
  ">
    <?php print format_plural(count($data['cluster_og']), 'New page', 'New pages') ?>
  </h3>
  <ul style="
    margin: 30px 0;
  ">
    <?php
    foreach ($data['cluster_og'] as $page):
      ?>
      <li style="
      margin-bottom: 5px;
    ">
        <a
          style="
          text-decoration: none;
          color: black;
        "
          href="<?php print $page['link']; ?>"
        >
          <?php print $page['title']; ?>
        </a>
      </li>
    <?php
    endforeach;
    ?>
  </ul>
<?php endif; ?>
