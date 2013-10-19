<div id="addComment">
	Commenting as: <?=$user->getDisplayName()?>
	<form method="POST" action="?a=submiteditcomment&id=<?=$commentData['comment_id']?>">
		<textarea name="commentBody"><?=$commentData['content']?></textarea>
		<br />
		<input type="submit" name="submit" value="Save changes" />
	</form>
</div>