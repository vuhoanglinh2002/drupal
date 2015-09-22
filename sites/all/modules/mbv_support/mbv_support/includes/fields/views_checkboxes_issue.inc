<?php
/**
 * @author baonguyen
 *
 */
class views_checkboxes_issue extends views_handler_field {

 function construct() {
  parent::construct();
  $this->additional_fields ['issue_id'] = 'issue_id';
 }

 function query() {
  $this->ensure_my_table();
  $this->add_additional_fields();
 }

 function render($values) {
  // Set render place for form
  return '<!--form-item-' . $this->options ['id'] . '--' . $this->view->row_index . '-->';
 }

 function views_form(&$form, &$form_state) {
  $form [$this->options ['id']] = array (
    '#tree' => TRUE 
  );
  
  // Repleace render form
  foreach ( $this->view->result as $row_index => $row ) {
   $form [$this->options ['id']] [$row_index] = array (
     '#type' => 'checkbox',
     '#return_value' => $row->{$this->aliases ['issue_id']} 
   );
  }
 }
}