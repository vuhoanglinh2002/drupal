<?php

class auto_topup_views_plugin_query extends views_plugin_query{
    var $offset = 1;
    /**
     * An array of fields.
     */
    var $fields = array();

    /**
     * An array of sections of the WHERE query. Each section is in itself
     * an array of pieces and a flag as to whether or not it should be AND
     * or OR.
     */
    var $where = array();

    /**
     * A simple array of order by clauses.
     */
    var $orderby = array();

    /**
     * The current used pager plugin.
     *
     * @var views_plugin_pager
     */
    var $pager = NULL;

    /**
     * An array mapping table aliases and field names to field aliases.
     */
    var $field_aliases = array();
    function execute(&$view){
        $filter = $this->query();
        $response = auto_topup_search($filter);
        if($response) {
            $json_output = $response;
            foreach($json_output['list'] as $key => $item) {
                $row = new stdClass();
                foreach($item as $delta => $property) {
                    $row->$delta = $property;
                }
                $view->result[] = $row;
            }
            $view->total_rows = $json_output['total'];
            $view->current_page = !empty($filter['page_number']) ? $filter['page_number']: '1';
            $view->items_per_page = $filter['page_size'];
            $this->pager->total_items = $json_output['total'];
            $this->pager->update_page_info();
        }
    }

    function query($get_count = FALSE){
        $filters = array();
        if (!empty($this->where)) {
            foreach ($this->where as $key => $item) {
                if (!empty($item['conditions']['0']['value'])) {
                    $filters[$item['conditions']['0']['field']] = $item['conditions']['0']['value'];
                }
            }
        }
        if (!empty($this->orderby)) {
            foreach ($this->orderby as $key => $item) {
                $filters['order_by'] = $item['field'];
                if($item['direction'] == 'ASC') {
                    $filters['order_asc'] = 'true';
                } else {
                    $filters['order_asc'] = 'false';
                }
            }
        }
        if (!$get_count) {
            if (!empty($this->limit) || !empty($this->offset)) {
                $limit  = intval(!empty($this->limit) ? $this->limit : 999999);
                $offset = intval(!empty($this->offset) ? $this->offset : 0);
                if ($this->offset != 0 && $limit != 999999) {
                    $filters['page_number'] = $offset/$limit + 1;
                }
                if ($limit < 999999)
                {
                    $filters['page_size'] = $limit;
                }
            }
        }
        return $filters;
    }

    function build(&$view) {

        // Store the view in the object to be able to use it later.
        $this->view = $view;

        $view->init_pager();

        // Let the pager modify the query to add limits.
        $this->pager->query();

        $view->build_info['query'] = $this->query();
        $view->build_info['count_query'] = $this->query(TRUE);
    }
    function add_where($group, $field, $value = NULL, $operator = NULL){
        if (empty($group)) {
            $group = 0;
        }
        if (!empty($field) == '.'){
            $field = substr($field,1);
        }
        if (!isset($this->where[$group])) {
            $this->set_where_group('AND', $group);
        }

        $this->where[$group]['conditions'][] = array(
            'field' => $field,
            'value' => $value,
            'operator' => $operator,
        );
    }

    function add_orderby($table, $field = NULL, $order = 'ASC', $alias = '', $params = array()) {
        // Only ensure the table if it's not the special random key.
        // @todo: Maybe it would make sense to just add a add_orderby_rand or something similar.
        $this->orderby[] = array(
            'field' => !empty($field) ? $field : $alias,
            'direction' => strtoupper($order)
        );
    }

    function add_field($table, $field, $alias = '', $params = array()){
        $alias = $alias ? $alias : $field;

        // Create a field info array.
        $field_info = array(
                'field' => $field,
                'table' => $table,
                'alias' => $alias,
            ) + $params;

        $base = $alias;
        $counter = 0;
        while (!empty($this->fields[$alias]) && $this->fields[$alias] != $field_info) {
            $field_info['alias'] = $alias = $base . '_' . ++$counter;
        }

        if (empty($this->fields[$alias])) {
            $this->fields[$alias] = $field_info;
        }

        // Keep track of all aliases used.
        $this->field_aliases[$table][$field] = $alias;

        return $alias;
    }
}