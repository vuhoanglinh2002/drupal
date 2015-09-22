<?php
/**
 * @author baonguyen
 *
 */
class views_filter_issue_statues extends views_handler_filter_in_operator {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
  $form ['value'] ['#suffix'] = t('<style>#edit-filter-issue-statues-wrapper { float: left ; clear: both; }</style>' );
 }

 function get_value_options() {
  if (count(mbv_issue_statuses() ) == 0) {
   $this->value_options ['no data'] = 'no data';
  } else {
   foreach ( mbv_issue_statuses() as $type => $info ) {
    if (! empty($type )) {
     $this->value_options [strtolower($type )] = $info;
    }
   }
  }
 }

 function op_simple() {
  if (empty($this->value )) {
   return;
  }
  $this->ensure_my_table();
  
  $this->real_field = 'status';
  
  $this->query->add_where($this->options ['group'], "$this->table_alias.$this->real_field", array_values($this->value ), $this->operator );
 }
}