a:17:{i:0;a:3:{i:0;s:14:"document_start";i:1;a:0:{}i:2;i:0;}i:1;a:3:{i:0;s:6:"header";i:1;a:3:{i:0;s:8:"projects";i:1;i:1;i:2;i:1;}i:2;i:1;}i:2;a:3:{i:0;s:12:"section_open";i:1;a:1:{i:0;i:1;}i:2;i:1;}i:3;a:3:{i:0;s:6:"p_open";i:1;a:0:{}i:2;i:1;}i:4;a:3:{i:0;s:9:"linebreak";i:1;a:0:{}i:2;i:24;}i:5;a:3:{i:0;s:5:"cdata";i:1;a:1:{i:0;s:1:"
";}i:2;i:26;}i:6;a:3:{i:0;s:4:"html";i:1;a:1:{i:0;s:109:"
 
  <p> 
  <a href="#" class="open">Expand all</a> / 
  <a href="#" class="close">Collapse all</a>
  </p>
 
";}i:2;i:33;}i:7;a:3:{i:0;s:7:"p_close";i:1;a:0:{}i:2;i:149;}i:8;a:3:{i:0;s:6:"p_open";i:1;a:0:{}i:2;i:149;}i:9;a:3:{i:0;s:3:"php";i:1;a:1:{i:0;s:86:" 
include("/home/grad/cmdalbem/public_html/dokuwiki/lib/utils.php");
listProjects(); 
";}i:2;i:158;}i:10;a:3:{i:0;s:7:"p_close";i:1;a:0:{}i:2;i:250;}i:11;a:3:{i:0;s:6:"p_open";i:1;a:0:{}i:2;i:250;}i:12;a:3:{i:0;s:4:"html";i:1;a:1:{i:0;s:649:"
<script type="text/javascript" src="http://code.jquery.com/jquery-latest.pack.js"></script>
<script>	
var $j = jQuery.noConflict();

    $j('a.open').click(function(){
      $j('li').children('div').slideDown('10')
      .parent().removeClass('closed').addClass('open');
      return false; 
    });

    $j('a.close').click(function(){
      $j('li').children('div').slideUp('10')
      .parent().removeClass('open').addClass('closed');
      return false;
    });
	  
    $j('li a.expand').click(function(){
      $j(this).next().slideToggle('100')
      .parent().toggleClass('open').toggleClass('closed');
      return false;
    });
</script>
";}i:2;i:259;}i:13;a:3:{i:0;s:5:"cdata";i:1;a:1:{i:0;s:0:"";}i:2;i:915;}i:14;a:3:{i:0;s:7:"p_close";i:1;a:0:{}i:2;i:915;}i:15;a:3:{i:0;s:13:"section_close";i:1;a:0:{}i:2;i:915;}i:16;a:3:{i:0;s:12:"document_end";i:1;a:0:{}i:2;i:915;}}