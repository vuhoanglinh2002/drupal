<?php
/**
 * Implement hook_menu()
 * @return array
 */
function auto_topup_menu(){

    $items = array();
    $items['admin/auto_topup_package'] = array(
        'type' => MENU_DEFAULT_LOCAL_TASK,
    );
    $items['admin/auto_topup_package/add'] = array(
        'title' => t('Add Auto Topup Package'),
        'page callback' => 'auto_topup_add',
        'access callback' => TRUE,
        'file' => 'includes/auto_topup.form.inc',
        'type' => MENU_LOCAL_ACTION,
    );

    $items['admin/auto_topup_package/%auto_topup/edit'] = array(
        'title' => t('Edit'),
        'page callback' => 'drupal_get_form',
        'page arguments' => array('auto_topup_form', 2),
        'access callback' => TRUE,
        'file' => 'includes/auto_topup.form.inc',
        'type' => MENU_LOCAL_TASK,
    );

    $items['admin/auto_topup_package/%auto_topup/view'] = array(
        'title' => t('View'),
        'page callback' => 'auto_topup_view_',
        'page arguments' => array(2),
        'access callback' => TRUE,
        'file' => 'includes/auto_topup.page.inc',
        'type' => MENU_LOCAL_TASK,
    );

    return $items;
}

/**
 * Implement wildcard
 */
function auto_topup_load($code = NULL){
    return auto_topup_load_entity($code);
}