<?php
/**
 * @file
 * RSS template.
 */
?>
<?xml version="1.0" encoding="utf-8"?>
<rss version="2.0">
<channel>
  <title><?php print $title; ?> - <?php print $type; ?> RSS</title>
  <description><?php print $type; ?> RSS Feed for <?php print $title; ?></description>
  <link><?php print $path; ?></link>
  <lastBuildDate><?php print $date; ?></lastBuildDate>
  <pubDate><?php print $date ?></pubDate>
  <ttl>1800</ttl>
  <?php foreach($items as $item): ?>
    <item>
      <title><?php print $item->title; ?></title>
      <description><?php print $item->description; ?></description>
      <link><?php print $item->url; ?></link>
      <guid isPermaLink="true"><?php print $item->guid; ?></guid>
      <pubDate><?php print $item->pubDate; ?></pubDate>
      <?php if (isset($item->eventDate)): ?>
        <eventDate><?php print $item->eventDate; ?></eventDate>
      <?php endif; ?>
    </item>
  <?php endforeach; ?>
</channel>
</rss>
