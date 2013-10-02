<div id="addComment">
	Post a comment:
	<form method="POST" action="?a=submitnewcomment">
		<textarea name="commentBody"></textarea>
		<br /> <input type="text" name="commentTags"
			value="<?=implode(', ', $allTopicNames)?>" /> <input type="hidden"
			name="currentPost" value="<?=$postData['post_id']?>" /> <input
			type="hidden" name="parentComment" value="<?=$parentCommentId?>" /> <input type="submit"
			name="submit" value="Post" />
	</form>
</div>