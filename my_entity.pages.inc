<?php

/**
 * My Entity view callback.
 */
function my_entity_view($my_entity) {
  drupal_set_title(entity_label('my_entity', $my_entity));
  return entity_view('my_entity', array(entity_id('my_entity', $my_entity) => $my_entity), 'full');
}