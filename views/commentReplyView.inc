<div class="commentReply" id="comment<?=$commentData['comment_id']?>" style="display: none;">
Reply to <?=$commentData['user_display_name']?>:
	<form method="POST" action="?a=submitnewcomment">
		<textarea name="commentBody"></textarea>
		<br />
		<input type="hidden" name="commentTags" value="<?=$commentData['topic_display_name']?>" />
		<input type="hidden" name="currentTopic" value="<?=$commentData['topic_id']?>" />
		<input type="hidden" name="currentPost" value="<?=$commentData['parent_post_id']?>" />
		<input type="hidden" name="parentComment" value="<?=$commentData['comment_id']?>" />
		<input type="submit" name="submit" value="Reply" />
	</form>
</div>