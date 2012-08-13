<?php

define("BASE_URL","http://inf.ufrgs.br/~cmdalbem/");
define("MEDIA_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/lib/exe/fetch.php?media=");
define("PROJECTS_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/data/projects/");
define("PROJECTS_PATH","/home/grad/cmdalbem/public_html/dokuwiki/data/projects/");
define("MEDIA_VIEWER_URL","http://inf.ufrgs.br/~cmdalbem/dokuwiki/lib/exe/detail.php?id=projects_courses&media=");


############################################
# QUOTES

class QuoteDB
{
	public static $quotes = array(
	array("A posse de qualquer coisa começa na mente.","Bruce Lee"),
	array("O Muad'Dib aprendeu rapidamente porque seu treinamento básico era em como aprender. Sua primeira lição foi a confiança básica em sua capacidade de compreender. É chocante descobrir quantas pessoas não acreditam em sua capacidade de aprender, e quantas mais acreditam que o aprendizado seja algo difícil. Muad'Dib sabia que cada experiência carrega sua lição.","Frank Herbert"),
	array("É engraçado. A gente nunca devia contar nada a ninguém. Mal acaba de contar, a gente começa a sentir saudade de todo mundo.","J. D. Salinger"),
	array("Você deve ser a própria mudança que deseja ver no mundo.","Gandhi"),
	array("As palavras são assim, disfarçam muito, vão-se juntando umas com as outras, parece que não sabem aonde querem ir, e de repente, por causa de duas ou três, ou quatro que de repente saem, simples em si mesmas, um pronome pessoal, um advérbio, um verbo, um adjectivo, e aí temos a comoção a subir irresistível à superfície da pele e dos olhos, a estalar a compostura dos sentimentos, às vezes são os nervos que não podem aguentar mais, suportaram muito, suportaram tudo, era como se levassem uma armadura, diz-se. A mulher do médico tem nervos de aço, e afinal a mulher do médico está desfeita em lágrimas por obra de um pronome pessoal, de um advérbio, de um verbo, de um adjectivo, meras categorias gramaticais, meros designativos, como o são igualmente as duas mulheres mais, as outras, pronomes indefinidos, também eles chorosos, que se abraçam à da oração completa, três graças nuas sob a chuva que cai.","José Saramago"),
	array("Muito daquilo que tem sido chamado de religião carrega uma atitude inconsciente de hostilidade com relação à vida. A verdadeira religião deve ensinar que a vida é cheia de prazeres agradáveis ao olhar de Deus, que o conhecimento sem ação é vazio. Todos os homens devem perceber que o ensinamento de uma religião através de regras, mecanicamente, é uma farsa. O ensinamento adequado é facilmente reconhecido. Podemos reconhecê-lo sem dúvida quando ele nos desperta a sensação de termos ouvido algo que sempre soubemos.","Frank Herbert"),
	array("Aquele que deseja continuamente 'elevar-se' deve esperar um dia pela vertigem.","Milan Kundera"),
	array("(...) será que um acontecimento não se torna mais importante e carregado de significados quando depende de um número maior de circunstâncias fortuitas? Só o acaso pode ser interpretado como uma mensagem. Aquilo que acontece por necessidade, aquilo que é esperado e que se repete todos os dias, não é senão uma coisa muda. Somente o acaso tem voz.","Milan Kundera"),
	array("Aquilo que o 'eu' tem de único se esconde exatamente naquilo que o ser humano tem de inimaginável. Só podemos imaginar aquilo  que é idêntico em todos seres humanos, aquilo que lhes é comum. O 'eu' individual é aquilo que se distingue do geral, portante  aquilo que não se deixa adivinhar nem calcular antecipadamente, aquilo que precisa ser desvelado, descoberto e conquistado do  outro.","Milan Kundera"),
	array("Il mio silenzio, non ha altro frutto, che farmi sentire quanto mi resta da imparare.","La Quiete"),
	array("Olhe para mim, Pequeno Igor, os machucados desaparecem, assim como os ódios, e assim como a sensação de que tudo que você recebe na vida é só o que você conquistou.","Jonathan Safran Foer"),
	array("Ao escrever nós recebemos segundas chances.","Jonathan Safran Foer"),
	array("Quanto mais você ama uma pessoa, concluíra ele, mais difícil é dizer isso a ela. Ficava surpreso com o fato de estranhos não se pararem na rua pra dizer eu amo você.","Jonathan Safran Foer"),
	array("O homem tenta elaborar para si mesmo, do modo que melhor lhe pareça, uma descrição simplificada e inteligível do mundo.  Depois, tenta até certo ponto substituir o mundo da experiência por esse universo por ele construído, para poder dominar toda  a natureza... Ele faz desse universo e da sua construção o centro de sua vida emocional, para encontrar, assim, a paz e a  serenidade que não consegue dentro dos limites a ele impostos pelo turbilhão da experiência pessoal. O objetivo último a ser  atingido é chegar àquelas leis elementares universais a partir das quais o universo foi construído através de pura dedução.  Não há um caminho lógica que conduza até essas leis; apenas a intuição, baseada no conhecimento afetivo da experiência, pode  conduzir a elas...","Albert Einstein"),
	array("We can exist in ambiguity, but it means the deepest loneliness.","Ebullition Records(?)"),
	array("Ele [Stephen Hawking] acredita intensamente nas possiblidades quase infininitas da mente humana. Temos de descobrir o que não podemos saber antes de sabermos que n que esse pensamento não deve ser restringido de forma alguma. Por que razão não devemos continuar a pensar sobre o impensável? Alguém tem de começar.","Mãe de Stephen Hawking"),
	array("Dizem que a felicidade não é uma palavra, nem um sentimento, tampouco. Seria, digamos, um adjetivo dos olhos.","Machado de Assis"),
	array("Mas com o dia avançando, as sombras ampliavam a presença do homem pela casa inteira. Essa sombra se infiltrava devagar em cada quarto jogava no rosto de cada um tudo aquilo que não haviam sido, que não haviam feito, tudo aquilo que tinham apenas ameaçado ser, intensos e cheios de sangue, para depois se amoldurarem num dia-a-dia feito de automatismos. Quieta, remota, a presença do homem era uma afronta.","Caio Fernando Abreu"),
	array("Quero deixar bem claro que a única coisa que existe para mim é a juventude, tudo o mais é besteira, lantejoulas, vidrilho.  Posso fazer duas mil plásticas e não resolve, no fundo é a mesma bosta, só existe a juventude. Ele era a minha juventude mas  naquele tempo eu não sabia, na hora a gente nunca sabe nem pode mesmo saber, fica tudo natural como o dia que sucede à noite,  como o sol, a lua, eu era jovem e não pensava nisso como não pensava em respirar. Alguém por acaso fica atento ao ato de  respirar? Fica, sim, mas quando a respiração se esculhamba. Então dá aquela tristeza, puxa, eu respirava tão bem...","Lygia Fagundes Telles"),
	array("Nota-se, entre os matemáticos, uma imaginação assombrosa... Repetimos: havia mais imaginação na cabeça de Arquimedes do que na  de Homero.","Voltaire"),
	array("Ouça um bom conselho<br>Que eu lhe dou de graça<br>Inútil dormir que a dor não passa<br>Espere sentado<br>Ou você se cansa<br>Está provado, quem espera nunca alcança","Chico Buarque"),
	array("The only way to get rid of a temptation is to yield to it. Resist it, and your soul grows sick with longing for the things it  has forbidden to itself.","Oscar Wilde"),
	array("Ninguém mais morre devido a verdades fatais hoje em dia; existem antídotos em demasia.","Nietzsche"),
	array("Muad'Dib learned rapidly because his first training was in how to learn. And the first lesson of all was the basic trust that  he could learn. It's shocking to find how many people do not believe they can learn, and how many more believe learning to be  difficult. Muad'Dib knew that every experience carries its lesson." ,"Frank Herbert"),
	array("Wenn ist das nunstuck geht und slotermeyer? Ja! Ba yerhund das oder die flipperwaldt gespuhrt!",""),
	array("Se você está lendo este aviso, então isto é para você. Cada palavra lida deste texto inútil é um segundo perdido da sua vida.  Você não tem nada mais para fazer? Sua vida é tão vazia que você não consegue vivê-la melhor? Ou você está tão impressionado  com a autoridade que você respeita em todos aqueles que a exercem em você? Você lê tudo o que deveria? Pensa tudo o que  deveria? Compra tudo o que lhe dizem para comprar? Saia do seu apartamento. Encontre alguém do sexo oposto. Pare de comprar  tanto e de se masturbar tanto. Peça demissão. Comece a brigar. Prove que você está vivo. Se você não se fizer valer pelo seu  lado humano, você se tornará apenas mais um número. Você foi avisado...","Tyler Durden"),
	array("Dizem que sou tímido. Nada disso! sou é caladão, introspectivo. Não sei porque sujeitam os introvertidos a tratamentos.  Só por não poderem ser chatos como os outros?","Mário Quintana"),
	array("Throughout human history, as our species has faced the frightening, terrorizing fact that we do not know who we are, or where we are going in this ocean of chaos, it has been the authorities, the political, the religious, the educational authorities who attempted to comfort us by giving us order, rules, regulations, informing, forming in our minds their view of reality. To think for yourself you must question authority and learn how to put yourself in a state of vulnerable, open-mindedness; chaotic, confused, vulnerability to inform yourself. <br>Think for yourself. <br>Question authority.","Timothy Leary"),
	array("I think it [the consume of mescaline] would be extremey good for almost anybody with fixed ideas and with a great certainty about what's what to take this thing and to realize the world he's constructed is by no means the only world, that there are these extraordinary other types of Universe.","Aldous Huxley"),
	array("Talk among the prophets, give you something<br>Talk among the teachers, tell you something<br>Talk among your one true self now,<br>Forever, forever, forever...","Jon Anderson")
	);
}

function loadQuotes()
# Loads the quotes from a file.
## Actually it's not being used.
{
	$data = array();
	
	$path = "/home/grad/cmdalbem/public_html/dokuwiki/lib/quotes.txt";
	
	if (file_exists($path))
	{
		$file = fopen($path, 'r');
		
		while (!feof($file)) {
			$newquote = array(fgets($file, 4096), fgets($file, 4096));
			if(!feof($file))
				array_push( $data, $newquote );				
		}
		
		fclose($file);	
	}

	return $data;
}

function printRandomQuote()
# I swear this function prints a random quote everytime the page is loaded. It generates a javascript code that gets a random quote the vector.
{
	$quotesList = QuoteDB::$quotes;
	
	echo "<script type=\"text/javascript\"> var vetor = new Array(";
	for ($i=0; $i < count($quotesList); $i++)
	{
		echo "\"<p><div class=\\\"notetip\\\">\\";
		echo utf8_encode($quotesList[$i][0]);
		echo "\\\"<br><b>";
		echo utf8_encode($quotesList[$i][1]);
		echo "</b></div></p>\"";
		if( $i != count($quotesList)-1 )
			echo ",";
	}
	echo ");document.write(vetor[Math.floor(Math.random()*vetor.length)]);</script>";
}

function printQuotes()
{
	$quotesList = QuoteDB::$quotes;
	
	foreach ($quotesList as $q)
	{
		printQuote($q);
	}
}

function printQuote($q)
{
	$t1 = utf8_encode($q[0]);
	$t2 = utf8_encode($q[1]);

	echo "<p><div class=\"notetip\">";
	echo "$t1\"<br><b>$t2</b>";
	echo "</div></p>";
}

########################################################################################
########################################################################################
########################################################################################

global $sqltable, $dbhandle, $fileId, $sqltable_tmp;

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

function printFromFile($path)
{
	$data;

	if (file_exists($path))
	{
		$data = 'Empty file.';
	
		$fh = fopen($path, 'r');
		$data = fread($fh, filesize($path));
		fclose($fh);
	}

	echo utf8_encode($data);
}

function processContent( $dir )
{
	global $sqltable, $dbhandle, $fileId, $sqltable_tmp;

	$path = PROJECTS_PATH . $dir;

	if( file_exists($path . "/content.xml") )
	{
		$xml = simplexml_load_file($path . "/content.xml");

		$hasTitle = strlen($xml->title) > 0;
		$hasText = strlen($xml->text) > 0;
		$hasImage = strlen($xml->image) > 0;
		$hasDownloads = count($xml->downloads->download) > 0;

		$hasTable = $hasTitle || $hasImage || $hasDownloads;

		if( $hasTable )
			echo "<table class=\"inline\">";

		if( $hasTitle || $hasText || $hasImage)
			echo "<tr class=\"row0\">";

		if( $hasTitle || $hasText )
			echo "<td class=\"col0\">";

		if( $hasTitle )
		{	
			echo "<b>";
			echo $xml->title;
			echo "</b>";
		}

		if( $hasText )
		{
			if($hasTitle)
				echo "<br/><br/>";
			echo $xml->text;
			echo "<br>";
		}

		if( $hasTitle || $hasText )
			echo "</td>";

		if( $hasImage )
		{
			echo "<td class=\"col1\">";

			echo "<a href=\"";
			echo MEDIA_VIEWER_URL . "projects_courses:";
			echo $xml->image;
			echo "\"><img src=\"";
			echo MEDIA_URL . "projects_courses:";
			echo $xml->image;
			echo "\" width=\"128\" /></a>";

			echo "</td>";
		}

		if( $hasDownloads )
		{
			echo "</tr><tr class=\"row0\"><td class=\"col0\" colspan=\"2\">";
			echo "<b><font color=\"gray\">DOWNLOADS | </font></b>";
			foreach($xml->downloads->download as $download)
			{
				$fetchpath = BASE_URL . "fetch.php?id=" . $fileId;

				echo "<a href=\"";
				//echo $filepath;
				echo $fetchpath;
				echo "\" class=\"download\" rel=\"nofollow\">";
				echo $download;
				echo "</a>";

				$filepath = PROJECTS_URL . $dir . "/" . $download;
				$count = 0;
				
				//check if this file was already on the database. If that's the case, we recover it's COUNT and create the new entry with this value.
				$query = "SELECT count, path FROM $sqltable_tmp WHERE path=\"$filepath\"";
				$qresult = sqlite_array_query($dbhandle, $query, SQLITE_ASSOC);
				if(count($qresult)>0)
					$count = $qresult[0]['count'];
				
				$query = "INSERT INTO $sqltable(id, count, path) VALUES ('$fileId', '$count', '$filepath')";
				sqlite_query($dbhandle, $query);

				$fileId++;
			}
			echo "</td></tr>";
		}
		else
			echo "</tr>";

		if( $hasTable )
			echo "</table>";
	}
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
		echo "<li><a href=\"#\">";
		echo utf8_encode($project);
		echo "</a></li>";

		echo "<ul class=\"interactive\">";
		processContent( $dir ); //prints description and/or text
		echo "</ul>";
	}
	else //normal project with content
	{
		echo "<li class=\"closed\"><a href=\"#\" class=\"expand\">";
		
		$xml = simplexml_load_file(PROJECTS_PATH . $dir . "/content.xml");
		echo $xml->name;

		if( $level==0 )
			echo "</a> <div style=\"display:block\"><p>";
		else
			echo "</a> <div style=\"display:none\"><p>";

		echo "<ul class=\"interactive\">";
		processContent( $dir ); //prints description and/or text

		foreach ($projects as $proj) // subprojects iteration
		{
			if( is_dir("$projPath/$proj") )
				listSubProjects( $dir, $proj, $level+1 );
		}

		echo "</ul>"; //ends project's list of contents
		echo "</p></div></li>"; //ends projects list item
	}
}

function initDatabase()
{
	global $sqltable, $dbhandle, $fileId, $sqltable_tmp;

	$dbname = '../downloads.db';
	$sqltable ="downloads";
	$sqltable_tmp ="downloads2";
	$fileId = 0;

	$dbhandle = sqlite_open($dbname, 0666, $error);
	if ($err)  exit($err);
	
	//we criate a replicate of the last database to retrive last download counts
	$query = "CREATE TABLE $sqltable_tmp AS SELECT * FROM $sqltable";
	sqlite_query($dbhandle, $query);

	$query = "DROP TABLE $sqltable";	
	sqlite_query($dbhandle, $query);

	$query = "CREATE TABLE $sqltable (id INTEGER PRIMARY KEY,count INTEGER,path TEXT)";
	sqlite_query($dbhandle, $query);
}

function unitDatabase()
{
	global $dbhandle, $sqltable_tmp;

	$query = "DROP TABLE $sqltable_tmp";	
	sqlite_query($dbhandle, $query);
}

function createList()
{
	initDatabase();

	$dirs = dirList(PROJECTS_PATH);
	sort($dirs);

	foreach ($dirs as $dir)
	{
		$areaPath = PROJECTS_PATH . "/" . $dir;

		echo "<h2><a name=>";
		$xml = simplexml_load_file(PROJECTS_PATH . $dir . "/content.xml");
		echo $xml->name;
		echo "</a></h2>";

		$projects = dirList( $areaPath );
		sort($projects);

		echo "<ul class=\"interactive\">";

		// text generation
		processContent($dir);

		foreach ($projects as $project)
		{
			if( is_dir("$areaPath/$project") )
				listSubProjects( $dir , $project, 0 );
		}

		echo "</ul>";
	}

	unitDatabase();
}


?>