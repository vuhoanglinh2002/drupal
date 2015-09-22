<?php
/**
 * Implement hook_menu()
 */
function entity_employees_menu() {
    $items = array();

    $items['entity_employees'] = array(
        'title' => 'Entity Employees',
        'page callback' => 'entity_employees_info_page',
        'access arguments' => array('view any entity_employees'),
        'file' => 'includes/entity_employees.pages.inc',
        'type' =>  MENU_NORMAL_ITEM,
    );

    $items['admin/structure/entity_employees/manage'] = array(
        'title' => 'Entity Employees',
        'description' => 'Manager employees',
        'page callback' => 'entity_employees_list_entities',
        'access arguments' => array('administer entity_employees'),
    );
    $items['admin/structure/entity_employees/manage/all'] = array(
        'title' => 'All employees',
        'page callback' => 'entity_employees_list_entities',
        'access arguments' => array('administer entity_employees'),
        'type' => MENU_LOCAL_TASK,
        'weight' => -10
    );


    foreach (entity_employees_bundle_types() as $bundle_type => $values) {
        $items['admin/structure/entity_employees/manage/' . $bundle_type] = array(
            'title' => t($values),
            'page callback' => 'entity_employees_list_entities',
            'access arguments' => array('create entity_employees'),
            'page arguments' => array(4),
            'type' => MENU_LOCAL_TASK,
        );

        $items['admin/structure/entity_employees/manage/' . $bundle_type .'/add'] = array(
            'title' => 'Add employee',
            'page callback' => 'entity_employees_add',
            'access arguments' => array('create entity_employees'),
            'page arguments' => array(4),
            'file' => 'includes/entity_employees.pages.inc',
        );

        $items['admin/structure/entity_employees/manage/all/' . $bundle_type .'/add'] = array(
            'title' => 'Add employee of ' . $values,
            'page callback' => 'entity_employees_add',
            'access arguments' => array('create entity_employees'),
            'page arguments' => array(4),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_ACTION,
        );

        // List of all entity_example_basic entities.
        $items['admin/structure/entity_employees/manage/' . $bundle_type . '/list'] = array(
            'title' => 'List',
            'type' => MENU_DEFAULT_LOCAL_TASK,
        );

        $items['admin/structure/entity_employees/manage/' . $bundle_type .'/add'] = array(
            'title' => 'Add employee',
            'page callback' => 'entity_employees_add',
            'access arguments' => array('create entity_employees'),
            'page arguments' => array(4),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_ACTION,
        );

        $items['admin/structure/entity_employees/manage/%entity_employees'] = array(
            'title' => 'View',
            'page callback' => 'entity_employees_view_',
            'page arguments' => array(4),
            'access arguments' => array('entity_employees_access'),
            'file' => 'includes/entity_employees.pages.inc',
        );
        $items['admin/structure/entity_employees/manage/%entity_employees/view'] = array(
            'title' => 'View',
            'page callback' => 'entity_employees_view_',
            'page arguments' => array(4),
            'access arguments' => array('entity_employees_access'),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_TASK,
            'weight' => -10,
        );

        $items['admin/structure/entity_employees/manage/%entity_employees/edit'] = array(
            'title' => 'Edit',
            'page callback' => 'drupal_get_form',
            'page arguments' => array('entity_employees_form', 4),
            'access arguments' => array('edit any entity_example_basic entity'),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_TASK,
        );

//        $items['entity_employees/' . $bundle_type .'/add'] = array(
//            'title' => 'Add employee',
//            'page callback' => 'entity_employees_add',
//            'access arguments' => array('entity_employees_access'),
//            'page arguments' => array(2),
//            'file' => 'includes/entity_employees.pages.inc',
//        );
        // 'View' tab for an individual entity page.
        $items['entity_employees/%entity_employees/view'] = array(
            'title' => 'View',
            'page callback' => 'entity_employees_view_',
            'page arguments' => array(1),
            'access arguments' => array('entity_employees_access'),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_TASK,
            'weight' => -10,
        );

        // 'Edit' tab for an individual entity page.
        $items['entity_employees/%entity_employees/edit'] = array(
            'title' => 'Edit',
            'page callback' => 'drupal_get_form',
            'page arguments' => array('entity_employees_form', 1),
            'access arguments' => array('entity_employees_access'),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_LOCAL_TASK,
        );

        $items['entity_employees/%entity_employees'] = array(
            'title' => 'View',
            'page callback' => 'entity_employees_view_',
            'page arguments' => array(1),
            'access arguments' => array('entity_employees_access'),
            'file' => 'includes/entity_employees.pages.inc',
            'type' => MENU_DEFAULT_LOCAL_TASK,
        );

//        // Add example entities.
//        $items['entity_employees/' . $bundle_type . '/add'] = array(
//            'title' => 'Add An Employee of '. $values,
//            'page callback' => 'entity_employees_add',
//            'access arguments' => array('entity_employees_access'),
//            'page arguments' => array(2),
//            'file' => 'includes/entity_employees.pages.inc',
//            'type' => MENU_LOCAL_ACTION,
//        );

    }

    // Use Batch API
    $items['entity_employees/batch_employee'] = array(
        'title' => 'Batch Employee',
        'description' => 'Example of Drupal batch processing',
        'page callback' => 'drupal_get_form',
        'page arguments' => array('entity_employees_batch_form'),
        'file' => 'includes/entity_employees.batch.inc',
        'access callback' => TRUE,
    );

    return $items;
}

/**
 *
 * @see entity_employees_load_multiple()
 * @see eentity_employees_menu()
 */
function entity_employees_load($eid = NULL, $reset = FALSE) {
    $eids = (isset($eid) ? array($eid) : array());
    $basic = entity_employees_load_multiple($eids, array(), $reset);
    return $basic ? reset($basic) : FALSE;
}

/**
 * Implement the uri callback
 */
function entity_employees_uri($emp) {
    return array(
        'path' => 'entity_employees/' . $emp->eid,
    );
}

/**
 * Callback for a page title when this entity is displayed.
 */
function entity_employees_title($entity) {
    return t('Add an entity_employees (bundle_type=@bundle_type)', array('@bundle_type' => $entity->bundle_type));
}