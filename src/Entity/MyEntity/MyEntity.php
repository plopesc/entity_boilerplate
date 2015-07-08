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
   * The My Entity changed timestamp.
   *
   * @var int
   */
  public $changed;

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return array('path' => 'my_entity/' . $this->identifier());
  }

  /**
   * {@inheritdoc}
   */
  public function save() {
    $this->changed = REQUEST_TIME;
    parent::save();
  }

}
