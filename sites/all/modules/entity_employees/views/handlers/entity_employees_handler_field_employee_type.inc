<?php

/**
 * Field handler to translate a product type into its readable form.
 */
class entity_employees_handler_field_employee_type extends entity_employees_handler_field_employee {
    function option_definition() {
        $options = parent::option_definition();

        $options['use_raw_value'] = array('default' => FALSE);

        return $options;
    }

    function render($values) {
        if ($type = $this->get_value($values)) {
            $value = isset(entity_employees_bundle_types()[$type]) ? entity_employees_bundle_types()[$type] : 'Not found';
            return $this->render_link($this->sanitize_value($value), $values);
        }

        return '';
    }
}