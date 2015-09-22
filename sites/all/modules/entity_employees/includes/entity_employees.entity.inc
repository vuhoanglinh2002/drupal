<?php
/**
 * Implements hook_entity_info()
 */
function entity_employees_entity_info() {
    $info['entity_employees'] = array(
        'label' => t('Entity Employees'),
        'controller class' => 'EntityEmployeeController',
        'base table' => 'entity_employees',
        'uri callback' => 'entity_employees_uri',
        'fieldable' => TRUE,
        'entity keys' => array(
            'id' => 'eid',
            'bundle' => 'bundle_type',
            'label' => 'full_name',
        ),
        'bundle keys' => array(
            'bundle' => 'bundle_type',
        ),
        'static cache' => TRUE,
        'bundles' => array(),
        'view modes' => array(
            'full' => array(
                'label' => t('Full content'),
                'custom settings' => TRUE,
            ),
            'summary' => array(
                'label' => t('Summary'),
                'custom settings' => TRUE
            ),
        ),
        'label callback' => 'entity_employees_label_generate',
        'module' => 'entity_employees',
    );
    return $info;
}

/**
 * implement entity info alter
 */
function entity_employees_entity_info_alter(&$entity_info)
{
    $entity_info['entity_employees']['access callback'] = 'entity_employees_access';
    foreach(entity_employees_bundle_types() as $type => $info){
        $entity_info['entity_employees']['bundles'][$type] = array(
            'label' => $info,
            'admin' => array(
                'path' => 'admin/structure/entity_employees/manage/' . $type,
                'real path' => 'admin/structure/entity_employees/manage/' . $type,
                'bundle argument' => 4,
            ),
        );
    }
}

/**
 * Implement hook_entity_property_info()
 */
function entity_employees_entity_property_info(){
    $info = array();
    $properties = &$info['entity_employees']['properties'];

    $properties['eid'] = array(
        'label' => t('EID'),
        'type' => 'integer',
        'description' => t(''),
        'schema field' => 'eid',
    );

    $properties['employee_id'] = array(
        'label' => t('Employee ID (change)'),
        'type' => 'text',
        'description' => t('The unique content ID.'),
        'schema field' => 'employee_id',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['full_name'] = array(
        'label' => t('Full name'),
        'type' => 'text',
        'description' => t(''),
        'schema field' => 'full_name',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['department'] = array(
        'label' => t('Department'),
        'type' => 'text',
        'description' => t(''),
        'schema field' => 'department',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['uid'] = array(
        'label' => t('Account'),
        'type' => 'text',
        'description' => t(''),
        'schema field' => 'uid',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['password'] = array(
        'label' => t('Password'),
        'type' => 'text',
        'description' => t(''),
        'schema field' => 'password',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['sex'] = array(
        'label' => t('Gender'),
        'type' => 'integer',
        'description' => t(''),
        'schema field' => 'sex',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['dayofbirth'] = array(
        'label' => t('Day of birth'),
        'type' => 'integer',
        'description' => t(''),
        'schema field' => 'dayofbirth',
        'setter callback' => 'entity_property_verbatim_set',
    );

    $properties['created'] = array(
        'label' => t('Created'),
        'type' => 'integer',
        'description' => t(''),
        'schema field' => 'created',
        'setter callback' => 'entity_property_verbatim_set',
    );

    return $info;
}

/**
 * Implement hook_field_extra_fields()
 */
function entity_employees_field_extra_fields() {
    $form_elements['employee_id'] = array(
        'label' => t('Employee ID'),
        'description' => t('Employee ID'),
        'weight' => -5,
    );
    $form_elements['full_name'] = array(
        'label' => t('Full name'),
        'description' => t('Full name'),
        'weight' => 0,
    );
    $form_elements['uid'] = array(
        'label' => t('Account'),
        'description' => t('Account'),
        'weight' => 5,
    );
    $form_elements['department'] = array(
        'label' => t('Department'),
        'description' => t('Department'),
        'weight' => 10,
    );
    $form_elements['sex'] = array(
        'label' => t('Gender'),
        'description' => t('Gender'),
        'weight' => 15,
    );
    $form_elements['dayofbirth'] = array(
        'label' => t('Day of birth'),
        'description' => t('Day of birth (an extra for field)'),
        'weight' => 20,
    );

    $display_elements['employee_id'] = array(
        'label' => t('Employee ID'),
        'description' => t('Employee ID'),
        'weight' => -5,
    );

    $display_elements['full_name'] = array(
        'label' => t('Full name'),
        'desciption' => t('Full name (an extra for field)'),
        'weight' => 0,
    );
    $display_elements['uid'] = array(
        'label' => t('Account'),
        'description' => t('Account'),
        'weight' => 5,
    );
    $display_elements['department'] = array(
        'label' => t('Department'),
        'description' => t('Department'),
        'weight' => 10,
    );
    $display_elements['sex'] = array(
        'label' => t('Gender'),
        'description' => t('Gender'),
        'weight' => 15,
    );
    $display_elements['dayofbirth'] = array(
        'label' => t('Day of birth'),
        'desciption' => t('Day of birth(an extra for field)'),
        'weight' => 20,
    );
    $display_elements['created'] = array(
        'label' => t('Creation date'),
        'desciption' => t('Create date (an extra for field)'),
        'weight' => 25,
    );
    $extra_fields = array();
    foreach (entity_employees_bundle_types() as $bundle_type => $info) {
        $extra_fields['entity_employees'][$bundle_type]['form'] = $form_elements;
        $extra_fields['entity_employees'][$bundle_type]['display'] = $display_elements;
    }
    return $extra_fields;
}

/**
 * List bundle_types of entity employee
 */
function entity_employees_bundle_types(){
    $types = array(
        'mbv' => t('MBV'),
        'tcb' => t('TCB'),
        'acb' => t('ACB'),
    );
    return $types;
}

/**
 * Implement generate label
 */
function entity_employees_label_generate($entity, $entity_type){
    return isset($entity) ? $entity->full_name . ' - ' . $entity->employee_id . ' - ' . entity_employees_gender($entity->sex) : '';
}

function entity_employees_gender($sex) {
    $gender = 'Male';
    switch($sex){
        case 0:
            $gender = 'Male';
            break;
        case 1:
            $gender = 'Female';
            break;
    }
    return $gender;
}