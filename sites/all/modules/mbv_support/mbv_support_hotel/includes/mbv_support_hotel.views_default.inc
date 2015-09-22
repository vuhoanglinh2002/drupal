 <?php

 /**
  *
  * @author baonguyen
  *
  */
 function mbv_support_hotel_views_default_views(){
  $views = array();
  $list = mbv_support_hotel_list();
  $views[$list->name] = $list;

  return $views;
 }

 function mbv_support_hotel_list(){
  $view = new view();
  $view->name = 'mbv_hotel';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'mbv_support_issue';
  $view->human_name = 'MBV Hotel';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'MBV Hotel';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view mbv_issue_hotel entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '<strong style="border: solid 1px red;padding: 5px;">No data found, please try again with others keyword.</strong>';
  $handler->display->display_options['empty']['area']['format'] = 'full_html';
  /* Field: MBV Support: Checkbox */
  $handler->display->display_options['fields']['check_box']['id'] = 'check_box';
  $handler->display->display_options['fields']['check_box']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['check_box']['field'] = 'check_box';
  $handler->display->display_options['fields']['check_box']['label'] = '';
  $handler->display->display_options['fields']['check_box']['element_label_colon'] = FALSE;
  /* Field: MBV Support: Created */
  $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
  /* Field: MBV Support: Modifier */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: MBV Support: Ref Id */
  $handler->display->display_options['fields']['ref_id']['id'] = 'ref_id';
  $handler->display->display_options['fields']['ref_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['ref_id']['field'] = 'ref_id';
  /* Field: MBV Support: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: MBV Support: View Detail */
  $handler->display->display_options['fields']['view_detail']['id'] = 'view_detail';
  $handler->display->display_options['fields']['view_detail']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['view_detail']['field'] = 'view_detail';
  $handler->display->display_options['fields']['view_detail']['label'] = '';
  $handler->display->display_options['fields']['view_detail']['element_label_colon'] = FALSE;
  /* Sort criterion: MBV Support: Created */
  $handler->display->display_options['sorts']['created_at']['id'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['table'] = 'mbv_support_issue';
  $handler->display->display_options['sorts']['created_at']['field'] = 'created_at';
  $handler->display->display_options['sorts']['created_at']['order'] = 'DESC';
  /* Sort criterion: MBV Support: Updated */
  $handler->display->display_options['sorts']['updated_at']['id'] = 'updated_at';
  $handler->display->display_options['sorts']['updated_at']['table'] = 'mbv_support_issue';
  $handler->display->display_options['sorts']['updated_at']['field'] = 'updated_at';
  $handler->display->display_options['sorts']['updated_at']['order'] = 'DESC';
  /* Filter criterion: MBV Support Entity: Hotel Provider (hotel_provider) */
  $handler->display->display_options['filters']['hotel_provider_value']['id'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['table'] = 'field_data_hotel_provider';
  $handler->display->display_options['filters']['hotel_provider_value']['field'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_provider_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['operator_id'] = 'hotel_provider_value_op';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['label'] = 'Hotel Provider';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['operator'] = 'hotel_provider_value_op';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['identifier'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support Entity: Hotel Failure (hotel_failure) */
  $handler->display->display_options['filters']['hotel_failure_value']['id'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['table'] = 'field_data_hotel_failure';
  $handler->display->display_options['filters']['hotel_failure_value']['field'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_failure_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['operator_id'] = 'hotel_failure_value_op';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['label'] = 'Hotel Failure';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['operator'] = 'hotel_failure_value_op';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['identifier'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: System name */
  $handler->display->display_options['filters']['filter_system_name']['id'] = 'filter_system_name';
  $handler->display->display_options['filters']['filter_system_name']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_system_name']['field'] = 'filter_system_name';
  $handler->display->display_options['filters']['filter_system_name']['value'] = array(
   'mbv_issue_hotel' => 'mbv_issue_hotel'
  );
  $handler->display->display_options['filters']['filter_system_name']['group'] = 1;
  /* Filter criterion: MBV Support: Status */
  $handler->display->display_options['filters']['filter_issue_statues']['id'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_issue_statues']['field'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['group'] = 1;
  $handler->display->display_options['filters']['filter_issue_statues']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['operator_id'] = 'filter_issue_statues_op';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['operator'] = 'filter_issue_statues_op';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['identifier'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Type */
  $handler->display->display_options['filters']['filter_issue_type']['id'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_issue_type']['field'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['group'] = 1;
  $handler->display->display_options['filters']['filter_issue_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_type']['expose']['operator_id'] = 'filter_issue_type_op';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['operator'] = 'filter_issue_type_op';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['identifier'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_type']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: From */
  $handler->display->display_options['filters']['filter_created_from']['id'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_created_from']['field'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['group'] = 1;
  $handler->display->display_options['filters']['filter_created_from']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_created_from']['expose']['operator_id'] = 'filter_created_from_op';
  $handler->display->display_options['filters']['filter_created_from']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['filter_created_from']['expose']['operator'] = 'filter_created_from_op';
  $handler->display->display_options['filters']['filter_created_from']['expose']['identifier'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_created_from']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: To */
  $handler->display->display_options['filters']['filter_created_to']['id'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_created_to']['field'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['group'] = 1;
  $handler->display->display_options['filters']['filter_created_to']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_created_to']['expose']['operator_id'] = 'filter_created_to_op';
  $handler->display->display_options['filters']['filter_created_to']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['filter_created_to']['expose']['operator'] = 'filter_created_to_op';
  $handler->display->display_options['filters']['filter_created_to']['expose']['identifier'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_created_to']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Memo */
  $handler->display->display_options['filters']['filter_memo']['id'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_memo']['field'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['operator'] = 'contains';
  $handler->display->display_options['filters']['filter_memo']['group'] = 1;
  $handler->display->display_options['filters']['filter_memo']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_memo']['expose']['operator_id'] = 'filter_memo_op';
  $handler->display->display_options['filters']['filter_memo']['expose']['label'] = 'Memo';
  $handler->display->display_options['filters']['filter_memo']['expose']['operator'] = 'filter_memo_op';
  $handler->display->display_options['filters']['filter_memo']['expose']['identifier'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_memo']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Ref id */
  $handler->display->display_options['filters']['filter_ref_id']['id'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_ref_id']['field'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['group'] = 1;
  $handler->display->display_options['filters']['filter_ref_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_ref_id']['expose']['operator_id'] = 'filter_ref_id_op';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['label'] = 'Ref id';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['operator'] = 'filter_ref_id_op';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['identifier'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_ref_id']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support Entity: Jira Bug Id (hotel_jira_bug_id) */
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['id'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['table'] = 'field_data_hotel_jira_bug_id';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['field'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['operator_id'] = 'hotel_jira_bug_id_value_op';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['label'] = 'Jira Bug Id  ';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['operator'] = 'hotel_jira_bug_id_value_op';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['identifier'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'mbv/issue/hotel/list';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%timestamp-full.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: MBV Support: Created */
  $handler->display->display_options['fields']['created_at']['id'] = 'created_at';
  $handler->display->display_options['fields']['created_at']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['created_at']['field'] = 'created_at';
  /* Field: MBV Support: Issue Id */
  $handler->display->display_options['fields']['issue_id']['id'] = 'issue_id';
  $handler->display->display_options['fields']['issue_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['issue_id']['field'] = 'issue_id';
  /* Field: MBV Support: Issue Type */
  $handler->display->display_options['fields']['issue_type']['id'] = 'issue_type';
  $handler->display->display_options['fields']['issue_type']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['issue_type']['field'] = 'issue_type';
  /* Field: MBV Support: Memo */
  $handler->display->display_options['fields']['memo']['id'] = 'memo';
  $handler->display->display_options['fields']['memo']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['memo']['field'] = 'memo';
  /* Field: MBV Support: Modifier */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  /* Field: MBV Support: Ref Id */
  $handler->display->display_options['fields']['ref_id']['id'] = 'ref_id';
  $handler->display->display_options['fields']['ref_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['ref_id']['field'] = 'ref_id';
  /* Field: MBV Support: Revision Id */
  $handler->display->display_options['fields']['revision_id']['id'] = 'revision_id';
  $handler->display->display_options['fields']['revision_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['revision_id']['field'] = 'revision_id';
  /* Field: MBV Support: Status */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  /* Field: MBV Support: System Name */
  $handler->display->display_options['fields']['system_name']['id'] = 'system_name';
  $handler->display->display_options['fields']['system_name']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['system_name']['field'] = 'system_name';
  /* Field: MBV Support: Updated */
  $handler->display->display_options['fields']['updated_at']['id'] = 'updated_at';
  $handler->display->display_options['fields']['updated_at']['table'] = 'mbv_support_issue';
  $handler->display->display_options['fields']['updated_at']['field'] = 'updated_at';
  /* Field: MBV Support Entity: Hotel Failure */
  $handler->display->display_options['fields']['hotel_failure']['id'] = 'hotel_failure';
  $handler->display->display_options['fields']['hotel_failure']['table'] = 'field_data_hotel_failure';
  $handler->display->display_options['fields']['hotel_failure']['field'] = 'hotel_failure';
  /* Field: MBV Support Entity: Hotel Provider */
  $handler->display->display_options['fields']['hotel_provider']['id'] = 'hotel_provider';
  $handler->display->display_options['fields']['hotel_provider']['table'] = 'field_data_hotel_provider';
  $handler->display->display_options['fields']['hotel_provider']['field'] = 'hotel_provider';
  /* Field: MBV Support Entity: Jira Bug Id */
  $handler->display->display_options['fields']['hotel_jira_bug_id']['id'] = 'hotel_jira_bug_id';
  $handler->display->display_options['fields']['hotel_jira_bug_id']['table'] = 'field_data_hotel_jira_bug_id';
  $handler->display->display_options['fields']['hotel_jira_bug_id']['field'] = 'hotel_jira_bug_id';
  /* Field: MBV Support Entity: Upload file */
  $handler->display->display_options['fields']['hotel_upload_file']['id'] = 'hotel_upload_file';
  $handler->display->display_options['fields']['hotel_upload_file']['table'] = 'field_data_hotel_upload_file';
  $handler->display->display_options['fields']['hotel_upload_file']['field'] = 'hotel_upload_file';
  $handler->display->display_options['fields']['hotel_upload_file']['click_sort_column'] = 'fid';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: MBV Support: System name */
  $handler->display->display_options['filters']['filter_system_name']['id'] = 'filter_system_name';
  $handler->display->display_options['filters']['filter_system_name']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_system_name']['field'] = 'filter_system_name';
  $handler->display->display_options['filters']['filter_system_name']['value'] = array(
   'mbv_issue_hotel' => 'mbv_issue_hotel'
  );
  $handler->display->display_options['filters']['filter_system_name']['group'] = 1;
  /* Filter criterion: MBV Support: From */
  $handler->display->display_options['filters']['filter_created_from']['id'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_created_from']['field'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['group'] = 1;
  $handler->display->display_options['filters']['filter_created_from']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_created_from']['expose']['operator_id'] = 'filter_created_from_op';
  $handler->display->display_options['filters']['filter_created_from']['expose']['label'] = 'From';
  $handler->display->display_options['filters']['filter_created_from']['expose']['operator'] = 'filter_created_from_op';
  $handler->display->display_options['filters']['filter_created_from']['expose']['identifier'] = 'filter_created_from';
  $handler->display->display_options['filters']['filter_created_from']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_created_from']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Memo */
  $handler->display->display_options['filters']['filter_memo']['id'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_memo']['field'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['operator'] = 'contains';
  $handler->display->display_options['filters']['filter_memo']['group'] = 1;
  $handler->display->display_options['filters']['filter_memo']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_memo']['expose']['operator_id'] = 'filter_memo_op';
  $handler->display->display_options['filters']['filter_memo']['expose']['label'] = 'Memo';
  $handler->display->display_options['filters']['filter_memo']['expose']['operator'] = 'filter_memo_op';
  $handler->display->display_options['filters']['filter_memo']['expose']['identifier'] = 'filter_memo';
  $handler->display->display_options['filters']['filter_memo']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_memo']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Ref id */
  $handler->display->display_options['filters']['filter_ref_id']['id'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_ref_id']['field'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['group'] = 1;
  $handler->display->display_options['filters']['filter_ref_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_ref_id']['expose']['operator_id'] = 'filter_ref_id_op';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['label'] = 'Ref id';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['operator'] = 'filter_ref_id_op';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['identifier'] = 'filter_ref_id';
  $handler->display->display_options['filters']['filter_ref_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_ref_id']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Status */
  $handler->display->display_options['filters']['filter_issue_statues']['id'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_issue_statues']['field'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['group'] = 1;
  $handler->display->display_options['filters']['filter_issue_statues']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['operator_id'] = 'filter_issue_statues_op';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['operator'] = 'filter_issue_statues_op';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['identifier'] = 'filter_issue_statues';
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_statues']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: To */
  $handler->display->display_options['filters']['filter_created_to']['id'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_created_to']['field'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['group'] = 1;
  $handler->display->display_options['filters']['filter_created_to']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_created_to']['expose']['operator_id'] = 'filter_created_to_op';
  $handler->display->display_options['filters']['filter_created_to']['expose']['label'] = 'To';
  $handler->display->display_options['filters']['filter_created_to']['expose']['operator'] = 'filter_created_to_op';
  $handler->display->display_options['filters']['filter_created_to']['expose']['identifier'] = 'filter_created_to';
  $handler->display->display_options['filters']['filter_created_to']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_created_to']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support: Type */
  $handler->display->display_options['filters']['filter_issue_type']['id'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['table'] = 'mbv_support_issue';
  $handler->display->display_options['filters']['filter_issue_type']['field'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['group'] = 1;
  $handler->display->display_options['filters']['filter_issue_type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_type']['expose']['operator_id'] = 'filter_issue_type_op';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['operator'] = 'filter_issue_type_op';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['identifier'] = 'filter_issue_type';
  $handler->display->display_options['filters']['filter_issue_type']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['filter_issue_type']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support Entity: Jira Bug Id (hotel_jira_bug_id) */
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['id'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['table'] = 'field_data_hotel_jira_bug_id';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['field'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['operator_id'] = 'hotel_jira_bug_id_value_op';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['label'] = 'Jira Bug Id  ';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['operator'] = 'hotel_jira_bug_id_value_op';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['identifier'] = 'hotel_jira_bug_id_value';
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_jira_bug_id_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support Entity: Hotel Provider (hotel_provider) */
  $handler->display->display_options['filters']['hotel_provider_value']['id'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['table'] = 'field_data_hotel_provider';
  $handler->display->display_options['filters']['hotel_provider_value']['field'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_provider_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['operator_id'] = 'hotel_provider_value_op';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['label'] = 'Hotel Provider';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['operator'] = 'hotel_provider_value_op';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['identifier'] = 'hotel_provider_value';
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_provider_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  /* Filter criterion: MBV Support Entity: Hotel Failure (hotel_failure) */
  $handler->display->display_options['filters']['hotel_failure_value']['id'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['table'] = 'field_data_hotel_failure';
  $handler->display->display_options['filters']['hotel_failure_value']['field'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['group'] = 1;
  $handler->display->display_options['filters']['hotel_failure_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['operator_id'] = 'hotel_failure_value_op';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['label'] = 'Hotel Failure';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['operator'] = 'hotel_failure_value_op';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['identifier'] = 'hotel_failure_value';
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['hotel_failure_value']['expose']['remember_roles'] = array(
   2 => '2',
   1 => 0,
   3 => 0,
   4 => 0
  );
  $handler->display->display_options['path'] = 'mbv/issue/hotel/export';
  $handler->display->display_options['displays'] = array(
   'page' => 'page',
   'default' => 0
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['return_path'] = 'mbv/issue/hotel/list';
  $handler->display->display_options['segment_size'] = '20';

  return $view;
 }