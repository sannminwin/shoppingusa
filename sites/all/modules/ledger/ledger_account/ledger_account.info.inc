<?php

/**
 * @file
 * Ledger Account property info
 */

/**
 * Implementations hook_entity_property_info().
 */
function ledger_account_entity_property_info() {
  $info = array();

  // Add meta-data about the account properties.
  $account = &$info['ledger_account']['properties'];

  $account['aid'] = array(
    'type' => 'integer',
    'label' => t('Account ID'),
    'description' => t('The unique ID of the ledger account.'),
    'setter permission' => 'administer ledger',
    'schema field' => 'aid',
  );
  $account['parent'] = array(
    'type' => 'ledger_account',
    'label' => t('Parent Account'),
    'description' => t('The parent account in the ledger.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'pid',
  );
  $account['book'] = array(
    'type' => 'ledger_book',
    'label' => t('Book'),
    'description' => t('The book that the account is assigned to.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'bid',
  );
  $account['name'] = array(
    'label' => t('Name'),
    'description' => t('The name of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'required' => TRUE,
    'schema field' => 'name',
  );
  $account['description'] = array(
    'label' => t('Description'),
    'description' => t('A brief description of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'schema field' => 'description',
  );
  $account['type'] = array(
    'type' => 'token',
    'label' => t('Account type'),
    'description' => t('The type of the account.'),
    'setter callback' => 'entity_property_verbatim_set',
    'setter permission' => 'administer ledger',
    'options list' => 'ledger_account_type_get_names',
    'required' => TRUE,
    'schema field' => 'type',
  );

  return $info;
}

