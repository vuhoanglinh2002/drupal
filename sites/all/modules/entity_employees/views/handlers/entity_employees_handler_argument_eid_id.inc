<?php

/**
 * Argument handler to display employee titles in View using employee arguments.
 */
class entity_employees_handler_argument_eid_id extends views_handler_argument_numeric {
    function title_query() {
        $titles = array();
        $result = db_select('entity_employees', 'cp')
            ->fields('cp', array('employee_id'))
            ->condition('cp.eid', $this->value)
            ->execute();
        foreach ($result as $employee) {
            $titles[] = check_plain($employee->employee_id);
        }
        return $titles;
    }
}