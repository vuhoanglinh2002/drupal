<?php
/**
 * @author baonguyen
 *
 */

/**
 * ======
 * SYNC CONFIG - EMAIL
 * ======
 */
/**
 * Email form
 * Send email of sync with issue, run with CRON only
 */
function mbv_support_email_config_form($form, &$form_state) {
 $form ['sync_email_config'] = array (
   '#type' => 'textarea',
   '#title' => 'SYNC SYSTEM EMAIL',
   '#required' => TRUE,
   '#description' => 'Enter list email here, sperate by <strong>";" (semicolon)</strong><br/>
     Ex: <i>abc@mobivi.vn</i><br/>
     or <i>bce@mobivi.vn;mr.a@mobivi.com</i><br/>',
   '#default_value' => variable_get('sync_email_config' )
 );

 $form ['test_email'] = array (
   '#type' => 'textfield',
   '#title' => 'SYNC SYSTEM EMAIL TEST',
   '#description' => 'Type in an address to have a test e-mail sent there.<br/>
     Ex: <i>abc@mobivi.vn</i><br/>'
 );

 $form ['actions'] ['submit'] = array (
   '#type' => 'submit',
   '#value' => t('Save configuration' ),
   '#submit' => array (
     'system_settings_form_submit'
   ),
   '#validate' => array (
     'mbv_support_validate_email_config'
   )
 );

 $form ['submit'] = array (
   '#type' => 'submit',
   '#value' => t('Send Test Email' ),
   '#submit' => array (
     'mbv_support_send_test_email'
   )
 );
 return $form;
}

/**
 * Validate email form
 * Check corrent format email
 */
function mbv_support_validate_email_config($form, &$form_state) {
 $email = trim($form_state ['values'] ['sync_email_config'] );

 if (! empty($email )) {
  $email = trim($email, ";" );
  $list_email_arr = explode(";", $email );

  foreach ( $list_email_arr as $email ) {
   if (! filter_var($email, FILTER_VALIDATE_EMAIL )) {
    form_set_error("Error", "Wrong format with this email [" . $email . "]" );
   }
  }
 }
}

/**
 * Send test email
 */
function mbv_support_send_test_email($form, &$form_state) {
 global $language;

 $params ['subject'] = t('MBV Support Issue - Sync Status' );
 $params ['body'] = array (
   t('If you receive this message it means your site is capable of using SMTP to send e-mail.' )
 );

 $result = drupal_mail('mbv_support', 'system_sync', $form_state ['values'] ['test_email'], $language, $params );
 if ($result ['result']) {
  drupal_set_message("Send test email success" );
 } else {
  form_set_error("test_email", "Cannot send email, please contact to administrator." );
 }
}

