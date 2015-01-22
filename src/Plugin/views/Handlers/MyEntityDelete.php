<?php

/**
 * @file
 * Contains \Drupal\entity_boilerplate\Plugin\Views\Handlers\MyEntityDelete.
 */

namespace Drupal\entity_boilerplate\Plugin\views\Handlers;

class MyEntityDelete extends MyEntityLink {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    // Ensure user has access to delete this node.
    if (!my_entity_access('delete', $entity)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "my_entity/$entity->eid/delete";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');
    return $text;
  }
}
