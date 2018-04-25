<div>
  <?php if (!$label_hidden): ?>
    <h3><?php
      print $label;
      if (isset($cluster_factsheets) && isset($cluster_factsheets['hh_abbr']))
        print $cluster_factsheets['hh_abbr'];
      ?></h3>
  <?php endif; ?>
  <?php
  foreach ($items as $delta => $item)
    print render($item);
  ?>
</div>
