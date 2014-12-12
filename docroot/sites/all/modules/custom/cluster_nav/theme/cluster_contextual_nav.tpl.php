<nav id="contextual-navigation">

  <?php if ($regions): ?>
  <span>
    <?php

    print t('In').' ';

    for ($i = 0; $i < count($regions); $i++) {

      if (count($regions) > 1 && $i == count($regions) - 1) {
        // Last item
        print ' '.t('and').' ';
      } elseif ($i > 0) {
        // Not the first item
        print ', ';
      }

      print $regions[$i];

    }
    ?>
  </span>
  <?php endif; ?>

  <?php if ($response): ?>
  <span>
    <?php

    print $regions ? t('and related to') : t('Related to');
    print ' '.$response;

    ?>
  </span>
  <?php endif; ?>

</nav>