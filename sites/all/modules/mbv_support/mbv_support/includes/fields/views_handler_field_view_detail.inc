<?php
/**
 * @author baonguyen
 *
 */
class views_handler_field_view_detail extends views_handler_field {

 function construct() {
  parent::construct();
  $this->additional_fields ['issue_id'] = 'issue_id';
  $this->additional_fields ['system_name'] = 'system_name';
 }

 function query() {
  $this->ensure_my_table();
  $this->add_additional_fields();
 }
 
 // mbv/issue/view/mbv_issue_air/46
 function render($values) {
  $issue_id = $this->get_value($values, 'issue_id' );
  $system_name = $this->get_value($values, 'system_name' );
  $system_name = explode('_', $system_name);
  return l('Edit', "mbv/issue/" . $system_name[2] . "/" . $issue_id .'');
 }
}