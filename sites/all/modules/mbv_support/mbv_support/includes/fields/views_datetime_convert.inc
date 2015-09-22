<?php
/**
 * @author baonguyen
 *
 */

class views_datetime_convert extends views_handler_field {

 function get_value($values, $field = NULL) {
  $value = parent::get_value($values, $field );
  if (! empty($value )) {
   return date("Y-m-d H:i:s", $value );
  }
 }
}