<?php
$humanReadableTime = new HumanReadableTime();
foreach ($comments as $commentData) {
	?>
	<div class="comment">
		<div class="commentByline"><?=$commentData['display_name']?> - <?=$humanReadableTime->formatString($commentData['timestamp'])?></div>
		<p><?=$commentData['content']?></p>
		<?php if($commentData['replies'] > 0) {?>
		<div class="replies">
			<a data-id="<?=$commentData['comment_id']?>" href="javascript:;">View replies (<?=$commentData['replies']?>)</a>
		</div>
		<?php } ?>
	</div>
<?php
}
?>
