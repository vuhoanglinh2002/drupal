<?php
/**
 * @author baonguyen
 *
 */

// List system type pages
function mbv_support_list_entities() {
 $header = array (
   t('Name' ),
   t('Operations' )
 );

 $rows = array ();
 foreach ( mbv_issue_types() as $type => $system_type ) {

  $links = menu_contextual_links('mbv_support', 'admin/structure/mbv_support', array (
    $type
  ) );

  $theme_url = '';
  $rows [] = array (
    theme('mbv_issue_types_admin_overview', array (
      'issue_types' => $system_type
    ) ),
    theme('links', array (
      'links' => $links,
      'attributes' => array (
        'class' => 'links inline operations'
      )
    ) )
  );
 }

 if (empty($rows )) {
  $rows [] = array (
    array (
      'data' => t('There are no system types defined by enabled modules. Click ' . l('here', '?q=admin/modules' . '#' . 'edit-modules-mbv', array (
        'external' => TRUE
      ) ) . ' to enable module.' ),
      'colspan' => 2
    )
  );
 }

 return array (
   '#theme' => 'table',
   '#header' => $header,
   '#rows' => $rows
 );
}