<?php
/**
 * EntityEmployeeBasicControllerInterface definition
 */
interface EntityEmployeeBasicControllerInterface extends DrupalEntityControllerInterface {

    /**
     * Create an entity
     */
    public function create($bundle_type);

    /**
     * Save an entity
     * @param object $entity
     */
    public function save($entity);

    /**
     * Delete an entity
     * @param object $entity
     */
    public function delete($entity);

    /**
     * @param $entity
     * @param string $view_mode
     * @param null $langcode
     * @param array $content
     * @return mixed
     */
    public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array());
}

/**
 * EntityEmployeeController extends DrupalDefaultEntityController
 */
class EntityEmployeeController extends DrupalDefaultEntityController implements EntityEmployeeBasicControllerInterface {

    /**
     * Create and return a new entity employee.
     */
    public function create($bundle_type = NULL) {
        $entity = new stdClass();
        $entity->type = 'entity_employees';
        $entity->eid = 0;
        $entity->bundle_type = $bundle_type;
        $entity->employee_id = '';
        $entity->full_name = '';
        $entity->department = '';
        $entity->uid = '';
        $entity->password = '';
        $entity->sex = 0;
        $entity->dayofbirth = time();
        $entity->created = time();
        return $entity;
    }

    /**
     * Insert and update entity employees
     */
    public function save($entity) {
        // If our entity has no basic_id, then we need to give it a
        // time of creation.
        if (empty($entity->eid)) {
            $entity->created = time();
        }
        // Invoke hook_entity_presave().
        module_invoke_all('entity_presave', $entity, 'entity_employees');
        // The 'primary_keys' argument determines whether this will be an insert
        // or an update. So if the entity already has an ID, we'll specify
        // basic_id as the key.
        $primary_keys = $entity->eid ? 'eid' : array();
        // Write out the entity record.
        drupal_write_record('entity_employees', $entity, $primary_keys);
        // We're going to invoke either hook_entity_update() or
        // hook_entity_insert(), depending on whether or not this is a
        // new entity. We'll just store the name of hook_entity_insert()
        // and change it if we need to.
        $invocation = 'entity_insert';
        // Now we need to either insert or update the fields which are
        // attached to this entity. We use the same primary_keys logic
        // to determine whether to update or insert, and which hook we
        // need to invoke.
        if (empty($primary_keys)) {
            field_attach_insert('entity_employees', $entity);
        }
        else {
            field_attach_update('entity_employees', $entity);
            $invocation = 'entity_update';
        }
        // Invoke either hook_entity_update() or hook_entity_insert().
        module_invoke_all($invocation, $entity, 'entity_employees');
        return $entity;
    }

    /**
     * Delete one or more entity employee
     *
     * Really a convenience function for deleteMultiple()
     */
    public function delete($entity) {
        $this->deleteMultiple(array($entity));
    }

    public function deleteMultiple($entities) {
        $eids = array();
        if(!empty($entities)) {
            $transaction = db_transaction();
            try {
                foreach ($entities as $entity) {
                    // Invoke hook_entity_delete()
                    module_invoke_all('entity_delete', $entity, 'entity_employees');
                    field_attach_delete('entity_employees', $entity);
                    $eids[] = $entity->eid;
                }
                db_delete('entity_employees')
                    ->condition('eid', $eids, 'IN')
                    ->execute();
            }
            catch (Exception $e) {
                $transaction->rollback();
                watchdog_exception('entitty_employees', $e);
                throw $e;
            }
        }
    }

    /**
     * @param $entity
     * @param string $view_mode
     * @param null $langcode
     * @param array $content
     */
    public function buildContent($entity, $view_mode = 'full', $langcode = NULL, $content = array()){
        $wrapper = entity_metadata_wrapper('entity_employees', $entity);

    }

}