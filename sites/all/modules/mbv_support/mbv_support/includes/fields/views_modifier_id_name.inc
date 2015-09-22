<?php
/**
 * @author baonguyen
 *
 */
class views_modifier_id_name extends views_handler_field {

 function construct() {
  parent::construct();
  $this->additional_fields ['uid'] = 'uid';
 }

 function query() {
  $this->ensure_my_table();
  $this->add_additional_fields();
 }

 function render($values) {
  global $user;
  $user_fields = user_load($this->get_value($values, 'uid' ) );
  
  return $user_fields->name;
 }
}