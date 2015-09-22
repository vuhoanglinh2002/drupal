<?php
/**
 * @author baonguyen
 *
 */
class views_search_form_issue_date_to extends views_handler_filter_string {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
  $form ['value'] ['#type'] = 'date_popup';
  $form ['value'] ['#date_label_position'] = 'within';
  $form ['value'] ['#date_format'] = 'Y-m-d H:i:s';
  $form ['value'] ['#suffix'] = '<style>#edit-filter-created-to-wrapper { float: none;clear:both } </style>';
  
  // Hack, $_SESSION convert array [date] [time] to string, so we need to reconvert to array again
  if (! is_array($form_state ['input'] ['filter_created_to'] ) && $form_state ['input'] ['filter_created_to'] != '') {
   $datatime = explode(" ", $form_state ['input'] ['filter_created_to'] );
   $form_state ['input'] ['filter_created_to'] = array (
     'date' => $datatime [0],
     'time' => $datatime [1] 
   );
  }
 }

 function op_equal($field) {
  $field = 'mbv_support_issue.created_at';
  $time = $this->value;
  
  $date = DateTime::createFromFormat('Y-m-d H:i:s', $time, new DateTimeZone('Etc/GMT-7' ) );
  if ($date) {
   $this->value = $date->getTimestamp();
   $this->query->add_where($this->options ['group'], $field, $this->value, '<=' );
  }
 }
}