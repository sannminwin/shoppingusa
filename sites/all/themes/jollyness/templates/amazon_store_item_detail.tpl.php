<?php
/**
 * @file
 *   Amazon item detail template
 */
?>

<div id="" class="product-content">
<?php drupal_set_title((string)$amazon_item->ItemAttributes->Title); ?>
<div class="cart" style="float:left; margin-bottom:20px;">
<a href="<?php print url(AMAZON_STORE_PATH) ?>">Continue Shopping</a> or <a href='<?php print url(AMAZON_STORE_PATH . "/cart")?>'>See your cart</a>
</div>
<div class="clearfix"></div>


  <div class="row">
  
   <div class="product-image col-lg-5 col-md-5 col-sm-12">
  	<?php print theme('amazon_store_item_image', array('amazon_item' => $amazon_item, 'size' => 'LargeImage')); ?>
  </div>
  <div class="buying-detail col-lg-7 col-md-7 col-sm-12">
  
  	<div class="row">
  	<div class="title text-center col-md-12">
  	<h1><?php print (string)$amazon_item->ItemAttributes->Title ?></h1>
  	</div>
  	<div class="clearfix"></div>
 
  	<div class="buying-option col-lg-6 col-md-6 col-sm-12">
 		<?php if (!empty($listpriceformattedprice)) { print $listpriceformattedprice; }?>
                  <?php print theme('amazon_store_item_offers', array('amazon_item' => $amazon_item)); ?>
  	</div>
  	<div class="clearfix"></div>
  	<div class="amazon-detail">
  	<hr/>
  		<?php print theme('amazon_store_details_panel', array('item' => $amazon_item)); ?>
  	</div><!--Amazon Detail End-->
  	</div>
  </div>
 <div class="clearfix"></div>
 <hr/>
  <div class="similar-item col-lg-4 col-md-4 col-sm-12">
  	<h3>Similar Items</h3>
        <?php print theme('amazon_store_similar_items_panel', array('item' => $amazon_item)); ?>
  </div>
  <div class="review col-lg-8 col-md-8 col-sm-12">
  	
            <div class="product-details-wrap dexp_tab_wrapper">
                <ul class="nav nav-tabs" id="myTab">
                    <li class="">
                      <a data-toggle="tab" href="#Description">Description</a>
                    </li>
                     <li class="active">
                        <a data-toggle="tab" href="#Reviews">Reviews</a>
                    </li>
                </ul>

                <div class="tab-content" id="myTabContent">
                    <div id="Description" class="tab-pane fade">
                        <?php
                        if (!empty($editorialreview)) {
                          print $editorialreview;
                        }
                        ?>                                
                    </div><!-- col-tab pane -->

                    <div id="Reviews" class="tab-pane fade active in">
                        <!--<div class="col-lg-12 col-md-12 col-sm-12"> -->
                            <?php print theme('amazon_store_item_reviews_panel', array('item' => $amazon_item)); ?>
                        <!-- </div> --><!-- end col-12 -->
                        <div class="clearfix"></div>
                    </div><!-- end tab pane review -->
                </div><!-- end  tab content -->
                
           </div>
            
  </div>
  
</div>
</div>
    