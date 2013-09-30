<?php
include "header.php";
$humanReadableTime = new HumanReadableTime();
?>
<div id="content">
<h1><?=$postData['post_name']?></h1>
<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$postData['user_display_name']?></div>
<div id="parentTopics">Topics: <ul>
<?php foreach($postTopics as $topic) { ?>
	<li><a href="?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
<?php } ?>
</ul>
</div>
<div id="postContents"><?=$postData['content']?></div>
<div id="comments"><?=$commentView?></div>
</div>
</body>
</html>

