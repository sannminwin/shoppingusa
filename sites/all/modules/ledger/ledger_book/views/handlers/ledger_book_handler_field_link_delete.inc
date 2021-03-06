<?php

/**
 * @file
 * Field handler to present a link to delete an book.
 */
class ledger_book_handler_field_link_delete extends ledger_book_handler_field_link {

  // Render the field.
  function render($values) {

    // Ensure the user has access to edit this book.
    $book = ledger_book_load($this->get_value($values, 'bid'));
    if (!ledger_book_access('update', $book)) {
      return;
    }

    // Assemble the link options.
    $options = array();
    if (!empty($this->options['destination'])) {
      $options['query']['destination'] = current_path();
    }

    // Load the link text, if it is defined in the options, otherwise just use "delete".
    $text = !empty($this->options['text']) ? $this->options['text'] : t('delete');

    // Return the text as a link to the book delete page.
    return l($text, 'ledger/book/' . $book->bid . '/delete', $options);
  }
}

