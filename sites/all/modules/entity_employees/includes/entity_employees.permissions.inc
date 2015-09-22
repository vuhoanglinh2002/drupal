<?php
/**
 * Implement hook_permission()
 */
function entity_employees_permission() {
    $permissions = array(
        'administer entity_employees' => array(
            'title' => t('Administer entity_employees'),
        ),
        'view any entity_employees' => array(
            'title' => t('View any entity_employees'),
        ),
        'edit any entity_employees' => array(
            'title' => t('Edit any entity_employees'),
        ),
        'create entity_employees' => array(
            'title' => t('Create any entity_employees'),
        ),
        'delete entity_employees' => array(
            'title' => t('Delete any entity_employees'),
        ),
    );
    return $permissions;
}

/**
 * Implement access permissions for employee entities
 */
function entity_employees_access($op, $employee = NULL, $account = NULL, $entity_type = NULL) {
    switch($op){
        case 'create':
            return user_access('administer entity_employees', $account) || user_access('create entity_employees', $account);
        case 'view':
            return user_access('administer entity_employees', $account) || user_access('view any entity_employees', $account);
        case 'edit':
            return user_access('administer entity_employees', $account) || user_access('edit any entity_employees', $account);
        case 'delete':
            return user_access('administer entity_employees', $account) || user_access('delete entity_employees', $account);
    }
}