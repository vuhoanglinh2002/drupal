<?php
/**
 * Implement Basic infomation for the page
 */
function entity_employees_info_page() {
    $content['preface'] = array(
        '#type' => 'item',
        '#markup' => t('The entity employee provides a simple entity.'),
    );

    if(user_access('administer entity_employees')) {
        $content['preface']['#markup'] = t('You can adminiter these and add fields and change the view !link.',
            array('!link' => l(t('here'), 'admin/structure/entity_employees/manage')));
    }
    $content['table'] = entity_employees_list_entities();

    return $content;
}

/**
 * Menu callback to display an entity.
 *
 * As we load the entity for display, we're responsible for invoking a number
 * of hooks in their proper order.
 *
 * @see hook_entity_prepare_view()
 * @see hook_entity_view()
 * @see hook_entity_view_alter()
 */
function entity_employees_view_($entity, $view_mode = 'full')
{

    $entity_type = 'entity_employees';
    // Our entity type, for convenience.
    $wrapper = entity_metadata_wrapper($entity_type, $entity);

    // Start setting up the content.
    $entity->content = array(
        '#view_mode' => $view_mode,
    );
    // Build fields content - this is where the Field API really comes in to play.
    // The task has very little code here because it all gets taken care of by
    // field module.
    // field_attach_prepare_view() lets the fields load any data they need
    // before viewing.
    field_attach_prepare_view($entity_type, array($entity->eid => $entity),$view_mode);
    // We call entity_prepare_view() so it can invoke hook_entity_prepare_view()
    // for us.
    entity_prepare_view($entity_type, array($entity->eid => $entity));
    // Now field_attach_view() generates the content for the fields.
    $entity->content += field_attach_view($entity_type, $entity, $view_mode);

    // OK, Field API done, now we can set up some of our own data.
    $entity->content['created'] = array(
        '#type' => 'item',
        '#title' => t('Created date'),
        '#markup' => format_date($entity->created),
    );
    $entity->content['employee_id'] = array(
        '#type' => 'item',
        '#title' => t('Employee ID'),
        '#markup' => $wrapper->employee_id->value(),
    );
    $entity->content['full_name'] = array(
        '#type' => 'item',
        '#title' => t('Full name'),
        '#markup' => $wrapper->full_name->value(),
    );


    if($view_mode == 'full') {
        $entity->content['dayofbirth'] = array(
            '#type' => 'item',
            '#title' => t('Day of birth'),
            '#markup' => date('d-m-Y', intval($entity->dayofbirth)),
        );
    }

    // Now to invoke some hooks. We need the language code for
    // hook_entity_view(), so let's get that.
    global $language;
    $langcode = $language->language;
    // And now invoke hook_entity_view().
    module_invoke_all('entity_view', $entity, $entity_type, $view_mode, $langcode);
    // Now invoke hook_entity_view_alter().
    drupal_alter(array('entity_employees', 'entity_view'), $entity->content, $entity_type);

    // And finally return the content.
    return $entity->content;
}

/**
 * Provides a wrapper on the edit form to add a new entity.
 */
function entity_employees_add($bundle_type) {
    // Create a basic entity structure to be used and passed to the validation
    // and submission functions.
    $entity = entity_get_controller('entity_employees')->create($bundle_type);
    return drupal_get_form('entity_employees_form', $entity, $bundle_type);
}

/**
 * Implement form
 */
function entity_employees_form($form, &$form_state, $entity = NULL, $bundle_type = NULL) {
    global $user;
    $user_field = user_load($entity->uid);
    $form['employee_id'] = array(
      '#type'  => 'textfield',
      '#title' => t('Employee ID'),
      '#required' => TRUE,
      '#default_value' => ($entity) ? $entity->employee_id : '',
    );

    $form['full_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Full name'),
      '#required' => TRUE,
      '#default_value' => ($entity) ? $entity->full_name : '',
    );

    $form['department'] = array(
        '#type' => 'textfield',
        '#title' => t('Department'),
        '#default_value' => ($entity) ? $entity->department : '',
    );

    if(!empty($entity->uid)) {
        $form['uid'] = array(
            '#type' => 'textfield',
            '#title' => t('User Created'),
            '#attributes' => array('readonly' => 'readonly'),
            '#default_value' => ($user_field) ? $user_field->name : '',
        );
    }

    $form['sex'] = array(
        '#type' => 'select',
        '#title' => t('Gender'),
        '#options' => array(
            0 => t('Male'),
            1 => t('Female'),
        ),
        '#default_value' => ($entity) ? $entity->sex : '',
    );

//    if(empty($entity->uid)) {
//        $form['uid'] = array(
//            '#type' => 'textfield',
//            '#title' => t('Account'),
//            '#default_value' => '',
//        );
//
//        $form['password'] = array(
//            '#type' => 'password',
//            '#title' => t('Password'),
//            '#default_value' => '',
//        );
//
//        $form['repassword'] = array(
//            '#type' => 'password_confirm',
//            '#title' => t('Confirm password'),
//            '#default_value' => '',
//        );
//    }

    $format = 'Y-m-d';
    $bod = ($entity) ? date('Y-m-d', intval($entity->dayofbirth)) : '';
    $form['info']['dob'] = array(
        '#type' => 'date_popup',
        '#title' => t('Day of birth'),
        '#default_value' => $bod,
        '#date_format' => $format,
        '#date_timezone' => date_default_timezone(),
        '#date_increment' => 15,
        '#attributes' => array('readonly' => 'readonly'),
        '#date_year_range' => '-100:+0',
        '#suffix' => t('<style>#edit-dob { padding: 0; }</style>' ),
    );

    $form['basic_entity'] = array(
        '#type' => 'value',
        '#value' => $entity,
    );

    field_attach_form('entity_employees', $entity, $form, $form_state);

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Save'),
        '#weight' => 100,
    );

    if(!empty($entity->eid)) {
        $form['delete'] = array(
            '#type' => 'submit',
            '#value' => t('Delete'),
            '#submit' => array('entity_employees_form_delete'),
            '#weight' => 200,
        );
    }

    return $form;
}

/**
 * Implement hook_form_alter()
 */
function entity_employees_form_alter(&$form, &$form_state, $form_id) {
    $format = 'd-m-Y';
    $form['info']['dob']['#date_format'] = $format;
    $form['info']['dob']['#date_label_position'] = 'within';
}


/**
 * Implement hook_form_FORM_ID_alter()
 */
function entity_employees_form_entity_employees_form_alter(&$form, &$form_state, $form_id) {
    $form['info']['dob']['#title'] = t('Birth day');
    $form['cancel'] = array(
        '#type' => 'submit',
        '#value' => t('Cancel'),
        '#submit' => array('entity_employees_form_cancel'),
        '#weight' => 200,
    );
}

/**
 * Implement redirect back when click cancel button
 */
function entity_employees_form_cancel($form, &$form_state) {
    $entity = $form_state['values']['basic_entity'];
    $form_state['redirect'] = 'admin/structure/entity_employees/manage/' . $entity->bundle_type;
}

/**
 * Validation handler for entity_example_basic_add_form form.
 *
 * We pass things straight through to the Field API to handle validation
 * of the attached fields.
 */
function entity_employees_form_validate($form, &$form_state) {
    field_attach_form_validate('entity_employees', $form_state['values']['basic_entity'], $form, $form_state);

    $entity = $form_state['values']['basic_entity'];
    $employee_id_val = $form_state['values']['employee_id'];
    if(empty($entity->employee_id) || $employee_id_val != $entity->employee_id) {
        $employee_id = db_select('entity_employees', 'ene')
            ->fields('ene')
            ->condition('employee_id', $form_state['values']['employee_id'])
            ->execute()
            ->fetchAssoc();
        if($employee_id) {
            form_set_error('title', t('An Employee Id was existed.'));
        }
    }
}

/**
 * Form submit handler: Submits basic_add_form information.
 */
function entity_employees_form_submit($form, &$form_state) {
    global $user;
    $entity_type = 'entity_employees';
    $entity = $form_state['values']['basic_entity'];
//    $wrapper = entity_metadata_wrapper($entity_type, $entity);
//    $wrapper->employee_id->set($form_state['values']['employee_id']);
//    $wrapper->full_name->set($form_state['values']['full_name']);
//    $wrapper->department->set($form_state['values']['department']);
//    $wrapper->sex->set(intval($form_state['values']['sex']));
//    $wrapper->uid->set($form_state['values']['uid']);
//    $wrapper->dayofbirth->set(strtotime($form_state['values']['dob']));

    $entity->employee_id = $form_state['values']['employee_id'];
    $entity->full_name = $form_state['values']['full_name'];
    $entity->department = $form_state['values']['department'];
    $entity->sex = intval($form_state['values']['sex']);
    if(empty($entity->uid)) {
        $entity->uid = $user->uid;
    }
    $entity->dayofbirth =strtotime($form_state['values']['dob']);
    field_attach_submit('entity_employees', $entity, $form, $form_state);

    //$wrapper->save();
    $entity = entity_employees_save($entity);
    $form_state['redirect'] = 'admin/structure/entity_employees/manage/' . $entity->bundle_type;
}


/**
 * Form deletetion handler
 *
 * @toto: 'Are you sure?' message
 */
function entity_employees_form_delete($form, &$form_state) {
    $entity = $form_state['values']['basic_entity'];
    entity_employees_delete($entity);
    drupal_set_message(t('The entity %item_description (ID %id) has been deleted',
            array('%item_description' => $entity->full_name, '%id' => $entity->employee_id))
    );
    $form_state['redirect'] = 'admin/structure/entity_employees/manage/' . $entity->bundle_type;
}

/**
 * Implement show entity detail
 */