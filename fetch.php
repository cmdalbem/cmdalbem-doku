<?php
//echo 'Hello ' . ($_GET["id"]);

$dbname='downloads.db';
$t ="downloads";

//$dbhandle= new SQLiteDatabase($dbname, 0666, $err);
$dbhandle = sqlite_open($dbname, 0666, $error);
if ($err)  exit($err);

$id = $_GET["id"];

// get file on the database
$query = "SELECT count, path FROM $t WHERE id=$id";
$result = sqlite_query($dbhandle, $query);
$row = sqlite_fetch_array($result, SQLITE_ASSOC);

// update the download count
$query = "UPDATE $t SET count=" . ($row['count']+1) . " WHERE id=$id";
sqlite_query($dbhandle, $query);

$path = $row['path'];
$count = $row['count']+1;

//echo "File: " . path . "<br>";
//echo "Downloads: " . count . "<br>";

header("Location: " . $path);
exit;

?>