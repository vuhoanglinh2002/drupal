<?php
/**
 * Implement hook_views_default_views()
 */
function entity_employees_views_default_views(){
    $views = array();
    $list = entity_employees_views_employee_default();
    $views[$list->name] = $list;

    return $views;
}

function entity_employees_views_employee_default(){

    $view = new view();
    $view->name = 'employees';
    $view->description = 'Display a list of employees for store admin.';
    $view->tag = 'default';
    $view->base_table = 'entity_employees';
    $view->human_name = 'List Employees';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Employees';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['access']['type'] = 'perm';
    $handler->display->display_options['access']['perm'] = 'administer entity_employees';
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
    $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = 50;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'employee_id' => 'employee_id',
        'full_name' => 'full_name',
        'department' => 'department',
        'bundle_type' => 'bundle_type',
        'sex' => 'sex',
        'operations' => 'operations',
    );
    $handler->display->display_options['style_options']['default'] = 'employee_id';
    $handler->display->display_options['style_options']['info'] = array(
        'employee_id' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'full_name' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'department' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'bundle_type' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'sex' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'operations' => array(
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
    );
//    $handler->display->display_options['style_options']['empty_table'] = TRUE;
//    /* No results behavior: Commerce Product: Empty text */
//    $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
//    $handler->display->display_options['empty']['empty_text']['table'] = 'commerce_product';
//    $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
//    $handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/commerce/products/add';
    /* Field: Entity Employees: Employee ID */
    $handler->display->display_options['fields']['employee_id']['id'] = 'employee_id';
    $handler->display->display_options['fields']['employee_id']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['employee_id']['field'] = 'employee_id';
    /* Field: Entity Employees: Full name */
    $handler->display->display_options['fields']['full_name']['id'] = 'full_name';
    $handler->display->display_options['fields']['full_name']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['full_name']['field'] = 'full_name';
    $handler->display->display_options['fields']['full_name']['link_to_employee'] = 1;
    /* Field: Entity Employees: Department */
    $handler->display->display_options['fields']['department']['id'] = 'department';
    $handler->display->display_options['fields']['department']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['department']['field'] = 'department';
    /* Field: Entity Employees: Type */
    $handler->display->display_options['fields']['bundle_type']['id'] = 'bundle_type';
    $handler->display->display_options['fields']['bundle_type']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['bundle_type']['field'] = 'bundle_type';
    /* Field: Commerce Product: Status */
    $handler->display->display_options['fields']['sex']['id'] = 'sex';
    $handler->display->display_options['fields']['sex']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['sex']['field'] = 'sex';
    /* Field: Commerce Product: Operations links */
    $handler->display->display_options['fields']['operations']['id'] = 'operations';
    $handler->display->display_options['fields']['operations']['table'] = 'entity_employees';
    $handler->display->display_options['fields']['operations']['field'] = 'operations';
    $handler->display->display_options['fields']['operations']['label'] = 'Operations';
    $handler->display->display_options['fields']['operations']['add_destination'] = 1;
    /* Sort criterion: Commerce Product: SKU */
    $handler->display->display_options['sorts']['employee_id']['id'] = 'employee_id';
    $handler->display->display_options['sorts']['employee_id']['table'] = 'entity_employees';
    $handler->display->display_options['sorts']['employee_id']['field'] = 'employee_id';
    /* Filter criterion: Commerce Product: SKU */
    $handler->display->display_options['filters']['employee_id']['id'] = 'employee_id';
    $handler->display->display_options['filters']['employee_id']['table'] = 'entity_employees';
    $handler->display->display_options['filters']['employee_id']['field'] = 'employee_id';
    $handler->display->display_options['filters']['employee_id']['operator'] = 'contains';
    $handler->display->display_options['filters']['employee_id']['exposed'] = TRUE;
    $handler->display->display_options['filters']['employee_id']['expose']['operator_id'] = 'employee_id_op';
    $handler->display->display_options['filters']['employee_id']['expose']['label'] = 'Filter by EmployeeIDs containing';
    $handler->display->display_options['filters']['employee_id']['expose']['operator'] = 'employee_id_op';
    $handler->display->display_options['filters']['employee_id']['expose']['identifier'] = 'employee_id';

    /* Display: Admin page */
    $handler = $view->new_display('page', 'Admin page', 'admin_page');
    $handler->display->display_options['path'] = 'admin/structure/entity_employees/manage/list';
    $handler->display->display_options['menu']['type'] = 'default tab';
    $handler->display->display_options['menu']['title'] = 'List';
    $handler->display->display_options['menu']['weight'] = '-10';
    $handler->display->display_options['tab_options']['type'] = 'normal';
    $handler->display->display_options['tab_options']['title'] = 'Employees';
    $handler->display->display_options['tab_options']['description'] = 'Manage employees.';
    $handler->display->display_options['tab_options']['weight'] = '';
    $handler->display->display_options['tab_options']['name'] = 'management';
    $translatables['commerce_products'] = array(
        t('Defaults'),
        t('Employees'),
        t('more'),
        t('Search'),
        t('Reset'),
        t('Sort by'),
        t('Asc'),
        t('Desc'),
        t('Items per page'),
        t('- All -'),
        t('Offset'),
        t('« first'),
        t('‹ previous'),
        t('next ›'),
        t('last »'),
        t('Employee ID'),
        t('Name'),
        t('Department'),
        t('Type'),
        t('Gender'),
        t('Account'),
        t('Operations'),
        t('Filter by EmployeeIDs containing'),
        t('Admin page'),
    );

    return $view;
}