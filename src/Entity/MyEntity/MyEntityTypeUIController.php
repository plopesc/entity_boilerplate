<?php

/**
 * @file
 * Contains class \Drupal\entity_boilerplate\Entity\MyEntity\MyEntityTypeUIController.
 */

namespace Drupal\entity_boilerplate\Entity\MyEntity;

class MyEntityTypeUIController extends \EntityDefaultUIController {

  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();
    $items[$this->path]['description'] = 'Manage My Entity types.';
    return $items;
  }

}
