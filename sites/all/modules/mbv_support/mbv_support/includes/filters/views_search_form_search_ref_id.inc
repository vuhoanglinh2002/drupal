<?php
/**
 * @author baonguyen
 *
 */
class views_search_form_search_ref_id extends views_handler_filter_string {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
 }

 function op_equal($field) {
  $field = 'mbv_support_issue.ref_id';
  $this->query->add_where($this->options ['group'], $field, $this->value, $this->operator() );
 }
}