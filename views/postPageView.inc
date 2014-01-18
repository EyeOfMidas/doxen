<?php
$humanReadableTime = new HumanReadableTime();
$allTopicNames = array();
$session = new Session();
$userId = $session->getValue('logged_in');
?>
<?=$header?>
<style type="text/css">
#postAttachments {
	font-size: 10px;
}
</style>
<div id="contentContainer">
	<div id="content">
		<a href="?a=post&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>"><?=$postData['post_name']?></a>

		<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <a href="/?a=user&id=<?=$postData['user_id']?>"><?=$postData['user_display_name']?></a>
		in topic:<a href="?a=topic&id=<?=$postData['topic_id']?>"><?=$postData['topic_display_name']?></a>
		</div>
		<div id="postContents">
		<?=$postData['content']?>
		<div id="postAttachments">
			<ul>
			<?php foreach($fileData as $file) { ?>
				<li><a href="/?a=files&id=<?=$file['file_id']?>&force=1"><img src="images/icons/<?=$file['icon']?>.png" /></a> <a href="/?a=files&id=<?=$file['file_id']?>" target="_blank"><?=$file['name']?></a></li>
			<?php } ?>
			</ul>
		</div>
		</div>
			<?php if ($userId) { ?>
			<div class="postActions">
				<?php if($userId == $postData['user_id']) {?>
					<a data-id="<?=$postData['post_id']?>" class="edit" href="?a=editpost&id=<?=$postData['post_id']?>&t=<?=$topicData['topic_id']?>">edit</a>
					<!--<a data-id="<?=$postData['post_id']?>" class="delete" href="javascript:;">delete</a> -->
				<?php } ?>
			</div>
			<?php }
			$parentCommentId = 0;
			 include "addNewCommentView.inc"; ?>
			<div id="comments"><?=$commentView?></div>
		</div>
	</div>
	<?php include "topicSidebarView.inc"; ?>

<script type="text/javascript">
$(document).ready(function() {
	var toggleCommentInputWindow = function() {
		$('#comment'+$(this).data('id')+'.commentReply').toggle();
	};
	var openCommentReplyFunction = function() {};
	openCommentReplyFunction = function() {
			var replyContainer = $(this).parent();
			var parentCommentId = $(this).data('id');
			$.get('?a=commentreplies&id=' + parentCommentId, function(result) {
				replyContainer.html(result);
				$('.loadCommentReplies').unbind('click');
				$('.toggleCommentReply').unbind('click');
				$('.openCommentEdit').unbind('click');
				$('.loadCommentReplies').click(openCommentReplyFunction);
				$('.toggleCommentReply').click(toggleCommentInputWindow);
				$('.openCommentEdit').click(openCommentEdit);
				});
	};
	var openCommentEdit = function() {
		var commentId = $(this).data('id');
		//TODO: async call to server to get comment contents
		$('#comment'+commentId+ ' .editWindow').toggle();
		$('#comment'+commentId+ ' .contents').toggle();
	};
	$('.loadCommentReplies').click(openCommentReplyFunction);
	$('.toggleCommentReply').click(toggleCommentInputWindow);
	$('.openCommentEdit').click(openCommentEdit);
	
});
</script>
</body>
</html>

