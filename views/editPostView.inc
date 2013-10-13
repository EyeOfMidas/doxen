<?php
$humanReadableTime = new HumanReadableTime();
?>
<?=$header?>
<div id="contentContainer">
<div id="content">
	<h1>
			<a href="?a=post&id=<?=$postData['post_id']?>&t=<?=$topicId?>"><?=$postData['name']?></a>
		</h1>

		<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$username?>
			<?php /*<div id="parentTopics">Posted in topics:
				<ul>
				<?php foreach($postTopics as $topic) { ?>
					<li><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
					<?php $allTopicNames[] = $topic['display_name'];
				} ?>
				</ul>
			</div>
			 */ ?>
		</div>
	<form method="POST" action="/?a=submiteditpost&id=<?=$postData['post_id']?>&t=<?=$topicId?>">
		<textarea id="postContent" name="postContent"><?=$postData['content']?></textarea>
		<br />
		<input type="submit" value="Save Changes" />
	</form>
</div>
</div>
<?php include "topicSidebarView.inc"; ?>
</html>
