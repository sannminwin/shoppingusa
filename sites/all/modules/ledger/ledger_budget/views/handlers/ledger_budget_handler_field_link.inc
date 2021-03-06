<?php

/**
 * @file
 * Field handler to present a link to a budget.
 */
class ledger_budget_handler_field_link extends views_handler_field {

  // Construct the handler.
  function construct() {

    // Inherit the parent's construction.
    parent::construct();

    // Add the budget id as an additional field to load to ensure that it is available in this handler.
    $this->additional_fields['bid'] = 'bid';
  }

  // Define the options.
  function option_definition() {

    // Inherit the parent's options.
    $options = parent::option_definition();

    // Provide a text field so users can change the text of the link.
    $options['text'] = array(
      'default' => '',
      'translatable' => TRUE
    );

    return $options;
  }

  // Define the options form.
  function options_form(&$form, &$form_state) {

    // Inherit the parent's options form.
    parent::options_form($form, $form_state);

    // Provide a text field so users can change the text of the link.
    $form['text'] = array(
      '#type' => 'textfield',
      '#title' => t('Text to display'),
      '#default_value' => $this->options['text'],
    );
  }

  // Add fields to the query.
  function query() {

    // Ensure the main table for this field is included.
    $this->ensure_my_table();

    // Include additional fields (like budget id defined in $this->construct())
    $this->add_additional_fields();
  }

  // Render the field.
  function render($values) {

    // Load the link text, if it is defined by the user, otherwise just use "view".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('view');

    // Load the budget id value.
    $bid = $this->get_value($values, 'bid');

    // Return the text as a link to the budget page.
    return l($text, 'ledger/budget/' . $bid);
  }
}

