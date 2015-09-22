<?php

/**
 * @author baonguyen
 *
 */

function mbv_support_issues_pages_redirect($system_name) {
 drupal_goto('mbv/issue/' . $system_name . '/list' );
 return '';
}



// List all ssystem pages
function mbv_support_issues_pages_list() {
 $q = explode("/", $_GET ['q'] );
 if (empty($q [3] )) {
  $markup = t('The list all system types.' );
  if (count(mbv_issue_types() ) > 0) {
   foreach ( mbv_issue_types() as $type => $profile_type ) {
    $list [] = l($profile_type ['name'], 'mbv/issue/' . $profile_type ['short_name'] . '/list' );
   }
   
   $variables ['items'] = $list;
   $variables ['type'] = 'ul';
   $markup .= theme('item_list', $variables );
   return $markup;
  } else {
   return 'Not found any system';
  }
 } else if (! empty($q [3] )) {
  drupal_goto('mbv/issue/' . $q [3] . '/list', array () );
  return '';
 } else {
  return 'Not found any system';
 }
}

/**
 * Implements hook_form_alter().
 */

// Create new
function mbv_support_issues_type_pages($system_type) {
 // Create stdClass
 $entity = entity_get_controller('mbv_support_entity' )->create();
 
 // Set Bundle - system name
 $entity->system_name = 'mbv_issue_' . $system_type;
 
 // Return form
 return drupal_get_form('mbv_support_issues_type_pages_form', $system_type, $entity );
}

// View detail
function mbv_support_issues_type_pages_form($form, &$form_state, $system_type, $entity) {
 $upload_max_filesize = ini_get('upload_max_filesize' );
 
 field_attach_form('mbv_support_entity', $entity, $form, $form_state );
 
 if ($entity->issue_id != 0) {
  $user = ! empty($entity->uid ) ? user_load($entity->uid ) : '';
  
  $form ['modifier'] = array (
    '#type' => 'item',
    '#title' => 'Modifier: ',
    '#markup' => ! empty($user->name ) ? $user->name : 'sync from system',
    '#weight' => 98,
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $form ['created_at'] = array (
    '#type' => 'item',
    '#title' => 'Created at: ',
    '#markup' => date('Y-m-d H:i:s', $entity->created_at ),
    '#weight' => 99,
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div>' 
  );
  
  $form ['updated_at'] = array (
    '#type' => 'item',
    '#title' => 'Updated at: ',
    '#markup' => date('Y-m-d H:i:s', $entity->updated_at ),
    '#weight' => 100,
    '#prefix' => '<div class="container-inline">',
    '#suffix' => '</div> <br/>' 
  );
 }
 
 $form ['type'] = array (
   '#title' => 'Type',
   '#type' => 'select',
   '#options' => array (
     '' => '- Select a value -',
     'bug' => 'Bug',
     'error' => 'Error',
     'request' => 'Request',
     'unknown' => 'Unknown' 
   ),
   '#default_value' => $entity->issue_type,
   '#required' => TRUE,
   '#weight' => 5 
 );
 
 $form ['memo'] = array (
   '#type' => 'textarea',
   '#title' => 'Memo',
   '#required' => TRUE,
   '#default_value' => $entity->memo,
   '#weight' => 10 
 );
 
 $form ['status'] = array (
   '#title' => 'Status',
   '#type' => 'select',
   '#options' => mbv_issue_statuses(),
   '#default_value' => $entity->status,
   '#required' => TRUE,
   '#weight' => 13 
 );
 
 if (count(unserialize($entity->meta_data ) ) > 0 && is_array(unserialize($entity->meta_data ) )) {
  $form ['meta_data'] = array (
    '#type' => 'fieldset',
    '#title' => 'Meta data',
    '#rows' => 12,
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#suffix' => '<style>#edit-meta-data{color:black;width: 690px;}   #edit-meta-data .fieldset-wrapper {width: 635px;} </style>',
    '#weight' => 25 
  );
  
  $prop_f = &$form ['meta_data'];
  $prop_f ['props'] = array (
    '#markup' => theme('mbv_support_meta_data_theme', array (
      'meta' => unserialize($entity->meta_data ) ? unserialize($entity->meta_data ) : array () 
    ) ) 
  );
 }
 
 $form ['basic_entity'] = array (
   '#type' => 'value',
   '#value' => $entity 
 );
 if (user_access('edit ' . $entity->system_name . ' entities' )) {
  $form ['submit'] = array (
    '#type' => 'submit',
    '#value' => t('Save' ),
    '#weight' => 100,
    '#submit' => array (
      'mbv_support_issues_type_pages_submit' 
    ),
    '#validate' => array (
      'mbv_support_issues_type_pages_validate' 
    ) 
  );
 }
 
 global $base_url;
 $system_name = explode("_", $entity->system_name );
 $full_url = $base_url . '?q=mbv/issue/' . $system_name [2] . '/list';
 $form ['back-button'] = array (
   '#type' => 'button',
   '#value' => 'Back',
   '#suffix' => ('
			<script type="text/javascript">
				jQuery(document).ready(function() {
					jQuery("#edit-back-button").click(function() {
						 window.location.replace("' . $full_url . '");
						return false;
					});
				});
			</script>
		'),
   '#weight' => 101 
 );
 
 return $form;
}

// Validate create or update issue
function mbv_support_issues_type_pages_validate($form, &$form_state) {
 // $entity = $form_state ['values'] ['basic_entity'];
 // $system = explode('_', $entity->system_name );
 // $field_failure = $system [2] . '_failure';
 // $field_value = $form_state['values'][$field_failure]['und'][0]['value'];
}

// Submit
function mbv_support_issues_type_pages_submit($form, &$form_state) {
 global $user;
 
 $entity = $form_state ['values'] ['basic_entity'];
 
 // Set data to entity
 $entity->memo = $form_state ['values'] ['memo'];
 $entity->status = $form_state ['values'] ['status'];
 $entity->issue_type = $form_state ['values'] ['type'];
 $entity->meta_data = (is_array(unserialize($entity->meta_data ) )) ? unserialize($entity->meta_data ) : array ();
 $entity->updated_at = time();
 // $entity->meta_data =
 
 // Get user id
 $entity->uid = $user->uid;
 
 // Attach field to submit
 field_attach_submit('mbv_support_entity', $entity, $form, $form_state );
 
 // Show message by new or update
 if ($entity->issue_id != 0) {
  drupal_set_message("Update success !!!" );
 } else {
  drupal_set_message("Add new success !!!" );
 }
 
 // Save entity with fields
 $entity = mbv_support_issues_type_save($entity );
 $system_name = explode('_', $entity->system_name );
 // Redirect after insert success
 $form_state ['redirect'] = 'mbv/issue/' . $system_name [2] . '/' . $entity->issue_id;
}

function mbv_support_issues_type_save(&$entity) {
 return entity_get_controller('mbv_support_entity' )->save($entity );
}




