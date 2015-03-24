#Entity Boilerplate

This repository contains a simple boilerplate to create a fully functional
entity type for Drupal 7.

By default, provides an entity type called _my_entity_ which can be configured
under _admin/structure/my_entity-types_.

This project takes advantage of [xautoload](http://drupal.org/project/xautoload)
to use PSR-4 and OOP in the Entity definition.

## Customization

To create a new entity type from this boilerplate, you have to follow the steps
above:

* In this example, we want to create a module named et_artwork containing an
entity type named example_artwork. 

1. Rename all the files containing the example module name to the new one.
  * IE: entity_boilerplate.module -> et_artwork.module 
2. Rename all the files containing the example entity_type name to the new one.
  * IE: my_entity.api.inc -> example_artwork.api.inc
3. Rename the src/Entity/MyEntity folder and files form the old entity type
camel case name to the new one.
  * IE: MyEntityController.php -> ExampleArtworkController.php
4. Search and replace all the appearances of "MyEntity" with your camel case
entity type name.
  * IE: MyEntity -> ExampleArtwork
5. Search and replace all the appearances of "my_entity" with your machine name
entity type name.
  * IE: my_entity -> example_artwork
6. Search and replace all the appearances of "My Entity" with your human name
entity type name.
  * IE: My Entity -> Example Artwork
7. Search and replace all the appearances of "entity_boilerplate" with your new
module name.
  * IE: entity_boilerplate -> et_artwork
8. Search and replace all the appearances of "eid" with your new entity id
property.
  * IE: eid -> aid
9. You're done!
