<?php
/**
 * Provides a wrapper on the edit form to add a new entity.
 */
function auto_topup_add() {
    // Create a basic entity structure to be used and passed to the validation
    // and submission functions.
    $entity = entity_get_controller('auto_topup_package')->create();
    return drupal_get_form('auto_topup_form', $entity);
}

/**
 * Implement hook_form().
 * @param $form
 * @param $form_state
 * @param $entity
 * @return array
 */
function auto_topup_form($form, &$form_state, $entity){
    $form = array();
    $form['entity'] = array(
        '#type' => 'value',
        '#value' => $entity,
    );

    $form['code'] = array(
        '#type' => 'textfield',
        '#title' => t('Package code'),
        '#required' => TRUE,
        '#default_value' => $entity->code,
        '#weight' => 0,
    );

    $form['name'] = array(
        '#type' => 'textfield',
        '#title' => t('Name'),
        '#required' => TRUE,
        '#default_value' => $entity->name,
        '#weight' => 1,
    );

    $form['amount'] = array(
        '#type' => 'textfield',
        '#title' => t('Amount'),
        '#default_value' => $entity->amount,
        '#required' => TRUE,
        '#weight' => 2,
    );

    $form['month'] = array(
        '#type' => 'select',
        '#title' => t('Month'),
        '#default_value' => $entity->month,
        '#options' => array(
            1 => t('1'),
            2 => t('2'),
            3 => t('3'),
            4 => t('4'),
            5 => t('5'),
            6 => t('6'),
            7 => t('7'),
            8 => t('8'),
            9 => t('9'),
            10 => t('10'),
            11 => t('11'),
            12 => t('12'),

        ),
    );

    $form['telco'] = array(
        '#type' => 'select',
        '#title' => t('Telco'),
        '#options' => array(
            'MOBI' => t('MobiPhone'),
            'VINA' => t('VinaPhone'),
            'VTEL' => t('Viettel'),
        ),
        '#default_value' => $entity->telco,
        '#weight' => 4,
    );

    $form['status'] = array(
        '#type' => 'radios',
        '#title' => t('Status'),
        '#options' => array(
            'enabled' => t('Enable'),
            'disabled' => t('Disable'),
        ),
        '#default_value' => $entity->status,
        '#weight' => 5,
    );

    $form['sms_code'] = array(
        '#type' => 'textfield',
        '#title' => t('SMS Code'),
        '#default_value' => $entity->sms_code,
        '#required' => TRUE,
        '#weight' => 6,
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#weight' => 100,
    );

    $form['cancel'] = array(
        '#type' => 'submit',
        '#value' => t('Cancel'),
        '#submit' => array('auto_topup_form_cancel'),
        '#weight' => 200,
    );

    return $form;
}

/**
 * Implement hook_form_validate
 * @param $form
 * @param $form_state
 */
function auto_topup_form_validate($form, &$form_state){
    field_attach_form_validate('auto_topup', $form_state['values']['entity'], $form, $form_state);
    $entity = $form_state['values']['entity'];
    $amount = $form_state['values']['amount'];
    $month = $form_state['values']['month'];
    $code = $form_state['values']['code'];
    $sms_code = $form_state['values']['sms_code'];
    $telco = $form_state['values']['telco'];

    if(!is_numeric($amount)) {
        form_set_error('title', t('Amount is not numeric or not integer.'));
    }

    if(!is_numeric($month)) {
        form_set_error('title', t('Month of repay is not numeric or not integer.'));
    }

    if(empty($entity->id) || ($entity->code != $code && !empty($entity->id))){
        $codes = array(
            'code' => $code,
        );
        if(auto_topup_search_property($codes)) {
            form_set_error('title', t('Code was existed.'));
        }
    }

    if(empty($entity->id) || ($entity->sms_code != $sms_code && !empty($entity->id))){
        $sms_codes = array(
            'sms_code' => $sms_code,
        );

        if(auto_topup_search_property($sms_codes)){
            form_set_error('title', t('SMS Code was existed.'));
        }
    }

    if(empty($entity->id) || ($entity->telco != $telco && $entity->amount != $amount && $entity->month != $month && !empty($entity->id))){
        $prop = array(
            'month' => $month,
            'amount' => $amount,
            'telco' => $telco,
        );

        if(auto_topup_search_property($prop)){
            form_set_error('title', t('Telco, Amount and Month were existed.'));
        }
    }
}

/**
 * Implement event cancel
 */
function auto_topup_form_cancel(){
    drupal_goto('admin/auto_topup_package');
}

/**
 * Implement hook_form_submit()
 */
function auto_topup_form_submit($form, &$form_state){
    $entity = $form_state['values']['entity'];
    $entity->code = $form_state['values']['code'];
    $entity->name = $form_state['values']['name'];
    $entity->amount = $form_state['values']['amount'];
    $entity->telco = $form_state['values']['telco'];
    $entity->month = $form_state['values']['month'];
    $entity->status = $form_state['values']['status'];
    $entity->sms_code = $form_state['values']['sms_code'];

    $response = auto_topup_save($entity);
    if(isset($response->code)){
        if($response->code == 200) {
            $form_state['redirect'] = 'admin/auto_topup_package';
        } elseif($response->code == 400){
            $json_output = json_decode($response->data, true);
            form_set_error('title', t('Message : @msg.', array('@msg' => $json_output['message'])));
        } else {
            form_set_error('title', t('Backend was not connected.'));
        }
    }
}
