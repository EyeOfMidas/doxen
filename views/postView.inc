<?php
$humanReadableTime = new HumanReadableTime();
?>
<ul>
<?php
foreach ($posts as $post) {
	?>
<li><a href="/?a=post&id=<?=$post['post_id']?>&t=<?=$post['topic_id']?>"><?=$post['post_name']?></a>
	<div class="postByline">submitted <?=$humanReadableTime->formatString($post['timestamp'])?> by <a href="/?a=user&id=<?=$post['user_id']?>"><?=$post['user_display_name']?></a> to <a
				href="?a=topic&id=<?=$post['topic_id']?>"><?=$post['topic_display_name']?></a> <span class="commentCount"><a href="/?a=post&id=<?=$post['post_id']?>&t=<?=$post['topic_id']?>">comments (<?=$post['comment_count']?>)</a></span>
		</div></li>
<?php } ?>
</ul>
