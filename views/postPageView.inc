<?php
include "header.php";
$humanReadableTime = new HumanReadableTime();
$allTopicNames = array();
?>
<div id="content">
	<h1><?=$postData['post_name']?></h1>
	<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$postData['user_display_name']?></div>
	<div id="parentTopics">
		Topics:
		<ul>
<?php foreach($postTopics as $topic) { ?>
	<li><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
<?php
	$allTopicNames[] = $topic['display_name'];
}
?>
</ul>
	</div>
	<div id="postContents"><?=$postData['content']?></div>
<?php include "addNewCommentView.inc";?>
<div id="comments"><?=$commentView?></div>
</div>
</body>
</html>

