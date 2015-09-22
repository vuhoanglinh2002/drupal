<?php
/**
 * Implement hook_cron()
 */
function entity_employees_cron(){
    $queue = 'cron_queue_entity_employees';
    $employees = db_select('entity_employees', 'e')
        ->fields('e', array('eid', 'full_name', 'employee_id'))
        ->condition('employee_id', '')
        ->execute();
    $queues = DrupalQueue::get($queue);
    foreach($employees as $delta => $emp){
        $item = new stdClass();
        $item->created = time();
        $item->name = $emp->full_name;
        $queues->createItem($item);
    }

}
/**
 * Implement hook_cron_queue_info().
 */
function entity_employees_cron_queue_info(){
    $queues['cron_queue_entity_employees'] = array(
        'worker callback' => 'entity_employees_cron_queue_worker',
        'time' => 1,
    );
    return $queues;
}

/**
 * Implement cron worker
 */
function entity_employees_cron_queue_worker($item){
    watchdog('entity_employees', 'Queue employee !name processed item create at !time,',
        array(
           '!name' => $item->name,
           '!time' => date_iso8601($item->created)
        )
    );
}