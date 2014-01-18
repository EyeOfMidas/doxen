<div id="addComment">
	Commenting as: <?=$user->getDisplayName()?>
	<form method="POST" action="?a=submitnewcomment&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>" enctype="multipart/form-data">
		<textarea name="commentBody"></textarea>
		<br />
		<label for="attachment1">Upload Attachment:</label><input type="file" name="attachment1" id="attachment1" />
		<br />
		<input type="hidden" name="parentComment" value="<?=$parentCommentId?>" />
		<input type="submit" name="submit" value="Post" />
	</form>
</div>