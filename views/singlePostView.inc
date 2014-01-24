<?php
$humanReadableTime = new HumanReadableTime();
?>
<div class="post" id="post<?=$postData['post_id']?>">
	<a class="<?=($postData['new_content'] ? "newPost" : "")?>" href="/?a=post&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>"><?=$postData['post_name']?></a>
	<div class="postByline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <a href="/?a=user&id=<?=$postData['user_id']?>"><?=$postData['user_display_name']?></a> to <a href="?a=topic&id=<?=$postData['topic_id']?>"><?=$postData['topic_display_name']?></a> <span class="commentCount"><a href="/?a=post&id=<?=$postData['post_id']?>&t=<?=$postData['topic_id']?>">comments</a></span>
	</div>
</div>