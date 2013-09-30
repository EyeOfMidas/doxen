<?php
include "header.php";
$humanReadableTime = new HumanReadableTime();
?>
<div id="content">
<h1><?=$postData['name']?></h1>
<div id="byline">submitted <?=$humanReadableTime->formatString($postData['timestamp'])?> by <?=$postData['display_name']?></div>
<div id="postContents"><?=$postData['content']?></div>
<div id="comments"><?=$commentView?></div>
</div>
</body>
</html>

