<?php

/**
 * Interface EntityAutoTopupBasicControllerInterface
 */

interface EntityAutoTopupBasicControllerInterface extends EntityAPIControllerInterface {

    /**
     * @param $entity
     * @return mixed
     */
    public function save($entity);

    public function load($ids = array(), $conditions = array());

}

class EntityAutoTopupController extends EntityAPIController implements  EntityAutoTopupBasicControllerInterface {

    private $header = array();
    private $method = "POST";
    private $filter = array();

    public function create(array $values = array()){
//        $values = array_merge($values, array(
//            'id' => 0,
//            'code' => '',
//            'name' => '',
//            'amount' => '',
//            'monthsel' => '',
//            'telco' => '',
//            'status' => '',
//            'sms_code' => '',
//        ));
//        return parent::create($values);

        $entity = new stdClass();
        $entity->id = 0;
        $entity->code = '';
        $entity->name = '';
        $entity->amount = 0;
        $entity->telco = '';
        $entity->month = 0;
        $entity->status = '';
        $entity->sms_code = '';
        return $entity;
    }

    public function getHeader(){
        return $this->header;
    }

    public function getMethod(){
        return $this->method;
    }

    public function getFilter(){
        return $this->encode_data($this->filter);
    }

    public function setFilter($filter = array()){
        $this->filter = $filter;
    }

    protected function encode_data($object) {
        return json_encode($object, JSON_UNESCAPED_UNICODE);
    }

    protected function decode_data($entity, $assoc = TRUE){
        if($assoc){
            $return = json_decode($entity, TRUE);
        } else {
            $return = json_decode($entity, FALSE);
        }
        return $return;
    }

    public function generate_data($object){
        $entity = $this->create();
        if($object) {
            $entity->id = $object->id;
            if($entity->id == 0){
                unset($entity->id);
            }
            $entity->code = $object->code;
            $entity->name = $object->name;
            $entity->amount = $object->amount;
            $entity->telco = $object->telco;
            $entity->month = $object->month;
            $entity->status = $object->status;
            $entity->sms_code = $object->sms_code;
            return $entity;
        } else {
            return FALSE;
        }
    }

    public function convert_data($object){
        $entity = $this->generate_data($object);
        $json_entity = $this->encode_data($entity);
        return $json_entity;
    }

    public function render($json_output, &$output = array()){
        if($json_output){
            if(!is_object($json_output)) {
                $json_output = auto_topup_convert_to_object($json_output);
            }
            foreach($json_output->list as $row){
                $output[$row->id] = $row;
            }
        }
        return $output;
    }

    public function save($entity){
        $url = auto_topup_package_save_link();
        $options = array(
          'header' => $this->getHeader(),
          'method' => $this->getMethod(),
          'data'   => $this->convert_data($entity),
        );
        $response = drupal_http_request($url, $options);
        return $response;
    }

    public function load($ids = array(), $conditions = array()) {
        $entities = array();
        $queried_entities = array();
        if($ids) {

            foreach($ids as $delta => $values){
                $filter = array(
                    'id' => $values,
                );
                $output = $this->search($filter, FALSE);
                $this->render($output, $queried_entities);
            }
        } else {
            $output = $this->search(array(), FALSE);
            $this->render($output, $queried_entities);
        }

        if(!empty($queried_entities)){
            $entities += $queried_entities;
        }
        return $entities;
    }

    public function search($filter = array(), $assoc = TRUE){
        $json_output = FALSE;
        $url = auto_topup_get_package_search_link();
        $filters = !empty($filter) ? $this->encode_data($filter) : '{}';
        $option = array(
            'headers' => $this->getHeader(),
            'method' => $this->getMethod(),
            'data' => $filters,
        );
        $response = drupal_http_request($url , $option);
        if(isset($response->code) && $response->code == 200){
            if($assoc){
                $json_output = $this->decode_data($response->data);
            } else {
                $json_output =  $this->decode_data($response->data, FALSE);
            }
        }
        return $json_output;
    }
}