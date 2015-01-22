<?php

/**
 * @file
 * API functions related to My Entity entity.
 */

/*******************************************************************************
 ********************************* My Entity API's *******************************
 ******************************************************************************/

/**
 * Access callback for My Entity.
 */
function my_entity_access($op, $my_entity, $account = NULL, $entity_type = NULL) {
  return entity_boilerplate_entity_access($op, $my_entity, $account, 'my_entity');
}

/**
 * Load a My Entity.
 */
function my_entity_load($eid, $reset = FALSE) {
  $my_entities = my_entity_load_multiple(array($eid), array(), $reset);
  return reset($my_entities);
}

/**
 * Load multiple My Entity based on certain conditions.
 */
function my_entity_load_multiple($eids = array(), $conditions = array(), $reset = FALSE) {
  return entity_load('my_entity', $eids, $conditions, $reset);
}

/**
 * Save My Entity.
 */
function my_entity_save($my_entity) {
  entity_save('my_entity', $my_entity);
}

/**
 * Delete single My Entity.
 */
function my_entity_delete($my_entity) {
  entity_delete('my_entity', entity_id('my_entity', $my_entity));
}

/**
 * Delete multiple My Entitys.
 */
function my_entity_delete_multiple($eids) {
  entity_delete_multiple('my_entity', $eids);
}


/*******************************************************************************
 ****************************** My Entity Type API's *****************************
 ******************************************************************************/

/**
 * Access callback for My Entity Type.
 */
function my_entity_type_access($op, $entity = NULL, $account = NULL) {
  return user_access('administer my_entity_type entities', $account);
}

/**
 * Load My Entity Type.
 */
function my_entity_type_load($my_entity_type) {
  return my_entity_types($my_entity_type);
}

/**
 * List of My Entity Types.
 */
function my_entity_types($type_name = NULL) {
  $types = entity_load_multiple_by_name('my_entity_type', isset($type_name) ? array($type_name) : FALSE);
  return isset($type_name) ? reset($types) : $types;
}

/**
 * Save My Entity Type entity.
 */
function my_entity_type_save($my_entity_type) {
  entity_save('my_entity_type', $my_entity_type);
}

/**
 * Delete single My Entity type.
 */
function my_entity_type_delete($my_entity_type) {
  entity_delete('my_entity_type', entity_id('my_entity_type', $my_entity_type));
}

/**
 * Delete multiple My Entity types.
 */
function my_entity_type_delete_multiple($my_entity_type_ids) {
  entity_delete_multiple('my_entity_type', $my_entity_type_ids);
}
