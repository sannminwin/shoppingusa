<?php
/**
 * @file
 * 	Contents of amazon_store_search_block
 */
 ?>
 <div class="go-to-cart" style="float:right;">
	
<a href='<?php print url(AMAZON_STORE_PATH . "/cart") ?>'>
<i class="fa fa-shopping-cart" aria-hidden="true"></i>
&nbsp;Go to your cart</a>
</div>
<div class="row amazon-search-result">
<div class="search-form-wrapper"
		<div class="search-form col-md-12">
		<?php
		  if (variable_get('amazon_store_show_searchform',TRUE)) {
		    // Argument specifies how wide the keywords textfield should be, in chars.
		    $form = drupal_get_form('amazon_store_search_form', 50);
		    print drupal_render($form);
		  }
		?>
	</div><!--search-form-end-->
</div>
 