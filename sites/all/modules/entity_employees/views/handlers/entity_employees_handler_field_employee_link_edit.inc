<?php

/**
 * Field handler to present a employee edit link.
 */
class entity_employees_handler_field_employee_link_edit extends entity_employees_handler_field_employee_link {
    function construct() {
        parent::construct();

        $this->additional_fields['type'] = 'type';
        $this->additional_fields['uid'] = 'uid';
    }

    function render($values) {
        // Ensure the user has access to edit this employee.
        $employee = entity_employees_new();
        $employee->eid = $this->get_value($values, 'eid');
        $employee->type = $this->get_value($values, 'type');
        $employee->uid = $this->get_value($values, 'uid');

        $text = !empty($this->options['text']) ? $this->options['text'] : t('edit');

        return l($text, 'admin/structure/entity_employees/manage/' . $employee->eid . '/edit', array('query' => drupal_get_destination()));
    }
}