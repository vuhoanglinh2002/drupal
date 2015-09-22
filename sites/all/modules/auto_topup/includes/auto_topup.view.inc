<?php
/**
 * Implement hook_views_api()
 * @return array
 */
function auto_topup_views_api() {

    return array (
        'api' => 3,
        'path' => drupal_get_path('module', 'auto_topup' ) . '/views',
    );
}