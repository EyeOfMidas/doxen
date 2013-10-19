<div class="commentReply" id="comment<?=$commentData['comment_id']?>" style="display: none;">
Commenting as: <?=$user->getDisplayName()?>
	<form method="POST" action="?a=submitnewcomment&id=<?=$commentData['post_id']?>&t=<?=$commentData['topic_id']?>">
		<textarea name="commentBody"></textarea>
		<br />
		<input type="hidden" name="parentComment" value="<?=$commentData['comment_id']?>" />
		<input type="submit" name="submit" value="Reply" />
	</form>
</div>