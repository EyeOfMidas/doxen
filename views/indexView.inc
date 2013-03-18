<html>
<head>
	<title>Doxen</title>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
	<script type="text/javascript"></script>
</head>
<body>
	<div id="loginContainer"><?=$loginView?></div>
	<div id="defaultTopics">
	<ul>
	<?php foreach($defaultTopics as $topic) { ?>
		<li><a href="/?t=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
	<?php } ?>
	</ul>
	</div>
	<div id="createTopicContainer"><a href="/?a=createtopic">Create a new topic</a></div>
	<div id="viewPosts"><?=$postsView?></div>
	<script type="text/javascript" src="/js/doxenInit.js"></script>
	<script type="text/javascript">
	$(document).ready(function() {
		DOXEN.init();
	});
	</script>
</body>
</html>

