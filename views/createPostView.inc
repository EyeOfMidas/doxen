<?php include "header.inc"; ?>
<div id="content">
<form method="POST" action="/?a=submitnewpost">
	<label for="postTitle">Post title:</label><input type="text" name="postTitle" id="postTitle" />
	<br />
	<label for="postContent">Post text:</label><textarea name="postContent" id="postContent"></textarea>
	<br />
	<label for="tags">Topic tags:</label><input type="text" name="tags" id="tags" value="<?=$tag?>"/>
	<br />
	<input type="submit" value="Create Post" />
</form>
</div>
<?php include "sidebar.inc"; ?>
</html>
