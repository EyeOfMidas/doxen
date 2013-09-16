<html>
<head>
	<title><?=$topicData['display_name']?></title>
        <script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
        <script type="text/javascript"></script>
        <style type="text/css" title="currentStyle" media="screen">
                @import "/css/main.css";
        </style>
</head>
<body>
<div id="header">
	<a href="/">Doxen</a>
	<h1><a href="?a=topic&id=<?=$topicData['topic_id']?>"><?=$topicData['display_name']?></a></h1>
	<div id="loginContainer"><?=$loginView?></div>
</div>
<div id="createPostContainer"><a href="/?a=createpost">Create a new post</a></div>
<div id="posts"><?=$postView?></div>
</body>
</html>
