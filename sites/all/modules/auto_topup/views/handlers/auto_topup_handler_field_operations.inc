<?php

/**
 * Field handler to present a employee's operations links.
 */
class auto_topup_handler_field_operations extends views_handler_field {
    function construct() {
        parent::construct();

        $this->additional_fields['code'] = 'code';
    }

    function render($values){
        $code = $this->get_value($values, 'code');
        return l('Edit', 'admin/auto_topup_package/' . $code . '/edit') . '&nbsp&nbsp' . l('View', 'admin/auto_topup_package/' . $code . '/view');
    }

}
