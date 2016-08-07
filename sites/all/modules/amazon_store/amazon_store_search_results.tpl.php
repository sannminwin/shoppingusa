<?php
/**
 * @file
 *   Template file for the searchresults page (/amazon_store)
 *
 */

?>
<div class="row">
		
	<?php if (!empty($results->Item)): ?>
	<div class="sort-form col-md-3">	
		<?php
		if (variable_get('amazon_store_show_sort_form',TRUE) && (int)$results->TotalResults > 1) {
 		 	$form = drupal_get_form('amazon_store_sort_form');
  		print drupal_render($form);
		}
		?>		
		
	</div><!--sort-form-->
</div><!--search form wrapper end-->
	
	
	<div class="clearfix"></div>
	
	<div class="left-sidebar col-md-2">
		<div class="search-sets narrow-by">
			<?php
			if (variable_get('amazon_store_show_narrowby_form',TRUE) && !empty($results->SearchBinSets) && (int)$results->TotalResults > 1) {
  			$form = drupal_get_form('amazon_store_searchbin_sets_form', $results->SearchBinSets);
  			print drupal_render($form);
			}?>
		</div>
	</div><!-- left-sidebar-end-->
	
	<div class="right-content col-md-10">
		<?php if  (isset($Keywords) && isset($SearchIndex) && count($SearchIndex)) : ?>
		<h3>Your search for <?php print "$Keywords in $SearchIndex" ?></h3>
		<?php endif; ?>
	<div class="row">
		<?php $i=0;
		foreach ($results->Item as $result):
		if ($result->OfferSummary->TotalNew == 0 && empty($result->Variations->Item)) {
	  	continue;
		}
		$asin = (string)$result->ASIN;
		module_load_include('inc', 'amazon_store', 'amazon_store.pages');
		$form = drupal_get_form('amazon_store_addcart_form',(string)$result->ASIN);
		?>
		<hr/>
		<!--  BEGIN ITEM PROCESSING -->
		<div class="amazon-image col-md-3">
				<?php if (!empty($result->LargeImage)) : ?> <a rel="nofollow"
				href="<?php print $result->LargeImage->URL; ?>" class="image-responsive"
				title="<?php print $result->ItemAttributes->Title ?>"> <img
				src="<?php print $result->MediumImage->URL ?>"
				alt="Image of <?php print $result->ItemAttributes->Title ?>"
				class="product-image img-responsive" /></a> 
				<?php else: ?>
        		<?php print theme('image', array('path' => "$directory/images/no_image_med.jpg")); ?>
       			<?php endif; ?>
       		</div><!--Amazon Image End-->
		<div class="col-md-9">
			<h2 class="title"><a rel="nofollow"
				href="<?php print url(AMAZON_STORE_PATH ."/item/{$result->ASIN}") ?>"> <?php print $result->ItemAttributes->Title ?></a>
			</h2>
			<div class="manufacturer">
				<?php if (!empty($result->ItemAttributes->Manufacturer)){
				  print theme('amazon_store_search_results_manufacturer', array('manufacturer' => 				(string)$result->ItemAttributes->Manufacturer));

				}?>
			</div>
			<div class="price">
				<?php print drupal_render($form); ?>
			</div>
			
		</div><!--amazon-content-->
		

		<!--  END ITEM PROCESSING -->
		<div class="clearfix"></div>
		
		<?php endforeach; ?>
	
	</div><!--right-content-row-->
	
		
	</div><!-- right-content -->
	<div class="clearfix"></div>
	<div class="row"> 
		<div class="amazon-pager col-md-12" align="center">
				<?php print amazon_store_search_results_pager($results); ?>
		</div><!--amazon-pager-end-->
		<?php endif; ?>
	</div> <!--amazon-pager-row_end-->
</div><!-- amazon-search-result -->
