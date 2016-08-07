<?php
/**
 * @file
 *   Amazon item detail template
 */
?>

<div id="" class="product-content">
  <div class="row">
  
    <div class="shop-left col-lg-4 col-md-4 col-sm-12">
    	
          
         <div class="buy">
                <span class="price1-new">
                <?php if (!empty($listpriceformattedprice)) { print $listpriceformattedprice; }?>
                    <h3>Buying Options</h3>
                  <?php print theme('amazon_store_item_offers', array('amazon_item' => $amazon_item)); ?>
                </span>
        	</div>   
           <div class="similar-items">
                <h3>Similar Items</h3>
                  <?php print theme('amazon_store_similar_items_panel', array('item' => $amazon_item)); ?>
            </div>
     </div> 
    <div class="shop-right col-lg-8 col-md-8 col-sm-12">
    		<div class='title'>
                <h3><?php print (string)$amazon_item->ItemAttributes->Title ?></h3>    
   		</div>
	        <?php print theme('amazon_store_item_image', array('amazon_item' => $amazon_item, 'size' => 'LargeImage')); ?>    
       	 	    
           
      
          <!--  <div class="clearfix"></div> -->
            <?php if (!$has_sidebar) :?>
            <hr>
            <div class="product-details-wrap dexp_tab_wrapper">
                <ul class="nav nav-tabs" id="myTab">
                    <li class="">
                      <a data-toggle="tab" href="#Description">Description</a>
                    </li>
                    <li class="">
                        <a data-toggle="tab" href="#Details">Details</a>
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

                    <div id="Details" class="tab-pane fade">
                        <?php print theme('amazon_store_details_panel', array('item' => $amazon_item)); ?>                               
                    </div><!-- col-tab pane -->
                    <div id="Reviews" class="tab-pane fade active in">
                        <!--<div class="col-lg-12 col-md-12 col-sm-12"> -->
                            <?php print theme('amazon_store_item_reviews_panel', array('item' => $amazon_item)); ?>
                        <!-- </div> --><!-- end col-12 -->
                        <div class="clearfix"></div>
                    </div><!-- end tab pane review -->
                </div><!-- end  tab content -->
                
            </div>
            <?php endif; ?>
       </div>
       <hr>