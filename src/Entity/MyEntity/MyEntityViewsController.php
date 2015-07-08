<?php

/**
 * @file
 * Contains class \Drupal\entity_boilerplate\Entity\MyEntity\MyEntityViewsController.
 */

namespace Drupal\entity_boilerplate\Entity\MyEntity;

class MyEntityViewsController extends \EntityDefaultViewsController {

  /**
   * {@inheritdoc}
   */
  public function views_data() {
    $data = parent::views_data();

    $data['my_entity']['link_my_entity'] = array(
      'field' => array(
        'title' => t('Link'),
        'help' => t('Provide a link to the My Entity.'),
        'handler' => '\Drupal\entity_boilerplate\Plugin\views\Handlers\MyEntityLink',
      ),
    );
    $data['my_entity']['edit_my_entity'] = array(
      'field' => array(
        'title' => t('Edit Link'),
        'help' => t('Provide a link to the edit form for the My Entity.'),
        'handler' => '\Drupal\entity_boilerplate\Plugin\views\Handlers\MyEntityEdit',
      ),
    );
    $data['my_entity']['delete_my_entity'] = array(
      'field' => array(
        'title' => t('Delete Link'),
        'help' => t('Provide a link to delete the My Entity.'),
        'handler' => '\Drupal\entity_boilerplate\Plugin\views\Handlers\MyEntityDelete',
      ),
    );

    return $data;
  }

}
