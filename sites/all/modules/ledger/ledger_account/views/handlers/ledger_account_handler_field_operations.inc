<?php

/**
 * @file
 * Field handler to present a list of links to account operations.
 */
class ledger_account_handler_field_operations extends ledger_account_handler_field_link {

  // Alter the field options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent form.
    parent::options_form($form, $form_state);

    // Unset the 'text' field that was defined by the parent class.
    unset($form['text']);
  }

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this account.
    $account = ledger_account_load($this->get_value($values, 'aid'));
    if (!ledger_account_access('update', $account)) {
      return;
    }

    // Assemble the link options.
    $options = array();
    if (!empty($this->options['destination'])) {
      $options['query']['destination'] = current_path();
    }

    // Define the operations to include.
    $ops = array(
      l(t('Edit'), 'ledger/account/' . $account->aid . '/edit', $options),
      l(t('Delete'), 'ledger/account/' . $account->aid . '/delete', $options),
    );

    // Assemble the list of operations.
    return implode(' | ', $ops);
  }
}

