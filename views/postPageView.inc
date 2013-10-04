<?php
include "header.php";
$humanReadableTime = new HumanReadableTime();
$allTopicNames = array();
?>
<div id="pageBody">
	<div id="content">
		<h1>
			<a
				href="?a=post&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>"><?=$postData['post_name']?></a>
		</h1>

		<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$postData['user_display_name']?>
		<div id="parentTopics">
				Posted in topics:
				<ul>
<?php foreach($postTopics as $topic) { ?>
	<li><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
<?php
	$allTopicNames[] = $topic['display_name'];
}
?>
</ul>
			</div>
		</div>
		<div id="postContents"><?=$postData['content']?></div>
<?php
$parentCommentId = 0;
if ($userId) {
	include "addNewCommentView.inc";
}
?>
<div id="comments"><?=$commentView?></div>
	</div>
</div>
<script type="text/javascript">
$(document).ready(function() {
	var toggleCommentInputWindow = function() {
		$('#comment'+$(this).data('id')+'.commentReply').toggle();
	};
	var openCommentReplyFunction = function() {
			var replyContainer = $(this).parent();
			var parentCommentId = $(this).data('id');
			console.log('doxen.test/?a=commentreplies&id=' + parentCommentId);
			$.get('?a=commentreplies&id=' + parentCommentId, function(result) {
				console.log('got response', result);
				replyContainer.html(result);
				$('.loadCommentReplies').unbind('click');
				$('.loadCommentReplies').click(openCommentReplyFunction);
				$('.toggleCommentReply').unbind('click');
				$('.toggleCommentReply').click(toggleCommentInputWindow);
				});
	};
	$('.loadCommentReplies').click(openCommentReplyFunction);
	$('.toggleCommentReply').click(toggleCommentInputWindow);
});
</script>
</body>
</html>

