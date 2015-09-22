<?php
/**
 * Implement hook_entity_info().
 */
function auto_topup_entity_info(){
    $info['auto_topup_package'] = array(
        'label' => t('Auto Topup Package'),
        'controller class' => 'EntityAutoTopupController',
        'static cache' => TRUE,
        'entity keys' => array(
            'id' => 'id',
        ),
        'view modes' => array(
          'full' => array(
            'label' => t('Full Content'),
            'custom settings' => TRUE,
          ),
          'summary' => array(
            'label' => t('Summary'),
            'custom settings' => TRUE,
          ),
        ),
        'label callback' => 'auto_topup_label_generate',
        'module' => 'auto_topup',
    );
    return $info;
}

function auto_topup_entity_property_info(){
    $info = array();
    $properties = &$info['auto_topup_package']['properties'];

    $properties['id'] = array(
        'label' => 'ID',
        'type' => 'integer',
        'schema field' => 'id',
    );

    $properties['code'] = array(
        'label' => 'Code',
        'type' => 'text',
        'schema field' => 'code',
    );

    $properties['name'] = array(
        'label' => 'Name',
        'type' => 'text',
        'schema field' => 'name',
    );

    $properties['month'] = array(
        'label' => 'Month',
        'type' => 'integer',
        'schema field' => 'month',
    );

    $properties['telco'] = array(
        'label' => 'Telco',
        'type' => 'text',
        'schema field' => 'telco',
    );

    $properties['amount'] = array(
        'label' => 'Amount',
        'type' => 'integer',
        'schema field' => 'amount',
    );

    $properties['status'] = array(
        'label' => 'Status',
        'type' => 'text',
        'schema field' => 'status',
    );

    $properties['sms_code'] = array(
        'label' => 'SMS Code',
        'type' => 'text',
        'schema field' => 'sms_code',
    );

    return $info;
}
/**
 * Implement generate label
 */
function auto_topup_label_generate($entity, $entity_type){
    return isset($entity) ? t('Code: @code, Name: @name',
        array(
           '@code' => $entity->code,
           '@name' => $entity->name,
        )
    ) : '';
}

