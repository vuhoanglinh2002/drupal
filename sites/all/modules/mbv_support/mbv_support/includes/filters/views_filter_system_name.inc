<?php
/**
 * @author baonguyen
 *
 */
class views_filter_system_name extends views_handler_filter_in_operator {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
 }

 function get_value_options() {
  foreach ( mbv_issue_types() as $type => $info ) {
   $this->value_options [$type] = $type;
  }
 }

 function op_simple() {
  $this->ensure_my_table();
  
  $this->real_field = 'system_name';
  
  $this->query->add_where($this->options ['group'], "$this->table_alias.$this->real_field", array_values($this->value ), $this->operator );
 }
}