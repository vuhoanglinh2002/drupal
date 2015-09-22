<?php
/**
 * @author baonguyen
 *
 */
class views_search_form_search_issue_type extends views_handler_filter_in_operator {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
  $form ['value'] ['#suffix'] = t('<style>#edit-filter-issue-type-wrapper { float: left ; clear: right; }</style>' );
 }

 function get_value_options() {
  $status_arr = array (
    'bug' => 'Bug',
    'error' => 'Error',
    'request' => 'Request',
    'unknown' => 'Unknown' 
  );
  foreach ( $status_arr as $value => $status ) {
   $this->value_options [$value] = $status;
  }
 }

 function op_simple() {
  if (empty($this->value )) {
   return;
  }
  $this->ensure_my_table();
  
  $this->real_field = 'issue_type';
  
  $this->query->add_where($this->options ['group'], "$this->table_alias.$this->real_field", array_values($this->value ), $this->operator );
 }
}