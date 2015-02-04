<?php

/**
 * My Entity view callback.
 */
function my_entity_view($my_entity) {
  drupal_set_title(entity_label('my_entity', $my_entity));
  return entity_view('my_entity', array(entity_id('my_entity', $my_entity) => $my_entity), 'full');
}

/**
 * Add new My Entity page callback.
 */
function my_entity_add($type) {
  $my_entity_type = my_entity_types($type);

  $my_entity = entity_create('my_entity', array('type' => $type));
  drupal_set_title(t('Create My Entity @name', array('@name' => entity_label('my_entity_type', $my_entity_type))));

  $form_state = array();
  $form_state['build_info']['args'] = array($my_entity);
  form_load_include($form_state, 'inc', 'entity_boilerplate', 'my_entity.entity');
  return drupal_build_form($type . '_my_entity_form', $form_state);
}

/**
 * Edit My Entity page callback.
 */
function my_entity_edit($my_entity) {
  $my_entity_type = my_entity_types($my_entity->type);
  drupal_set_title(t('<em>Edit @type</em> @title', array('@type' => entity_label('my_entity_type', $my_entity_type), '@title' => entity_label('my_entity', $my_entity))), PASS_THROUGH);

  $form_state = array();
  $form_state['build_info']['args'] = array($my_entity);
  form_load_include($form_state, 'inc', 'entity_boilerplate', 'my_entity.entity');
  return drupal_build_form($my_entity->type . '_my_entity_form', $form_state);
}