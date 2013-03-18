<?php
$humanReadableTime = new HumanReadableTime();
?>
<html>
<head>
	<title><?=$postData['display_name']?></title>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
        <script type="text/javascript"></script>
        <style type="text/css" title="currentStyle" media="screen">
                @import "/css/main.css";
        </style>
</head>
<body>
<div id="header">
	<a href="/">Doxen</a>
	<h1><a href="?a=post&id=<?=$postData['post_id']?>"><?=$postData['name']?></a></h1>
	Submitted <?=$humanReadableTime->formatString($postData['timestamp']);?> by <?=$postData['display_name']?>
	<div id="loginContainer"><?=$loginView?></div>
</div>
<div id="postContents"><?=$postData['content']?></div>
<div id="comments"><?=$commentView?></div>
</body>
</html>

