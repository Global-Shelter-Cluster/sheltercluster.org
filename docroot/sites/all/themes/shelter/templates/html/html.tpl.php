<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 */
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML+RDFa 1.0//EN"
  "http://www.w3.org/MarkUp/DTD/xhtml-rdfa-1.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="<?php print $language->language; ?>" version="XHTML+RDFa 1.0" dir="<?php print $language->dir; ?>"<?php print $rdf_namespaces; ?>>

<head profile="<?php print $grddl_profile; ?>">
  <meta http-equiv="X-UA-Compatible" content="IE=edge">
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <?php print $styles; ?>
  <?php print $scripts; ?>

  <?php /* TODO: add "app-argument" to link to the proper place in the app (see SA-114) */ ?>
  <meta name="apple-itunes-app" content="app-id=1415068304">
<script>
  console.log(JSON.stringify([{type: 'user', id: 733}]));
 // jQuery.ajax({
 //    type: "POST",
 //    url: "http://sheltercluster.lndo.site:8000/api-v1/get-objects",
 //    dataType: "json",
 //    contentType: "application/json",
 //    success: console.log,
 //    data: JSON.stringify([
 //      {type: 'user', id: 733},
 //    ])
 //  });
</script>
</head>
<body class="<?php print $classes; ?>" <?php print $attributes;?>>
  <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>
  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php print $page_bottom; ?>
</body>
</html>

