<?php
$session = new Session();
$userId = $session->getValue('logged_in');
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Strict//EN"
	"http://www.w3.org/TR/xhtml1/DTD/xhtml1-strict.dtd">
<html xmlns="http://www.w3.org/1999/xhtml" xml:lang="en" >
<head>
	<title>Doxen</title>
	<script src="//ajax.googleapis.com/ajax/libs/jquery/1.9.0/jquery.min.js"></script>
	<script type="text/javascript"></script>
	<style type="text/css" title="currentStyle" media="screen">
		@import "/css/main.css";
	</style>
</head>
<body>
	<div id="header">
	<a href="/">Doxen</a>
	<div id="defaultTopics">
	<ul>
	<?php foreach($defaultTopics as $topic) { ?>
		<li><a href="/?a=topic&id=<?=$topic['topic_id']?>"><?=$topic['display_name']?></a></li>
	<?php } ?>
	</ul>
	</div>
	<div id="loginContainer"><?=$loginView?></div>
	</div>
	<div id="createTopicContainer"><a href="/?a=createtopic">Create a new topic</a></div>
	<div id="posts"><?=$postsView?></div>
	<script type="text/javascript" src="/js/doxenInit.js"></script>
	<script type="text/javascript">
	$(document).ready(function() {
		DOXEN.init();
	});
	</script>
</body>
</html>

