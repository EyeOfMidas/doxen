<?php
$humanReadableTime = new HumanReadableTime();
$allTopicNames = array();
$session = new Session();
$userId = $session->getValue('logged_in');
?>
<?=$header?>
<div id="pageBody">
	<div id="content">
		<h1>
			<a href="?a=post&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>"><?=$postData['post_name']?></a>
		</h1>

		<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$postData['user_display_name']?>
			<div id="parentTopics">Posted in topics:
				<ul>
				<?php foreach($postTopics as $topic) { ?>
					<li><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
					<?php $allTopicNames[] = $topic['display_name'];
				} ?>
				</ul>
			</div>
		</div>
		<div id="postContents"><?=$postData['content']?></div>
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
	<?php include "topicSidebarView.inc"; ?>
</div>

<script type="text/javascript">
$(document).ready(function() {
	var toggleCommentInputWindow = function() {
		$('#comment'+$(this).data('id')+'.commentReply').toggle();
	};
	var openCommentReplyFunction = function() {
			var replyContainer = $(this).parent();
			var parentCommentId = $(this).data('id');
			$.get('?a=commentreplies&id=' + parentCommentId, function(result) {
				replyContainer.html(result);
				$('.loadCommentReplies').unbind('click');
				$('.toggleCommentReply').unbind('click');
				$('.loadCommentReplies').click(openCommentReplyFunction);
				$('.toggleCommentReply').click(toggleCommentInputWindow);
				});
	};
	$('.loadCommentReplies').click(openCommentReplyFunction);
	$('.toggleCommentReply').click(toggleCommentInputWindow);
});
</script>
</body>
</html>

