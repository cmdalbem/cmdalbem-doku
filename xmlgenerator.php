<?php

define("MEDIA_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/lib/exe/fetch.php?media=");
define("PROJECTS_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/data/projects/");
define("PROJECTS_PATH","/home/grad/cmdalbem/public_html/dokuwiki/data/projects/");
define("MEDIA_VIEWER_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/lib/exe/detail.php?id=projects_courses&media=");

function dirList ($directory)
# thanks to http://www.laughing-buddha.net/jon/php/dirlist/
{
    // create an array to hold directory list
    $results = array();

    // create a handler for the directory
    $handler = opendir($directory);

    // keep going until all files in directory have been read
    while ($file = readdir($handler)) {

        // if $file isn't this directory or its parent,
        // add it to the results array
        if ($file != '.' && $file != '..')
            $results[] = $file;
    }

    // tidy up: close the handler
    closedir($handler);

    // done!
    return $results;

}

function readFromFile($path)
{
	$data;

	if (file_exists($path))
	{
		$data = 'ERROR! Empty file.';
	
		$fh = fopen($path, 'r');
		$data = fread($fh, filesize($path));
		fclose($fh);
	}

	return utf8_encode($data);
}

function listProjects()
{
	$dirs = dirList(PROJECTS_PATH);
	sort($dirs);

	foreach ($dirs as $dir)
	{
		$areaPath = PROJECTS_PATH . "/" . $dir;

		if( file_exists( $areaPath . "/" . "name.txt" ) )
			$project = readFromFile($areaPath . "/" . "name.txt");
		else
			$project = "$dir";

		// text generation
		printContent($dir, $project);

		$projects = dirList( $areaPath );
		sort($projects);

		foreach ($projects as $project)
		{
			if( is_dir("$areaPath/$project") )
				listSubProjects( $dir , $project, 0 );
		}

		echo "</ul>";
	}
}

function output( $string, $xmlfile )
{
	fwrite($xmlfile, $string);
}

function breakline( $xmlfile )
{
	output( "\n", $xmlfile );
}

function listDownloads( $path,$dir )
{
	$file = fopen($path, 'r');
	$i = 0;

	while ( !feof($file) ) {
		$dw = fgets($file, 4096);
		
		$downloads[$i] = $dw;
		$i++;
	}
		
	fclose($file);

	return $downloads;
}

function printContent( $dir, $project )
{
	$path = PROJECTS_PATH . $dir;

	$hasTitle = file_exists( $path . "/" . "title.txt" );
	$hasText = file_exists( $path . "/" . "text.txt" );
	$hasImage = file_exists( $path . "/" . "img.txt" );
	$hasDownloads = file_exists( $path . "/" . "downloads.txt" );

	$xmlfile = fopen($path . "/content.xml", 'w');

	output("<?xml version=\"1.0\" encoding=\"UTF-8\"?>", $xmlfile);
	breakline($xmlfile);

	output( "<content>", $xmlfile );
	breakline($xmlfile);

	output( "<name>" . $project . "</name>", $xmlfile );
	breakline($xmlfile);

	output( "<title>", $xmlfile );
	if( $hasTitle )
		output( readFromFile($path . "/" . "title.txt"), $xmlfile );
	output( "</title>", $xmlfile );
	breakline($xmlfile);

	output( "<text>", $xmlfile );
	if( $hasText  )
		output( "<![CDATA[" . readFromFile($path . "/" . "text.txt") . "]]>", $xmlfile);
	output( "</text>", $xmlfile );
	breakline($xmlfile);

	output( "<image>", $xmlfile );
	if( $hasImage )
		output( readFromFile($path . "/" . "img.txt"), $xmlfile);
	output( "</image> ", $xmlfile );
	breakline($xmlfile);

	output( "<downloads>", $xmlfile );
	breakline($xmlfile);
	if( $hasDownloads )
	{
		$downloads = listDownloads($path . "/" . "downloads.txt", $dir);
		for($i=0; $i<count($downloads); $i++)
		{
			output( "<download>" . $downloads[$i] . "</download>", $xmlfile );
			breakline($xmlfile);
		}
	}
	output( "</downloads>", $xmlfile );
	breakline($xmlfile);


	output( "</content>", $xmlfile );
	breakline($xmlfile);

	//output( "___________________________\n", $xmlfile );
	//breakline($xmlfile);

	fclose($xmlfile);
}

function listSubProjects($dir,$project,$level)
{
	$dir = $dir . "/" . $project;
	$projPath = PROJECTS_PATH . $dir;
	$projects = dirList( utf8_encode($projPath) );
	sort($projects);

	// create this project's link and list
	if( count($projects) == 0 ) //for empty projetcs
	{
		/*echo "<li><a href=\"#\">";
		echo utf8_encode($project);
		echo "</a></li>";

		echo "<ul class=\"interactive\">";
		printContent( $dir ); //prints description and/or text
		echo "</ul>";*/
	}
	else //normal project with content
	{
		$projectName = "";

		if( file_exists( $projPath . "/" . "name.txt" ) )
			$projectName = readFromFile($projPath . "/" . "name.txt");
		else
			$projectName = utf8_encode($project);
		
		printContent( $dir, $projectName ); //prints description and/or text

		foreach ($projects as $proj) // subprojects iteration
		{
			if( is_dir("$projPath/$proj") )
				listSubProjects( $dir, $proj, $level+1 );
		}
	}
}

echo "This script will navigate through the file system and generate xml files encapsulating all content of every project.<br>";
echo "(...)<br>";
listProjects();
echo "All done.<br>";

?>