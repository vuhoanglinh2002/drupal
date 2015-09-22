<?php
/**
 * Implement hook_views_api()
 * @return array
 */
function entity_employees_views_api() {

    return array (
        'api' => 3,
        'path' => drupal_get_path('module', 'entity_employees' ) . '/views',
    );
}

