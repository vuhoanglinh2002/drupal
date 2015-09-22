<?php

/**
 * @file
 * Contains the basic product field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a employee.
 */
class entity_employees_handler_field_eid extends views_handler_field {
    function init(&$view, &$options) {
        parent::init($view, $options);

        if (!empty($this->options['link_to_employee'])) {
            $this->additional_fields['eid'] = 'eid';
        }
    }

    function option_definition() {
        $options = parent::option_definition();

        $options['link_to_employee'] = array('default' => FALSE);

        return $options;
    }

    /**
     * Provide the link to employee option.
     */
    function options_form(&$form, &$form_state) {
        parent::options_form($form, $form_state);

        $form['link_to_employee'] = array(
            '#title' => t("Link this field to the employee's administrative view page"),
            '#description' => t('This will override any other link you have set.'),
            '#type' => 'checkbox',
            '#default_value' => !empty($this->options['link_to_employee']),
        );
    }

    /**
     * Render whatever the data is as a link to the employee.
     *
     * Data should be made XSS safe prior to calling this function.
     */
    function render_link($data, $values) {
        if (!empty($this->options['link_to_employee']) && $data !== NULL && $data !== '') {
            $eid = $this->get_value($values, 'eid');
            $this->options['alter']['make_link'] = TRUE;
            $this->options['alter']['path'] = 'admin/structure/entity_employees/manage/' . $eid;
        }

        return $data;
    }

    function render($values) {
        $value = $this->get_value($values);
        return $this->render_link($this->sanitize_value($value), $values);
    }
}
