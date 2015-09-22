<?php

/**
 * @author baonguyen
 *
 */

/**
 * ADMIN
 * Config form
 */
function mbv_support_air_config_form($form, &$form_state, $system_name) {
 $url_config = $system_name . '_sync_url';
 $time_config = $system_name . '_sync_time';
 $time_remind = $system_name . '_remind_time';
 $time_remind_flag = $system_name . '_remind_time_flag';
 
 $form [$url_config] = array (
   '#type' => 'textfield',
   '#title' => 'Sync system URL (Require JSON output format)',
   '#description' => 'URL where REST end-point is deployed (including trailing slash)<br/>
     Ex: <i>http://104.131.44.79/~truonglt/index.php?route=report/order&status=new&type=airline</i><br/>',
   '#required' => TRUE,
   '#default_value' => variable_get($url_config ) 
 );
 
 $form [$time_config] = array (
   '#type' => 'textfield',
   '#title' => 'Time for automatic sync (Minute unit)',
   '#description' => 'Time (minute) for schedule<br/>
     Ex: <i>20</i>',
   '#required' => TRUE,
   '#default_value' => variable_get($time_config ) 
 );
 
 $form [$time_remind] = array (
   '#type' => 'textfield',
   '#title' => 'Time for remind (Minute unit)',
   '#description' => 'Time (minute) for schedule, after xxx minute, MBV Support will automatic send remind email to resolve issues<br/>
    *Note*: Leave it empty if you want to stop recieving notify email <br/>',
   '#default_value' => variable_get($time_remind ) 
 );
 
 if (! empty(variable_get($time_remind ) )) {
  if (empty(variable_get($time_remind_flag ) )) {
   variable_set($time_remind_flag, time() );
  }
  $form [$time_remind_flag] = array (
    '#type' => 'item',
    '#title' => 'Last time send remind: ',
    '#markup' => date("Y-m-d H:i:s", variable_get($time_remind_flag ) ),
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $date = date("Y-m-d H:i:s", variable_get($time_remind_flag ) ); // current date
  
  $t = ! empty(variable_get($time_remind ) ) ? variable_get($time_remind ) : "0";
  
  $date = date("Y-m-d H:i:s", strtotime(date("Y-m-d H:i:s", strtotime($date ) ) . " + " . $t . " minute" ) );
  
  $form ['next_time_remind'] = array (
    '#type' => 'item',
    '#title' => 'Next time send remind: ',
    '#markup' => $date,
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div><br/>' 
  );
 } else {
  variable_set($time_remind_flag, '' );
 }
 
 $form ['actions'] ['submit'] = array (
   '#type' => 'submit',
   '#value' => t('Save configuration' ),
   '#submit' => array (
     'system_settings_form_submit' 
   ),
   '#validate' => array (
     'mbv_support_air_test_config_connection' 
   ),
   '#weight' => 100 
 );
 
 return $form;
}

function mbv_support_air_test_config_connection($form, &$form_state) {
 $url = $form_state ['values'] ['mbv_issue_air' . '_sync_url'];
 
 $res = drupal_http_request($url, array (
   "method" => "GET",
   "timeout" => 120 
 ) );
 
 if ($res->code != 200 || $res->status_message != 'OK') {
  $full_error = '';
  foreach ( $res as $key => $value ) {
   if (! is_array($value )) {
    $full_error .= $key . ": " . strip_tags($value ) . "<br/>";
   }
  }
  form_set_error('mbv_issue_air' . '_sync_url', 'URL: ' . $url . '<br/>' . ($full_error) );
 }
 
 // Change remind time if change value
 $time_remind_val = variable_get('mbv_issue_air' . '_remind_time' );
 $time_remind_form = $form_state ['values'] ['mbv_issue_air' . '_remind_time'];
 if ($time_remind_form != $time_remind_val) {
  $time_remind_flag = 'mbv_issue_air' . '_remind_time_flag';
  variable_set($time_remind_flag, time() );
 }
}