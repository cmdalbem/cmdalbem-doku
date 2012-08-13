<?php

$xml = simplexml_load_file("dokuwiki/data/projects/test/quasares/observatorio/content.xml");
if(!$xml)
	echo "Couldn't open xml file.";

echo $xml->name . "<br>";
echo $xml->title . "<br>";
echo $xml->description . "<br>";
echo $xml->image . "<br>";
foreach($xml->downloads->download as $download)
{
	echo $download . "<br>"; 
}

echo "#######################<br>";

?>