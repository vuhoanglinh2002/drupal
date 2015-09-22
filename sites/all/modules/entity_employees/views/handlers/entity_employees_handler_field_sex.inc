<?php

/**
 * Field handler to translate a product type into its readable form.
 */
class entity_employees_handler_field_sex extends views_handler_field {
    function option_definition() {
        $options = parent::option_definition();

        $options['use_raw_value'] = array('default' => FALSE);

        return $options;
    }

    function render($values) {
        if ($type = $this->get_value($values)) {
            $value = ($type == 0) ? 'Male' : 'Female';
            return $value;
        }

        return 'Male';
    }
}