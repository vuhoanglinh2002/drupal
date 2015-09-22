<?php
/**
 * Implement hook_views_plugins().
 * @return array
 */
function auto_topup_views_plugins(){
    $plugins = array();
    $plugins['query'] = array(
        'auto_topup_views_plugin_query' => array(
            'title' => t('Auto Topup Query'),
            'help' => t('Auto Topup Object'),
            'handler' => 'auto_topup_views_plugin_query',
        )
    );
    return $plugins;
}

/**
 * Implement hook_views_data().
 */
function auto_topup_views_data(){
    $data = array();

    $data['auto_topup_package']['table']['group']  = t('Auto Topup');
    $data ['auto_topup_package']['table']['entity type'] = 'auto_topup_package';
    $data['auto_topup_package']['table']['base'] = array(
        'field' => 'id',
        'title' => t('Auto Topup Package'),
        'help' => t('Auto Topup.'),
        'query class' => 'auto_topup_views_plugin_query',
    );

    $data['auto_topup_package']['id'] = array(
      'title' => t('ID'),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => TRUE,
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort',
      ),
    );

    $data['auto_topup_package']['code'] = array(
        'title' => t('Code'),
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

    $data['auto_topup_package']['name'] = array(
        'title' => t('Name'),
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

    $data['auto_topup_package']['amount'] = array(
        'title' => t('Amount'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    $data['auto_topup_package']['month'] = array(
        'title' => t('Month'),
        'field' => array(
            'handler' => 'views_handler_field',
            'click sortable' => TRUE,
        ),
        'filter' => array(
            'handler' => 'views_handler_filter_numeric',
        ),
        'sort' => array(
            'handler' => 'views_handler_sort',
        ),
    );

    $data['auto_topup_package']['telco'] = array(
        'title' => t('Telco'),
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

    $data['auto_topup_package']['status'] = array(
        'title' => t('Status'),
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

    $data['auto_topup_package']['sms_code'] = array(
        'title' => t('SMS Code'),
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

    $data['auto_topup_package']['operations'] = array(
        'field' => array(
            'title' => t('Operations links'),
            'help' => t('Display all the available operations links.'),
            'handler' => 'auto_topup_handler_field_operations',
        ),
    );

    $data['auto_topup_package']['empty_text'] = array(
        'title' => t('Empty text'),
        'help' => t(''),
        'area' => array(
            'handler' => 'auto_topup_handler_area_empty_text',
        ),
    );

    return $data;
}

function auto_topup_views_data_alter(&$data){

    if ($data['auto_topup_package']['table']['entity type'] == 'auto_topup_package') {
        $data['auto_topup_package']['views_bulk_operations'] = array(
            'title' => $data['auto_topup_package']['table']['group'],
            'group' => t('Bulk operations'),
            'help' => t('Provide a radio to checkbox the row for bulk operations.'),
            'real field' => 'id',
            'field' => array(
                'handler' => 'auto_topup_handler_field_vbo',
                'click sortable' => FALSE,
            ),
        );
    }
}