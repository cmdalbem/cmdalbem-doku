<?php
if(isset($_POST['entry_text'])) {
     
    // CHANGE THE TWO LINES BELOW
    $email_to = "ninja.dalbem@gmail.com";
    $email_from = "ninja.dalbem@gmail.com";
     
    $email_subject = "website html form submissions";
     
    function died($error) {
        // your error code can go here
        echo "We are very sorry, but there were error(s) found with the form you submitted. ";
        echo "These errors appear below.<br /><br />";
        echo $error."<br /><br />";
        echo "Please go back and fix these errors.<br /><br />";
        die();
    }
     
    $email_message .= $_POST['entry_text'];
     
$headers = 'From: '.$email_from."\r\n".
'Reply-To: '.$email_from."\r\n" .
'X-Mailer: PHP/' . phpversion();
    mail($email_to, $email_subject, $email_message, $headers); 
?>
 
Thank you for contacting us.
 
<?php
}
else {
	echo "Empty message.";
}
die();
?>