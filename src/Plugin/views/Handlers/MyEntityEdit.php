<?php

/**
 * @file
 * Contains \Drupal\entity_boilerplate\Plugin\Views\Handlers\MyEntityEdit.
 */

namespace Drupal\entity_boilerplate\Plugin\views\Handlers;

class MyEntityEdit extends MyEntityLink {

  /**
   * Renders the link.
   */
  function render_link($entity, $values) {
    // Ensure user has access to edit this node.
    if (!my_entity_access('update', $entity)) {
      return;
    }

    $this->options['alter']['make_link'] = TRUE;
    $this->options['alter']['path'] = "admin/content/my_entity/$entity->eid/edit";
    $this->options['alter']['query'] = drupal_get_destination();

    $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');
    return $text;
  }
}
