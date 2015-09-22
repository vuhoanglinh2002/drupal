<?php
/**
 * Implement hook_views_data()
 */
function entity_employees_views_data() {

    $data = array();

    $data['entity_employees']['table']['group']  = t('Entity Employees');

    $data['entity_employees']['table']['base'] = array(
        'field' => 'eid',
        'title' => t('Entity Employees'),
        'help' => t('Employees from the store.'),
        'access query tag' => 'entity_employees_access',
    );
    $data['entity_employees']['table']['entity type'] = 'entity_employees';

    // Expose the employee ID.
    $data['entity_employees']['eid'] = array(
        'title' => t('Emp (serial) ID'),
        'help' => t('The unique internal identifier of the employee.'),
        'field' => array(
            'handler' => 'entity_employees_handler_field_employee',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
        'argument' => array(
            'handler' => 'entity_employees_handler_argument_eid_id',
        ),
    );

    // Expose the employee SKU.
    $data['entity_employees']['employee_id'] = array(
        'title' => t('Employee ID'),
        'help' => t('The unique human-readable identifier of the employee.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    // Expose the employee title.
    $data['entity_employees']['full_name'] = array(
        'title' => t('Full Name'),
        'help' => t('The title of the employee used for administrative display.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );


    $data['entity_employees']['department'] = array(
        'title' => t('Department'),
        'help' => t('The title of the employee used for administrative display.'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    // Expose the employee type.
    $data['entity_employees']['bundle_type'] = array(
        'title' => t('Type'),
        'help' => t('The human-readable name of the type of the employee.'),
        'field' => array(
            'handler' => 'entity_employees_handler_field_employee_type',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_in_operator',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    $data['entity_employees']['sex'] = array(
        'title' => t('Gender'),
        'help' => t('The title of the employee used for administrative display.'),
        'field' => array(
            'handler' => 'entity_employees_handler_field_sex',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_string',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    // Expose the creator uid.
    $data['entity_employees']['uid'] = array(
        'title' => t('Account'),
        'help' => t('Relate a employee to the user who created it.'),
        'relationship' => array(
            'handler' => 'views_handler_relationship',
            'base' => 'users',
            'field' => 'name',
            'label' => t('employee creator'),
        ),
        'sort' => array(
            'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );


    // Expose the created and changed timestamps.
    $data['entity_employees']['created'] = array(
        'title' => t('Created date'),
        'help' => t('The date the employee was created.'),
        'field' => array(
            'handler' => 'views_handler_field_date',
            'click sortable' => TRUE,
        ),
        'sort' => array(
            'handler' => 'views_handler_sort_date',
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_date',
        ),
    );

    $data['entity_employees']['created_fulldate'] = array(
        'title' => t('Created date'),
        'help' => t('In the form of CCYYMMDD.'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_fulldate',
        ),
    );

    $data['entity_employees']['created_year_month'] = array(
        'title' => t('Created year + month'),
        'help' => t('In the form of YYYYMM.'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_year_month',
        ),
    );

    $data['entity_employees']['created_timestamp_year'] = array(
        'title' => t('Created year'),
        'help' => t('In the form of YYYY.'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_year',
        ),
    );

    $data['entity_employees']['created_month'] = array(
        'title' => t('Created month'),
        'help' => t('In the form of MM (01 - 12).'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_month',
        ),
    );

    $data['entity_employees']['created_day'] = array(
        'title' => t('Created day'),
        'help' => t('In the form of DD (01 - 31).'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_day',
        ),
    );

    $data['entity_employees']['created_week'] = array(
        'title' => t('Created week'),
        'help' => t('In the form of WW (01 - 53).'),
        'argument' => array(
            'field' => 'created',
            'handler' => 'views_handler_argument_node_created_week',
        ),
    );


    // Expose links to operate on the employee.
    $data['entity_employees']['view_employee'] = array(
        'field' => array(
            'title' => t('Link'),
            'help' => t('Provide a simple link to the administrator view of the employee.'),
            'handler' => 'entity_employees_handler_field_employee_link',
        ),
    );
    $data['entity_employees']['edit_employee'] = array(
        'field' => array(
            'title' => t('Edit link'),
            'help' => t('Provide a simple link to edit the employee.'),
            'handler' => 'entity_employees_handler_field_employee_link_edit',
        ),
    );
//    $data['entity_employees']['delete_employee'] = array(
//        'field' => array(
//            'title' => t('Delete link'),
//            'help' => t('Provide a simple link to delete the employee.'),
//            'handler' => 'entity_employees_handler_field_employee_link_delete',
//        ),
//    );

    $data['entity_employees']['operations'] = array(
        'field' => array(
            'title' => t('Operations links'),
            'help' => t('Display all the available operations links for the employee.'),
            'handler' => 'entity_employees_handler_field_employee_operations',
        ),
    );

//    $data['entity_employees']['empty_text'] = array(
//        'title' => t('Empty text'),
//        'help' => t('Displays an appropriate empty text message for employee lists.'),
//        'area' => array(
//            'handler' => 'entity_employees_handler_area_empty_text',
//        ),
//    );


    return $data;
}