<?php include "header.php"; ?>
<div id="content">
<form method="POST" action="/?a=submitnewpost">
	<label for="title">Post title:</label><input type="text" name="title" id="title" />
	<label for="postContent">Post text:</label><textarea name="postContent" id="postContent"></textarea>
	<label for="tags">Topic tags:</label><input type="text" name="tags" id="tags" />
	<input type="submit" value="Create Post" />
</form>
</div>
</html>
