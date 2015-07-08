<?php

/**
 * Implements hook_views_default_views().
 */
function entity_boilerplate_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'my_entity_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'my_entity';
  $view->human_name = 'My entities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My entities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer my_entity entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: My Entity: My entity ID */
  $handler->display->display_options['fields']['eid']['id'] = 'eid';
  $handler->display->display_options['fields']['eid']['table'] = 'my_entity';
  $handler->display->display_options['fields']['eid']['field'] = 'eid';
  /* Field: My Entity: Label */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'my_entity';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = 'my_entity/[eid]';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'There are no results';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: My Entity: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'my_entity';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: My Entity: Link */
  $handler->display->display_options['fields']['link_my_entity']['id'] = 'link_my_entity';
  $handler->display->display_options['fields']['link_my_entity']['table'] = 'my_entity';
  $handler->display->display_options['fields']['link_my_entity']['field'] = 'link_my_entity';
  $handler->display->display_options['fields']['link_my_entity']['label'] = '';
  $handler->display->display_options['fields']['link_my_entity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_my_entity']['element_label_colon'] = FALSE;
  /* Field: My Entity: Delete Link */
  $handler->display->display_options['fields']['delete_my_entity']['id'] = 'delete_my_entity';
  $handler->display->display_options['fields']['delete_my_entity']['table'] = 'my_entity';
  $handler->display->display_options['fields']['delete_my_entity']['field'] = 'delete_my_entity';
  $handler->display->display_options['fields']['delete_my_entity']['label'] = '';
  $handler->display->display_options['fields']['delete_my_entity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['delete_my_entity']['element_label_colon'] = FALSE;
  /* Field: My Entity: Edit Link */
  $handler->display->display_options['fields']['edit_my_entity']['id'] = 'edit_my_entity';
  $handler->display->display_options['fields']['edit_my_entity']['table'] = 'my_entity';
  $handler->display->display_options['fields']['edit_my_entity']['field'] = 'edit_my_entity';
  $handler->display->display_options['fields']['edit_my_entity']['label'] = '';
  $handler->display->display_options['fields']['edit_my_entity']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_my_entity']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[link_my_entity] [edit_my_entity] [delete_my_entity]';
  /* Sort criterion: My Entity: My entity ID */
  $handler->display->display_options['sorts']['eid']['id'] = 'eid';
  $handler->display->display_options['sorts']['eid']['table'] = 'my_entity';
  $handler->display->display_options['sorts']['eid']['field'] = 'eid';
  $handler->display->display_options['sorts']['eid']['order'] = 'DESC';
  /* Filter criterion: My Entity: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'my_entity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
    2 => '2',
    3 => '3',
    1 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/my_entity';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'My entity list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['my_entity_list'] = $view;
  return $views;

}
