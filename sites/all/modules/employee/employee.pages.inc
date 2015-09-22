<?php

/**
 * implement page employee admin info
 */
function admin_employee_info($type){

    if(user_access('administrator entity_employees')) {
        $entities = db_select('employee_tbl', 'em')
            ->fields('em', array('employee_id', 'fullname', 'id'))
            ->condition('bundle_type', $type)
            ->execute();
        $content = array();
        $rows = array();

        if(!empty($entities)) {
            foreach ($entities as $entity) {

                $rows[] = array(
                    'data' => array(
                        'eid' => $entities->id,
                        'fullname' => l($entity->fullname, 'employee/edit/' .$entity->id),
                        'employee_id' => l('View', 'employee/view/' . $entity->id) . ' | ' . l('Edit', 'employee/edit/' . $entity->id)
                    ),
                );
            }

            //Put our entities into a theme table. See theme_table() for detials.
            $content['entity_table'] = array(
                '#theme' => 'table',
                '#rows'=> $rows,
                '#header' => array(t('ID'), t('Full name'), t('Action'))
            );
        }
        else{
            $content[] = array(
                '#type' => 'item',
                '#markup' => t('No employee exist.')
            );
        }
        return $content;
    }
}

/**
 * implement employee form
 */
function employee_form($form, &$form_state, $entity = NULL, $bundle_type = NULL){
    $form = array();
    $form['employee_id'] = array(
        '#type' => 'textfield',
        '#title' => t('Employee ID'),
        '#description' => t('Input employee id'),
        '#default_value' => ($entity) ? $entity->employee_id : '',
        '#attributes' => array('placeholder' => t('Employee ID')),
    );
    $form['fullname'] = array(
      '#type' => 'textfield',
        '#title' => t('Full name'),
        '#description' => t('Input full name'),
        '#default_value' => ($entity) ? $entity->fullname : '',
        '#attributes' => array('placeholder' => t('Full name')),
        '#maxlength' => variable_get('name_maxnumber'),
        '#required' => variable_get('name_required') == 1 ? TRUE : FALSE,
    );

    $format = 'Y-m-d';
    $dob = ($entity) ? date('Y-m-d', $entity->dayofbirth) : '';
    $form['dob'] = array(
        '#type' => 'date_popup',
        '#attributes' => array('placeholder' => t('Date of birth')),
        '#default_value' => $dob,
        '#date_format' => $format,
        '#date_timezone' => date_default_timezone(),
        '#attributes' => array('readonly' => 'readonly'),
        '#date_year_range' => '-100:+0',
    );
    $form['employee_entity'] = array(
        '#type' => 'value',
        '#value' => $entity
    );
    field_attach_form('employee', $entity, $form, $form_state);

    $form['submit'] = array(
      '#type' => 'submit',
        '#value' => t('Submit'),
        '#weight' => 100,
    );

    if($entity) {
        $form['delete'] = array(
            '#type' => 'submit',
            '#value' => t('Delete'),
            '#submit' => array('emplyee_delete_submit'),
            '#weight' => 100,
        );
    }
    return $form;

}

/**
 * views embed
 */
function employee_views_embed($username = NULL){
    if($username){
        $embed = views_embed_view('nhanvien', 'page', $username);
    }else{
        $embed = views_embed_view('nhanvien', 'page');
    }
    $items = array(
        '#items' => $embed,
        '#theme' => 'employee_template_views_embed',
    );
    return $items;
}

/**
 * implement page employee list
 */
function employee_list(){
    $items = array(
        '#items' => employee_load_multiple(),
        '#theme' => 'employee_template_info'
    );
    return $items;
}

/**
 * add new employee
 */
function employee_popup_form($form, &$form_state)
{
    $form['bundle_type'] = array
    (
        '#title' => t('Select Bundle Type'),
        '#type' => 'select',
        '#default_value' => t('mbv'),
        '#options' => array('mbv' => t('MBV'), 'tcb' => t('TCB')),
    );
    $form['submit'] = array
    (
        '#type' => 'submit',
        '#value' => t('ADD'),
    );
    return $form;
}
/**
 * implement validate
 */

function employee_form_validate($form, &$form_state)
{
    if (variable_get('name_required') == 1 && strlen($form_state['values']['fullname']) == 0 ) {
        form_set_error('fullname', t('Input Full Name'));
    }
    field_attach_form_validate('employee', $form_state['values']['employee_entity'], $form, $form_state);

}

/**
 * form submit
 */
function employee_form_submit($form, &$form_state)
{
    global $user;
    $entity = $form_state['values']['employee_entity'] ? $form_state['values']['employee_entity'] : NULL;
    $entity->uid = $user->uid;
    $entity->employee_id = $form_state['values']['employee_id'] ? $form_state['values']['employee_id'] : '';;
    $entity->bundle_type = $entity->bundle_type;
    $entity->full_name = $form_state['values']['fullname'] ? $form_state['values']['fullname'] : '';
    $entity->dayofbirth = strtotime($form_state['values']['dob'] ? $form_state['values']['dob'] : 0);

    //drupal_set_message('<pre>' . print_r($entity, TRUE) .'</pre>');
    //entity_form_submit_build_entity('entity_employees', $entity, $form, $form_state);
    field_attach_submit('employee', $entity, $form, $form_state);
    employee_save($entity);
    //watchdog("employee", "Employee Action", array('%name' => $entity->full_name));
    //watchdog_exception("employee", new Exception(), "Employee Action", array('%name' => $entity->full_name));
}

/**
 * entity_employees add new employee submit
 */
function employee_popup_form_submit($form, &$form_state){
    $bundle_type = $form_state['values']['bundle_type'] ? $form_state['values']['bundle_type'] : 'mbv';
    $form_state['redirect'] = 'admin/structure/employee/manage/' . $bundle_type . '/add';
}
/**
 * delete employee
 */
function employees_delete_submit($form, &$form_state)
{
    $entity = $form_state['values']['employees_entity'] ? $form_state['values']['employees_entity'] : NULL;
    employees_delete($entity);
    field_attach_delete('entity_employees', $entity);
    watchdog("employee", 'delete employee ' . $entity->full_name);
    $form_state['redirect'] = 'entity_employees';//drupal_encode_path('#overlay=admin/structure/employee/manage/' . $entity->employee_id);
}

/**
 * employee view menu
 */
function employee_view_($entity, $view_mode = 'full')
{
    drupal_set_title($entity->full_name);
    $entity_type = 'employee';
    return entity_view($entity_type, array($entity->eid => $entity), $view_mode);
}

/**
 * module setting admin
 */
function employee_setting_admin() {
    $form = array();
    $form['name_maxnumber'] = array(
        '#type' => 'textfield',
        '#title' => t('Maximum field name number'),
        '#default_value' => variable_get('name_maxnumber', 3),
        '#maxlength' => 13,
        '#description' => t("The maximum field name number to display in the block."),
        '#required' => TRUE,
    );

    $form['name_required'] = array(
        '#type' => 'checkbox',
        '#title' => t('Required field name'),
        '#default_value' => variable_get('name_required'),
        '#description' => t("The required field name to display in the block."),
    );
    return system_settings_form($form);
}

?>