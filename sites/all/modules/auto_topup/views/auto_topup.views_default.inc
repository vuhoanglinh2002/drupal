<?php
/**
 * Implement hook_views_default_views()
 */
function auto_topup_views_default_views(){
    $views = array();
    $list  = auto_topup_views_topup_default();
    $views[$list->name] = $list;

    return $views;
}

function auto_topup_views_topup_default(){

    $view = new view();
    $view->name = 'auto_topup_package';
    $view->description = '';
    $view->tag = 'default';
    $view->base_table = 'auto_topup_package';
    $view->human_name = 'List Auto Topup Package';
    $view->core = 0;
    $view->api_version = '3.0';
    $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

    /* Display: Defaults */
    $handler = $view->new_display('default', 'Master', 'default');
    $handler->display->display_options['title'] = 'Auto Topup Package';
    $handler->display->display_options['use_more_always'] = FALSE;
    $handler->display->display_options['cache']['type'] = 'none';
    $handler->display->display_options['query']['type'] = 'views_query';
    $handler->display->display_options['query']['options']['query_comment'] = FALSE;
    $handler->display->display_options['exposed_form']['type'] = 'basic';
    $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
    $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
    $handler->display->display_options['pager']['type'] = 'full';
    $handler->display->display_options['pager']['options']['items_per_page'] = 10;
    $handler->display->display_options['style_plugin'] = 'table';
    $handler->display->display_options['style_options']['columns'] = array(
        'code' => 'code',
        'name' => 'name',
        'amount' => 'amount',
        'month' => 'month',
        'telco' => 'telco',
        'status' => 'status',
        'sms_code' => 'sms_code',
        'operations' => 'operations',
    );
    $handler->display->display_options['style_options']['default'] = 'code';
    $handler->display->display_options['style_options']['info'] = array(
        'code' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'name' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'amount' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'month' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'telco' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'status' => array(
            'sortable' => 1,
            'default_sort_order' => 'asc',
            'align' => '',
            'separator' => '',
            'empty_column' => 0,
        ),
        'sms_code' => array(
            'sortable' => 0,
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
//    /* No results behavior: Auto Topup Package: Empty text */
//    $handler->display->display_options['empty']['empty_text']['id'] = 'empty_text';
//    $handler->display->display_options['empty']['empty_text']['table'] = 'auto_topup_package';
//    $handler->display->display_options['empty']['empty_text']['field'] = 'empty_text';
//    $handler->display->display_options['empty']['empty_text']['add_path'] = 'admin/auto_topup_package/add';
    /* Field: Auto Topup Package:  */
    $handler->display->display_options['fields']['code']['id'] = 'code';
    $handler->display->display_options['fields']['code']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['code']['field'] = 'code';
    /* Field: Auto Topup Package:  */
    $handler->display->display_options['fields']['name']['id'] = 'name';
    $handler->display->display_options['fields']['name']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['name']['field'] = 'name';
    /* Field: Auto Topup Package: Amount */
    $handler->display->display_options['fields']['amount']['id'] = 'amount';
    $handler->display->display_options['fields']['amount']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['amount']['field'] = 'amount';
    /* Field: Auto Topup Package: Month */
    $handler->display->display_options['fields']['month']['id'] = 'month';
    $handler->display->display_options['fields']['month']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['month']['field'] = 'month';
    /* Field: Auto Topup Package: Telco */
    $handler->display->display_options['fields']['telco']['id'] = 'telco';
    $handler->display->display_options['fields']['telco']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['telco']['field'] = 'telco';
    /* Field: Auto Topup Package: Status */
    $handler->display->display_options['fields']['status']['id'] = 'status';
    $handler->display->display_options['fields']['status']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['status']['field'] = 'status';
    /* Field: Auto Topup Package: SMS Code */
    $handler->display->display_options['fields']['sms_code']['id'] = 'sms_code';
    $handler->display->display_options['fields']['sms_code']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['sms_code']['field'] = 'sms_code';
    /* Field: Auto Topup Package: Operations links */
    $handler->display->display_options['fields']['operations']['id'] = 'operations';
    $handler->display->display_options['fields']['operations']['table'] = 'auto_topup_package';
    $handler->display->display_options['fields']['operations']['field'] = 'operations';
    $handler->display->display_options['fields']['operations']['label'] = 'Operations';
    /* Sort criterion: Auto Topup Package: Code */
    $handler->display->display_options['sorts']['code']['id'] = 'code';
    $handler->display->display_options['sorts']['code']['table'] = 'auto_topup_package';
    $handler->display->display_options['sorts']['code']['field'] = 'code';
    /* Filter criterion: Auto Topup Package: Code */
    $handler->display->display_options['filters']['code']['id'] = 'code';
    $handler->display->display_options['filters']['code']['table'] = 'auto_topup_package';
    $handler->display->display_options['filters']['code']['field'] = 'code';
    $handler->display->display_options['filters']['code']['exposed'] = TRUE;
    $handler->display->display_options['filters']['code']['expose']['operator_id'] = 'code_op';
    $handler->display->display_options['filters']['code']['expose']['label'] = 'Filter by Codes containing';
    $handler->display->display_options['filters']['code']['expose']['operator'] = 'code_op';
    $handler->display->display_options['filters']['code']['expose']['identifier'] = 'code';

    /* Display: Admin page */
    $handler = $view->new_display('page', 'Auto Topup Package', 'auto_topup_package');
    $handler->display->display_options['path'] = 'admin/auto_topup_package/list';
    $handler->display->display_options['menu']['type'] = 'default tab';
    $handler->display->display_options['menu']['title'] = 'List';
    $handler->display->display_options['menu']['weight'] = '-10';
    $handler->display->display_options['tab_options']['type'] = 'normal';
    $handler->display->display_options['tab_options']['title'] = 'Auto Topup Package';
    $handler->display->display_options['tab_options']['description'] = 'Manage Auto Topup Package';
    $handler->display->display_options['tab_options']['weight'] = '';
    $handler->display->display_options['tab_options']['name'] = 'management';

    return $view;
}