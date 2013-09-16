<?php
$session = new Session();
$userId = $session->getValue('logged_in'); ?>
<html>
<form method="POST" action="/?a=submitnewpost">
	<label for="title">Post title:</label><input type="text" name="title" id="title" />
	<label for="content">Post text:</label><textarea type="text" name="content" id="content"></textarea>
	<label for="tags">Topic tags:</label><input type="text" name="tags" id="tags" />
	<input type="submit" value="Create Post" />
</form>
</html>
