<div class="commentReply" style="display: none;">
	Reply to [username]:
	<form method="POST" action="?a=submitnewcomment">
		<textarea name="commentBody"></textarea>
		<br />
		<input type="hidden" name="commentTags" value="[current topic]" />
		<input type="hidden" name="parentComment" value="<?=$parentCommentId?>" />
		<input type="submit" name="submit" value="Reply" />
	</form>
</div>