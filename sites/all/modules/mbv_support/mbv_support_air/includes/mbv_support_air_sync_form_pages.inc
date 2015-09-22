<?php

/**
 * @author baonguyen
 *
 */

/**
 * Sync form
 */
function mbv_support_air_sync_data_form($form, &$form_state, $system_name) {
 $url_config = $system_name . '_sync_url';
 $time_config = $system_name . '_sync_time';
 $time_remind = $system_name . '_remind_time';
 $time_remind_flag = $system_name . '_remind_time_flag';
 
 if (! empty(variable_get($url_config ) ) && ! empty(variable_get($time_config ) )) {
  // Load data by system_name
  $entity = mbv_support_check_exist_system_air($system_name );
  
  $form ['system_entity'] = array (
    '#type' => 'value',
    '#value' => $entity 
  );
  
  $form [$url_config] = array (
    '#type' => 'item',
    '#title' => 'Sync url: ',
    '#markup' => '<a href="' . variable_get($url_config ) . '" target="_blank">' . variable_get($url_config ) . '</a>',
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $form [$time_config] = array (
    '#type' => 'item',
    '#title' => 'Time sync: ',
    '#markup' => variable_get($time_config ) . ' minutes',
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  if (! empty(variable_get($time_remind ) ) && variable_get($time_remind ) > 0) {
   $form [$time_remind] = array (
     '#type' => 'item',
     '#title' => 'Time remind: ',
     '#markup' => variable_get($time_remind ) . ' minute',
     '#prefix' => '<div class="container-inline">',
     '#suffix' => '</div>' 
   );
  }
  
  $form ['sync_last_sync_time'] = array (
    '#type' => 'item',
    '#title' => 'Last sync time: ',
    '#markup' => date('Y-m-d H:i:s', $entity->last_sync_time ),
    '#prefix' => '<br/><div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $form ['sync_next_sync_time'] = array (
    '#type' => 'item',
    '#title' => 'Next sync time: ',
    '#markup' => date('Y-m-d H:i:s', $entity->next_sync_time ),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $form ['sync_status'] = array (
    '#type' => 'item',
    '#title' => 'Status',
    '#markup' => $entity->sync_status 
  );
  
  $form ['sync_start'] = array (
    '#type' => 'submit',
    '#value' => 'Start sync',
    '#submit' => array (
      'mbv_support_air_start_sync_submit' 
    ),
    '#validate' => array (
      'mbv_support_air_start_sync_validate' 
    ),
    '#weight' => 90 
  );
 } else {
  drupal_set_message("'Sync system URL' and 'Time for automatic sync' is empty, please check again.", "warning" );
 }
 return $form;
}

/**
 * Validate sync form
 * Check make sure url can fetch data and status is not syncing
 */
function mbv_support_air_start_sync_validate($form, &$form_state) {
 $entity = ($form_state ['values'] ['system_entity']);
 $url = variable_get('mbv_issue_air' . '_sync_url' );
 
 $res = drupal_http_request($url, array (
   "method" => "GET",
   "timeout" => 120 
 ) );
 
 if (! isset($res->data )) {
  $full_error = '';
  foreach ( $res as $key => $value ) {
   if (! is_array($value )) {
    $full_error .= $key . ": " . strip_tags($value ) . "<br/>";
   }
  }
  form_set_error('', 'URL: ' . $url . '<br/>' . ($full_error) );

 }
 if (! is_object(json_decode(substr($res->data, 3, strlen($res->data ) ) ) )) {
  $full_error = '';
  foreach ( $res as $key => $value ) {
   if (! is_array($value )) {
    $full_error .= $key . ": " . strip_tags($value ) . "<br/>";
   }
  }
  form_set_error('', 'URL: ' . $url . '<br/>' . ($full_error) );
 }
}

/**
 * Submit sync form
 */
function mbv_support_air_start_sync_submit($form, &$form_state) {
 $entity = ($form_state ['values'] ['system_entity']);
 
 $data_config = array (
   'url_config' => variable_get('mbv_issue_air' . '_sync_url' ),
   'time_config' => variable_get('mbv_issue_air' . '_sync_time' ) 
 );
 
 mbv_support_air_load_system_air($entity, $data_config );
}