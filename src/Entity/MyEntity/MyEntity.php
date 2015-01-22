<?php

/**
 * @file
 * Contains class \Drupal\entity_boilerplate\Entity\MyEntity\MyEntity.
 */

namespace Drupal\entity_boilerplate\Entity\MyEntity;

class MyEntity extends \Entity implements MyEntityInterface {

  /**
   * The My Entity description.
   *
   * @var int
   */
  public $description;

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'my_entity/' . $this->identifier());
  }

}
