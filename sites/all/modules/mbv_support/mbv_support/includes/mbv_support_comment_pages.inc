<?php
/**
 * @author baonguyen
 *
 */

// Comment
function mbv_support_comment($bundle, $entity) {
 $options = array (
   'entity_type' => 'mbv_support_entity',
   'entity_id' => $entity->issue_id
 );
 $renderer = array (
   simple_comment_last_comments($options ),
   drupal_get_form('simple_comment_form', $options )
 );
 return $renderer;
}