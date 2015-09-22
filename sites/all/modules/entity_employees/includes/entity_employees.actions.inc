<?php
/**
 * Implement redirect
 */
function entity_employees_redirect($type) {
    drupal_goto('admin/structure/entity_employees/manage/' . $type . '/fields' );
}

/**
 * Load multiple entities
 *
 * We only need to pass this request along to entity_load(),
 * which will in turn call the load() method of our entity controller class
 */
function entity_employees_load_multiple($eids = FALSE, $conditions = array(), $reset = FALSE) {
    return entity_load('entity_employees', $eids, $conditions, $reset);
}

/**
 * Implements list_entities()
 */
function entity_employees_list_entities($bundle_type = NULL) {
    $content = array();

    $entities = NULL;
    if(!empty($bundle_type)) {
        // Load all of our entities.
        $condition = array(
            'bundle_type' => $bundle_type,
        );
        $entities = entity_employees_load_multiple(NULL, $condition);
    }
    else{
        $entities = entity_employees_load_multiple();
    }

    if( !empty($entities)) {
        foreach ($entities as $entity) {
            // Create tabular rows for our entities
            $rows[] = array(
                'data' => array(
                    'id' => $entity->eid,
                    'full_name' => l($entity->full_name, 'admin/structure/entity_employees/manage/' . $entity->eid. '/edit'),
                    'type' => entity_employees_bundle_types()[$entity->bundle_type],
                    'dob' => t(date('d-m-Y', $entity->dayofbirth)),
                    'action' => l(t('View'), 'admin/structure/entity_employees/manage/' . $entity->eid. '/view') . '&nbsp;&nbsp;' .l(t('Edit'), 'admin/structure/entity_employees/manage/' . $entity->eid. '/edit')
                )
            );
        }
        // Put our entities into a themed table. See theme_table() for details.
        $content['entity_table'] = array(
            '#theme' => 'table',
            '#rows' => $rows,
            '#header' => array(t('ID'), t('Name'), t('Type'), t('Day of birth'), t('Action')),
        );
    }
    else {
        $content[] = array(
            '#type' => 'item',
            '#markup' => t('No entity_employees entities currently exist.')
        );
    }
    return $content;

}

/**
 * We create the entity by calling the controller.
 */
function entity_employees_new($type = NULL) {
    return entity_get_controller('entity_employees')->create($type);
}

/**
 * We save the entity by calling the controller.
 */
function entity_employees_save(&$entity) {
    return entity_get_controller('entity_employees')->save($entity);
}

/**
 * Use the controller to delete the entity.
 */
function entity_employees_delete($entity) {
    entity_get_controller('entity_employees')->delete($entity);
}

