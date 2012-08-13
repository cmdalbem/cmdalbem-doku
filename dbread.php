<?php
echo "SQLite version " . sqlite_libversion() . "<br>";
echo "PHP version " . phpversion() . "<br>";


$dbname='downloads.db';
$t ="downloads";

//$dbhandle= new SQLiteDatabase($dbname, 0666, $err);
$dbhandle = sqlite_open($dbname, 0666, $error);
if ($err)  exit($err);

/* 

$query = "DROP TABLE $t";
sqlite_query($dbhandle, $query);

$query = "CREATE TABLE $t (id INTEGER PRIMARY KEY,count INTEGER,path TEXT)";
sqlite_query($dbhandle, $query);

$count=0;
$path="http://inf.ufrgs.br/~cmdalbem/dokuwiki/data/projects/Ciencia%20da%20Computacao/Eletivas/Categorias/Artigo%20Final/paper.pdf";

for($i=0; $i<5; $i++)
{
	$query = "INSERT INTO $t(id, count, path) VALUES ('$i', '$count', '$path')";
	sqlite_query($dbhandle, $query);	
}*/

$query = "SELECT id, count, path FROM $t ORDER BY count DESC";
$result = sqlite_array_query($dbhandle, $query, SQLITE_ASSOC);

echo "DATABASE:<br><br>";
foreach( $result as $row )
{
	print_r($row);
	echo "<br>";
}

/*$query = "SELECT count FROM $t WHERE id=3";
$result = sqlite_query($dbhandle, $query);
$row = sqlite_fetch_array($result, SQLITE_ASSOC);
print_r($row);

$query = "UPDATE $t SET count=" . ($row[count]+1) . "WHERE id=3";
$result = sqlite_query($dbhandle, $query);*/
	

/*echo "Found " . count($results) . " results.<br>";

for($i=0; $i<count($results); $i++)
{
	$arr = $results[i];

	if($results)
	{
	   $id = $arr['ID'];
	   $id = $arr['name'];	   
	}  

	echo "id: " . $id . "<br>";
	echo "name: " . $name . "<br>";
}*/

/*$query = "SELECT post_title, post_content, post_author, post_date, guid FROM $t";
$results = $base->arrayQuery($query, SQLITE_ASSOC);

echo "Found " . count($results) . " results.<br>";



for($i=0; $i<count($results); $i++)
{
	$arr = $results[i];

	if($results)
	{
	   $title = $arr['post_title'];
	   $content = $arr['post_content']; 
	   $user = $arr['post_author'];
	   $date = $arr['post_date'];
	   $url = $arr['guid'];
	}  

	echo "Title: " . $title;
	echo "<br>";
	echo $content;
	echo "<br>";
	echo "by" . $user . "on" . $date;
	echo "<br>";
}*/

?>