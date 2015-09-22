<?php
/**
 * @author baonguyen
 *
 */
class views_search_form_issue_memo extends views_handler_filter_string {

 function value_form(&$form, &$form_state) {
  parent::value_form($form, $form_state );
  // $form ['value'] ['#suffix'] = t('<style>#edit-search-memo-wrapper { margin-left: 10px; }</style>' );
 }

 function op_contains($field) {
  $field = 'mbv_support_issue.memo';
  $this->query->add_where($this->options ['group'], $field, '%' . db_like($this->value ) . '%', 'LIKE' );
 }
}