<?=$header?>
<div id="contentContainer">
	<div id="content">
		<form method="POST" action="/?a=submitnewpost" enctype="multipart/form-data">
			<label for="postTitle">Post title:</label><input type="text" name="postTitle" id="postTitle" />
			<br />
			<label for="postContent">Post text:</label><textarea name="postContent" id="postContent"></textarea>
			<br />
			<label for="tags">Topic tags:</label><input type="text" name="tags" id="tags" value="<?=$tag?>" />
			<br />
			<label for="attachment1">Upload Attachment:</label><input type="file" name="attachment1" id="attachment1" />
			<br />
			<input type="submit" value="Create Post" />
		</form>
	</div>
</div>
<?php include "sidebar.inc"; ?>
</html>
