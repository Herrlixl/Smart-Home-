<!DOCTYPE html>
<?php
/* if(notloggedin)
	goto index.php 
	session?		*/
?>
<head>
<title>�bersicht</title>
</head>
<body>
<div>
<form action='' method='post'>
<input type='submit' name='logout' value='Logout'/>
</form>
</div>
<nav>
<a href="steuerung.php?zimmer=wohnzimmer" title="Wohnzimmer">Wohnzimmer</a>
<a href="steuerung.php?zimmer=schlafzimmer" title="Schlafzimmer">Schlafzimmer</a>
<a href="steuerung.php?zimmer=kueche" title="Kueche">K�che</a>
</nav>
<?php
/* if(logout)
	logout + goto index.php */
?>
</body>