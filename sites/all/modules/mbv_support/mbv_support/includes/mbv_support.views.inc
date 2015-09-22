<?php

/**
 * @author baonguyen
 *
 */
function mbv_support_views_data() {
 $data ['mbv_support_issue'] ['table'] ['group'] = t('MBV Support' );
 
 $data ['mbv_support_issue'] ['table'] ['base'] = array (
   'field' => 'issue_id',
   'title' => t('MBV Support' ) 
 );
 
 $data ['mbv_support_issue'] ['issue_id'] = array (
   'title' => t('Issue Id' ),
   'help' => t('Issue Id.' ),
   'field' => array (
     'handler' => 'views_handler_field',
     'click sortable' => TRUE 
   ) 
 );
 
 $data ['mbv_support_issue'] ['ref_id'] = array (
   'title' => t('Ref Id' ),
   'help' => t('Ref Id' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['system_name'] = array (
   'title' => t('System Name' ),
   'help' => t('The system name.' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['issue_type'] = array (
   'title' => t('Issue Type' ),
   'help' => t('The type of Issue.' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['status'] = array (
   'title' => t('Status' ),
   'help' => t('Status' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['memo'] = array (
   'title' => t('Memo' ),
   'help' => t('Detail information of Issue.' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['uid'] = array (
   'title' => t('Modifier' ),
   'help' => t('Modifier.' ),
   'field' => array (
     'handler' => 'views_modifier_id_name' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['created_at'] = array (
   'title' => t('Created' ),
   'help' => t('Created' ),
   'field' => array (
     'handler' => 'views_datetime_convert' 
   ),
   'sort' => array (
     'handler' => 'views_handler_sort' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['updated_at'] = array (
   'title' => t('Updated' ),
   'help' => t('Updated' ),
   'field' => array (
     'handler' => 'views_datetime_convert' 
   ),
   'sort' => array (
     'handler' => 'views_handler_sort' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['revision_id'] = array (
   'title' => t('Revision Id' ),
   'help' => t('Revision Id' ),
   'field' => array (
     'handler' => 'views_handler_field' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['view_detail'] = array (
   'title' => t('View Detail' ),
   'help' => t('View Detail' ),
   'field' => array (
     'handler' => 'views_handler_field_view_detail' 
   ) 
 );
 
 $data ['mbv_support_issue'] ['check_box'] = array (
   'title' => t('Checkbox' ),
   'help' => t('Checkbox' ),
   'field' => array (
     'handler' => 'views_checkboxes_issue' 
   ) 
 );
 
 /**
  * FILTER
  */
 
 // System name
 $data ['mbv_support_issue'] ['filter_system_name'] = array (
   'title' => t('System name' ),
   'help' => t('System name' ),
   'filter' => array (
     'handler' => 'views_filter_system_name' 
   ) 
 );
 
 // Issue status
 $data ['mbv_support_issue'] ['filter_issue_statues'] = array (
   'title' => t('Status' ),
   'help' => t('Status' ),
   'filter' => array (
     'handler' => 'views_filter_issue_statues' 
   ) 
 );
 
 // Issue type
 $data ['mbv_support_issue'] ['filter_issue_type'] = array (
   'title' => t('Type' ),
   'help' => t('Type' ),
   'filter' => array (
     'handler' => 'views_search_form_search_issue_type'
   )
 );
 
 // From
 $data ['mbv_support_issue'] ['filter_created_from'] = array (
   'title' => t('From' ),
   'help' => t('From' ),
   'filter' => array (
     'handler' => 'views_search_form_issue_date_form' 
   ) 
 );
 
 // To
 $data ['mbv_support_issue'] ['filter_created_to'] = array (
   'title' => t('To' ),
   'help' => t('To' ),
   'filter' => array (
     'handler' => 'views_search_form_issue_date_to' 
   ) 
 );
 
 // Memo
 $data ['mbv_support_issue'] ['filter_memo'] = array (
   'title' => t('Memo' ),
   'help' => t('Memo' ),
   'filter' => array (
     'handler' => 'views_search_form_issue_memo' 
   ) 
 );
 
 // Ref
 $data ['mbv_support_issue'] ['filter_ref_id'] = array (
   'title' => t('Ref id' ),
   'help' => t('Ref id' ),
   'filter' => array (
     'handler' => 'views_search_form_search_ref_id' 
   ) 
 );
 
 return $data;
}