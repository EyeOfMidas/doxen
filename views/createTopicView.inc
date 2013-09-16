<?php
$session = new Session();
$userId = $session->getValue('logged_in'); ?>
<html>
<form method="POST" action="/?a=submitnewtopic">
	<label for="name">Topic name:</label><input type="text" name="name" id="name" />
	<input type="submit" value="Create Topic" />
</form>
</html>
