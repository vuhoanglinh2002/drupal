<?php
class auto_topup_handler_field_vbo extends views_bulk_operations_handler_field_operations{
    function get_entity_type(){
        $base_table = $this->view->base_table;

        if (!empty($this->options['relationship']) && $this->options['relationship'] != 'none') {
            $relationships = $this->view->display_handler->get_option('relationships');
            $options = $relationships[$this->options['relationship']];
            $data = views_fetch_data($options['table']);
            $base_table = $data[$options['field']]['relationship']['base'];
        }
        // The base table is now known, use it to determine the entity type.
        foreach (entity_get_info() as $entity_type => $info) {
            if (isset($info['base table']) && $info['base table'] == $base_table) {
                return $entity_type;
            }
            elseif (isset($info['revision table']) && $info['revision table'] == $base_table) {
                $this->revision = TRUE;
                return $entity_type;
            }
        }
        return 'auto_topup_package';
    }
}