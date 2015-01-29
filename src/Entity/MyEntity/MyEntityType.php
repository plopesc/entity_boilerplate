<?php

/**
 * @file
 * Contains class \Drupal\entity_boilerplate\Entity\MyEntity\MyEntityType.
 */

namespace Drupal\entity_boilerplate\Entity\MyEntity;

class MyEntityType extends \Entity {

  public function __construct($values = array()) {
    parent::__construct($values, 'my_entity_type');
  }

  function isLocked() {
    return isset($this->status) && empty($this->is_new) && (($this->status & ENTITY_IN_CODE) || ($this->status & ENTITY_FIXED));
  }

}
