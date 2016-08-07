<?php

/**
 * @file
 * Theme the 'amazon-item' 'details' style.
 * Many, many available variables. See template_preprocess_amazon_item().
 * Everything that gets put into $variables there is available.
 */
?>
<div class="<?php print $classes; ?>">
<?php if (!empty($invalid_asin)) { print "<div class='invalid_asin'>This item is no longer valid on Amazon.</div>"; } ?>

<div class="image facebook-image col-md-6">
	<?php if (!empty($largeimage)): ?>
  		<?php print $largeimage; ?>
	<?php endif; ?>
</div>
<div class="detail col-md-6">

<div class="title">
<h1>
<?php print l($title, $detailpageurl, array('html' => TRUE, 'attributes' => array('rel' => 'nofollow'))); ?>
</h1>
</div>
<p>
<div class="price">
	<span class="label"><?php print t('List Price'); ?></span>
	<span class="list-price"><del><?php if (!empty($listpriceformattedprice)) { print $listpriceformattedprice; }?></del></span>
	<span class="label"><?php print t('Discount Price'); ?></span>
	<span class="amazon-price"><?php if (!empty($amazonpriceformattedprice)) { print $amazonpriceformattedprice; }?></span>
</div>
<div class="review">
	<span class="label"><?php print t('Review'); ?></span><br/>
	<span><?php if (!empty($editorialreview)) { print $editorialreview; }?></span>
</div>
</p>
</div>
