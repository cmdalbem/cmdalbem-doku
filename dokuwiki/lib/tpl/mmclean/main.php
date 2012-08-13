<?php
/**
 * @author Cristiano Medeiros Dalbem (adapted from zenzire)
 */

 require_once(dirname(__FILE__).'/tpl_functions.php');
 @include(dirname(__FILE__).'/header.php');
?>
<body>
<?php @include(dirname(__FILE__).'/topheader.html')?>
<div class="page">
     <div class="container">

<!-- _________________________________________________________Start of sliding panel code -->
<div class="panel">
<!-- <form name="htmlform" method="post" action="mailto:ninja.dalbem@gmail.com?subject=Feedback for ~cmdalbem.">//action="lib/tpl/mmclean/html_form_send.php"> -->

<form method="post" action="mailto:ninja.dalbem@gmail.com?subject=Feedback on ~cmdalbem." enctype="text/plain">
Warnings of broken links and typos, corrections, critics or compliments, its all very welcome! <!-- <img src="http://inf.ufrgs.br/~cmdalbem/dokuwiki/lib/exe/fetch.php?media=smile.png"> -->
<br><br>
<textarea required name="message" style="resize:vertical" maxlength="10000" rows="5" placeholder="Enter your message here..."></textarea><br>
<input type="submit" value="Send">
</form>
</div>
<a class="trigger" href="#">Feedback?</a>

<script type="text/javascript" src="http://code.jquery.com/jquery-latest.pack.js"></script>
<script>	
	var oddClick = true;
      $(".trigger").click(function(){
		$(this).animate({width: (oddClick) ? "+=97px" : "-=97px"},'fast').toggleClass("active");
		$(".panel").toggle("fast");
		oddClick = !(oddClick);
		return false;
	});

</script>
<!-- _________________________________________________________End of sliding panel code -->

    <div class="header">
		<!--<b class="rtop"><b class="r1"></b><b class="r2"></b><b class="r3"></b><b class="r4"></b></b>-->
      <div class="logo">
				   			
<br>

<?php tpl_link(wl(),$conf['title'],'name="top" accesskey="h" title="[ALT+H]"') ?>
				
				<?php if ( true == $conf['tpl_mmClean']['searchForm'] ) { ?>
					<div class="searchform" style="margin-top: 60px;"> <?php tpl_searchform() ?> </div>
				<?php } ?>
				<br><br><br><br><br><br><br>
				<div class="topbar">
					<?php tpl_menu1(); ?>
			      </div>
      </div>
  		<!--<b class="rbottom"><b class="r4"></b><b class="r3"></b><b class="r2"></b><b class="r1"></b></b>-->

    </div>
    <?php /*old includehook*/ @include(dirname(__FILE__).'/header.html')?>

  <?php flush()?>

  <?php /*old includehook*/ @include(dirname(__FILE__).'/pageheader.html')?>
  <?php
    if ( !tpl_isMenu2() )
    { 
  ?>
      <div class="content">
  			<?php html_msgarea()?>
        <?php tpl_content()?>
      </div>
  <?php 
    } 
    else 
    { 
  ?>
      <div class="content_with_sidebar">
        <?php tpl_content()?>
  		<?php html_msgarea()?>
      </div>
      <div class="sidebar">
      <b class="rtop"><b class="r1"></b><b class="r2"></b><b class="r3"></b><b class="r4"></b></b>
      <?php tpl_menu2() ?>
      <b class="rbottom"><b class="r4"></b><b class="r3"></b><b class="r2"></b><b class="r1"></b></b>
      </div>
  <?php } ?>

  <div class="clearer">&nbsp;</div>

  <?php flush()?>

  <?php if ($INFO['perm'] > AUTH_READ || true == $conf['tpl_mmClean']['wikiBar']  ) { ?>
  <div class="stylefoot">
<table width=100%><tr>  
    <div class="meta">
       <?php tpl_pageinfo()?>
       <!-- <?php tpl_userinfo()?> -->
	|
	<?php tpl_bottombar(); ?>
    </div>
</tr></table>
    <?php /*old includehook*/ @include(dirname(__FILE__).'/pagefooter.html')?>
  </div>
  <?php } ?>

<?php /*old includehook*/ @include(dirname(__FILE__).'/footer.php')?>

</div>

</div>

<?php tpl_indexerWebBug();?>

</body>
</html>
