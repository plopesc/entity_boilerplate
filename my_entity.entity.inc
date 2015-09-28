<?php

/**
 * @file
 * Specific form handlers for My Entity entity.
 */

/**
 * Generates the My Entity type editing form.
 */
function my_entity_type_form($form, &$form_state, $my_entity_type, $op = 'edit') {

  if ($op == 'clone') {
    $my_entity_type->label .= ' (cloned)';
    $my_entity_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $my_entity_type->label,
    '#description' => t('The human-readable name of this My Entity type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => $my_entity_type->type,
    '#maxlength' => 32,
    '#disabled' => $my_entity_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'my_entity_type_load',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this My Entity type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($my_entity_type->description) ? $my_entity_type->description : '',
    '#description' => t('Description about the My Entity type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save My Entity type'),
    '#weight' => 40,
  );

  if (!$my_entity_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete My Entity type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('my_entity_type_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing My Entity type.
 */
function my_entity_type_form_submit(&$form, &$form_state) {
  $my_entity_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  my_entity_type_save($my_entity_type);

  if ($form_state['op'] == 'edit') {
    drupal_set_message(t('My Entity type @type updated', array('@type' => $my_entity_type->type)));
  }
  else {
    drupal_set_message(t('My Entity type @type created', array('@type' => $my_entity_type->type)));
  }

  // Redirect user back to list of My Entity types.
  $form_state['redirect'] = 'admin/structure/my_entity-types';
}

/**
 * Page to select My Entity Type to add new My Entity.
 */
function my_entity_admin_add_page() {
  $items = array();
  foreach (my_entity_types() as $my_entity_type_key => $my_entity_type) {
    $items[] = l(entity_label('my_entity_type', $my_entity_type), 'my_entity/add/' . $my_entity_type_key);
  }
  if (!empty($items)) {
    return array(
      'list' => array(
        '#theme' => 'item_list',
        '#items' => $items,
        '#title' => t('Select type of My Entity to create.')
      )
    );
  }
  else {
    return t('You need to add My Entity types before create My Entity items. !link', array('!link' => l(t('You can add My Entity types here.'), 'admin/structure/my_entity-types/add', array('query' => array('destination' => 'my_entity/add')))));
  }
}

/**
 * My Entity Form.
 */
function my_entity_form($form, &$form_state, $my_entity) {
  $form_state['my_entity'] = $my_entity;

  // Basic my_entity information.
  // These elements are just values so they are not even sent to the client.
  foreach (array('eid', 'uid', 'created', 'type') as $key) {
    $form[$key] = array(
      '#type' => 'value',
      '#value' => isset($my_entity->$key) ? $my_entity->$key : NULL,
    );
  }

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Name'),
    '#default_value' => $my_entity->title,
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $my_entity->description,
  );

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $my_entity->uid,
  );

  field_attach_form('my_entity', $my_entity, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save My Entity'),
    '#submit' => $submit + array('my_entity_form_submit'),
  );

  // Show Delete button if we edit My Entity.
  $eid = entity_id('my_entity', $my_entity);
  if (!empty($eid) && my_entity_access('edit', $my_entity)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('my_entity_form_submit_delete'),
    );
  }

  return $form;
}

/**
 * My Entity validate callback.
 */
function my_entity_form_validate($form, &$form_state) {
  entity_form_field_validate('my_entity', $form, $form_state);
}

/**
 * My Entity submit handler.
 */
function my_entity_form_submit($form, &$form_state) {
  $my_entity = $form_state['my_entity'];

  entity_form_submit_build_entity('my_entity', $my_entity, $form, $form_state);

  my_entity_save($my_entity);

  $my_entity_uri = entity_uri('my_entity', $my_entity);

  $form_state['redirect'] = $my_entity_uri['path'];

  drupal_set_message(t('My Entity %title saved.', array('%title' => entity_label('my_entity', $my_entity))));
}

/**
 * My Entity delete submit handler.
 */
function my_entity_form_submit_delete($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $my_entity = $form_state['my_entity'];
  $my_entity_uri = entity_uri('my_entity', $my_entity);
  $form_state['redirect'] = array($my_entity_uri['path'] . '/delete', array('query' => $destination));

}

/**
 * Delete confirmation form.
 */
function my_entity_delete_form($form, &$form_state, $my_entity) {
  $form_state['my_entity'] = $my_entity;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['eid'] = array('#type' => 'value', '#value' => entity_id('my_entity', $my_entity));
  $my_entity_uri = entity_uri('my_entity', $my_entity);
  return confirm_form($form,
    t('Are you sure you want to delete My Entity %title?', array('%title' => entity_label('my_entity', $my_entity))),
    $my_entity_uri['path'],
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function my_entity_delete_form_submit($form, &$form_state) {
  $my_entity = $form_state['my_entity'];
  my_entity_delete($my_entity);

  drupal_set_message(t('My Entity %title deleted.', array('%title' => entity_label('my_entity', $my_entity))));

  $form_state['redirect'] = '<front>';
}
