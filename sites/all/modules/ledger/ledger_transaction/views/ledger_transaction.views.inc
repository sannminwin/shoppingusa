<?php

/**
 * @file
 * Ledger Transaction Views data.
 */

/**
 * Implements hook_views_data_alter().
 */
function ledger_transaction_views_data_alter(&$data) {

  // Replace the transaction description field handler with one that provides a "Link this field to" option.
  $data['ledger_transaction']['description']['field']['handler'] = 'ledger_transaction_handler_field';

  // Add a field for transaction view link.
  $data['ledger_transaction']['view_transaction'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the transaction.'),
      'handler' => 'ledger_transaction_handler_field_link',
    ),
  );

  // Add a field for transaction edit link.
  $data['ledger_transaction']['edit_transaction'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the transaction.'),
      'handler' => 'ledger_transaction_handler_field_link_edit',
    ),
  );

  // Add a field for transaction delete link.
  $data['ledger_transaction']['delete_transaction'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the transaction.'),
      'handler' => 'ledger_transaction_handler_field_link_delete',
    ),
  );

  // Add a field for common transaction operations. This is just a combination of Edit, and Delete fields above.
  $data['ledger_transaction']['transaction_ops'] = array(
    'field' => array(
      'title' => t('Operations'),
      'help' => t('Links to various transaction operations.'),
      'handler' => 'ledger_transaction_handler_field_operations',
    ),
  );
}

