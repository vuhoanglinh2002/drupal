<?php
/**
 * Implement hook_action_info()
 */
function auto_topup_action_info(){
    return array(
        'auto_topup_amount_action' => array(
            'type' => 'entity',
            'label' => t('Change Amount'),
            'behavior' => array('changes_property'),
            'configurable' => FALSE,
            'vbo_configurable' => TRUE,
            'triggers' => array('any'),
        ),
        'auto_topup_status_action' => array(
            'type' => 'entity',
            'label' => t('Change status'),
            'behavior' => array('changes_property'),
            'configurable' => FALSE,
            'vbo_configurable' => TRUE,
            'triggers' => array('any'),
        ),
    );
}

function auto_topup_status_action(&$entity, $context){
    $message = t('Package name is %name has been change, %status', array(
        '%name' => $entity->name,
        '%status' => $context['status'],
    ));
    drupal_set_message($message);
    $entity->status = $context['status'];

}

function auto_topup_status_action_form($form, &$form_state) {
    $form = array();
    $form['status'] = array(
        '#type' => 'radios',
        '#title' => t('Choose your status'),
        '#options' => array(
            'enabled' => t('Enabled'),
            'disabled' => t('Disabled'),
        ),
        '#required' => TRUE,
    );
    return $form;
}

function auto_topup_status_action_submit($form, $form_state) {
    $return = array();
    $return['status'] = $form_state['values']['status'];
    return $return; //Note, return value here must be an array.
}

function auto_topup_amount_action(&$entity, $context){
    $message = t('Package name is %name has been change, %amount', array(
        '%name' => $entity->name,
        '%amount' => $context['amount'],
    ));
    drupal_set_message($message);
    $entity->amount = $context['amount'];
}

function auto_topup_amount_action_form($form, &$form_state) {
    $form = array();
    $form['amount'] = array(
        '#type' => 'textfield',
        '#title' => t('Type amount'),
        '#required' => TRUE,
    );
    return $form;
}

function auto_topup_amount_action_validate($form, &$form_state) {
    $amount = $form_state['values']['amount'];
    if(!is_numeric($amount)){
        form_set_error('title', 'Amount is not numeric.');
    }
}

function auto_topup_amount_action_submit($form, $form_state) {
    $return = array();
    $return['amount'] = $form_state['values']['amount'];
    return $return; //Note, return value here must be an array.
}