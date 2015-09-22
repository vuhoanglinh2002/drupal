<?php

/**
 * @author baonguyen
 *
 */

/**
 * @file
 * Hooks provided by the MBV Support Issue module.
 */

/**
 * implement hook_mbv_issue_status_info
 *
 * @return multitype:multitype:string number The multitype:string The
 */
function hook_mbv_issue_status_info() {
 $issue_status = array (
   'pending' => 'Pending',
   'classified' => 'Classified' 
 );
 
 return $issue_status;
}

/**
 * implement hook_mbv_issue_system_type
 */
function mbv_issue_system_type_info() {
}

/**
 * Allows modules to alter the Issue status types info array.
 *
 * Implement hook_mbv_issue_status_info_alter
 *
 * @param array $issues_status         
 */
function hook_mbv_issue_status_info_alter(&$issues_status) {
}

/**
 * implement hook_mbv_issue_type_info
 *
 * @return multitype:multitype:string The multitype:string number The
 */
function hook_mbv_issue_type_info() {
 $items = array (
   'mbv_support_air' => array (
     'description' => 'MBV Air',
     'module' => 'mbv_support_air',
     'type' => 'mbV_support_air',
     'name' => t('MBV Air' ) 
   ) 
 );
 return $items;
}

/**
 * Allows you to alter Issue type, add more or remove.
 *
 * implement hook_mbv_issue_type_info_alter
 *
 * @param unknown $issues_type         
 */
function hook_mbv_issue_type_info_alter(&$issues_type) {
}

/**
 * implement hook_mbv_sync_log_info
 *
 * @param unknown $issues_type         
 */
function hook_mbv_sync_log_info() {
 $items = array (
   'mbv_sync_vietjet' => array (
     'description' => 'Air Vietjet',
     'module' => 'mbv_air_vietjet',
     'type' => 'mbv_air_vietjet',
     'name' => t('MBV Air Vietjet' ) 
   ) 
 );
 return $items;
}

function hook_mbv_sync_log_info_alter(&$sync_log) {
}

function hook_mbv_sync_log_type(){
 $log_types = array (
   'error' => 'Error',
   'bug' => 'Bug'
 );
 
 return $log_types;
}