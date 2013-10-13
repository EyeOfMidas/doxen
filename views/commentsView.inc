<?php
$humanReadableTime = new HumanReadableTime();
foreach ($comments as $commentData) {
	?>
<div class="comment">
	<div class="commentByline"><?=$commentData['user_display_name']?> - <?=$humanReadableTime->formatString($commentData['timestamp'])?></div>
	<p><?=$commentData['content']?></p>
		<?php if(isset($userId)) {?>
			<div class="commentActions">
				<a data-id="<?=$commentData['comment_id']?>" class="toggleCommentReply" href="javascript:;">reply</a>
				<a data-id="<?=$commentData['comment_id']?>" class="openCommentEdit" href="javascript:;">edit</a>
			</div>
		<?php } ?>
		<?php
	include "commentReplyView.inc";
	?>
		<?php if($commentData['replies'] > 0) {?>
		<div class="replies">
		<a data-id="<?=$commentData['comment_id']?>"
			class="loadCommentReplies" href="javascript:;">View replies (<?=$commentData['replies']?>)</a>
	</div>
		<?php } ?>
	</div>
<?php
}
?>
