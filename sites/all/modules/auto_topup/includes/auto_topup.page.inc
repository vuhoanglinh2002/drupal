<?php
/**
 * @param $entity
 * @return bool
 */
function auto_topup_view_($entity, $view_mode = 'full'){
    $entity_type = 'auto_topup_package';
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
    field_attach_prepare_view($entity_type, array($entity->id => $entity),$view_mode);
    // We call entity_prepare_view() so it can invoke hook_entity_prepare_view()
    // for us.
    entity_prepare_view($entity_type, array($entity->id => $entity));
    // Now field_attach_view() generates the content for the fields.
    $entity->content += field_attach_view($entity_type, $entity, $view_mode);

    // OK, Field API done, now we can set up some of our own data.
    $entity->content['code'] = array(
        '#type' => 'item',
        '#title' => t('Package Code'),
        '#markup' => $wrapper->code->value(),
    );
    $entity->content['name'] = array(
        '#type' => 'item',
        '#title' => t('Name'),
        '#markup' => $wrapper->name->value(),
    );
    $entity->content['amount'] = array(
        '#type' => 'item',
        '#title' => t('Amount'),
        '#markup' => $wrapper->amount->value(),
    );
    $entity->content['telco'] = array(
        '#type' => 'item',
        '#title' => t('Telco'),
        '#markup' => $wrapper->telco->value(),
    );
    $entity->content['month'] = array(
        '#type' => 'item',
        '#title' => t('Month'),
        '#markup' => $wrapper->month->value(),
    );
    $entity->content['status'] = array(
        '#type' => 'item',
        '#title' => t('status'),
        '#markup' => $wrapper->status->value(),
    );
    $entity->content['sms_code'] = array(
        '#type' => 'item',
        '#title' => t('SMS Code'),
        '#markup' => $wrapper->sms_code->value(),
    );


    // hook_entity_view(), so let's get that.
    global $language;
    $langcode = $language->language;
    // And now invoke hook_entity_view().
    module_invoke_all('entity_view', $entity, $entity_type, $view_mode, $langcode);
    // Now invoke hook_entity_view_alter().
    drupal_alter(array($entity_type, 'entity_view'), $entity->content, $entity_type);

    // And finally return the content.
    return $entity->content;
}