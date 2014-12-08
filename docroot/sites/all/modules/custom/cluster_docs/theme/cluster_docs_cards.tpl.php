<?php
/**
 * @file
 *  Template file for a set of documents themed as cards.
 * variables:
 *  $category
 *    The taxonomy term that was queried for.
 *  $nodes
 *    Render array of nodes.
 */
?>
<h4><?print $category; ?></h4>
<ul class="document-cards clearfix">
  <?php foreach($nodes as $delta => $node): ?>
  <?php $zebra = ($delta % 2) ? 'odd' : 'even'; ?> 
  <li class="document-card <?php print $zebra; ?>">
    <div class="image-card"><?php //print _svg('icons/book', array('class'=>'document-external', 'alt' => 'Icon for an external resource')); ?></div>
    <div class="information-card">
      <a href="#">id lobortis leo maximus tristique</a>
      <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
    </div>
    <div class="information-file">
      <span class="size-type">[ 250k ] docx</span>
      <span class="source">Aenean pulvinar</span>
    </div>
  </li>
  <li class="document-card odd">
    <div class="image-card"><?php //print _svg('icons/file', array('class'=>'document-file', 'alt' => 'Icon for a file')); ?></div>
    <div class="information-card">
      <a href="#">id lobortis leo maximus tristique</a>
      <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nunc aliquet justo leo, id lobortis leo maximus tristique. Sed non odio eros. Aenean pulvinar sapien quam, a bibendum ante lobortis eu.</p>
    </div>
    <div class="information-file">
      <span class="size-type">[ 250k ] docx</span>
      <span class="source">Aenean pulvinar</span>
    </div>
  </li>
  <?php endforeach; ?>
</ul>