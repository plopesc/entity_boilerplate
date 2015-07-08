<?php

/**
 * @file
 * Contains class \Drupal\entity_boilerplate\Entity\MyEntity\MyEntityUIController.
 */

namespace Drupal\entity_boilerplate\Entity\MyEntity;

class MyEntityUIController extends \EntityBundleableUIController {

  /**
   * {@inheritdoc}
   */
  public function hook_menu() {
    $items = parent::hook_menu();

    $wildcard = isset($this->entityInfo['admin ui']['menu wildcard']) ? $this->entityInfo['admin ui']['menu wildcard'] : '%entity_object';

    // Fix the admin content path and clean up the extra manage links.
    unset($items[$this->path . '/list']);
    // Cleaning up cruft added by EntityDefaultUIController.
    unset($items[$this->path . '/manage/' . $wildcard]);
    unset($items[$this->path . '/manage/' . $wildcard . '/edit']);
    unset($items[$this->path . '/manage/' . $wildcard . '/clone']);
    unset($items[$this->path . '/manage/' . $wildcard . '/%']);

    return $items;
  }

}
