<nav id="contextual-navigation">

  <?php if ($regions): ?>
  <span>
    In
    <?php
    for ($i = 0; $i < count($regions); $i++) {
      if ($i == count($regions) - 1) {
        // Last item
        print ' '.t('and').' ';
      } elseif ($i > 0) {
        // Not the first item
        print ', ';
      }

      print l($regions[$i]['title'], $regions[$i]['path']);
    }
    ?>
  </span>
  <?php endif; ?>

  <?php if ($response): ?>
  <span>
    <?php

    if ($regions) {
      print t('and related to');
    }
    else {
      print t('Related to');
    }

    print ' ';

    print l($response['title'], $response['path']);

    ?>
  </span>
  <?php endif; ?>

</nav>