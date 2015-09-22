<?php
/**
 * Implement hook_form()
 * @param $form
 * @param $form_state
 * @return mixed
 */
function file_s3_form($form, &$form_state){
    $form['write_file'] = array(
        '#type' => 'fieldset',
        '#title' => t('Write to a file'),
    );
    $form['write_file']['file'] = array(
        '#title' => t('File Upload'),
        '#type'  => 'file',
    );

    $form['write_file']['managed_submit_local'] = array(
        '#type' => 'submit',
        '#value' => t('Write managed local file'),
        '#submit' => array('file_s3_managed_sumit_local'),
    );
//    $form['write_file']['unmanaged_submit_local'] = array(
//        '#type' => 'submit',
//        '#value' => t('Write unmanaged local file'),
//        '#submit' => array('file_s3_unmanaged_submit_local'),
//    );

    $form['write_file']['managed_submit_s3'] = array(
        '#type' => 'submit',
        '#value' => t('Write managed s3 file'),
        '#submit' => array('file_s3_managed_submit_s3'),
    );

//    $form['write_file']['unmanaged_submit_s3'] = array(
//        '#type' => 'submit',
//        '#value' => t('Write unmanaged s3 file'),
//        '#submit' => array('file_s3_managed_submit_s3'),
//    );

    return $form;
}

function file_s3_create_directory($directory){
    if (!file_prepare_directory($directory, FILE_MODIFY_PERMISSIONS | FILE_CREATE_DIRECTORY)) {
        drupal_set_message(t('Failed to create %directory.', array('%directory' => $directory)), 'error');
        return FALSE;
    } else{
        return TRUE;
    }
}

function file_s3_managed_sumit_local($form, &$form_state){
    $uri = 'public://demo';
    if(file_s3_create_directory($uri)) {
        $file = file_save_upload('file', array(
            // Validate extensions.
            'file_validate_extensions' => array(),
        ));
        // If the file passed validation:
        if ($file) {
            // Move the file into the Drupal file system.
            if ($file = file_move($file, $uri)) {
                // Save the file for use in the submit handler.
                $file->status = FILE_STATUS_PERMANENT;
                // Save file status.
                file_save($file);
                // Set a response to the user.
                drupal_set_message(t('The form has been submitted and the image has been saved, filename: @filename.', array('@filename' => $file->filename)));
            }
            else {
                form_set_error('file', t("Failed to write the uploaded file to the site's file folder."));
            }
        }
        else {
            form_set_error('file', t('No file was uploaded.'));
        }
    }
}

function file_s3_managed_submit_s3($form, &$form_state){
    $uri = 's3://mbvdev/share/linh.vh';

    $file = file_save_upload('file', array(
        // Validate extensions.
        'file_validate_extensions' => array(),
    ));
    // If the file passed validation:
    if ($file) {
        // Move the file into the Drupal file system.
        if ($file = file_move($file, $uri)) {
            // Save the file for use in the submit handler.
            $file->status = FILE_STATUS_PERMANENT;
            // Save file status.
            file_save($file);
            // Set a response to the user.
            drupal_set_message(t('The form has been submitted and the image has been saved, filename: @filename.', array('@filename' => $file->filename)));
        }
        else {
            form_set_error('file', t("Failed to write the uploaded file to the site's file folder."));
        }
    }
    else {
        form_set_error('file', t('No file was uploaded.'));
    }

}

//function file_s3_unmanaged_submit_local($form, &$form_state){
//    $uri = 'public://demo';
//    if(file_s3_create_directory($uri)) {
//        $file = file_save_upload('file', array(
//            // Validate extensions.
//            'file_validate_extensions' => array(),
//        ));
//        // If the file passed validation:
//        if ($file) {
//            // Move the file into the Drupal file system.
//            if ($file = file_move($file, $uri)) {
//                // Set a response to the user.
//                drupal_set_message(t('The form has been submitted and the image has been saved, filename: @filename.', array('@filename' => $file->filename)));
//            }
//            else {
//                form_set_error('file', t("Failed to write the uploaded file to the site's file folder."));
//            }
//        }
//        else {
//            form_set_error('file', t('No file was uploaded.'));
//        }
//    }
//}