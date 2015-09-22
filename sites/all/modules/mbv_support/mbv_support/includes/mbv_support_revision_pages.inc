<?php

/**
 * @author baonguyen
 *
 */

// Revision
function mbv_support_revision($system_name, $entity) {
 $query = db_select('mbv_support_issue_revision', 'm' );
 $query->innerjoin('users', 'u', 'u.uid = m.uid' );
 $query->fields('m' )->fields('u', array (
   'name' 
 ) )->condition('m.issue_id', array (
   $entity->revision_id 
 ), '=' )->orderBy('m.revision_timestamp', 'desc' );
 
 $entities = $query->execute()->fetchAll();
 
 if (! empty($entities )) {
  foreach ( $entities as $entity ) {
   
   // Create table rows for entities.
   $rows [] = array (
     'data' => array (
       'id' => $entity->revision_id,
       'issue_type' => $entity->issue_type,
       'status' => $entity->status,
       'uid' => $entity->name,
       'memo' => $entity->memo,
       'revision_timestamp' => date('Y-m-d H:i:s', $entity->revision_timestamp ),
       'view' => l('View', 'mbv/issue/' . $system_name . '/revision/' . $entity->issue_id . '/' . $entity->revision_id . '/view' ) 
     ) 
   );
  }
  
  $header = array (
    t('Revision Id' ),
    t('Issue Type' ),
    t('Status' ),
    t('Modifier' ),
    t('Memo' ),
    t('Created' ),
    t('' ) 
  );
  // Put our entities into a themed table. See theme_table() for details.
  $content ['entity_table'] = array (
    '#theme' => 'table',
    '#rows' => $rows,
    '#header' => $header 
  );
 }
 
 return $content;
}

function mbv_support_revision_detail_page($system_name, $entity, $revision) {
 global $base_url;
 
 $list_field_instance = field_info_instances('mbv_support_entity', 'mbv_issue_' . $system_name );
 
 $full_data = '';
 foreach ( $list_field_instance as $key => $value ) {
  
  $field_revision_table = 'field_revision_' . $key;
  
  $data = (field_get_items('mbv_support_entity', $entity, $key ));
  if (! empty($data )) {
   $data = reset($data );
   if (! empty($data ['value'] )) {
    
    $row = $key . '_value';
    
    $query = db_select($field_revision_table, 'r' );
    $query->fields('r', array (
      $row 
    ) )->condition('r.revision_id', array (
      $revision->revision_id 
    ), '=' );
    
    $results = $query->execute()->fetchAll();
    if (count($results ) > 0) {
     foreach ( $results as $issue ) {
      $full_data .= '<b>' . $key . '</b>: ' . $issue->{$key . '_value'} . '<br/>';
     }
    }
   } else if (! empty($data ['filename'] )) {
    
    $query = db_select($field_revision_table, 'r' );
    $query->innerjoin('file_managed', 'm', 'm.fid = r.' . $key . '_fid' );
    $query->fields('r' )->condition('r.revision_id', array (
      $revision->revision_id 
    ), '=' );
    
    $results = $query->execute()->fetchAll();
    if (count($results ) > 0) {
     
     $full_data .= '<b>' . $key . '</b>: ' . '<a href="' . $base_url . '/sites/default/files/' . $data ['filename'] . '"target="_blank">' . $data ['filename'] . '</a><br/>';
    }
   }
  }
 }
 
 foreach ( $revision as $key1 => $value1 ) {
  if (! is_array($value1 )) {
   if ($key1 == 'revision_timestamp') {
    $full_data .= '<b>' . $key1 . '</b>: ' . date('Y-d-m H:i:s', $value1 ) . '<br/>';
   } else if ($key1 == 'meta_data') {
    $full_data .= '<b>' . $key1 . '</b>: <pre>' . theme('mbv_support_meta_data_theme', array (
      'meta' => unserialize($entity->meta_data ) ? unserialize($entity->meta_data ) : array () 
    ) ) . '</pre><br/>';
   } else if ($key1 == 'uid') {
    $user = user_load($value1 );
    $full_data .= '<b>' . $key1 . '</b>: ' . $user->name . '<br/>';
   } else {
    $full_data .= '<b>' . $key1 . '</b>: ' . $value1 . '<br/>';
   }
  }
 }
 
 return $full_data;
}