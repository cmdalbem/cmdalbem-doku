<?php
/**
 * mmClean DokuWiki Template
 *
 * @author Marcin Mierzejewski <marcin.mierzejewski@zenzire.com>
 */

 require_once(dirname(__FILE__).'/tpl_functions.php');
 @include(dirname(__FILE__).'/header.php');
?>
<body>
<?php /*old includehook*/ @include(dirname(__FILE__).'/topheader.html')?>
<div class="page" style="width: <?php echo tpl_img_getTag('File.Width')+40; ?>px;">
<div class="container">

  <?php html_msgarea()?>

  <?php flush()?>

      <div class="content" style="width: <?php echo tpl_img_getTag('File.Width')+10; ?>px; padding-top: 15px;">
      <center>
  <img src="<?php echo ml($IMG);?>" width="<?php echo tpl_img_getTag('File.Width')?>" height="<? echo tpl_img_getTag('File.Height')?>">
  <!-- <br><br>Back to <?php echo tpl_pagelink($ID);?><br><br> -->
  <br><br><p>&larr; <?php echo $lang['img_backto']?> <?php tpl_pagelink($ID)?></p>
      </center>
      </div>
    </div>

  <div class="clearer">&nbsp;</div>
  <?php flush()?>
</div>

<?php tpl_indexerWebBug();?>

</body>
</html>

