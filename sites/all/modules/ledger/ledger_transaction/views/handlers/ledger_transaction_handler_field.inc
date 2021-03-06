<?php

/**
 * @file
 * Contains the basic transaction field handler.
 */

/**
 * Field handler to provide simple renderer that allows linking to a transaction.
 */
class ledger_transaction_handler_field extends views_handler_field {

  // Initialize the handler.
  function init(&$view, &$options) {

    // Inherit the parent initialization.
    parent::init($view, $options);

    // If the transaction is going to be linked to it's view page, we need to load the transaction id value so it's available to this handler.
    if ($this->options['link_to_transaction'] == 'view') {
      $this->additional_fields['tid'] = 'tid';
    }
  }

  // Define the options.
  function option_definition() {

    // Inherit the parent option definition.
    $options = parent::option_definition();

    // Add an option for displaying the transaction as a link to it's view page.
    $options['link_to_transaction'] = array('default' => 'none');

    return $options;
  }

  // Define the options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent options form.
    parent::options_form($form, $form_state);

    // Add an option for displaying the transaction as a link to it's view page.
    $form['link_to_transaction'] = array(
      '#type' => 'radios',
      '#title' => t('Link this field to'),
      '#description' => t('If the transaction view page is selected, this will override any other links you have set.'),
      '#options' => array(
        'none' => t('Nothing, unless specified in <em>Rewrite results</em> below'),
        'view' => t('The transaction view page'),
      ),
      '#default_value' => $this->options['link_to_transaction'],
    );
  }

  // Render the field.
  function render($values) {

    // Load the value.
    $value = $this->get_value($values);

    // Return a rendered link.
    return $this->render_link($this->sanitize_value($value), $values);
  }

  // Render a link.
  function render_link($data, $values) {

    // If the 'link_to_transaction' option is set to 'view', and the sanitized data is not empty...
    if ($this->options['link_to_transaction'] == 'view' && $data !== NULL && $data !== '') {

      // Load the transaction id.
      $tid = $this->get_value($values, 'tid');

      // Alter the options of the link.
      $this->options['alter']['make_link'] = TRUE;
      $this->options['alter']['path'] = 'ledger/transaction/' . $tid . '?destination=' . current_path();
    }

    return $data;
  }
}

