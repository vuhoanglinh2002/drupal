<?php
/**
 * Implement Create New Topup
 * @return mixed
 */
function auto_topup_new(){
    return entity_get_controller('auto_topup_package')->create();
}

/**
 * Implement Save Topup
 * @param $entity
 * @return mixed
 */
function auto_topup_save($entity){
    return entity_get_controller('auto_topup_package')->save($entity);
}

/**
 * Implement Function Search Use Rest API
 * Json example: {"code": "05006","telco": "VTEL","page_number":1,"page_size":20,"order_by":"id","order_asc":false}
 * @param $filter
 * @return bool
 */
function auto_topup_search($filter = array()){
    return entity_get_controller('auto_topup_package')->search($filter);
}

/**
 * @param $object
 * @return mixed
 */
function auto_topup_generate_data($object){
    return entity_get_controller('auto_topup_package')->generate_data($object);
}

/**
 * Implement function get info auto topup package by code
 */
function auto_topup_search_property($array = NULL){
    if(!empty($array)) {
        $filter = array();
        foreach($array as $delta => $value) {
            $filter[$delta] = $value;
        }
        $json_output = auto_topup_search($filter);
        if(isset($json_output['list']) && count($json_output['list']) == 1){
            $object = new stdClass();
            foreach ($json_output['list'][0] as $key => $value)
            {
                $object->$key = $value;
            }
            return $object;
        } else {
            return FALSE;
        }
    } else {
        return FALSE;
    }
}

function auto_topup_load_entity($code) {
    $array = array(
      'code' => $code,
    );
    $object = auto_topup_search_property($array);
    $entity = auto_topup_generate_data($object);
    return $entity;
}

function auto_topup_convert_to_object($array) {
    $object = new stdClass();
    foreach ($array as $key => $value) {
        if (is_array($value)) {
            $value = convertToObject($value);
        }
        $object->$key = $value;
    }
    return $object;
}
