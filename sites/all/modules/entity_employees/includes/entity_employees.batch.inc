<?php
function entity_employees_batch_form($form, &$form_state){

    $form['description'] = array(
        '#type' => 'markup',
        '#markup' => t('Demo the use of batch to create 50 employees'),
    );
    $form['batch'] = array(
        '#type' => 'select',
        '#title' => 'Choose batch',
        '#options' => array(
            'batch_1' => t('batch 1 - 10 operations, each create employees of ACB'),
            'batch_2' => t('batch 2 - 10 operations, each create employees of MBV'),
            'batch_3' => t('batch 3 - 10 operations, each create employees of TCB'),
            'batch_4' => t('batch 4 - 10 operations, each create employees of MBV and ACB'),
            'batch_5' => t('batch 5 - 10 operations, each create employees of MBV and TCB'),
        ),
    );
    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Go',
    );
    return $form;
}

function entity_employees_batch_form_submit($form, $form_state){
    $function = 'entity_employees_' . $form_state['values']['batch'];

    $batch = $function();

    batch_set($batch);
}

/**
 * Batch 1
 * @return array
 */
function entity_employees_batch_1(){
    $num_operations = 10;
    $operations = array();

    for($i = 0; $i < $num_operations; $i++){
        $operations[] = array(
            'entity_employees_insertdb',
            array(
                entity_employees_sample_data()['acb'][$i],
                t('ACB'),
                t('(Operation @operation)', array('@operation' => $i)),
            ),
        );
    }

    $batch = array(
        'operations' => $operations,
        'finished' => 'entity_employees_finished',
        'title' => t('Processing batch 1'),
        'init_message' => t('Batch 1 is starting.'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Batch 1 has encountered an error.'),
    );
    return $batch;
}

/**
 * Batch 2
 * @return array
 */
function entity_employees_batch_2(){
    $num_operations = 10;
    $operations = array();

    for($i = 0; $i < $num_operations; $i++){
        $operations[] = array(
            'entity_employees_insertdb',
            array(
                entity_employees_sample_data()['mbv'][$i],
                t('MBV'),
                t('(Operation @operation)', array('@operation' => $i)),
            ),
        );
    }

    $batch = array(
        'operations' => $operations,
        'finished' => 'entity_employees_finished',
        'title' => t('Processing batch 2'),
        'init_message' => t('Batch 2 is starting.'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Batch 2 has encountered an error.'),
    );
    return $batch;
}

/**
 * Batch 3
 * @return array
 */
function entity_employees_batch_3(){
    $num_operations = 10;
    $operations = array();

    for($i = 0; $i < $num_operations; $i++){
        $operations[] = array(
            'entity_employees_insertdb',
            array(
                entity_employees_sample_data()['tcb'][$i],
                t('TCB'),
                t('(Operation @operation)', array('@operation' => $i)),
            ),
        );
    }

    $batch = array(
        'operations' => $operations,
        'finished' => 'entity_employees_finished',
        'title' => t('Processing batch 3'),
        'init_message' => t('Batch 3 is starting.'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Batch 3 has encountered an error.'),
    );
    return $batch;
}

/**
 * Batch 4
 * @return array
 */
function entity_employees_batch_4(){
    $num_operations = 10;
    $operations = array();

    for($i = 0; $i < $num_operations; $i++){
        $operations[] = array(
            'entity_employees_insertdb',
            array(
                entity_employees_sample_data()['mbvacb'][$i],
                t('MBV and ACB '),
                t('(Operation @operation)', array('@operation' => $i)),
            ),
        );
    }

    $batch = array(
        'operations' => $operations,
        'finished' => 'entity_employees_finished',
        'title' => t('Processing batch 4'),
        'init_message' => t('Batch 4 is starting.'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Batch 4 has encountered an error.'),
    );
    return $batch;
}

/**
 * Batch 5
 * @return array
 */
function entity_employees_batch_5(){
    $num_operations = 10;
    $operations = array();

    for($i = 0; $i < $num_operations; $i++){
        $operations[] = array(
            'entity_employees_insertdb',
            array(
                entity_employees_sample_data()['mbvtcb'][$i],
                t('MBV and TCB '),
                t('(Operation @operation)', array('@operation' => $i)),
            ),
        );
    }

    $batch = array(
        'operations' => $operations,
        'finished' => 'entity_employees_finished',
        'title' => t('Processing batch 5'),
        'init_message' => t('Batch 5 is starting.'),
        'progress_message' => t('Processed @current out of @total.'),
        'error_message' => t('Batch 5 has encountered an error.'),
    );
    return $batch;
}

/**
 * Implement function insert employee per batch
 * @param $array_employee
 * @param $title
 * @param $operation_details
 * @param $context
 */
function entity_employees_insertdb($array_employee, $title, $operation_details, &$context){
    global $user;
    if(is_array($array_employee)) {
        $entity = entity_get_controller('entity_employees')->create($array_employee['bundle_type']);
        $entity->employee_id = $array_employee['employee_id'];
        $entity->full_name = $array_employee['full_name'];
        $entity->department = $array_employee['department'];
        $entity->sex = intval($array_employee['sex']);
        $entity->uid = $user->uid;
        $entity->dayofbirth =strtotime($array_employee['dob']);
        $entity = entity_employees_save($entity);
    }
    $context['message'] = t('Insert employee of "@title"', array('@title' => $title)) . ' ' . $operation_details;
}

function entity_employees_finished($success, $results, $operations) {
    if ($success) {
        drupal_set_message(t('The final result was "%final"', array('%final' => end($results))));
    }
    else {
        $error_operation = reset($operations);
        drupal_set_message(
            t('An error occurred while processing @operation with arguments : @args',
                array(
                    '@operation' => $error_operation[0],
                    '@args' => print_r($error_operation[0], TRUE),
                )
            )
        );
    }
}

function entity_employees_sample_data(){
    global $user;
    $per = 10;
    $sample_data = array();
    // Data of ACB
    for($i = 0; $i < $per; $i++){
        $sample_data['acb'][$i] = array(
            'bundle_type' => 'acb',
            'employee_id' => 'ABC' . ($i + 3),
            'full_name'   => 'Nguyen Van ' . ($i + 3),
            'department'  => 'Engineer',
            'uid' => $user->uid,
            'sex' => 0,
            'dayofbirth' => time(),
            'created' => time(),
        );
    }

    // Data of MBV
    for($i = 0; $i < $per; $i++){
        $sample_data['mbv'][$i] = array(
            'bundle_type' => 'mbv',
            'employee_id' => 'MBV' . ($i + 7),
            'full_name'   => 'Tran Van ' . ($i + 7),
            'department'  => 'QA',
            'uid' => $user->uid,
            'sex' => 0,
            'dayofbirth' => time(),
            'created' => time(),
        );
    }

    // Data of TCB
    for($i = 0; $i < $per; $i++){
        $sample_data['tcb'][$i] = array(
            'bundle_type' => 'tcb',
            'employee_id' => 'TCB' . ($i + 7),
            'full_name'   => 'Le Thi ' . ($i + 7),
            'department'  => 'BA',
            'uid' => $user->uid,
            'sex' => 1,
            'dayofbirth' => time(),
            'created' => time(),
        );
    }

    // Data of MBV and ACB
    for($i = 0; $i < $per; $i++){

        if($i < 4){
            $sample_data['mbvacb'][$i] = array(
                'bundle_type' => 'mbv',
                'employee_id' => 'MBV' . ($i + 20),
                'full_name'   => 'Huynh Tien ' . ($i + 20),
                'department'  => 'Tester',
                'uid' => $user->uid,
                'sex' => 0,
                'dayofbirth' => time(),
                'created' => time(),
            );
        }
        else{
            $sample_data['mbvacb'][$i] = array(
                'bundle_type' => 'acb',
                'employee_id' => 'ACB' . ($i + 20),
                'full_name'   => 'Vu Thanh ' . ($i + 20),
                'department'  => 'Security',
                'uid' => $user->uid,
                'sex' => 0,
                'dayofbirth' => time(),
                'created' => time(),
            );
        }
    }

    // Data of MBV and TCB
    for($i = 0; $i < $per; $i++){

        if($i < 4){
            $sample_data['mbvtcb'][$i] = array(
                'bundle_type' => 'mbv',
                'employee_id' => 'MBV' . ($i + 30),
                'full_name'   => 'Hoang Tan ' . ($i + 30),
                'department'  => 'Shipper',
                'uid' => $user->uid,
                'sex' => 0,
                'dayofbirth' => time(),
                'created' => time(),
            );
        }
        else{
            $sample_data['mbvtcb'][$i] = array(
                'bundle_type' => 'tcb',
                'employee_id' => 'TCB' . ($i + 20),
                'full_name'   => 'Ly Hoang ' . ($i + 20),
                'department'  => 'PM',
                'uid' => $user->uid,
                'sex' => 0,
                'dayofbirth' => time(),
                'created' => time(),
            );
        }
    }

    return $sample_data;
}

