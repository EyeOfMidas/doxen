<?php
$humanReadableTime = new HumanReadableTime();
?>
<div class="comment" id="comment<?=$commentData['comment_id']?>">
	<div class="commentByline"><?=$commentData['display_name']?> - <?=$humanReadableTime->formatString($commentData['timestamp'])?><?=$commentData['is_edited'] ? '*' : ''?></div>
	<p class="contents"><?=$commentData['content']?></p>
	<a href="?a=post&id=<?=$commentData['parent_post_id']?>&cid=<?=$commentData['comment_id']?>">parent</a>
</div>