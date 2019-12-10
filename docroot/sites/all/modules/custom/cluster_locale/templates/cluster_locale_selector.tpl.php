<?php /**
 * @var object $current_language
 * @var object[] $languages
 * @var string $current_path
 */ ?>
<div id="language-selector">
  <span>
    <?php print check_plain($current_language->native); ?>
  </span>
  <ul class="nav-items menu">
    <?php foreach ($languages as $language): ?>
    <li>
      <?php echo l($language->native, 'select-language/'.$language->language, [
        'query' => ['destination' => $current_path],
      ]); ?>
    </li>
    <?php endforeach; ?>
  </ul>
<?php //echo print_r(['list' => $languages, 'current' => $current_language, 'path' => $current_path], true); ?>
</div>
