<?php

/**
 * Looks for children using the provided DOMXPath object and queries.
 * @param DOMXPath $xpath
 * @param DOMNode|null $context
 * @param string $xpath_children
 *  Query to get the children elements (returned as array values)
 * @param string $xpath_label
 *  Query to get the label (returned as array keys)
 * @param string $xpath_link
 *  Query to get the anchor element, from which the href is obtained
 * @return array
 */
function _shelter_migrate_dom_children($xpath, $context, $xpath_children, $xpath_label = NULL, $xpath_link = NULL, &$links = array()) {
  $children = $xpath->query($xpath_children, $context);
  $ret = array();

  for ($i = 0; $i < $children->length; $i++) {
    /**
     * @var DOMElement
     */
    $e_child = $children->item($i);

    if ($e_child->nodeType != XML_ELEMENT_NODE) {
      continue;
    }

    if ($xpath_label) {
      $labels = $xpath->query($xpath_label, $e_child);
      if ($labels->length != 1) {
        throw new Exception('Something is wrong!');
        continue;
      }

      $ret[$key = trim($labels->item(0)->nodeValue)] = $e_child;
    }
    else {
      $ret[] = $e_child;
      $key = count($ret) - 1;
    }

    if ($xpath_link) {
      $labels = $xpath->query($xpath_link, $e_child);
      if ($labels->length != 1) {
        throw new Exception('Something is wrong!');
        continue;
      }

      $links[$key] = $labels->item(0)->getAttribute('href');
    }
    else {
      $ret[] = $e_child;
    }
  }

  return $ret;
}
