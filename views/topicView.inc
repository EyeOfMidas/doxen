<?php include "header.inc"; ?>
<div id="pageBody">
	<div id="content">
		<h1>
			<a href="?a=topic&id=<?=$topicData['topic_id']?>"><?=$title?></a>
		</h1>
		<div id="posts"><?=$postView?></div>
	</div>
<?php include "topicSidebarView.inc"; ?>
</div>
</body>
</html>
