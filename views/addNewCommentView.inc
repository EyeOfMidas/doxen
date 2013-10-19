<div id="addComment">
	Commenting as: <?=$user->getDisplayName()?>
	<form method="POST" action="?a=submitnewcomment&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>">
		<textarea name="commentBody"></textarea>
		<br />
		<input type="hidden" name="parentComment" value="<?=$parentCommentId?>" />
		<input type="submit" name="submit" value="Post" />
	</form>
</div>