<?php
$humanReadableTime = new HumanReadableTime();
?>
<div id="comments">
<?php
foreach ($comments as $commentData) {
	?>
	<div class="comment">
		<div class="commentByline"><?=$commentData['display_name']?> - <?=$humanReadableTime->formatString($commentData['timestamp'])?></div>
	<?=$commentData['content']?>
	</div>
<?php } ?>
</div>