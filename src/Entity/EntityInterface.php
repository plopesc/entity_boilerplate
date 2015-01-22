<?php

/**
 * @file
 * Contains \Drupal\entity_boilerplate\Entity\EntityInterface.
 */

namespace Drupal\entity_boilerplate\Entity;

interface EntityInterface {

  /**
   * Returns the internal, numeric identifier.
   *
   * Returns the numeric identifier, even if the entity type has specified a
   * name key. In the latter case, the numeric identifier is supposed to be used
   * when dealing generically with entities or internally to refer to an entity,
   * i.e. in a relational database. If unsure, use Entity:identifier().
   */
  public function internalIdentifier();

  /**
   * Returns the entity identifier, i.e. the entities name or numeric id.
   *
   * @return
   *   The identifier of the entity. If the entity type makes use of a name key,
   *   the name is returned, else the numeric id.
   *
   * @see entity_id()
   */
  public function identifier();

  /**
   * Returns the info of the type of the entity.
   *
   * @see entity_get_info()
   */
  public function entityInfo();

  /**
   * Returns the type of the entity.
   */
  public function entityType();

  /**
   * Returns the bundle of the entity.
   *
   * @return
   *   The bundle of the entity. Defaults to the entity type if the entity type
   *   does not make use of different bundles.
   */
  public function bundle();

  /**
   * Returns the label of the entity.
   *
   * Modules may alter the label by specifying another 'label callback' using
   * hook_entity_info_alter().
   *
   * @see entity_label()
   */
  public function label();

  /**
   * Returns the uri of the entity just as entity_uri().
   *
   * Modules may alter the uri by specifying another 'uri callback' using
   * hook_entity_info_alter().
   *
   * @see entity_uri()
   */
  public function uri();

  /**
   * Checks if the entity has a certain exportable status.
   *
   * @param $status
   *   A status constant, i.e. one of ENTITY_CUSTOM, ENTITY_IN_CODE,
   *   ENTITY_OVERRIDDEN or ENTITY_FIXED.
   *
   * @return
   *   For exportable entities TRUE if the entity has the status, else FALSE.
   *   In case the entity is not exportable, NULL is returned.
   *
   * @see entity_has_status()
   */
  public function hasStatus($status);

  /**
   * Permanently saves the entity.
   *
   * @see entity_save()
   */
  public function save();

  /**
   * Permanently deletes the entity.
   *
   * @see entity_delete()
   */
  public function delete();

  /**
   * Exports the entity.
   *
   * @see entity_export()
   */
  public function export($prefix = '');

  /**
   * Generate an array for rendering the entity.
   *
   * @see entity_view()
   */
  public function view($view_mode = 'full', $langcode = NULL, $page = NULL);

  /**
   * Builds a structured array representing the entity's content.
   *
   * @see entity_build_content()
   */
  public function buildContent($view_mode = 'full', $langcode = NULL);

  /**
   * Gets the raw, translated value of a property or field.
   *
   * Supports retrieving field translations as well as i18n string translations.
   *
   * Note that this returns raw data values, which might not reflect what
   * has been declared for hook_entity_property_info() as no 'getter callbacks'
   * are invoked or no referenced entities are loaded. For retrieving values
   * reflecting the property info make use of entity metadata wrappers, see
   * entity_metadata_wrapper().
   *
   * @param $property_name
   *   The name of the property to return; e.g., 'title'.
   * @param $langcode
   *   (optional) The language code of the language to which the value should
   *   be translated. If set to NULL, the default display language is being
   *   used.
   *
   * @return
   *   The raw, translated property value; or the raw, un-translated value if no
   *   translation is available.
   *
   * @todo Implement an analogous setTranslation() method for updating.
   */
  public function getTranslation($property, $langcode = NULL);

  /**
   * Checks whether the entity is the default revision.
   *
   * @return Boolean
   *
   * @see entity_revision_is_default()
   */
  public function isDefaultRevision();

}
